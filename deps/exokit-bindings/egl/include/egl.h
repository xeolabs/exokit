#ifndef _EGL_BINDINGS_H_
#define _EGL_BINDINGS_H_

#include <string>
#include <sstream>
#include <map>

#include <v8.h>
#include <nan.h>
#include <defines.h>

#ifndef EGL_EGLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#endif
#include <EGL/egl.h>
#include <EGL/eglext.h>
/* #include <GLES3/gl3.h>
#include <GLES3/gl3ext.h> */

// #include <webgl.h>

using namespace v8;

class WebGLRenderingContext;

class NATIVEwindow {
public:
  EGLDisplay display;
  EGLContext context;
  unsigned int width;
  unsigned int height;
};
#define windowsystem egl

namespace egl {
  void GetWindowSize(NATIVEwindow *window, int *width, int *height);
  void *GetGLContext(NATIVEwindow *window);
  NATIVEwindow *GetCurrentWindowContext();
  void SetCurrentWindowContext(NATIVEwindow *window);
  void ReadPixels(WebGLRenderingContext *gl, unsigned int fbo, int x, int y, int width, int height, unsigned int format, unsigned int type, unsigned char *data);
}

// Local<Object> makeGlfw();
Local<Object> makeWindow();

#endif