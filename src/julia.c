#include <stdio.h>
#include <math.h>

#include "glinclude.h"
#include "shader.h"

#define MAX_ITERATIONS 20

unsigned int shader;

// real and imaginary parts of C
float t = 0;

void draw() {
  t++;

  float ci = sin(t / 71);
  float cr = cos(t / 103);
  set_uniform2f(shader, "c", cr, ci);

  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex2f(-1, -1);
  glTexCoord2f(1, 0);
  glVertex2f(1, -1);
  glTexCoord2f(1, 1);
  glVertex2f(1, 1);
  glTexCoord2f(0, 1);
  glVertex2f(-1, 1);
  glEnd();

  glutSwapBuffers();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "You must supply the path to a shader file.\n");
    return 1;
  }

  glutInitWindowSize(800, 800);

  /* initialize glut */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutCreateWindow("Julia Fractal Viewer");

  glutDisplayFunc(draw);
  glutIdleFunc(draw);

  if(!(shader = setup_shader(argv[1]))) {
    return 1;
  }

  set_uniform1i(shader, "iter", MAX_ITERATIONS);

  glutMainLoop();
  return 0;
}
