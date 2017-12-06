#include "stdafx.h"
#include <gl/glut.h>

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);

	int counter = 0;
	int move = 0;
	double redGreen = 0;
	double blue = 0;
	
	while (counter < 50) {
		glColor3f(redGreen, redGreen, blue);
		glVertex2i(100 + move, 100 + move);
		glVertex2i(400 - move, 100 + move);
		glVertex2i(400 - move, 400 - move);
		glVertex2i(100 + move, 400 - move);
		move = move + 3;
		counter++;
		redGreen = redGreen - 0.02;
		blue = blue + 0.02;
	}
	
	glEnd();
	glFlush();
}


void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Pyramid Illusion");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glutDisplayFunc(display);
	glutMainLoop();
}