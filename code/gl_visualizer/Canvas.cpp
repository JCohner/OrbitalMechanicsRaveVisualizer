#include <math.h>     // Needed for sin, cos
#include "Canvas.h"

#define PI 3.14159265f

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
  int nonya = 0;
  glutInit(&nonya, 0);

  glutSetOption(
    GLUT_ACTION_ON_WINDOW_CLOSE,
    GLUT_ACTION_GLUTMAINLOOP_RETURNS
  );
  
  glutInitWindowSize(current_width_, current_height_);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  window_handle_ = glutCreateWindow(WINDOW_TITLE_PREFIX);

  if(window_handle_ < 1) {
    fprintf(
      stderr,
      "ERROR: Could not create a new rendering window.\n"
    );
    exit(EXIT_FAILURE);
  }

  glutReshapeFunc(ResizeFunction);
  glutDisplayFunc(RenderFunction);

  glutIdleFunc(IdleFunction);
  glutTimerFunc(0, TimerFunction, 0);

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(5.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

void Canvas::ResizeFunction(int Width, int Height)
{
  std::cout << "resize called with H: " << Height << " and W: " << Width << std::endl;
  CurrentWidth = Width;
  CurrentHeight = Height;
  glViewport(0, 0, CurrentWidth, CurrentHeight);
}

void Canvas::IdleFunction(void)
{
  glutPostRedisplay();
}

void Canvas::TimerFunction(int Value)
{
  if (0 != Value) {
    char* TempString = (char*)
      malloc(512 + strlen(WINDOW_TITLE_PREFIX));

    sprintf(
      TempString,
      "%s: %d Frames Per Second @ %d x %d",
      WINDOW_TITLE_PREFIX,
      frame_count_ * 4,
      CurrentWidth,
      CurrentHeight
    );

    glutSetWindowTitle(TempString);
    free(TempString);
  }
  
  FrameCount = 0;
  glutTimerFunc(250, TimerFunction, 1);
}


void Canvas::RenderFunction(void)
{
  ++frame_count_;

  glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
  glMatrixMode(GL_MODELVIEW);    // To operate on the model-view matrix, all calls are translated
  glLoadIdentity();              // Reset model-view matrix

  '''
  https://docs.gl/gl3/glTranslate
  f the matrix mode is either GL_MODELVIEW or GL_PROJECTION, all objects drawn after a call to glTranslate are translated. 
  '''
  glTranslatef(ballX, ballY, 0.0f);  // Translate to (xPos, yPos)
  
  // Use triangular segments to form a circle
  glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue
    glVertex2f(0.0f, 0.0f);       // Center of circle in ball frame
    int numSegments = 100;
    GLfloat angle;
    for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
      glColor3f(0.0f, 0.0f, 1.0f);  // Blue
      angle = i * 2.0f * PI / numSegments;  // 360 deg for all segments
      glVertex2f(cos(angle) * 10, sin(angle) * 10);
    }
  glEnd();

  glutSwapBuffers();  // Swap front and back buffers (of double buffered mode)
  glutPostRedisplay();
}

int WorkThread() {
  Initialize(argc, argv);

  glutMainLoop();
  
  exit(EXIT_SUCCESS);
}