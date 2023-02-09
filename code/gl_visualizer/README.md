## OpenGL Visualizer

### Summary
For computer side visualization of mechanics and reactivity we decided to use OpenGL as our canvas application.

There was a *large* host of c++ canvas UI / canvas generating frameworks. This one seems to give us the most control, modularity, and ability to mature (plus its nifty).

API reference used here:
* [GL](https://docs.gl/)
* [GLUT](https://www.opengl.org/resources/libraries/glut/spec3/spec3.html)
* [This OpenGLBook Tutorial](https://openglbook.com/)
### Schema
`Canvas` class provides an interface to OpenGl calls to create canvas and populate canvas with entities.

### Dev Machine Setup:
Debian packages I installed to get developlment library for OpenGL
`mesa-utils libglu1-mesa-dev freeglut3-dev mesa-common-dev`
`libglew-dev libglfw3-dev libglm-dev`
`libao-dev libmpg123-dev`