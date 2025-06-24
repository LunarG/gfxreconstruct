# triangle-extra-device test app

## Description

This test app was written to test the `--deduplicate-device` option of `replay`.
The test app is identical to the `triangle` app, with the addition that it creates an extra device, destroying it
before the normal test app cleanup happens.

## Usage

To use this app for testing the `--deduplicate-device` feature of `replay`, create a capture of the app,
then recapture with and without the option enabled. Diffing the outputs of `convert` should reveal
that without the option, there are two calls to vkCreateDevice/vkDestroyDevice, and only one call when
the option is enabled.
