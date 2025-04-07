//Crie uma animação de um círculo multicolorida girando no sentido horário.

#include <GL/glut.h>
#include <cmath>

float angle = 0.0f;

void update(int value) {
    angle -= 0.5f;  // rotação no sentido horário
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); 
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);

    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159f / 180.0f;
        float x = cos(angle) * 0.5f;
        float y = sin(angle) * 0.5f;

        glColor3f((float)i / 360.0f, 1.0f - (float)i / 360.0f, 0.5f);
        glVertex2f(x, y);
    }
    glEnd();

    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Círculo Multicolorido Girando");
    glClearColor(0, 0, 0, 1);
    glOrtho(-1, 1, -1, 1, -1, 1);
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}
