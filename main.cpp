#include<windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>
#include<bits/stdc++.h>
#include<stdio.h>
#define SPEED 4.0    //speed of traffic

float i=0.0;    //movement of car
float m=0.0;    //movement of flag

int c=1;
int w=1;

void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
int i;
int triangleAmount = 1000;
GLfloat twicePi = 2.0f * 3.1416;

    glEnable(GL_LINE_SMOOTH);
    glLineWidth(5.0);

    glBegin(GL_LINES);
    glColor4f(1.0, 0.0, 0.0, 1.0);
    for(int i = 0; i <= triangleAmount; i++)
    {
    glVertex2f( x, y);
    glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
	glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h, GLint k, GLint x, GLint y)
{
	draw_pixel(x + h, y + k);
	draw_pixel(-x + h, y + k);
	draw_pixel(x + h, -y + k);
	draw_pixel(-x + h, -y + k);
	draw_pixel(y + h, x + k);
	draw_pixel(-y + h, x + k);
	draw_pixel(y + h, -x + k);
	draw_pixel(-y + h, -x + k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d = 1 - r, x = 0, y = r;
	while (y>x)
	{
		plotpixels(h, k, x, y);
		if (d<0) d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			--y;
		}
		++x;
	}
	plotpixels(h, k, x, y);
}

void sahidMinar()
{
    drawCircle(0,10,17);

	glColor3f(1, 1, 1);
	glRectf(-1.5,-20,1.5,40);

	glPushMatrix();
	glTranslatef(10,0,0);
	glRectf(-1.5,-20,1.5,40);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10,0,0);
	glRectf(-1.5,-20,1.5,40);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10,40,0);
	glRectf(-1.5,-2,21.5,2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10,40,0);
	glRotatef(10, 0.0, 0.0, 1.0);
	glRectf(-1.5,0,1.5,15);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,40,0);
	glRotatef(10, 0.0, 0.0, 1.0);
	glRectf(-1.5,0,1.5,15);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10,40,0);
	glRotatef(10, 0.0, 0.0, 1.0);
	glRectf(-1.5,0,1.5,15);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-12.5,55,0);
	glRectf(-1.5,-2,21.5,2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(25,0,0);
	glRectf(-1.5,-20,1.5,20);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(33,0,0);
	glRectf(-1.5,-20,1.5,20);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(25,20,0);
	glRectf(-1.5,-2,9.5,2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-25,0,0);
	glRectf(-1.5,-20,1.5,20);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-33,0,0);
	glRectf(-1.5,-20,1.5,20);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-33,20,0);
	glRectf(-1.5,-2,9.5,2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(45,0,0);
	glRectf(-1.5,-20,1.5,15);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(53,0,0);
	glRectf(-1.5,-20,1.5,15);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(45,15,0);
	glRectf(-1.5,-2,9.5,2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-45,0,0);
	glRectf(-1.5,-20,1.5,15);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-53,0,0);
	glRectf(-1.5,-20,1.5,15);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-53,15,0);
	glRectf(-1.5,-2,9.5,2);
	glPopMatrix();
}

