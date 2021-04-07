

#include <stdlib.h>
#include <GL/glut.h>

static int rotate = 0;
static float scale = 1;
static float translateX = 0;
static float translateY = 0;

void drawObject()
{
  glColor3f(1.0f, 1.0f, 1.0f);
  glBegin(GL_TRIANGLES);
  glVertex3f(0.0f, 0.1f, 0.0f);
  glVertex3f(-0.1f, -0.1f, 0.0f);
  glVertex3f(0.1f, -0.1f, 0.0f);
  glEnd();
}

void display(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glPushMatrix();
  glLoadIdentity();

  glScalef(scale, scale, 0.0f);
  glRotatef((GLfloat)rotate, 0.0, 0.0, 1.0);
  glScalef(scale, scale, 0.0f);
  glTranslatef(translateX, translateY, 0.0f);

  drawObject();

  glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case '1':
    rotate = (rotate + 1) % 360;
    break;
  case '2':
    rotate = (rotate - 1) % 360;
    break;
  case '4':
    translateX = (translateX - 0.05);
    break;
  case '5':
    translateY = (translateY - 0.05);
    break;
  case '6':
    translateX = (translateX + 0.05);
    break;
  case '7':
    scale = (scale - 0.2);
    break;
  case '8':
    translateY = (translateY + 0.05);
    break;
  case '9':
    scale = (scale + 0.2);
    break;
  case 27:
    exit(0);
    break;
  }
  glutPostRedisplay();
}

int main(int argc, char **argv)
{

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(1000, 1000);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Formas Geometricas e Transformacoes - 2D");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
}
