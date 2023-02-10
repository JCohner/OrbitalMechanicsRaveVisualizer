#ifndef __CANVAS_H__
#define __CANVAS_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
#include <thread>
#include <queue>
#include <memory>

#include "gl_visualizer/visual_objects/Shape.h"

class Canvas {
private:
  // TODO: likely set by constructor params
  int current_width_ = 800;
  int current_height_ = 600;

  int window_handle_;
  unsigned frame_count_;

  std::thread work_thread_;

  void Initialize();
  void InitWindow();
  
  /* Static Callback Functions for FreeGLUT event handling */  // Unfortunately GLUT callback functions need to be static. TODO: figure out better workaround
  static void ResizeFunction(int, int);
  static void RenderFunction(void);
  static void TimerFunction(int);
  static void IdleFunction(void);
  static Canvas* instance_;
  
  int WorkThread();

  // quue of objects to be rendered in render thread
  std::vector<std::shared_ptr<Shape>> work_queue_;

public:
  void StartWork() {work_thread_ = std::thread(&Canvas::WorkThread, this);}
  void EnqueueShape(std::shared_ptr<Shape> shape) {work_queue_.push_back(shape);}
  int CurrentHeight() {return current_height_;}
  int CurrentWidth() {return current_width_;}
  static Canvas* GetInstance(int w = 800, int h = 600);
  Canvas(int width, int height) : current_width_(width), current_height_(height) {
    window_handle_ = 0;
    frame_count_ = 0;
  }
};


#endif