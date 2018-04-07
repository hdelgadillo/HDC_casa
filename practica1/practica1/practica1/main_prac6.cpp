//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int neptuno = 0;
float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);//camara
	//sol
	glPushMatrix();
	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glutSolidSphere(1.9, 30, 30);  //Draw Sun (radio,H,V);
	glPopMatrix();
	//electron1
	glPushMatrix();
	glRotatef(300, 0, 0, 1);
	glRotatef(mercurio, 0, 1, 0);//Traslacion electron1 
	glTranslatef(5, 0, 0);
	glColor3f(0.937, 0.286, 0.062);
	glRotatef(mercurio, 1, 0, 0);//rotacion electron1
	glutWireSphere(0.5, 20, 20);
	glPopMatrix();

	glPushMatrix();//electron
	glRotatef(300, 0, 0, 1);
	glRotatef(venus,0, 1, 0);//Traslacion electron2 
	glTranslatef(5, 0, 0);
	glColor3f(0.952, 0.635, 0.203);
	glRotatef(venus, 1, 0, 0);//rotacion electron2
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();

	//electron3
	glPushMatrix();//electron3
	glRotatef(45, 0, 0, 1);
	glRotatef(tierra, 0, 1, 0);//Traslacion electron3 
	glTranslatef(5, 0, 0);
	glColor3f(0.0705, 0.403, 0.945);
	glRotatef(tierra, 1, 0, 0);//rotacion electron3
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();

	glPushMatrix();//electron4
	glRotatef(65, 0, 0, 1);
	glRotatef(marte, 0, 1, 0);//Traslacion electron4 
	glTranslatef(5, 0, 0);
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(marte, 1, 0, 0);//rotacion electron4
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();

	glPushMatrix();//electron5
	glRotatef(90, 0, 0, 1);
	glRotatef(jupiter, 0, 1, 0);//Traslacion electron5 
	glTranslatef(5, 0, 0);
	glColor3f(0.517, 0.419, 0.13337);
	glRotatef(jupiter, 1, 0, 0);//rotacion electron5 
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();

	glPushMatrix();//electron6
	glRotatef(135, 0, 0, 1);
	glRotatef(saturno, 0, 1, 0);//Traslacion electron6 
	glTranslatef(5, 0, 0);
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(saturno, 1, 0, 0);//rotacion electron6
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();

	glPushMatrix();//electron7
	glRotatef(175, 0, 0, 1);
	glRotatef(urano, 0, 1, 0);//Traslacion electron7 
	glTranslatef(5, 0, 0);
	glColor3f(0.133337,0.9001, 0.713);
	glRotatef(urano, 1, 0, 0);//rotacion electron7
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();

	glPushMatrix();//electron8
	glRotatef(225, 0, 0, 1);
	glRotatef(neptuno, 0, 1, 0);//Traslacion electron8
	glTranslatef(5, 0, 0);
	glColor3f(0.145, 0.125, 0.835);
	glRotatef(neptuno, 1, 0, 0);//rotacion electron8
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();

	glPopMatrix();


	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;
		mercurio = (mercurio - 10) % 360;
		venus = (venus - 8) % 360;
		tierra = (tierra - 7) % 360;
		marte = (marte - 6) % 360;
		jupiter = (jupiter - 5) % 360;
		saturno = (saturno - 4) % 360;
		urano = (urano - 3) % 360;
		neptuno = (neptuno - 1) % 360;

		
		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}