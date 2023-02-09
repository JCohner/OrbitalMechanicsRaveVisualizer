#ifndef __CANVAS_H__
#define __CANVAS_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
#include <thread>

class Canvas {
private:
  // TODO: likely set by constructor params
  int current_width_ = 800;
  int current_height_ = 600;

  int window_handle_ = 0;
  unsigned frame_count_ = 0;

  // TODO probably only needed by owner of canvas class...
  GLfloat ballRadius = 0.5f;   // Radius of the bouncing ball
  GLfloat ballX = 250.0f;         // Ball's center (x, y) position
  GLfloat ballY = 250.0f;

  std::thread work_thread_;

  void Initialize();
  void InitWindow();
  void ResizeFunction(int, int);
  void RenderFunction(void);

  void TimerFunction(int);
  void IdleFunction(void);

  

public:


}


#endif