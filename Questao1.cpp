//Recrie esse desenho (barco a vela) o mais fielmente possível (não é necessário fazer as quinas arredondadas):

#include <GL/glut.h>

void desenhar() {
    glClear(GL_COLOR_BUFFER_BIT);

    // cor de fundo
    glClearColor(0.98f, 0.94f, 0.86f, 1.0f);

    // base vermelha
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(0.6f, -0.4f);
    glVertex2f(0.4f, -0.6f);
    glVertex2f(-0.4f, -0.6f);
    glEnd();

    // mastro marrom
    glColor3f(0.5f, 0.25f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.02f, -0.4f);
    glVertex2f(0.02f, -0.4f);
    glVertex2f(0.02f, 0.4f);
    glVertex2f(-0.02f, 0.4f);
    glEnd();

    // vela esquerda
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.02f, 0.35f);
    glVertex2f(-0.02f, -0.2f);
    glVertex2f(-0.4f, -0.2f);
    glEnd();

    // vela direita
    glBegin(GL_TRIANGLES);
    glVertex2f(0.02f, 0.35f);
    glVertex2f(0.02f, -0.2f);
    glVertex2f(0.4f, -0.2f);
    glEnd();

    // bandeirinha azul
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.02f, 0.4f);
    glVertex2f(0.15f, 0.4f);
    glVertex2f(0.15f, 0.45f);
    glVertex2f(0.02f, 0.45f);
    glEnd();

    glFlush();
}

void iniciarJanela() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Barco OpenGL");
    iniciarJanela();
    glutDisplayFunc(desenhar);
    glutMainLoop();
    return 0;
}
