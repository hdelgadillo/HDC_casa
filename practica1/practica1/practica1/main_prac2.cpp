//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s):Delgadillo Cortez Hugo*********************************//
//*************Version de Visual Studio: 2017******//
//*************											******//
//************************************************************//
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar
	glPointSize(10.0);
	glBegin(GL_POLYGON);
	glColor3f(0.93, 0.91, 0.82);
	glVertex3f(4.0, 0.0, -1.2);
	glVertex3f(-4.0, 0.0, -1.2);
	glVertex3f(0.0, 4.0, -1.2);
	glVertex3f(8.0, 4.0, -1.2);
	glVertex3f(-8.0, 4.0, -1.2);
	glVertex3f(-4.0, 0.0, -1.2);
	glVertex3f(2.0, 0.0, -1.2);
	glVertex3f(-4.0, 0.0, -1.2);
	glVertex3f(-4.0, 4.0, -1.2);
	glColor3f(0.27, 0.27, 0.26);
	glVertex3f(0.0, 4.0, -1.2);
	glVertex3f(0.0, 8.0, -1.2);
	glVertex3f(3.0, 8.0, -1.2);
	glVertex3f(3.0, 4.0, -1.2);
	glColor3f(0.93, 0.91, 0.82);
	glVertex3f(8.0, 4.0, -1.2);
	glVertex3f(-8.0, 4.0, -1.2);
	glVertex3f(-8.0, 4.0, -1.2);
	glVertex3f(0.0, 4.0, -1.2);
	glVertex3f(0.0, 0.0, -1.2);

	glColor3f(0.43, 0.85, 0.97);
	glVertex3f(0.0, -4.0, -1.2);
	glVertex3f(8.0, -4.0, -1.2);
	glVertex3f(8.0, 0.0, -1.2);
	glVertex3f(-8.0, 0.0, -1.2);
	glVertex3f(0.0, 0.0, -1.2);
    glVertex3f(-4.0, -4.0, -1.2);
	glVertex3f(-4.0, 0.0, -1.2);
	glVertex3f(0.0, -4.0, -1.2);
	glVertex3f(-4.0, -4.0, -1.2);
	glVertex3f(-8.0, -4.0, -1.2);
	glVertex3f(-8.0, 0.0, -1.2);


	glEnd();
	glFlush();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-10,10,-10,10,0.1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tama�o de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut funci�n de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

