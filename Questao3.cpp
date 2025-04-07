//Desenhe um quadrado vermelho na tela e programe para que ele sofra uma translação para cima (eixo Y positivo)  toda vez que apertar a barra de espaço.

#include <GL/glut.h>
// #include <iostream> // biblioteca para ver a tecla inserida

// using namespace std;

float y_position = 0.0f; 

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.2f, -0.2f + y_position);
        glVertex2f(0.2f, -0.2f + y_position);
        glVertex2f(0.2f, 0.2f + y_position);
        glVertex2f(-0.2f, 0.2f + y_position);
    glEnd();
    glFlush();
}

void teclado(unsigned char tecla, int x, int y) {
    // cout << int(tecla) << "\n"; // para descobrir a tecla
    if (tecla == 32) { // código ASCII da barra de espaço
        y_position += 0.1f;  // move o quadrado para cima
    }
    if (tecla == 27) { // código ASCII da tecla esc para fechar a janela
        exit(0);
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Quadrado");
    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);
    glutMainLoop();
    glClearColor(1, 1, 1, 0);
    return 0;
}
