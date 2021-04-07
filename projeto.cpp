/* Importação das bibliotecas utilizadas pelo programa */
#include <stdlib.h>
#include <GL/glut.h>

/* Definição e inicialização das variáveis utilizadas nas transformações geométricas */
static int rotate = 0;
static float scale = 1;
static float translateX = 0;
static float translateY = 0;

/* Definição do objeto, no caso um triangulo, para demonstrar as transformações geométricas em 2D */
void drawObject()
{
  glColor3f(1.0f, 1.0f, 1.0f); // Define a cor do triangulo como branco
  glBegin(GL_TRIANGLES);       // Define os vértices do triangulo
  glVertex3f(0.0f, 0.1f, 0.0f);
  glVertex3f(-0.1f, -0.1f, 0.0f);
  glVertex3f(0.1f, -0.1f, 0.0f);
  glEnd();
}

/* Define o que será mostrado na tela a cor do fundo */
void display(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0); // Fundo da tela com a cor preta
  glClear(GL_COLOR_BUFFER_BIT);     // Limpa a janela

  glPushMatrix();   //  Retira um item da pilha de matrizes, duplicando a matriz atual, após essas chamada a matriz do topo da pilha é idêntica à matriz abaixo dela
  glLoadIdentity(); // Troca a matriz atual pela matriz identidade

  glScalef(scale, scale, 0.0f);               // Função responsável por escalonar o triangulo teste
  glRotatef((GLfloat)rotate, 0.0, 0.0, 1.0);  // Função responsável por rotacionar o triangulo teste
  glTranslatef(translateX, translateY, 0.0f); // Função responsável por transladar o triangulo teste

  drawObject(); // Chamada da função que define o triangulo e aplica suas transformações geométricas

  glFlush(); // Executa os comandos GL por tempo finito
}

/* Define quais teclas serão utilizadas para aplicar as transformações geométricas no triangulo */
void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case '1':
    rotate = (rotate + 1) % 360; // Define que a tecla 1 será utilizada para rotacionar o triangulo para a esquerda
    break;
  case '2':
    rotate = (rotate - 1) % 360; // Define que a tecla 2 será utilizada para rotacionar o triangulo para a direita
    break;
  case '3':
    translateX = (translateX + 0.05); // Define que a tecla 3 será utilizada para transladar o triangulo para a direita
    break;
  case '4':
    translateX = (translateX - 0.05); // Define que a tecla 4 será utilizada para transladar o triangulo para a esquerda
    break;
  case '5':
    translateY = (translateY + 0.05); // Define que a tecla 5 será utilizada para transladar o triangulo para cima
    break;
  case '6':
    translateY = (translateY - 0.05); // Define que a tecla 6 será utilizada para transladar o triangulo para baixo
    break;
  case '7':
    scale = (scale + 0.2); // Define que a tecla 7 será utilizada para escalonar o triangulo para 120% do seu tamanho original
    break;
  case '8':
    scale = (scale - 0.2); // Define que a tecla 8 será utilizada para escalonar o triangulo para 80% do seu tamanho original
    break;
  case 27:
    exit(0);
    break;
  }
  glutPostRedisplay();
}

/* Função principal onde as demais são chamadas e ocorre a criação da janela apresentando o triangulo e podendo ser feita as transformações geométricas definidas anteriormente */

int main(int argc, char **argv)
{
  glutInit(&argc, argv);                                        // Inicializa o glut
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                  // Especifica o uso de cores e buffers
  glutInitWindowSize(1000, 1000);                               // Define o tamanho da janela
  glutInitWindowPosition(100, 100);                             // Define a posição onde a janela será mostrada no monitor
  glutCreateWindow("Formas Geometricas e Transformacoes - 2D"); // Define o nome da janela que será mostrada
  glutDisplayFunc(display);                                     // Função que será redesenhada pelo GLUT
  glutKeyboardFunc(keyboard);                                   // Funções de teclado
  glutMainLoop();                                               // Mostra todas as janelas criadas
}