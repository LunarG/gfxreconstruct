package com.lunarg.gfxreconstruct.replay;
import java.util.List;
import java.util.ArrayList;
import android.app.NativeActivity;
import android.os.Bundle;
import android.widget.FrameLayout;
import android.view.SurfaceView;
import android.view.SurfaceHolder;
import android.view.ViewGroup.LayoutParams;
import android.view.Surface;
import android.util.Log;
import android.content.Context;
import android.view.View;

public class ReplayActivity extends NativeActivity
{
    private FrameLayout         frameLayout;
    private static final String TAG = "gfxrecon: ReplayActivity";
    private Surface             mSurface;
    public native void          setSurface(Surface surface);
    private List<VKSurfaceView> mSurfaceviewList = new ArrayList<VKSurfaceView>();

    @Override protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        // Create a FrameLayout to hold SurfaceView instances
        frameLayout = new FrameLayout(this);
        setContentView(frameLayout);

        System.loadLibrary("gfxrecon-replay");
    }

    private class VKSurfaceView extends SurfaceView implements SurfaceHolder.Callback
    {
        private int width;
        private int height;

        public VKSurfaceView(Context context, int w, int h)
        {
            super(context);

            width  = w;
            height = h;

            SurfaceHolder holder = getHolder();
            holder.addCallback(this);
        }

        @Override public void surfaceCreated(SurfaceHolder holder)
        {
            mSurface = holder.getSurface();
            Log.i(TAG, "SurfaceHolder.Callback: surfaceCreated:" + mSurface);
        }

        @Override public void surfaceDestroyed(SurfaceHolder holder)
        {
            mSurface = holder.getSurface();
            Log.i(TAG, "SurfaceHolder.Callback: surfaceDestroyed:" + mSurface);
        }

        @Override public void surfaceChanged(SurfaceHolder holder, int format, int w, int h)
        {
            mSurface = holder.getSurface();
            Log.i(TAG, "SurfaceHolder.Callback: surfaceChanged:" + mSurface + " " + w + " " + h);
        }
    }

    public void addNewView(int width, int height)
    {
        // Create a new SurfaceView
        final Context context = this;
        final int     wid     = width;
        final int     hei     = height;
        mSurface              = null;
        runOnUiThread(new Runnable() {
            @Override public void run()
            {
                System.loadLibrary("gfxrecon-replay");
                VKSurfaceView newSurfaceView = new VKSurfaceView(context, wid, hei);
                frameLayout.addView(newSurfaceView,
                                    new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));
                Log.i(TAG,
                      "Create a new surface view:"
                          + " width:" + wid + " height:" + hei);
                mSurfaceviewList.add(newSurfaceView);
            }
        });
        while (mSurface == null)
        {
            try
            {
                Thread.sleep(100);
            }
            catch (Exception e)
            {
                Log.w(TAG, "Create new surface failed");
                e.printStackTrace();
            }
        }
        setSurface(mSurface);
    }

    private void removeOneView(int surface_idx)
    {
        final int sur_idx = surface_idx;
        runOnUiThread(new Runnable() {
            @Override public void run()
            {
                if (frameLayout != null)
                {
                    Log.i(TAG, "Remove one view");
                    frameLayout.removeView(mSurfaceviewList.get(sur_idx));
                }
                else
                {
                    Log.w(TAG, "View container has been destroyed!");
                }
            }
        });
    }
}