void draw_object()
{

glClear (GL_COLOR_BUFFER_BIT);



//Sky:
glBegin(GL_QUADS);
    glColor3ub(51, 236, 255);
    glVertex2i(0,641);
    glVertex2i(959,641);
    glVertex2i(959,186);
    glVertex2i(0,186);
    glEnd();
//Ground:grass
glBegin(GL_QUADS);
    glColor3ub(  16, 246, 65);
    glVertex2i(0,186);
    glVertex2i(959,186);
    glVertex2i(959,2);
    glVertex2i(0,0);
    glEnd();

//stair1
	glBegin(GL_QUADS);
    glColor3ub( 160,82,45 );
    glVertex2i(0,187);
    glVertex2i(959,187);
    glVertex2i(959,168);
    glVertex2i(0,168);
    glEnd();
	//thin part
	glBegin(GL_QUADS);
    glColor3ub( 205,133,63 );
    glVertex2i(0,168);
    glVertex2i(959,168);
    glVertex2i(959,160);
    glVertex2i(0,160);
    glEnd();
//stair2
	glBegin(GL_QUADS);
    glColor3ub( 160,82,45 );
    glVertex2i(0,160);
    glVertex2i(959,160);
    glVertex2i(959,146);
    glVertex2i(0,146);
    glEnd();
	//thin part
	glBegin(GL_QUADS);
    glColor3ub( 205,133,63 );
    glVertex2i(0,146);
    glVertex2i(959,146);
    glVertex2i(959,136);
    glVertex2i(0,136);
    glEnd();
	//stair3
	glBegin(GL_QUADS);
    glColor3ub(160,82,45 );
    glVertex2i(0,137);
    glVertex2i(959,137);
    glVertex2i(959,124);
    glVertex2i(0,124);
    glEnd();

//road
	glBegin(GL_QUADS);
    glColor3ub( 0.1,0.1,0.1 );
    glVertex2i(0,100);
    glVertex2i(959,100);
    glVertex2i(959,0);
    glVertex2i(0,0);
    glEnd();
//lines
	glBegin(GL_QUADS);
    glColor3ub(245,245,220  );
    glVertex2i(100,52);
    glVertex2i(200,52);
    glVertex2i(200,48);
    glVertex2i(100,48);
    glEnd();
	glBegin(GL_QUADS);
    glColor3ub(245,245,220  );
    glVertex2i(299,53);
    glVertex2i(401,53);
    glVertex2i(401,47);
    glVertex2i(299,47);
    glEnd();

	glBegin(GL_QUADS);
    glColor3ub(245,245,220  );
    glVertex2i(499,54);
    glVertex2i(601,54);
    glVertex2i(601,48);
    glVertex2i(499,48);
    glEnd();

	glBegin(GL_QUADS);
    glColor3ub(245,245,220  );
    glVertex2i(700,53);
    glVertex2i(800,53);
    glVertex2i(800,47);
    glVertex2i(700,47);
    glEnd();

	glBegin(GL_QUADS);
    glColor3ub(245,245,220  );
    glVertex2i(869,52);
    glVertex2i(951,52);
    glVertex2i(951,47);
    glVertex2i(869,47);
    glEnd();


/*
    Main buil
*/
    glPushMatrix();
    glTranslatef(500,287,0);
    glScalef(5,5,5);
    sahidMinar();
    glPopMatrix();


	//wheel..1
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_QUADS);
	glVertex2i(715-i , 25);
	glVertex2i(725-i , 25);
	glVertex2i(725-i , 35);
	glVertex2i(715-i , 35);
	glEnd();

	//wheel..2
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_QUADS);
	glVertex2i(755-i, 25);
	glVertex2i(765-i, 25);
	glVertex2i(765-i, 35);
	glVertex2i(755-i, 35);
	glEnd();

    //body2
	glColor3f(1.0, 1.0, 0.1);
	glBegin(GL_QUADS);
	glVertex2i(695-i , 30);
	glVertex2i(780-i , 30);
	glVertex2i(780-i , 50);
	glVertex2i(695-i , 50);
	glEnd();

	//car up 1st roof
	glColor3f(0.0, 0.0, 0.5);
	glBegin(GL_QUADS);
	glVertex2i(710-i , 50);
	glVertex2i(770-i , 50);
	glVertex2i(760-i , 65);
	glVertex2i(720-i , 65);
	glEnd();

	//glass
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(714-i , 53);
	glVertex2i(766-i , 53);
	glVertex2i(756-i , 62);
	glVertex2i(724-i , 62);
	glEnd();

	//glass 2 gap
	glColor3f(0.0, 0.0, 0.5);
	glBegin(GL_QUADS);
	glVertex2i(738-i , 50);
	glVertex2i(742-i , 50);
	glVertex2i(742-i , 65);
	glVertex2i(738-i , 65);
	glEnd();


	//1st car body

	//wheel..1
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_QUADS);
	glVertex2i(115+i , 15) ;
	glVertex2i(125+i , 15);
	glVertex2i(125+i , 25);
	glVertex2i(115+i , 25);
	glEnd();

	//wheel..2
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_QUADS);
	glVertex2i(155+i , 15);
	glVertex2i(165+i , 15);
	glVertex2i(165+i , 25);
	glVertex2i(155+i , 25);
	glEnd();

	//body
	glColor3f(0.0, 0.0, 0.9);
	glBegin(GL_QUADS);
	glVertex2i(95+i , 20);
	glVertex2i(180+i , 20);
	glVertex2i(180+i , 40);
	glVertex2i(95+i , 40);
	glEnd();

	//car up 1st roof
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(110+i , 40);
	glVertex2i(170 +i, 40);
	glVertex2i(160+i , 55);
	glVertex2i(120+i , 55);
	glEnd();

	//glass 1
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(114+i , 43);
	glVertex2i(166+i , 43);
	glVertex2i(156+i , 52);
	glVertex2i(124+i , 52);
	glEnd();

    //glass2 gap
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(138+i , 40);
	glVertex2i(142+i , 40);
	glVertex2i(142+i , 55);
	glVertex2i(138+i , 55);
	glEnd();


	//CNG
    //wheel..1
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_QUADS);
	glVertex2i(70+i*.7 , 60) ;
	glVertex2i(80+i*.7 , 60);
	glVertex2i(80+i*.7 , 70);
	glVertex2i(70+i*.7 , 70);
	glEnd();

	//wheel..2
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_QUADS);
	glVertex2i(90+i*.7 , 60);
	glVertex2i(100+i*.7 , 60);
	glVertex2i(100+i*.7 , 70);
	glVertex2i(90+i*.7 , 70);
	glEnd();

    //body CNG
