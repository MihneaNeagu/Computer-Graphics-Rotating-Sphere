#include <GL/glut.h>
#include <cmath>

GLfloat angle = 0.0;

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -5.0);
  glRotatef(angle, 1.0, 1.0, 5.0);
  glColor3f(0.2, 0.2, 0.9);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glutWireSphere(1.0, 40, 30);
  glutSwapBuffers();
}

void idle() {
  angle += 0.005;
  glutPostRedisplay();
}

void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Sfera");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
  return 0;
}
