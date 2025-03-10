/*
** Copyright (c) 2025 LunarG, Inc.
** Copyright (c) 2025 Arm Limited and/or its affiliates <open-source-office@arm.com>
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

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
    private FrameLayout         mFrameLayout;
    private static final String TAG = "gfxrecon";
    private Surface             mSurface;
    public native void          setSurface(Surface surface);
    private List<VKSurfaceView> mSurfaceviewList = new ArrayList<VKSurfaceView>();

    @Override protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        // Create a FrameLayout to hold SurfaceView instances
        mFrameLayout = new FrameLayout(this);
        setContentView(mFrameLayout);

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
                mFrameLayout.addView(newSurfaceView,
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
                if (mFrameLayout != null)
                {
                    Log.i(TAG, "Remove one view");
                    mFrameLayout.removeView(mSurfaceviewList.get(sur_idx));
                }
                else
                {
                    Log.w(TAG, "View container has been destroyed!");
                }
            }
        });
    }
}
