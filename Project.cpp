#include<windows.h>
#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include <GL/glut.h>
#include<stdlib.h>
#include<math.h>

int sm1 = 0;
int sm2 = 0;
int smj1 = 0;
int smj2 = 0;
int ch1;
int r1 = 0;
int r2 = 0;

void draw_pixel(GLint cx, GLint cy)
{
    glBegin(GL_POINTS);
    glVertex2i(cx, cy);
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
    while (y > x)
    {
        plotpixels(h, k, x, y);
        if (d < 0) d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            --y;
        }
        ++x;
    }
    plotpixels(h, k, x, y);
}

void stick1(int i, int j) {
    //Stick line
    glPushMatrix();
    float angle = 0.0;
    if (r1)
    {
        angle = -45;
        r1 = 0;
    }
    glTranslatef(500+i, 350+j, 0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glTranslatef(-500-i, -350-j, 0);
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(500 + i, 350 + j);
    glVertex2i(600 + i, 500 + j);
    glEnd();
    glPopMatrix();
}

//StickMan-1
void stickman1(int i,int j) {
    glPointSize(3);
    glColor3f(0.0, 0.0, 0.0);
    draw_circle(450+i, 400+j, 20);
    glLineWidth(3);

    //box lines
    glBegin(GL_LINES);
    glVertex2i(450 + i, 380 + j);
    glVertex2i(450 + i, 270 + j);
    glVertex2i(450 + i, 270 + j);
    glVertex2i(420 + i, 200 + j);
    glVertex2i(450 + i, 270 + j);
    glVertex2i(470 + i, 200 + j);
    glVertex2i(400 + i, 350 + j);
    glVertex2i(500 + i, 350 + j);
    glEnd();

    //eyes
    glLineWidth(1);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2i(450 + i, 400 + j);
    glVertex2i(460 + i, 400 + j);
    glEnd();

    //mouth
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(445 + i, 390 + j);
    glVertex2i(468 + i, 390 + j);
    glEnd();

    stick1(sm1, smj1);

}

void stick2(int i, int j) {
    //Stick line
    glPushMatrix();
    float angle = 0.0;
    if (r2)
    {
        angle = 45;
        r2 = 0;
    }
    glTranslatef(600 + i, 350 + j, 0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glTranslatef(-600 - i, -350 - j, 0);
    glColor3f(0.0, 0.9, 0.3);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(600 + i, 350 + j);
    glVertex2i(500 + i, 500 + j);
    glEnd();
    glPopMatrix();
}

//StickMan-1
void stickman2(int i, int j) {
    glPointSize(3);
    glColor3f(0.0, 0.0, 0.0);
    draw_circle(650 + i, 400 + j, 20);
    glLineWidth(3);

    //box lines
    glBegin(GL_LINES);
    glVertex2i(650 + i, 380 + j);
    glVertex2i(650 + i, 270 + j);
    glVertex2i(650 + i, 270 + j);
    glVertex2i(620 + i, 200 + j);
    glVertex2i(650 + i, 270 + j);
    glVertex2i(670 + i, 200 + j);
    glVertex2i(600 + i, 350 + j);
    glVertex2i(700 + i, 350 + j);
    glEnd();
    glColor3f(0.22, 0.15, 0.07);
    glLineWidth(5);

    //eyes
    glLineWidth(1);
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(640 + i, 400 + j);
    glVertex2i(650 + i, 400 + j);
    glEnd();

    //mouth
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(635 + i, 390 + j);
    glVertex2i(658 + i, 390 + j);
    glEnd();

    //stick
    stick2(sm2, smj2);
}



/*
void draw_tree()
{
   
    //1st tree
    glColor3f(0.1f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(130.0, 200.0);
    glVertex2i(110.0, 200.0);
    glVertex2i(110.0, 205.0);
    glVertex2i(130.0, 205.0);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(117.5, 205.0);
    glVertex2f(122.5, 210.0);
    glVertex2f(132.5, 210.0);
    glVertex2f(137.5, 205.0);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(120.0, 210.0);
    glVertex2f(125.0, 215.0);
    glVertex2f(130.0, 215.0);
    glVertex2f(135.0, 210.0);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(122.5, 215.0);
    glVertex2f(127.5, 220.0);
    glVertex2f(132.5, 215.0);
    glEnd();
}
*/



//keys Function
void keys(unsigned char key, int x, int y)
{
    switch (key)
    {
        //Stickman 1
        
        //right
    case 'd':
        sm1 += 10;
        break;
        //left
    case 'a':
        sm1 -= 10;
        break;
        //jump up
    case 'w':
        smj1 += 10;
        break;
        //jump down
    case 's':
        smj1 -= 10;
        break;
        
        //Stickman 2

        //left
    case 'j':
        sm2 -= 10;
        break;
        //right
    case 'l':
        sm2 += 10;
        break;
        //jump up
    case 'i':
        smj2 += 10;
        break;
        //jump down
    case 'k':
        smj2 -= 10;
        break;
    }
    glutPostRedisplay();
}

GLint k, x1 = 0;
//to display text on screen
void bitmap_output(double x, double y, const char* string, void* font)
{
    int len, k;
    glRasterPos2f(x, y);
    len = (double)strlen(string);
    for (k = 0; k < len; k++)
    {
        glutBitmapCharacter(font, string[k]);
    }

}

//display Function
void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	//Ground
	glColor3f(0.5, 0.3, 0.2);
	glBegin(GL_POLYGON);
	glVertex2i(0, 0);
	glVertex2i(0, 200);
	glVertex2i(1270, 200);
	glVertex2i(1270, 0);
	glEnd();

    //Sun & Cloud
    int i, j;
    glColor3f(1.0, 0.84, 0.0);
    glPointSize(5.0);
    for (i = 0; i < 45; i += 5)
        draw_circle(635, 580, 40 - i);

    //clouds
    glColor3f(1.0, 1.0, 1.0);
    for (j = 0; j < 1200; j += 300)
    {
        if (j == 600) j += 120;
        for (i = 0; i < 25; i += 5)
            draw_circle(85 + j, 570, 20 - i);
        for (i = 0; i < 25; i += 5)
            draw_circle(115 + j, 585, 20 - i);
        for (i = 0; i < 25; i += 5)
            draw_circle(145 + j, 585, 20 - i);
        for (i = 0; i < 25; i += 5)
            draw_circle(175 + j, 570, 20 - i);
        for (i = 0; i < 25; i += 5)
            draw_circle(145 + j, 555, 20 - i);
        for (i = 0; i < 25; i += 5)
            draw_circle(115 + j, 555, 20 - i);
    }
    

    //tree
    //draw_tree();

	//Stickman
	stickman1(sm1,smj1);
    stickman2(sm2,smj2);
	
    glFlush();
}

void display1(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    bitmap_output(-21, 40, "College Name:B.N.M Institute Of Technology", GLUT_BITMAP_TIMES_ROMAN_24);
    bitmap_output(-21, 30, "COMPUTER SCIENCE AND ENGINEERING DEPARTMENT", GLUT_BITMAP_HELVETICA_18);
    bitmap_output(-21, 20, "COMPUTER GRAPHICS AND VISUALIZATION PROJECT", GLUT_BITMAP_HELVETICA_18);
    bitmap_output(-15, 0, "SWORD DUEL BETWEEN STICKMAN", GLUT_BITMAP_HELVETICA_18);
    bitmap_output(-15, -20, "Project By", GLUT_BITMAP_HELVETICA_18);
    bitmap_output(-15, -25, "Name:Pruthvish M Shirur", GLUT_BITMAP_HELVETICA_18);
    bitmap_output(-15, -30, "USN:1BG18CS086", GLUT_BITMAP_HELVETICA_18);
    glFlush();
}

void select1(int ch1) {
    switch (ch1) {
    case 1:
        display();
        break;

    case 2:
        display1();
        break;

    }
}


void select2(int ch1) {
    switch (ch1) {
    case 1:
        r1 = 1;
        break;

    case 2:
        r2 = 1;
        break;

    }
    glutPostRedisplay();
}

void myInit() {
	glClearColor(0.54, 0.71, 0.94, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1270.0, 0.0, 650.0);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
	glutInitWindowSize(1270, 650);
    glutCreateWindow("Sword Duel Between Stickman");
    glutDisplayFunc(display);
    glutCreateMenu(select1);
    glutAddMenuEntry("Stickman Animation", 1);
    //glutAddMenuEntry("Credits", 2);
    glutAttachMenu(GLUT_LEFT_BUTTON);
    glutCreateMenu(select2);
    glutAddMenuEntry("Stickman-1 Strike", 1);
    glutAddMenuEntry("Stickman-2 Strike", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutKeyboardFunc(keys);
    myInit();
    glutMainLoop();
}