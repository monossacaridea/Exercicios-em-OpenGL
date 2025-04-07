//Fazer uma animação de um quadrado roxo se movendo de um lado para o outro sem parar no eixo X.

#include <GL/glut.h>

float x_position = -0.8f;
float speed = 0.01f;

void update(int value) {
    x_position += speed;

    // inverte a direção quando chega no limite
    if (x_position > 1.0f || x_position < -1.0f) {
        speed = -speed;
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.5f, 0.0f, 0.5f);  
    glBegin(GL_QUADS);
    glVertex2f(x_position - 0.1f, 0.1f);
    glVertex2f(x_position + 0.1f, 0.1f);
    glVertex2f(x_position + 0.1f, -0.1f);
    glVertex2f(x_position - 0.1f, -0.1f);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Animação do Quadrado");
    glClearColor(0, 0, 0, 1);
    glOrtho(-1, 1, -1, 1, -1, 1);
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}