//front
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(65+i*.7 , 70);
	glVertex2i(100+i*.7 , 70);
	glVertex2i(100+i*.7 , 95);
	glVertex2i(65+i*.7 , 95);
	glEnd();

//back
    glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(101+i*.7 , 70);
	glVertex2i(110+i*.7 , 70);
	glVertex2i(110+i*.7 , 85);
	glVertex2i(101+i*.7 , 95);
	glEnd();



    //Travelers

    //Couple1

//1
    //pant
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(70 , 100);
	glVertex2f(85 , 100);
	glVertex2f(85 , 120);
	glVertex2f(70 , 120);
	glEnd();
	//shirt
    glColor3f(1, 1 , 1);
	glBegin(GL_QUADS);
	glVertex2f(70 , 121);
	glVertex2f(85 , 121);
	glVertex2f(85 , 130);
	glVertex2f(70 , 130);
	glEnd();

//2
    //pant
	glColor3f(0, 0, 1);
	glBegin(GL_QUADS);
	glVertex2f(86 , 100);
	glVertex2f(100 , 100);
	glVertex2f(100 , 120);
	glVertex2f(86 , 120);
	glEnd();
	//shirt
    glColor3f(1, 1 , 1);
	glBegin(GL_QUADS);
	glVertex2f(86 , 121);
	glVertex2f(100 , 121);
	glVertex2f(100 , 130);
	glVertex2f(86 , 130);
	glEnd();

	//couple2
	//3
    //pant
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex2f(370 , 100);
	glVertex2f(385 , 100);
	glVertex2f(385 , 120);
	glVertex2f(370 , 120);
	glEnd();
	//shirt
    glColor3f(1, 1 , 1);
	glBegin(GL_QUADS);
	glVertex2f(370 , 121);
	glVertex2f(385 , 121);
	glVertex2f(385 , 130);
	glVertex2f(370 , 130);
	glEnd();

    //4
    //pant
	glColor3f(0, 1, 1);
	glBegin(GL_QUADS);
	glVertex2f(386 , 100);
	glVertex2f(400 , 100);
	glVertex2f(400 , 120);
	glVertex2f(386 , 120);
	glEnd();
	//shirt
    glColor3f(1, 1 , 1);
	glBegin(GL_QUADS);
	glVertex2f(386 , 121);
	glVertex2f(400 , 121);
	glVertex2f(400 , 130);
	glVertex2f(386 , 130);
	glEnd();


