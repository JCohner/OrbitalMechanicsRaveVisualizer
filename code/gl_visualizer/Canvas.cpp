#include <math.h>     // Needed for sin, cos
#include "Canvas.h"

Canvas* Canvas::instance_= nullptr;;

Canvas* Canvas::GetInstance(int w, int h){
    if(instance_ == nullptr){
        instance_ = new Canvas(w, h);
    }
    return instance_;
}


void Canvas::Initialize()
{
  InitWindow();
  
  fprintf(
    stdout,
    "INFO: OpenGL Version: %s\n",
    glGetString(GL_VERSION)
  );

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void Canvas::InitWindow()
{
  int nonya = 1;
  glutInit(&nonya, 0);

  glutSetOption(
    GLUT_ACTION_ON_WINDOW_CLOSE,
    GLUT_ACTION_GLUTMAINLOOP_RETURNS
  );
  
  glutInitWindowSize(current_width_, current_height_);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  window_handle_ = glutCreateWindow("WINDOW_TITLE_PREFIX");

  if(window_handle_ < 1) {
    fprintf(
      stderr,
      "ERROR: Could not create a new rendering window.\n"
    );
    exit(EXIT_FAILURE);
  }

  glutReshapeFunc(&Canvas::ResizeFunction);
  glutDisplayFunc(RenderFunction);

  glutIdleFunc(IdleFunction);
  glutTimerFunc(0, TimerFunction, 0);

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(5.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, current_width_, 0.0, current_height_);
}

// Unfortunately 
void Canvas::ResizeFunction(int Width, int Height)
{
  std::cout << "resize called with H: " << Height << " and W: " << Width << std::endl;
  instance_->current_width_ = Width;
  instance_->current_height_ = Height;
  glViewport(0, 0, Width, Height);
}

void Canvas::IdleFunction(void)
{
  glutPostRedisplay();
}

void Canvas::TimerFunction(int Value)
{
  if (0 != Value) {
    char* TempString = (char*)
      malloc(512 + strlen("WINDOW_TITLE_PREFIX"));

    sprintf(
      TempString,
      "%s: %d Frames Per Second @ %d x %d",
      "WINDOW_TITLE_PREFIX",
      instance_->frame_count_ * 4,
      instance_->CurrentWidth(),
      instance_->CurrentHeight()
    );

    glutSetWindowTitle(TempString);
    free(TempString);
  }
  
  instance_->frame_count_ = 0;
  glutTimerFunc(250, TimerFunction, 1);
}


void Canvas::RenderFunction(void)
{
  instance_->frame_count_++;

  glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
  glMatrixMode(GL_MODELVIEW);    // To operate on the model-view matrix, all calls are translated

  for (auto obj : instance_->entity_queue_){
    glLoadIdentity();              // Reset model-view matrix
    obj->Render();
  }

  glutSwapBuffers();  // Swap front and back buffers (of double buffered mode)
  glutPostRedisplay();
}

int Canvas::WorkThread() {
  Initialize();

  glutMainLoop();
  
  exit(EXIT_SUCCESS);
}