#include <GL/freeglut.h>

#include "Circle.h"

void Circle::Render(){
  /*
  https://docs.gl/gl3/glTranslate
  f the matrix mode is either GL_MODELVIEW or GL_PROJECTION, all objects drawn after a call to glTranslate are translated. 
  */

  auto cent = GetCentroid();
  glTranslatef(cent.x, cent.y, 0.0f);  // Translate to (xPos, yPos)
  
  // Use triangular segments to form a circle
  glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue
    glVertex2f(0.0f, 0.0f);       // Center of circle in ball frame
    int numSegments = 1000;
    GLfloat angle;
    for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
      glColor3f(0.0f, 0.0f, 1.0f);  // Blue
      angle = i * 2.0f * PI / numSegments;  // 360 deg for all segments
      glVertex2f(cos(angle) * radius_, sin(angle) * radius_);
    }
  glEnd();
}