//couple3
	//5
    //pant
	glColor3f(1, 0, 1);
	glBegin(GL_QUADS);
	glVertex2f(770 , 100);
	glVertex2f(785 , 100);
	glVertex2f(785 , 120);
	glVertex2f(770 , 120);
	glEnd();
	//shirt
    glColor3f(1, 1 , 1);
	glBegin(GL_QUADS);
	glVertex2f(770 , 121);
	glVertex2f(785 , 121);
	glVertex2f(785 , 130);
	glVertex2f(770 , 130);
	glEnd();

    //6
    //pant
	glColor3f(0, 0, 1);
	glBegin(GL_QUADS);
	glVertex2f(786 , 100);
	glVertex2f(800 , 100);
	glVertex2f(800 , 120);
	glVertex2f(786 , 120);
	glEnd();
	//shirt
    glColor3f(1, 1 , 1);
	glBegin(GL_QUADS);
	glVertex2f(786 , 121);
	glVertex2f(800 , 121);
	glVertex2f(800 , 130);
	glVertex2f(786 , 130);
	glEnd();


	// Traveler3
	//pant
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(960 - i*.8, 100);
	glVertex2f(970 - i*.8, 100);
	glVertex2f(970 - i*.8, 125);
	glVertex2f(960 - i*.8, 125);
	glEnd();

	//shirt
	glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
	glVertex2f(960 - i*.8, 125);
	glVertex2f(970 - i*.8, 125);
	glVertex2f(970 - i*.8, 140);
	glVertex2f(960 - i*.8, 140);
	glEnd();

	//birds
//red
	glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
	glVertex2f(20 + i*.8, 610);
	glVertex2f(30 + i*.8, 595);
	glVertex2f(20 + i*.8,580);

	glEnd();
//green
    glColor3f(0, 1, 0);
    glBegin(GL_TRIANGLES);
	glVertex2f(-10 + i*.8, 570);
	glVertex2f(0 + i*.8, 585);
	glVertex2f(-10 + i*.8,600);

	glEnd();
//yellow
    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLES);
	glVertex2f(0 + i*.8, 600);
	glVertex2f(10 + i*.8, 615);
	glVertex2f(0 + i*.8,630);

	glEnd();



    glFlush ();

}






void idle()
{
glClearColor(1.0,1.0,1.0,1.0);
if(c==0 )
 {

	 i+=2;

     m+=0.2;




 }


if(c==3){
i-=10;

}


if(c==2){
i-=i;

}


else
 {

     i+=SPEED/10;

     m+=0.2;



 }
if(i>1630)
	 i=0.0;
if(m>80){
	 m=0.0;
	 w=0;
}
glutPostRedisplay();

}











void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {

		case 'S':
	case 's':
 i=0.0;
 m=0.0;


 c=1;
	break;

	case 'w':
	case 'W':
	c=2;
	break;
case 'a':
case 'A':
	c=1;
break;

	case 'D':
	case 'd':
		c=0;
		break;

		case 'q':
	case 'Q':
		c=3;
		break;



    };

}












void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 960.0, 0.0, 642.0);
}



void display()
{


glClear(GL_COLOR_BUFFER_BIT);
draw_object();

glFlush();
}






int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize (1200, 700);
    glutInitWindowPosition (0, 0);
	glutCreateWindow("National Assembly Building");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);

	myinit();

	glutMainLoop();
	return 0;
}
