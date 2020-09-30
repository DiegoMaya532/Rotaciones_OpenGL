//Librer�as
#include "GL/glut.h"
//Variables 
int t2 = 0;
int t1 = 0;
int elapsed = 0;
int milisegundos = 1000; //tiempo en milisegundos para ejecutar la rotaci�n
int eje = 0; //Valores 0 para Z, 1 para Y y 2 para X.
/// <summary>
/// Rutina para animar el objeto creado, rotaci�n sobre el eje z.
/// </summary>
void animacion() {
	t2 = glutGet(GLUT_ELAPSED_TIME);
	elapsed = t2 - t1;
	if (elapsed >= milisegundos) {
		t1 = t2;
		switch (eje)
		{
		case 0://z
			glRotated(90.0f, 0.0f, 0.0f, 1.0f);//rotaci�n en eje z
			break;
		case 1://y
			glRotated(90.0f, 0.0f, 1.0f, 0.0f);//rotaci�n en eje y
			break;
		case 2://x
			glRotated(90.0f, 1.0f, 0.0f, 0.0f);//rotaci�n en eje x
			break;
		}
		glutPostRedisplay();//Redibujar
	}
}
/// <summary>
/// Configura el control OpenGL sobre el que se dibuja.
/// </summary>
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutIdleFunc(animacion);
	glutWireTeapot(0.5);//El objeto a manipular es una tetera.
	glFlush();
	glutSwapBuffers();//Control de doble buffer o buffer de fondo.
}
/// <summary>
/// M�todo de inicio de la aplicaci�n.
/// </summary>
void main() {
	t1 = glutGet(GLUT_ELAPSED_TIME);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rotaci�n 90�");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutMainLoop();
}