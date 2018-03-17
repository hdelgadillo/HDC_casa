//Semestre 2018-2
//************************************************************//
//************************************************************//
//************** Alumno (s):Delgadillo Cortez Hugo *********************************//
//*************Version de Visual Studio: 2017	******//
//*************Teclas de movimiento  : ******//
//************************************J,j: movimiento del hombro//
//************************************M,m: movimiento del codo, antebrazo//
//************************************N,n: movimiento de la mano//
//************************************B,b: movimiento del pulgar//
//************************************V,v: movimiento de dedos primera articulacion//
//************************************C,c: movimiento de dedos segunda articulacion//
//************************************X,x: movimiento de dedos tercera articulacion//
//************************************************************//

#include "Main.h"

float transZ = -5.0f;
int screenW = 0.0;
int screenH = 0.0;
float roty = 0.0;
float angCodo = 0.0;
float angHombro = 0.0;
float angMano = 0.0;
float angPulg = 0.0;
float pulg = 0.0;
float dedos = 0.0;
float dedos1 = 0.0;
float dedos2 = 0.0;

void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas V�rtice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas V�rtice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas V�rtice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas V�rtice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			//glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, transZ);
	glRotatef(roty, 0, 1, 0);
	//Poner C�digo Aqu�.
	//cabeza
	glPushMatrix();
	glScalef(4, 4, 4);
	glColor3f(1, 1, 1);
	prisma();
	glPopMatrix();
	//cuello
	glPushMatrix();
	glTranslatef(0, -3, 0);
	glScalef(3, 2, 3);
	glColor3f(1, 0.85, 0);
	prisma();
	glPopMatrix();
	glTranslatef(0, -9, 0);
	//torso
	glPushMatrix();
	glScalef(10, 10, 3);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();
	glTranslatef(2.5, -7.5, 0);
	//pierna izquierda
	glPushMatrix();
	glScalef(1, 5, 3);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();
	glTranslatef(0, -3, 0);
	//rodilla
	glPushMatrix();
	glScalef(2, 1, 3);
	glColor3f(1, 0.66, 1);
	prisma();
	glPopMatrix();
	glTranslatef(0, -3, 0);
	//espinilla
	glPushMatrix();
	glScalef(2, 5, 3);
	glColor3f(1, 0.5, 0.5);
	prisma();
	glPopMatrix();
	glTranslatef(0, -2.75, 0);
	//tobillo
	glPushMatrix();
	glScalef(2, 0.5, 3);
	glColor3f(0.85, 0.75, 0.01);
	prisma();
	glPopMatrix();
	glTranslatef(0, -1.25, 0);
	//pie izquierdo
	glPushMatrix();
	glScalef(2, 2, 3);
	glColor3f(0.50, 0.85, 0.75);
	prisma();
	glPopMatrix();
	glTranslatef(-5, 10, 0);
	//pierna derecho
	glPushMatrix();
	glScalef(1, 5, 3);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();
	glTranslatef(0, -3, 0);
	//rodilla
	glPushMatrix();
	glScalef(2, 1, 3);
	glColor3f(1, 0.66, 1);
	prisma();
	glPopMatrix();
	glTranslatef(0, -3, 0);
	//espinilla
	glPushMatrix();
	glScalef(2, 5, 3);
	glColor3f(1, 0.5, 0.5);
	prisma();
	glPopMatrix();
	glTranslatef(0, -2.75, 0);
	//tobillo
	glPushMatrix();
	glScalef(2, 0.5, 3);
	glColor3f(0.85, 0.75, 0.01);
	prisma();
	glPopMatrix();
	glTranslatef(0, -1.25, 0);
	//pie derecho
	glPushMatrix();
	glScalef(2, 2, 3);
	glColor3f(0.50, 0.85, 0.75);
	prisma();
	glPopMatrix();
	glTranslatef(-3, 21.5, 0);
	//brazo derecho

	//brazo izquierdo

	glTranslatef(11, 0, 0);
	glRotatef(angHombro, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1, 2, 2);
	glColor3f(0, 1, 0.5);
	prisma();
	glPopMatrix();
	//bicep
	glPushMatrix();
	glTranslatef(2, 0, 0);
	glScalef(3, 2, 2);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();
	//codo
	glRotatef(angCodo, 0.0f, 0.0f, 1.0);
	glPushMatrix();
	glTranslatef(3.75, 0, 0);
	glScalef(0.5, 2, 2);
	glColor3f(0.94, 0.82, 0.53);
	prisma();
	glPopMatrix();

	//antebrazo

	glPushMatrix();
	glTranslatef(6, 0, 0);
	glScalef(4, 2, 2);
	glColor3f(0.5, 0.65, 0.52);
	prisma();
	glPopMatrix();
	//mu�eca
	glPushMatrix();
	glTranslatef(8.25, 0, 0);
	glScalef(0.5, 2, 2);
	glColor3f(0.72, 0.99, 0.89);
	prisma();
	glPopMatrix();
	//mano
	glRotatef(angMano, 1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(9.50, 0, 0);
	glScalef(2, 2, 2);
	glColor3f(0.05, 0.725, 0.15);
	prisma();
	glPopMatrix();
	//pulgar1

	glPushMatrix();

	glTranslatef(10.25, 1.25, 0);
	glScalef(0.4, 0.75, 2);
	glColor3f(0.05, 0.725, 0.15);
	prisma();
	glPopMatrix();
	//pulgar2

	glPushMatrix();
	glRotatef(angPulg, 1.0, 0.0, 1.0);
	glTranslatef(10.25, 1.75, 0);
	glScalef(0.4, 0.75, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//indice1
	glRotatef(dedos, 1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(10.75, 0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//indice2

	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glTranslatef(11.25, 0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.15, 0.35, 0.65);
	prisma();
	glPopMatrix();
	//indice3
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glRotatef(dedos2, 1.0, 1.0, 0.0);
	glTranslatef(11.75, 0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.80, 0.45, 0.85);
	prisma();
	glPopMatrix();
	//dedo medio
	glPushMatrix();
	glTranslatef(10.75, 0.40, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//dedo medio2

	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glTranslatef(11.25, 0.40, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.15, 0.35, 0.65);
	prisma();
	glPopMatrix();
	//dedo medio 3
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glRotatef(dedos2, 1.0, 1.0, 0.0);
	glTranslatef(11.75, 0.40, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.80, 0.45, 0.85);
	prisma();
	glPopMatrix();
	//anular1
	glPushMatrix();
	glTranslatef(10.75, -0.2, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//anular2
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glTranslatef(11.25, -0.20, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.15, 0.35, 0.65);
	prisma();
	glPopMatrix();
	//anular3
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glRotatef(dedos2, 1.0, 1.0, 0.0);
	glTranslatef(11.75, -0.20, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.80, 0.45, 0.85);
	prisma();
	glPopMatrix();
	//me�ique1
	glPushMatrix();
	glTranslatef(10.75, -0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//me�ique2
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glTranslatef(11.25, -0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.15, 0.35, 0.65);
	prisma();
	glPopMatrix();
	//me�ique3
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glRotatef(dedos2, 1.0, 1.0, 0.0);
	glTranslatef(11.75, -0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.80, 0.45, 0.85);
	prisma();
	glPopMatrix();

	//brazo derecho
	glTranslatef(-11.0, 0.0, 0.0);
	glRotatef(angHombro, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScalef(1, 2, 2);
	glColor3f(0, 1, 0.5);
	prisma();
	glPopMatrix();
	//bicep
	glTranslatef(-4, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(2, 0, 0);
	glScalef(3, 2, 2);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();
	//codo
	glTranslatef(-3.5, 0.0, 0.0);
	glRotatef(-angCodo, 0.0f, 0.0f, -1.0);
	glPushMatrix();
	glTranslatef(3.75, 0, 0);
	glScalef(0.5, 2, 2);
	glColor3f(0.94, 0.82, 0.53);
	prisma();
	glPopMatrix();

	//antebrazo
	glTranslatef(-4.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(6, 0, 0);
	glScalef(4, 2, 2);
	glColor3f(0.5, 0.65, 0.52);
	prisma();
	glPopMatrix();
	glTranslatef(-4, 0.0, 0.0);
	//mu�eca
	glPushMatrix();
	glTranslatef(8.25, 0, 0);
	glScalef(0.5, 2, 2);
	glColor3f(0.72, 0.99, 0.89);
	prisma();
	glPopMatrix();
	glTranslatef(-2.5, 0.0, 0.0);
	//mano
	glRotatef(angMano, 1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(9.50, 0, 0);
	glScalef(2, 2, 2);
	glColor3f(0.05, 0.725, 0.15);
	prisma();
	glPopMatrix();
	glTranslatef(-1, 0.0, 0.0);
	//pulgar1

	glPushMatrix();

	glTranslatef(10.25, 1.25, 0);
	glScalef(0.4, 0.75, 2);
	glColor3f(0.05, 0.725, 0.15);
	prisma();
	glPopMatrix();
	//pulgar2
	glTranslatef(0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(angPulg, 1.0, 0.0, 1.0);
	glTranslatef(10.25, 1.75, 0);
	glScalef(0.4, 0.75, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//indice1
	glTranslatef(-1.5, 0.0, 0.0);
	glRotatef(dedos, 1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(10.75, 0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//indice2
	glTranslatef(-1, 0.0, 0.0);
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glTranslatef(11.25, 0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.15, 0.35, 0.65);
	prisma();
	glPopMatrix();
	//indice3
	glTranslatef(-1, 0.0, 0.0);
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glRotatef(dedos2, 1.0, 1.0, 0.0);
	glTranslatef(11.75, 0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.80, 0.45, 0.85);
	prisma();
	glPopMatrix();
	//dedo medio
	glTranslatef(2, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(10.75, 0.40, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//dedo medio2
	glTranslatef(-1, 0.0, 0.0);
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glTranslatef(11.25, 0.40, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.15, 0.35, 0.65);
	prisma();
	glPopMatrix();
	//dedo medio 3
	glTranslatef(-1, 0.0, 0.0);
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glRotatef(dedos2, 1.0, 1.0, 0.0);
	glTranslatef(11.75, 0.40, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.80, 0.45, 0.85);
	prisma();
	glPopMatrix();
	//anular1
	glTranslatef(2, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(10.75, -0.2, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//anular2
	glTranslatef(-1, 0.0, 0.0);
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glTranslatef(11.25, -0.20, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.15, 0.35, 0.65);
	prisma();
	glPopMatrix();
	//anular3
	glTranslatef(-1, 0.0, 0.0);
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glRotatef(dedos2, 1.0, 1.0, 0.0);
	glTranslatef(11.75, -0.20, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.80, 0.45, 0.85);
	prisma();
	glPopMatrix();
	//me�ique1
	glTranslatef(2, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(10.75, -0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//me�ique2
	glTranslatef(-1, 0.0, 0.0);
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glTranslatef(11.25, -0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.15, 0.35, 0.65);
	prisma();
	glPopMatrix();
	//me�ique3
	glTranslatef(-1, 0.0, 0.0);

	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glRotatef(dedos2, 1.0, 1.0, 0.0);
	glTranslatef(11.75, -0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.80, 0.45, 0.85);
	prisma();
	glPopMatrix();

	


	


	glutSwapBuffers ( );
  // Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.3f;
			break;
		case 's':
		case 'S':
			transZ -= 0.3f;
			break;
		case 'a':
		case 'A':
			
			break;
		case 'd':
		case 'D':
	
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
		case 'j':
			angHombro += 0.2f;
			printf("%f \n", angHombro);
			if (angHombro >= 45) {
				angHombro = 45;                  //movimiento del hombro
			}

			printf("%f \n", angHombro);
			break;
		case 'J':
			angHombro -= 0.2f;
			printf("%f \n", angHombro);
			if (angHombro <= -45) {
				angHombro = -45;
			}

			break;
		case 'm':
			angCodo += 0.2f;
			printf("%f \n", angCodo);
			if (angCodo >= 11) {
				angCodo = 11;                  //movimiento del antebrazo
			}

			printf("%f \n", angCodo);
			break;
		case 'M':
			angCodo -= 0.2f;
			printf("%f \n", angCodo);
			if (angCodo <= 0) {
				angCodo = 0;
			}

			break;
		case 'n':
			angMano += 0.2f;
			printf("%f \n", angMano);
			if (angMano >= 28) {
				angMano = 28;                  //movimiento de la mano
			}

			printf("%f \n", angCodo);
			break;
		case 'N':
			angMano -= 0.2f;
			printf("%f \n", angMano);
			if (angMano <= -28) {
				angMano = -28;
			}

			break;
		case 'b':
			angPulg += 0.2f;
			pulg = 0.2f;
			printf("%f \n", angPulg);
			if (angPulg >= 0) {
				angPulg = 0;                  //movimiento del pulgar
			}

			printf("%f \n", angPulg);
			break;
		case 'B':
			angPulg -= 0.2f;
			pulg = 0.2f;
			printf("%f \n", angPulg);
			if (angPulg <= -4) {
				angPulg = -4;
			}

			break;
		case 'v':
			dedos += 0.2f;
			printf("%f \n", dedos);
			if (dedos >= 6) {
				dedos = 6;                  //movimiento del hombro
			}

			printf("%f \n", dedos);
			break;
		case 'V':
			dedos -= 0.2f;
			printf("%f \n", dedos);
			if (dedos <= 0) {
				dedos = 0;
			}

			break;
			break;
		case 'c':
			dedos1 += 0.2f;
			printf("%f \n", dedos1);
			if (dedos1 >= 10) {
				dedos1 = 10;                  //movimiento del dedos
			}

			printf("%f \n", dedos1);
			break;
		case 'C':
			dedos1 -= 0.2f;
			printf("%f \n", dedos1);
			if (dedos1 <= 0) {
				dedos1 = 0;
			}

			break;
		case 'x':
			dedos2 += 0.2f;
			printf("%f \n", dedos2);
			if (dedos2 >= 4) {
				dedos2 = 4;                  //movimiento del dedos
			}

			printf("%f \n", dedos2);
			break;
		case 'X':
			dedos2 -= 0.2f;
			printf("%f \n", dedos2);
			if (dedos2 <= 0) {
				dedos2 = 0;
			}

			break;

  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		break;
	case GLUT_KEY_LEFT:
		roty -= 0.5;
		break;
	case GLUT_KEY_RIGHT:
		roty += 0.5;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tama�o de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci�n de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



