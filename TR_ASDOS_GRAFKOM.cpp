#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <windows.h>
#ifdef __APPLE__
#include<openGL/openGL.h>
#include<GLUT/glut.h>
#else
#include <math.h>
#include<GL/glut.h>
#endif

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int buttom, int state, int x, int y);
void ukuran(int,int);
void mouseMotion(int x, int y);
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;
int a,b;

int main (int argc, char **argv)
{
	glutInit(& argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000,600);
	glutInitWindowPosition(350,100);
	glutCreateWindow("TR Grafkom");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);

	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);

	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;

}

void init(void){
    //seting cahaya
    GLfloat LightAmbient[] ={400.0f,400.0f,0.0f,1.0f};
    GLfloat LightDiffuse[] = {400.0f, 400.0f, 0.0f, 1.0f};
    GLfloat Shine[] = {80};
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
    glMaterialfv(GL_FRONT,GL_SHININESS,Shine);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //
	glClearColor (0/255.f,255/255.f,255/255.f,1.0);
	glMatrixMode(GL_PROJECTION);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}
void pohon(void)
{
    //pohon1
    glBegin(GL_TRIANGLES);
    glColor3f(0/255.0f,128/255.0f,0/255.0f);
    glVertex3f(-200,50,-200);
    glVertex3f(-180,150,-215);
    glVertex3f(-160,50,-200);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0/255.0f,128/255.0f,0/255.0f);
    glVertex3f(-200,50,-230);
    glVertex3f(-180,150,-215);
    glVertex3f(-160,50,-230);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0/255.0f,128/255.0f,0/255.0f);
    glVertex3f(-200.01,50,-200.01);
    glVertex3f(-180.01,150,-215);
    glVertex3f(-200.01,50,-230);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0/255.0f,128/255.0f,0/255.0f);
    glVertex3f(-160.01,50,-200.01);
    glVertex3f(-180.01,150,-215);
    glVertex3f(-160.01,50,-230);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0/255.0f,128/255.0f,0/255.0f);
    glVertex3f(-200,50,-200.01);
    glVertex3f(-160,50,-200.01);
    glVertex3f(-160,50,-230);
    glVertex3f(-200,50,-230);
    glEnd();

    //batang
    glBegin(GL_QUADS);
    glColor3f(136/255.0f,68/255.0f,0/255.0f);
    glVertex3f(-190,-10,-210);
    glVertex3f(-170,-10,-210);
    glVertex3f(-170,50,-210);
    glVertex3f(-190,50,-210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(136/255.0f,68/255.0f,0/255.0f);
    glVertex3f(-190,-10,-225);
    glVertex3f(-170,-10,-225);
    glVertex3f(-170,50,-225);
    glVertex3f(-190,50,-225);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(136/255.0f,68/255.0f,0/255.0f);
    glVertex3f(-190.01,-10,-210.01);
    glVertex3f(-190.01,50,-210.01);
    glVertex3f(-190.01,50,-225);
    glVertex3f(-190.01,-10,-225);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(136/255.0f,68/255.0f,0/255.0f);
    glVertex3f(-170.01,-10,-210.01);
    glVertex3f(-170.01,50,-210.01);
    glVertex3f(-170.01,50,-225);
    glVertex3f(-170.01,-10,-225);
    glEnd();

    //pohon2
    glBegin(GL_TRIANGLES);
    glColor3f(0/255.0f,128/255.0f,0/255.0f);
    glVertex3f(-300,50,-200);
    glVertex3f(-280,150,-215);
    glVertex3f(-260,50,-200);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0/255.0f,128/255.0f,0/255.0f);
    glVertex3f(-300,50,-230);
    glVertex3f(-280,150,-215);
    glVertex3f(-260,50,-230);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0/255.0f,128/255.0f,0/255.0f);
    glVertex3f(-300.01,50,-200.01);
    glVertex3f(-280.01,150,-215);
    glVertex3f(-300.01,50,-230);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0/255.0f,128/255.0f,0/255.0f);
    glVertex3f(-260.01,50,-200.01);
    glVertex3f(-280.01,150,-215);
    glVertex3f(-260.01,50,-230);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0/255.0f,128/255.0f,0/255.0f);
    glVertex3f(-300,50,-200.01);
    glVertex3f(-260,50,-200.01);
    glVertex3f(-260,50,-230);
    glVertex3f(-300,50,-230);
    glEnd();

    //batang
    glBegin(GL_QUADS);
    glColor3f(136/255.0f,68/255.0f,0/255.0f);
    glVertex3f(-290,-10,-210);
    glVertex3f(-270,-10,-210);
    glVertex3f(-270,50,-210);
    glVertex3f(-290,50,-210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(136/255.0f,68/255.0f,0/255.0f);
    glVertex3f(-290,-10,-225);
    glVertex3f(-270,-10,-225);
    glVertex3f(-270,50,-225);
    glVertex3f(-290,50,-225);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(136/255.0f,68/255.0f,0/255.0f);
    glVertex3f(-290.01,-10,-210.01);
    glVertex3f(-290.01,50,-210.01);
    glVertex3f(-290.01,50,-225);
    glVertex3f(-290.01,-10,-225);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(136/255.0f,68/255.0f,0/255.0f);
    glVertex3f(-270.01,-10,-210.01);
    glVertex3f(-270.01,50,-210.01);
    glVertex3f(-270.01,50,-225);
    glVertex3f(-270.01,-10,-225);
    glEnd();
}
void kolam (void)
{
    ////
    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(200,-10,-50);
    glVertex3f(220,-10,-50);
    glVertex3f(220,7,-50);
    glVertex3f(200,7,-50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(200,-10,-200);
    glVertex3f(220,-10,-200);
    glVertex3f(220,7,-200);
    glVertex3f(200,7,-200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(200,-10,-50.01);
    glVertex3f(200,7,-50.01);
    glVertex3f(200,7,-200);
    glVertex3f(200,-10,-200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(220,-10,-50.01);
    glVertex3f(220,7,-50.01);
    glVertex3f(220,7,-200);
    glVertex3f(220,-10,-200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(200,-10,-50.01);
    glVertex3f(220,-10,-50.01);
    glVertex3f(220,-10,-200);
    glVertex3f(200,-10,-200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(200,7,-50.01);
    glVertex3f(220,7,-50.01);
    glVertex3f(220,7,-200);
    glVertex3f(200,7,-200);
    glEnd();

    ////
    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(350,-10,-50);
    glVertex3f(370,-10,-50);
    glVertex3f(370,7,-50);
    glVertex3f(350,7,-50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(350,-10,-200);
    glVertex3f(370,-10,-200);
    glVertex3f(370,7,-200);
    glVertex3f(350,7,-200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(350,-10,-50.01);
    glVertex3f(350,7,-50.01);
    glVertex3f(350,7,-200);
    glVertex3f(350,-10,-200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(370,-10,-50.01);
    glVertex3f(370,7,-50.01);
    glVertex3f(370,7,-200);
    glVertex3f(370,-10,-200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(350,-10,-50.01);
    glVertex3f(370,-10,-50.01);
    glVertex3f(370,-10,-200);
    glVertex3f(350,-10,-200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(350,7,-50.01);
    glVertex3f(370,7,-50.01);
    glVertex3f(370,7,-200);
    glVertex3f(350,7,-200);
    glEnd();

    ////
    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(220,-10,-50);
    glVertex3f(350,-10,-50);
    glVertex3f(350,7,-50);
    glVertex3f(220,7,-50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(200,-10,-40);
    glVertex3f(370,-10,-40);
    glVertex3f(370,7,-40);
    glVertex3f(200,7,-40);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(200,-10,-40);
    glVertex3f(200,7,-40);
    glVertex3f(200,7,-50);
    glVertex3f(200,-10,-50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(370,-10,-40);
    glVertex3f(370,7,-40);
    glVertex3f(370,7,-50);
    glVertex3f(370,-10,-50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(200,-10,-40);
    glVertex3f(370,-10,-40);
    glVertex3f(370,-10,-50);
    glVertex3f(200,-10,-50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(200,7,-40);
    glVertex3f(370,7,-40);
    glVertex3f(370,7,-50);
    glVertex3f(200,7,-50);
    glEnd();

    ////
    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(220,-10,-200);
    glVertex3f(350,-10,-200);
    glVertex3f(350,7,-200);
    glVertex3f(220,7,-200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(200,-10,-210);
    glVertex3f(370,-10,-210);
    glVertex3f(370,7,-210);
    glVertex3f(200,7,-210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(200,-10,-200);
    glVertex3f(200,7,-200);
    glVertex3f(200,7,-210);
    glVertex3f(200,-10,-210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(370,-10,-200);
    glVertex3f(370,7,-200);
    glVertex3f(370,7,-210);
    glVertex3f(370,-10,-210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(200,7,-200);
    glVertex3f(370,7,-200);
    glVertex3f(370,7,-210);
    glVertex3f(200,7,-210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(64/255.0f,128/255.0f,128/255.0f);
    glVertex3f(200,-10,-200);
    glVertex3f(370,-10,-200);
    glVertex3f(370,-10,-210);
    glVertex3f(200,-10,-210);
    glEnd();

    ////
    glBegin(GL_QUADS);
    glColor3f(0/255.0f,156/255.0f,232/255.0f);
    glVertex3f(220,-10,-50);
    glVertex3f(350,-10,-50);
    glVertex3f(350,-10,-200);
    glVertex3f(220,-10,-200);
    glEnd();
}
void kursi(void)
{
    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(150,-5,-110);
    glVertex3f(170,-5,-110);
    glVertex3f(170,-5,-160);
    glVertex3f(150,-5,-160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(150,-1,-110);
    glVertex3f(170,-1,-110);
    glVertex3f(170,-1,-160);
    glVertex3f(150,-1,-160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(150,-1,-110);
    glVertex3f(150,-5,-110);
    glVertex3f(150,-5,-160);
    glVertex3f(150,-1,-160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(170,-1,-110);
    glVertex3f(170,-5,-110);
    glVertex3f(170,-5,-160);
    glVertex3f(170,-1,-160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(150,-5,-160);
    glVertex3f(170,-5,-160);
    glVertex3f(170,-1,-160);
    glVertex3f(150,-1,-160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(150,-5,-110);
    glVertex3f(170,-5,-110);
    glVertex3f(170,-1,-110);
    glVertex3f(150,-1,-110);
    glEnd();


    //kaki 1
    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(155,-15,-155);
    glVertex3f(160,-15,-155);
    glVertex3f(160,-5,-155);
    glVertex3f(155,-5,-155);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(155,-15,-158);
    glVertex3f(160,-15,-158);
    glVertex3f(160,-5,-158);
    glVertex3f(155,-5,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(160,-15,-155);
    glVertex3f(160,-5,-155);
    glVertex3f(160,-5,-158);
    glVertex3f(160,-15,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(155,-15,-155);
    glVertex3f(155,-5,-155);
    glVertex3f(155,-5,-158);
    glVertex3f(155,-15,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(155,-15,-155);
    glVertex3f(160,-15,-155);
    glVertex3f(160,-15,-158);
    glVertex3f(155,-15,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(155,-5,-155);
    glVertex3f(160,-5,-155);
    glVertex3f(160,-5,-158);
    glVertex3f(155,-5,-158);
    glEnd();

    //kaki 2
    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(163,-15,-155);
    glVertex3f(168,-15,-155);
    glVertex3f(168,-5,-155);
    glVertex3f(163,-5,-155);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(163,-15,-158);
    glVertex3f(168,-15,-158);
    glVertex3f(168,-5,-158);
    glVertex3f(163,-5,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(168,-15,-155);
    glVertex3f(168,-5,-155);
    glVertex3f(168,-5,-158);
    glVertex3f(168,-15,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(163,-15,-155);
    glVertex3f(163,-5,-155);
    glVertex3f(163,-5,-158);
    glVertex3f(163,-15,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(163,-15,-155);
    glVertex3f(168,-15,-155);
    glVertex3f(168,-15,-158);
    glVertex3f(163,-15,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(163,-5,-155);
    glVertex3f(168,-5,-155);
    glVertex3f(168,-5,-158);
    glVertex3f(163,-5,-158);
    glEnd();

    //kaki 3
    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(155,-15,-116);
    glVertex3f(160,-15,-116);
    glVertex3f(160,-5,-116);
    glVertex3f(155,-5,-116);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(155,-15,-119);
    glVertex3f(160,-15,-119);
    glVertex3f(160,-5,-119);
    glVertex3f(155,-5,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(160,-15,-116);
    glVertex3f(160,-5,-116);
    glVertex3f(160,-5,-119);
    glVertex3f(160,-15,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(155,-15,-116);
    glVertex3f(155,-5,-116);
    glVertex3f(155,-5,-119);
    glVertex3f(155,-15,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(155,-15,-116);
    glVertex3f(160,-15,-116);
    glVertex3f(160,-15,-119);
    glVertex3f(155,-15,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(155,-5,-116);
    glVertex3f(160,-5,-116);
    glVertex3f(160,-5,-119);
    glVertex3f(155,-5,-119);
    glEnd();

     //kaki 4
    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(163,-15,-116);
    glVertex3f(168,-15,-116);
    glVertex3f(168,-5,-116);
    glVertex3f(163,-5,-116);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(163,-15,-119);
    glVertex3f(168,-15,-119);
    glVertex3f(168,-5,-119);
    glVertex3f(163,-5,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(168,-15,-116);
    glVertex3f(168,-5,-116);
    glVertex3f(168,-5,-119);
    glVertex3f(168,-15,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(163,-15,-116);
    glVertex3f(163,-5,-116);
    glVertex3f(163,-5,-119);
    glVertex3f(163,-15,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(163,-15,-116);
    glVertex3f(168,-15,-116);
    glVertex3f(168,-15,-119);
    glVertex3f(163,-15,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(163,-5,-116);
    glVertex3f(168,-5,-116);
    glVertex3f(168,-5,-119);
    glVertex3f(163,-5,-119);
    glEnd();

    //penyangga
    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(150,-10,-98);
    glVertex3f(170,-10,-98);
    glVertex3f(170,-5,-110);
    glVertex3f(150,-5,-110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(150,-7,-100);
    glVertex3f(170,-7,-100);
    glVertex3f(170,-1,-110);
    glVertex3f(150,-1,-110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(150,-10,-98);
    glVertex3f(170,-10,-98);
    glVertex3f(170,-7,-100);
    glVertex3f(150,-7,-100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(170,-10,-98);
    glVertex3f(170,-7,-100);
    glVertex3f(170,-1,-110);
    glVertex3f(170,-5,-110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(150,-10,-98);
    glVertex3f(150,-7,-100);
    glVertex3f(150,-1,-110);
    glVertex3f(150,-5,-110);
    glEnd();

    //penyangga 2
    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(150,-1.01,-150);
    glVertex3f(170,-1.01,-150);
    glVertex3f(170,8,-155);
    glVertex3f(150,8,-155);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(150,-1.01,-159);
    glVertex3f(170,-1.01,-159);
    glVertex3f(170,8,-155);
    glVertex3f(150,8,-155);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(170,-1.01,-150);
    glVertex3f(170,8,-155);
    glVertex3f(170,-1.01,-159);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(150,-1.01,-150);
    glVertex3f(150,8,-155);
    glVertex3f(150,-1.01,-159);
    glEnd();

}
void chair(void)
{
    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(95,-5,-110);
    glVertex3f(115,-5,-110);
    glVertex3f(115,-5,-160);
    glVertex3f(95,-5,-160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(95,-1,-110);
    glVertex3f(115,-1,-110);
    glVertex3f(115,-1,-160);
    glVertex3f(95,-1,-160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(95,-1,-110);
    glVertex3f(95,-5,-110);
    glVertex3f(95,-5,-160);
    glVertex3f(95,-1,-160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(115,-1,-110);
    glVertex3f(115,-5,-110);
    glVertex3f(115,-5,-160);
    glVertex3f(115,-1,-160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(95,-5,-160);
    glVertex3f(115,-5,-160);
    glVertex3f(115,-1,-160);
    glVertex3f(95,-1,-160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(95,-5,-110);
    glVertex3f(115,-5,-110);
    glVertex3f(115,-1,-110);
    glVertex3f(95,-1,-110);
    glEnd();


    //kaki 1
    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(100,-15,-155);
    glVertex3f(105,-15,-155);
    glVertex3f(105,-5,-155);
    glVertex3f(100,-5,-155);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(100,-15,-158);
    glVertex3f(105,-15,-158);
    glVertex3f(105,-5,-158);
    glVertex3f(100,-5,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(105,-15,-155);
    glVertex3f(105,-5,-155);
    glVertex3f(105,-5,-158);
    glVertex3f(105,-15,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(100,-15,-155);
    glVertex3f(100,-5,-155);
    glVertex3f(100,-5,-158);
    glVertex3f(100,-15,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(100,-15,-155);
    glVertex3f(105,-15,-155);
    glVertex3f(105,-15,-158);
    glVertex3f(100,-15,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(100,-5,-155);
    glVertex3f(105,-5,-155);
    glVertex3f(105,-5,-158);
    glVertex3f(100,-5,-158);
    glEnd();

    //kaki 2
    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(108,-15,-155);
    glVertex3f(111,-15,-155);
    glVertex3f(111,-5,-155);
    glVertex3f(108,-5,-155);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(108,-15,-158);
    glVertex3f(111,-15,-158);
    glVertex3f(111,-5,-158);
    glVertex3f(108,-5,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(111,-15,-155);
    glVertex3f(111,-5,-155);
    glVertex3f(111,-5,-158);
    glVertex3f(111,-15,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(108,-15,-155);
    glVertex3f(108,-5,-155);
    glVertex3f(108,-5,-158);
    glVertex3f(108,-15,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(108,-15,-155);
    glVertex3f(111,-15,-155);
    glVertex3f(111,-15,-158);
    glVertex3f(108,-15,-158);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(108,-5,-155);
    glVertex3f(111,-5,-155);
    glVertex3f(111,-5,-158);
    glVertex3f(108,-5,-158);
    glEnd();

    //kaki 3
    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(100,-15,-116);
    glVertex3f(105,-15,-116);
    glVertex3f(105,-5,-116);
    glVertex3f(100,-5,-116);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(100,-15,-119);
    glVertex3f(105,-15,-119);
    glVertex3f(105,-5,-119);
    glVertex3f(100,-5,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(105,-15,-116);
    glVertex3f(105,-5,-116);
    glVertex3f(105,-5,-119);
    glVertex3f(105,-15,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(100,-15,-116);
    glVertex3f(100,-5,-116);
    glVertex3f(100,-5,-119);
    glVertex3f(100,-15,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(100,-15,-116);
    glVertex3f(105,-15,-116);
    glVertex3f(105,-15,-119);
    glVertex3f(100,-15,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(100,-5,-116);
    glVertex3f(105,-5,-116);
    glVertex3f(105,-5,-119);
    glVertex3f(100,-5,-119);
    glEnd();

     //kaki 4
    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(108,-15,-116);
    glVertex3f(111,-15,-116);
    glVertex3f(111,-5,-116);
    glVertex3f(108,-5,-116);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(108,-15,-119);
    glVertex3f(111,-15,-119);
    glVertex3f(111,-5,-119);
    glVertex3f(108,-5,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(111,-15,-116);
    glVertex3f(111,-5,-116);
    glVertex3f(111,-5,-119);
    glVertex3f(111,-15,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(108,-15,-116);
    glVertex3f(108,-5,-116);
    glVertex3f(108,-5,-119);
    glVertex3f(108,-15,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(108,-15,-116);
    glVertex3f(111,-15,-116);
    glVertex3f(111,-15,-119);
    glVertex3f(108,-15,-119);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(108,-5,-116);
    glVertex3f(111,-5,-116);
    glVertex3f(111,-5,-119);
    glVertex3f(108,-5,-119);
    glEnd();

    //penyangga
    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(95,-10,-98);
    glVertex3f(115,-10,-98);
    glVertex3f(115,-5,-110);
    glVertex3f(95,-5,-110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(95,-7,-100);
    glVertex3f(115,-7,-100);
    glVertex3f(115,-1,-110);
    glVertex3f(95,-1,-110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(95,-10,-98);
    glVertex3f(115,-10,-98);
    glVertex3f(115,-7,-100);
    glVertex3f(95,-7,-100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(115,-10,-98);
    glVertex3f(115,-7,-100);
    glVertex3f(115,-1,-110);
    glVertex3f(115,-5,-110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(95,-10,-98);
    glVertex3f(95,-7,-100);
    glVertex3f(95,-1,-110);
    glVertex3f(95,-5,-110);
    glEnd();

    //penyangga 2
    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(95,-1.01,-150);
    glVertex3f(115,-1.01,-150);
    glVertex3f(115,8,-155);
    glVertex3f(95,8,-155);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(95,-1.01,-159);
    glVertex3f(115,-1.01,-159);
    glVertex3f(115,8,-155);
    glVertex3f(95,8,-155);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(115,-1.01,-150);
    glVertex3f(115,8,-155);
    glVertex3f(115,-1.01,-159);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(176/255.0f,0/255.0f,176/255.0f);
    glVertex3f(95,-1.01,-150);
    glVertex3f(95,8,-155);
    glVertex3f(95,-1.01,-159);
    glEnd();

}
void meja(void)
{
    //kaki 1
    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(130,-15,-150);
    glVertex3f(133,-15,-150);
    glVertex3f(133,0,-150);
    glVertex3f(130,0,-150);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(130,-15,-154);
    glVertex3f(133,-15,-154);
    glVertex3f(133,0,-154);
    glVertex3f(130,0,-154);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(130,-15,-150);
    glVertex3f(133,-15,-150);
    glVertex3f(133,-15,-154);
    glVertex3f(130,-15,-154);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(130,0,-150);
    glVertex3f(133,0,-150);
    glVertex3f(133,0,-154);
    glVertex3f(130,0,-154);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(130,-15,-150);
    glVertex3f(130,0,-150);
    glVertex3f(130,0,-154);
    glVertex3f(130,-15,-154);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(133,-15,-150);
    glVertex3f(133,0,-150);
    glVertex3f(133,0,-154);
    glVertex3f(133,-15,-154);
    glEnd();

    //kaki 2
    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(122,-15,-150);
    glVertex3f(125,-15,-150);
    glVertex3f(125,0,-150);
    glVertex3f(122,0,-150);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(122,-15,-154);
    glVertex3f(125,-15,-154);
    glVertex3f(125,0,-154);
    glVertex3f(122,0,-154);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(122,-15,-150);
    glVertex3f(125,-15,-150);
    glVertex3f(125,-15,-154);
    glVertex3f(122,-15,-154);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(122,0,-150);
    glVertex3f(125,0,-150);
    glVertex3f(125,0,-154);
    glVertex3f(122,0,-154);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(122,-15,-150);
    glVertex3f(122,0,-150);
    glVertex3f(122,0,-154);
    glVertex3f(122,-15,-154);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(125,-15,-150);
    glVertex3f(125,0,-150);
    glVertex3f(125,0,-154);
    glVertex3f(125,-15,-154);
    glEnd();

    //kaki 3
    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(130,-15,-142);
    glVertex3f(133,-15,-142);
    glVertex3f(133,0,-146);
    glVertex3f(130,0,-146);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(130,-15,-146);
    glVertex3f(133,-15,-146);
    glVertex3f(133,0,-146);
    glVertex3f(130,0,-146);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(130,-15,-142);
    glVertex3f(133,-15,-142);
    glVertex3f(133,-15,-146);
    glVertex3f(130,-15,-146);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(130,0,-142);
    glVertex3f(133,0,-142);
    glVertex3f(133,0,-146);
    glVertex3f(130,0,-146);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(130,-15,-142);
    glVertex3f(130,0,-142);
    glVertex3f(130,0,-146);
    glVertex3f(130,-15,-146);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(133,-15,-142);
    glVertex3f(133,0,-142);
    glVertex3f(133,0,-146);
    glVertex3f(133,-15,-146);
    glEnd();

    //kaki 4
    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(122,-15,-142);
    glVertex3f(125,-15,-142);
    glVertex3f(125,0,-142);
    glVertex3f(122,0,-142);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(122,-15,-146);
    glVertex3f(125,-15,-146);
    glVertex3f(125,0,-146);
    glVertex3f(122,0,-146);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(122,-15,-142);
    glVertex3f(125,-15,-142);
    glVertex3f(125,-15,-146);
    glVertex3f(122,-15,-146);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(122,0,-142);
    glVertex3f(125,0,-142);
    glVertex3f(125,0,-146);
    glVertex3f(122,0,-146);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(122,-15,-142);
    glVertex3f(122,0,-142);
    glVertex3f(122,0,-146);
    glVertex3f(122,-15,-146);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(125,-15,-142);
    glVertex3f(125,0,-142);
    glVertex3f(125,0,-146);
    glVertex3f(125,-15,-146);
    glEnd();

    //meja
    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(120,0,-140);
    glVertex3f(135,0,-140);
    glVertex3f(135,0,-157);
    glVertex3f(120,0,-157);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(120,2,-140);
    glVertex3f(135,2,-140);
    glVertex3f(135,2,-157);
    glVertex3f(120,2,-157);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(120,0,-140);
    glVertex3f(135,0,-140);
    glVertex3f(135,2,-140);
    glVertex3f(120,2,-140);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(120,0,-157);
    glVertex3f(135,0,-157);
    glVertex3f(135,2,-157);
    glVertex3f(120,2,-157);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(135,0,-140);
    glVertex3f(135,2,-140);
    glVertex3f(135,2,-157);
    glVertex3f(135,0,-157);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(120,0,-140);
    glVertex3f(120,2,-140);
    glVertex3f(120,2,-157);
    glVertex3f(120,0,-157);
    glEnd();

    ////////////////////////////////////
    glBegin(GL_TRIANGLES);
    glColor3f(0/255.0f,255/255.0f,64/255.0f);
    glVertex3f(93,24,-113);
    glVertex3f(133,40,-140);
    glVertex3f(173,24,-113);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0/255.0f,255/255.0f,64/255.0f);
    glVertex3f(93,24,-159);
    glVertex3f(133,40,-140);
    glVertex3f(173,24,-159);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0/255.0f,255/255.0f,64/255.0f);
    glVertex3f(93,24,-113);
    glVertex3f(133,40,-140);
    glVertex3f(93,24,-159);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0/255.0f,255/255.0f,64/255.0f);
    glVertex3f(173,24,-113);
    glVertex3f(133,40,-140);
    glVertex3f(173,24,-159);
    glEnd();

    ////////////
    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(126,0,-150);
    glVertex3f(129,0,-150);
    glVertex3f(129,38,-140);
    glVertex3f(126,38,-140);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(126,0,-149);
    glVertex3f(129,0,-149);
    glVertex3f(129,38,-139);
    glVertex3f(126,38,-139);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(126,0,-149);
    glVertex3f(129,0,-149);
    glVertex3f(129,0,-150);
    glVertex3f(126,0,-150);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(126,38,-139);
    glVertex3f(129,38,-139);
    glVertex3f(129,38,-140);
    glVertex3f(126,38,-140);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(126,0,-149);
    glVertex3f(126,38,-139);
    glVertex3f(126,38,-140);
    glVertex3f(126,0,-150);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(129,0,-149);
    glVertex3f(129,38,-139);
    glVertex3f(129,38,-140);
    glVertex3f(129,0,-150);
    glEnd();

}

void tempatTidur (void)
{
    glBegin(GL_QUADS);
    glColor3f(0/255.0f,0/255.0f,128/255.0f);
    glVertex3f(10,-5,-287);
    glVertex3f(38,-5,-287);
    glVertex3f(38,-10,-287);
    glVertex3f(10,-10,-287);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0/255.0f,0/255.0f,128/255.0f);
    glVertex3f(10,-5,-300);
    glVertex3f(38,-5,-300);
    glVertex3f(38,-10,-300);
    glVertex3f(10,-10,-300);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0/255.0f,0/255.0f,128/255.0f);
    glVertex3f(38.01,-5,-287);
    glVertex3f(38.01,-10,-287);
    glVertex3f(38.01,-10,-300);
    glVertex3f(38.01,-5,-300);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0/255.0f,0/255.0f,128/255.0f);
    glVertex3f(10.01,-5,-287);
    glVertex3f(10.01,-10,-287);
    glVertex3f(10.01,-10,-300);
    glVertex3f(10.01,-5,-300);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0/255.0f,0/255.0f,128/255.0f);
    glVertex3f(10,-10,-287);
    glVertex3f(38,-10,-287);
    glVertex3f(38,-10,-300);
    glVertex3f(10,-10,-300);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0/255.0f,0/255.0f,128/255.0f);
    glVertex3f(10,-5,-287);
    glVertex3f(38,-5,-287);
    glVertex3f(38,-5,-300);
    glVertex3f(10,-5,-300);
    glEnd();

    //kaki 1
    glBegin(GL_QUADS);//depan
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(12,-10,-289);
    glVertex3f(14,-10,-289);
    glVertex3f(14,-15,-289);
    glVertex3f(12,-15,-289);
    glEnd();

    glBegin(GL_QUADS);//belakang
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(12,-10,-291);
    glVertex3f(14,-10,-291);
    glVertex3f(14,-15,-291);
    glVertex3f(12,-15,-291);
    glEnd();

    glBegin(GL_QUADS);//bawah
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(12,-15,-289);
    glVertex3f(14,-15,-289);
    glVertex3f(14,-15,-291);
    glVertex3f(12,-15,-291);
    glEnd();

    glBegin(GL_QUADS);//atas
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(12,-10,-289);
    glVertex3f(14,-10,-289);
    glVertex3f(14,-10,-291);
    glVertex3f(12,-10,-291);
    glEnd();

    glBegin(GL_QUADS);//kiri
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(12,-15,-289);
    glVertex3f(12,-10,-289);
    glVertex3f(12,-10,-291);
    glVertex3f(12,-15,-291);
    glEnd();

    glBegin(GL_QUADS);//kanan
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(14,-15,-289);
    glVertex3f(14,-10,-289);
    glVertex3f(14,-10,-291);
    glVertex3f(14,-15,-291);
    glEnd();

    //kaki 2
    glBegin(GL_QUADS);//depan
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(34,-10,-289);
    glVertex3f(36,-10,-289);
    glVertex3f(36,-15,-289);
    glVertex3f(34,-15,-289);
    glEnd();

    glBegin(GL_QUADS);//belakang
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(34,-10,-291);
    glVertex3f(36,-10,-291);
    glVertex3f(36,-15,-291);
    glVertex3f(34,-15,-291);
    glEnd();

    glBegin(GL_QUADS);//bawah
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(34,-15,-289);
    glVertex3f(36,-15,-289);
    glVertex3f(36,-15,-291);
    glVertex3f(34,-15,-291);
    glEnd();

    glBegin(GL_QUADS);//atas
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(34,-10,-289);
    glVertex3f(36,-10,-289);
    glVertex3f(36,-10,-291);
    glVertex3f(34,-10,-291);
    glEnd();

    glBegin(GL_QUADS);//kiri
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(34,-15,-289);
    glVertex3f(34,-10,-289);
    glVertex3f(34,-10,-291);
    glVertex3f(34,-15,-291);
    glEnd();

    glBegin(GL_QUADS);//kanan
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(36,-15,-289);
    glVertex3f(36,-10,-289);
    glVertex3f(36,-10,-291);
    glVertex3f(36,-15,-291);
    glEnd();

    //kaki 3
    glBegin(GL_QUADS);//depan
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(12,-10,-296);
    glVertex3f(14,-10,-296);
    glVertex3f(14,-15,-296);
    glVertex3f(12,-15,-296);
    glEnd();

    glBegin(GL_QUADS);//belakang
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(12,-10,-298);
    glVertex3f(14,-10,-298);
    glVertex3f(14,-15,-298);
    glVertex3f(12,-15,-298);
    glEnd();

    glBegin(GL_QUADS);//bawah
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(12,-15,-296);
    glVertex3f(14,-15,-296);
    glVertex3f(14,-15,-298);
    glVertex3f(12,-15,-298);
    glEnd();

    glBegin(GL_QUADS);//atas
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(12,-10,-296);
    glVertex3f(14,-10,-296);
    glVertex3f(14,-10,-298);
    glVertex3f(12,-10,-298);
    glEnd();

    glBegin(GL_QUADS);//kiri
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(12,-15,-296);
    glVertex3f(12,-10,-296);
    glVertex3f(12,-10,-298);
    glVertex3f(12,-15,-298);
    glEnd();

    glBegin(GL_QUADS);//kanan
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(14,-15,-296);
    glVertex3f(14,-10,-296);
    glVertex3f(14,-10,-298);
    glVertex3f(14,-15,-298);
    glEnd();

     //kaki 4
    glBegin(GL_QUADS);//depan
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(34,-10,-296);
    glVertex3f(36,-10,-296);
    glVertex3f(36,-15,-296);
    glVertex3f(34,-15,-296);
    glEnd();

    glBegin(GL_QUADS);//belakang
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(34,-10,-298);
    glVertex3f(36,-10,-298);
    glVertex3f(36,-15,-298);
    glVertex3f(34,-15,-298);
    glEnd();

    glBegin(GL_QUADS);//bawah
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(34,-15,-296);
    glVertex3f(36,-15,-296);
    glVertex3f(36,-15,-298);
    glVertex3f(34,-15,-298);
    glEnd();

    glBegin(GL_QUADS);//atas
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(34,-10,-296);
    glVertex3f(36,-10,-296);
    glVertex3f(36,-10,-298);
    glVertex3f(34,-10,-298);
    glEnd();

    glBegin(GL_QUADS);//kiri
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(34,-15,-296);
    glVertex3f(34,-10,-296);
    glVertex3f(34,-10,-298);
    glVertex3f(34,-15,-298);
    glEnd();

    glBegin(GL_QUADS);//kanan
    glColor3f(255/255.0f,95/255.0f,17/255.0f);
    glVertex3f(36,-15,-296);
    glVertex3f(36,-10,-296);
    glVertex3f(36,-10,-298);
    glVertex3f(36,-15,-298);
    glEnd();

    //bantal
    glBegin(GL_QUADS);
    glColor3f(255/255.0f,0/255.0f,0/255.0f);
    glVertex3f(33,-5,-289);
    glVertex3f(37,-5,-289);
    glVertex3f(37,-5,-292);
    glVertex3f(33,-5,-292);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,0/255.0f,0/255.0f);
    glVertex3f(33,-4,-289);
    glVertex3f(37,-4,-289);
    glVertex3f(37,-4,-292);
    glVertex3f(33,-4,-292);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,0/255.0f,0/255.0f);
    glVertex3f(33,-5,-289);
    glVertex3f(37,-5,-289);
    glVertex3f(37,-4,-289);
    glVertex3f(33,-4,-289);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,0/255.0f,0/255.0f);
    glVertex3f(33,-5,-292);
    glVertex3f(37,-5,-292);
    glVertex3f(37,-4,-292);
    glVertex3f(33,-4,-292);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,0/255.0f,0/255.0f);
    glVertex3f(37,-5,-289);
    glVertex3f(37,-4,-289);
    glVertex3f(37,-4,-292);
    glVertex3f(37,-5,-292);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0f,0/255.0f,0/255.0f);
    glVertex3f(33,-5,-289);
    glVertex3f(33,-4,-289);
    glVertex3f(33,-4,-292);
    glVertex3f(33,-5,-292);
    glEnd();
}
void barang (void)
{
    //// lemari

glBegin(GL_QUADS);
glColor3f(0.0,1.0,0.0);
glVertex3f(150.0,50.0,-335.0);
glVertex3f(160.0,50.0,-335.0);
glVertex3f(160.0,80.0,-335.0);
glVertex3f(150.0,80.0,-335.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,1.0,0.0);
glVertex3f(150.0,50.0,-335.0);
glVertex3f(150.0,50.0,-330.0);
glVertex3f(150.0,80.0,-330.0);
glVertex3f(150.0,80.0,-335.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,1.0,0.0);
glVertex3f(160.0,50.0,-335.0);
glVertex3f(160.0,50.0,-330.0);
glVertex3f(160.0,80.0,-330.0);
glVertex3f(160.0,80.0,-335.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,1.0,0.0);
glVertex3f(150.0,50.0,-330.0);
glVertex3f(160.0,50.0,-330.0);
glVertex3f(160.0,80.0,-330.0);
glVertex3f(150.0,80.0,-330.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,1.0,0.0);
glVertex3f(150.0,50.0,-330.0);
glVertex3f(160.0,50.0,-335.0);
glVertex3f(160.0,50.0,-335.0);
glVertex3f(150.0,50.0,-330.0);
glEnd();

// meja resepsionis

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(120.0,-10.0,-340.0);
glVertex3f(140.0,-10.0,-340.0);
glVertex3f(140.0,-3.0,-340.0);
glVertex3f(120.0,-3.0,-340.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(120.0,-10.0,-340.0);
glVertex3f(120.0,-10.0,-336.0);
glVertex3f(120.0,-3.0,-336.0);
glVertex3f(120.0,-3.0,-340.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(140.0,-10.0,-340.0);
glVertex3f(140.0,-10.0,-336.0);
glVertex3f(140.0,-3.0,-336.0);
glVertex3f(140.0,-3.0,-340.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(120.0,-10.0,-336.0);
glVertex3f(140.0,-10.0,-336.0);
glVertex3f(140.0,-3.0,-336.0);
glVertex3f(120.0,-3.0,-336.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(120.0,-3.0,-336.0);
glVertex3f(140.0,-3.0,-340.0);
glVertex3f(140.0,-3.0,-340.0);
glVertex3f(120.0,-3.0,-336.0);
glEnd();

// kursi konstomer

glBegin(GL_QUADS);
glColor3f(0.0,0.0,1.0);
glVertex3f(120.0,-10.0,-335.0);
glVertex3f(140.0,-10.0,-335.0);
glVertex3f(140.0,-5.0,-335.0);
glVertex3f(120.0,-5.0,-335.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,0.0,1.0);
glVertex3f(120.0,-10.0,-335.0);
glVertex3f(120.0,-10.0,-332.0);
glVertex3f(120.0,-5.0,-332.0);
glVertex3f(120.0,-5.0,-335.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,0.0,1.0);
glVertex3f(140.0,-10.0,-335.0);
glVertex3f(140.0,-10.0,-332.0);
glVertex3f(140.0,-5.0,-332.0);
glVertex3f(140.0,-5.0,-335.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,1.0,0.0);
glVertex3f(120.0,-10.0,-332.0);
glVertex3f(140.0,-10.0,-332.0);
glVertex3f(140.0,0.0,-332.0);
glVertex3f(120.0,0.0,-332.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,0.0,1.0);
glVertex3f(120.0,-5.0,-332.0);
glVertex3f(140.0,-5.0,-335.0);
glVertex3f(140.0,-5.0,-335.0);
glVertex3f(120.0,-5.0,-332.0);
glEnd();


//rak

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(120.0,50.0,-335.0);
glVertex3f(140.0,50.0,-335.0);
glVertex3f(140.0,70.0,-335.0);
glVertex3f(120.0,70.0,-335.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(120.0,50.0,-335.0);
glVertex3f(120.0,50.0,-330.0);
glVertex3f(120.0,70.0,-330.0);
glVertex3f(120.0,70.0,-335.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(140.0,50.0,-335.0);
glVertex3f(140.0,50.0,-330.0);
glVertex3f(140.0,70.0,-330.0);
glVertex3f(140.0,70.0,-335.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,1.0,0.0);
glVertex3f(120.0,70.0,-330.0);
glVertex3f(140.0,70.0,-330.0);
glVertex3f(140.0,70.0,-335.0);
glVertex3f(120.0,70.0,-335.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,1.0,0.0);
glVertex3f(120.0,60.0,-330.0);
glVertex3f(140.0,60.0,-330.0);
glVertex3f(140.0,60.0,-335.0);
glVertex3f(120.0,60.0,-335.0);
glEnd();

//////////////////////
}
void tampil(void)
{
if(is_depth){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    GLfloat LightPosition[] = {400.0f, 400.0f, 400.0f, 0.0f};
    LightPosition[0]= a;
    LightPosition[1]= b;
    glLightfv(GL_LIGHT0,GL_POSITION,LightPosition);
    gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
    glEnable(GL_COLOR_MATERIAL);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glPushMatrix();
}
else{
    glClear(GL_COLOR_BUFFER_BIT);
}
// bawah

glBegin(GL_QUADS);
glColor3f(10.0,1.0,1.0);
glVertex3f(-400.0,-15.0,8.0);
glVertex3f(400.0,-15.0,8.0);
glVertex3f(400.0,-15.0,-800.0);
glVertex3f(-400.0,-15.0,-800.0);
glEnd();

//atas
glBegin(GL_QUADS);
glColor3f(10.0,1.0,1.0);
glVertex3f(-400.0,-10.0,8.0);
glVertex3f(400.0,-10.0,8.0);
glVertex3f(400.0,-10.0,-800.0);
glVertex3f(-400.0,-10.0,-800.0);
glEnd();

//depan
glBegin(GL_QUADS);
glColor3f(10.0,10.0,1.0);
glVertex3f(-400.0,-10.0,8.0);
glVertex3f(400.0,-10.0,8.0);
glVertex3f(400.0,-15.0,8.0);
glVertex3f(-400.0,-15.0,8.0);
glEnd();

//samping kiri
glBegin(GL_QUADS);
glColor3f(10.0,10.0,1.0);
glVertex3f(-400.0,-10.0,-800.0);
glVertex3f(-400.0,-10.0,8.0);
glVertex3f(-400.0,-15.0,8.0);
glVertex3f(-400.0,-15.0,-800.0);
glEnd();

//samping kanan
glBegin(GL_QUADS);
glColor3f(10.0,10.0,1.0);
glVertex3f(400.0,-10.0,-800.0);
glVertex3f(400.0,-10.0,8.0);
glVertex3f(400.0,-15.0,8.0);
glVertex3f(400.0,-15.0,-800.0);
glEnd();

//samping belakang
glBegin(GL_QUADS);
glColor3f(10.0,10.0,1.0);
glVertex3f(-400.0,-10.0,-800.0);
glVertex3f(400.0,-10.0,-800.0);
glVertex3f(400.0,-15.0,-800.0);
glVertex3f(-400.0,-15.0,-800.0);
glEnd();

//gedung 1
glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(180.0,-10.0,-280.0);
glVertex3f(200.0,-10.0,-280.0);
glVertex3f(200.0,250.0,-280.0);
glVertex3f(180.0,250.0,-280.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(200.0,-10.0,-280.0);
glVertex3f(220.0,-10.0,-285.0);
glVertex3f(220.0,250.0,-285.0);
glVertex3f(200.0,250.0,-280.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(220.0,-10.0,-285.0);
glVertex3f(240.0,-10.0,-295.0);
glVertex3f(240.0,250.0,-295.0);
glVertex3f(220.0,250.0,-285.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(240.0,-10.0,-295.0);
glVertex3f(260.0,-10.0,-310.0);
glVertex3f(260.0,250.0,-310.0);
glVertex3f(240.0,250.0,-295.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(260.0,-10.0,-310.0);
glVertex3f(280.0,-10.0,-335.0);
glVertex3f(280.0,250.0,-335.0);
glVertex3f(260.0,250.0,-310.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(280.0,-10.0,-335.0);
glVertex3f(300.0,-10.0,-365.0);
glVertex3f(300.0,250.0,-365.0);
glVertex3f(280.0,250.0,-335.0);
glEnd();

//tutup gedung 1

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(300.0,-10.0,-425.0);
glVertex3f(300.0,-10.0,-365.0);
glVertex3f(300.0,250.0,-365.0);
glVertex3f(300.0,250.0,-425.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(80.0,-10.0,-445.0);
glVertex3f(80.0,-10.0,-385.0);
glVertex3f(80.0,300.0,-385.0);
glVertex3f(80.0,300.0,-445.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(180.0,-10.0,-340.0);
glVertex3f(180.0,-10.0,-280.0);
glVertex3f(180.0,250.0,-280.0);
glVertex3f(180.0,250.0,-340.0);
glEnd();

//

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(180.0,-10.0,-300.0);
glVertex3f(160.0,-10.0,-305.0);
glVertex3f(160.0,300.0,-305.0);
glVertex3f(180.0,300.0,-300.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(160.0,-10.0,-305.0);
glVertex3f(140.0,-10.0,-315.0);
glVertex3f(140.0,300.0,-315.0);
glVertex3f(160.0,300.0,-305.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(140.0,-10.0,-315.0);
glVertex3f(120.0,-10.0,-330.0);
glVertex3f(120.0,300.0,-330.0);
glVertex3f(140.0,300.0,-315.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(120.0,-10.0,-330.0);
glVertex3f(100.0,-10.0,-355.0);
glVertex3f(100.0,300.0,-355.0);
glVertex3f(120.0,300.0,-330.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(100.0,-10.0,-355.0);
glVertex3f(80.0,-10.0,-385.0);
glVertex3f(80.0,300.0,-385.0);
glVertex3f(100.0,300.0,-355.0);
glEnd();

////

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(180.0,-10.0,-340.0);
glVertex3f(200.0,-10.0,-340.0);
glVertex3f(200.0,250.0,-340.0);
glVertex3f(180.0,250.0,-340.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(200.0,-10.0,-340.0);
glVertex3f(220.0,-10.0,-345.0);
glVertex3f(220.0,250.0,-345.0);
glVertex3f(200.0,250.0,-340.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(220.0,-10.0,-345.0);
glVertex3f(240.0,-10.0,-355.0);
glVertex3f(240.0,250.0,-355.0);
glVertex3f(220.0,250.0,-345.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(240.0,-10.0,-355.0);
glVertex3f(260.0,-10.0,-370.0);
glVertex3f(260.0,250.0,-370.0);
glVertex3f(240.0,250.0,-355.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(260.0,-10.0,-370.0);
glVertex3f(280.0,-10.0,-395.0);
glVertex3f(280.0,250.0,-395.0);
glVertex3f(260.0,250.0,-370.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(280.0,-10.0,-395.0);
glVertex3f(300.0,-10.0,-425.0);
glVertex3f(300.0,250.0,-425.0);
glVertex3f(280.0,250.0,-395.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(180.0,-10.0,-360.0);
glVertex3f(160.0,-10.0,-365.0);
glVertex3f(160.0,300.0,-365.0);
glVertex3f(180.0,300.0,-360.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(160.0,-10.0,-365.0);
glVertex3f(140.0,-10.0,-375.0);
glVertex3f(140.0,300.0,-375.0);
glVertex3f(160.0,300.0,-365.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(140.0,-10.0,-375.0);
glVertex3f(120.0,-10.0,-390.0);
glVertex3f(120.0,300.0,-390.0);
glVertex3f(140.0,300.0,-375.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(120.0,-10.0,-390.0);
glVertex3f(100.0,-10.0,-415.0);
glVertex3f(100.0,300.0,-415.0);
glVertex3f(120.0,300.0,-390.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(100.0,-10.0,-415.0);
glVertex3f(80.0,-10.0,-445.0);
glVertex3f(80.0,300.0,-445.0);
glVertex3f(100.0,300.0,-415.0);
glEnd();

////
glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(180.0,300.0,-360.0);
glVertex3f(160.0,300.0,-365.0);
glVertex3f(160.0,300.0,-305.0);
glVertex3f(180.0,300.0,-300.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(160.0,300.0,-365.0);
glVertex3f(140.0,300.0,-375.0);
glVertex3f(140.0,300.0,-315.0);
glVertex3f(160.0,300.0,-305.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(140.0,300.0,-375.0);
glVertex3f(120.0,300.0,-390.0);
glVertex3f(120.0,300.0,-330.0);
glVertex3f(140.0,300.0,-315.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(120.0,300.0,-390.0);
glVertex3f(100.0,300.0,-415.0);
glVertex3f(100.0,300.0,-355.0);
glVertex3f(120.0,300.0,-330.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(100.0,300.0,-415.0);
glVertex3f(80.0,300.0,-445.0);
glVertex3f(80.0,300.0,-385.0);
glVertex3f(100.0,300.0,-355.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(180.0,-10.0,-360.0);
glVertex3f(180.0,-10.0,-300.0);
glVertex3f(180.0,300.0,-300.0);
glVertex3f(180.0,300.0,-360.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(180.0,250.0,-340.0);
glVertex3f(200.0,250.0,-340.0);
glVertex3f(200.0,250.0,-280.0);
glVertex3f(180.0,250.0,-280.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(200.0,250.0,-340.0);
glVertex3f(220.0,250.0,-345.0);
glVertex3f(220.0,250.0,-285.0);
glVertex3f(200.0,250.0,-280.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(220.0,250.0,-345.0);
glVertex3f(240.0,250.0,-355.0);
glVertex3f(240.0,250.0,-295.0);
glVertex3f(220.0,250.0,-285.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(240.0,250.0,-355.0);
glVertex3f(260.0,250.0,-370.0);
glVertex3f(260.0,250.0,-310.0);
glVertex3f(240.0,250.0,-295.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(260.0,250.0,-370.0);
glVertex3f(280.0,250.0,-395.0);
glVertex3f(280.0,250.0,-335.0);
glVertex3f(260.0,250.0,-310.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(280.0,250.0,-395.0);
glVertex3f(300.0,250.0,-425.0);
glVertex3f(300.0,250.0,-365.0);
glVertex3f(280.0,250.0,-335.0);
glEnd();




//gedung dua
glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(0.0,-10.0,-255.0);
glVertex3f(20.0,-10.0,-255.0);
glVertex3f(20.0,250.0,-255.0);
glVertex3f(0.0,250.0,-255.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(20.0,-10.0,-255.0);
glVertex3f(40.0,-10.0,-260.0);
glVertex3f(40.0,250.0,-260.0);
glVertex3f(20.0,250.0,-255.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(40.0,-10.0,-260.0);
glVertex3f(60.0,-10.0,-270.0);
glVertex3f(60.0,250.0,-270.0);
glVertex3f(40.0,250.0,-260.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(60.0,-10.0,-270.0);
glVertex3f(80.0,-10.0,-285.0);
glVertex3f(80.0,250.0,-285.0);
glVertex3f(60.0,250.0,-270.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(80.0,-10.0,-285.0);
glVertex3f(100.0,-10.0,-300.0);
glVertex3f(100.0,250.0,-300.0);
glVertex3f(80.0,250.0,-285.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(100.0,200.0,-300.0);
glVertex3f(120.0,200.0,-330.0);
glVertex3f(120.0,250.0,-330.0);
glVertex3f(100.0,250.0,-300.0);
glEnd();
//

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(0.0,-10.0,-255.0);
glVertex3f(-20.0,-10.0,-260.0);
glVertex3f(-20.0,250.0,-260.0);
glVertex3f(0.0,250.0,-255.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-20.0,-10.0,-260.0);
glVertex3f(-40.0,-10.0,-270.0);
glVertex3f(-40.0,250.0,-270.0);
glVertex3f(-20.0,250.0,-260.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-40.0,-10.0,-270.0);
glVertex3f(-60.0,-10.0,-285.0);
glVertex3f(-60.0,250.0,-285.0);
glVertex3f(-40.0,250.0,-270.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-60.0,-10.0,-285.0);
glVertex3f(-80.0,-10.0,-300.0);
glVertex3f(-80.0,250.0,-300.0);
glVertex3f(-60.0,250.0,-285.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-80.0,-10.0,-300.0);
glVertex3f(-100.0,-10.0,-330.0);
glVertex3f(-100.0,250.0,-330.0);
glVertex3f(-80.0,250.0,-300.0);
glEnd();

////
glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(0.0,-10.0,-285.0);
glVertex3f(-20.0,-10.0,-285.0);
glVertex3f(-20.0,250.0,-285.0);
glVertex3f(0.0,250.0,-285.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-20.0,-10.0,-285.0);
glVertex3f(-40.0,-10.0,-290.0);
glVertex3f(-40.0,250.0,-290.0);
glVertex3f(-20.0,250.0,-285.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-40.0,-10.0,-290.0);
glVertex3f(-60.0,-10.0,-305.0);
glVertex3f(-60.0,250.0,-305.0);
glVertex3f(-40.0,250.0,-290.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-60.0,-10.0,-305.0);
glVertex3f(-80.0,-10.0,-335.0);
glVertex3f(-80.0,250.0,-335.0);
glVertex3f(-60.0,250.0,-305.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-80.0,-10.0,-335.0);
glVertex3f(-100.0,-10.0,-365.0);
glVertex3f(-100.0,250.0,-365.0);
glVertex3f(-80.0,250.0,-335.0);
glEnd();

////
glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(0.0,-10.0,-285.0);
glVertex3f(20.0,-10.0,-290.0);
glVertex3f(20.0,250.0,-290.0);
glVertex3f(0.0,250.0,-285.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(20.0,-10.0,-290.0);
glVertex3f(40.0,-10.0,-300.0);
glVertex3f(40.0,250.0,-300.0);
glVertex3f(20.0,250.0,-290.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(40.0,-10.0,-300.0);
glVertex3f(60.0,-10.0,-315.0);
glVertex3f(60.0,250.0,-315.0);
glVertex3f(40.0,250.0,-300.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(60.0,-10.0,-315.0);
glVertex3f(80.0,-10.0,-330.0);
glVertex3f(80.0,250.0,-330.0);
glVertex3f(60.0,250.0,-315.0);
glEnd();

//////
glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(80.0,250.0,-330.0);
glVertex3f(100.0,250.0,-360.0);
glVertex3f(125.0,250.0,-330.0);
glVertex3f(100.0,250.0,-300.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(60.0,250.0,-315.0);
glVertex3f(80.0,250.0,-330.0);
glVertex3f(100.0,250.0,-300.0);
glVertex3f(80.0,250.0,-285.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(40.0,250.0,-300.0);
glVertex3f(60.0,250.0,-315.0);
glVertex3f(80.0,250.0,-285.0);
glVertex3f(60.0,250.0,-270.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(20.0,250.0,-290.0);
glVertex3f(40.0,250.0,-300.0);
glVertex3f(60.0,250.0,-270.0);
glVertex3f(40.0,250.0,-260.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(0.0,250.0,-285.0);
glVertex3f(20.0,250.0,-290.0);
glVertex3f(40.0,250.0,-260.0);
glVertex3f(20.0,250.0,-255.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-20.0,250.0,-285.0);
glVertex3f(0.0,250.0,-285.0);
glVertex3f(20.0,250.0,-255.0);
glVertex3f(0.0,250.0,-255.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-40.0,250.0,-290.0);
glVertex3f(-20.0,250.0,-285.0);
glVertex3f(0.0,250.0,-255.0);
glVertex3f(-20.0,250.0,-260.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-60.0,250.0,-305.0);
glVertex3f(-40.0,250.0,-290.0);
glVertex3f(-20.0,250.0,-260.0);
glVertex3f(-40.0,250.0,-270.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-80.0,250.0,-335.0);
glVertex3f(-60.0,250.0,-305.0);
glVertex3f(-40.0,250.0,-270.0);
glVertex3f(-60.0,250.0,-285.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-100.0,250.0,-365.0);
glVertex3f(-80.0,250.0,-335.0);
glVertex3f(-60.0,250.0,-285.0);
glVertex3f(-80.0,250.0,-300.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-100.0,250.0,-385.0);
glVertex3f(-100.0,250.0,-365.0);
glVertex3f(-80.0,250.0,-300.0);
glVertex3f(-100.0,250.0,-330.0);
glEnd();



////
glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(80.0,200.0,-330.0);
glVertex3f(100.0,200.0,-360.0);
glVertex3f(125.0,200.0,-330.0);
glVertex3f(100.0,200.0,-300.0);
glEnd();


//tubup gedung 3

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-100.0,-10.0,-330.0);
glVertex3f(-100.0,-10.0,-370.0);
glVertex3f(-100.0,250.0,-370.0);
glVertex3f(-100.0,250.0,-330.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(100.0,-10.0,-300.0);
glVertex3f(80.0,-10.0,-330.0);
glVertex3f(80.0,200.0,-330.0);
glVertex3f(100.0,200.0,-300.0);
glEnd();

//

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(80.0,200.0,-330.0);
glVertex3f(100.0,200.0,-360.0);
glVertex3f(100.0,250.0,-360.0);
glVertex3f(80.0,250.0,-330.0);
glEnd();


//gedung3

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-100.0,-10.0,-280.0);
glVertex3f(-100.0,-10.0,-410.0);
glVertex3f(-100.0,100.0,-410.0);
glVertex3f(-100.0,100.0,-280.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-100.0,-10.0,-280.0);
glVertex3f(-120.0,-10.0,-285.0);
glVertex3f(-120.0,100.0,-285.0);
glVertex3f(-100.0,100.0,-280.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-120.0,-10.0,-285.0);
glVertex3f(-140.0,-10.0,-295.0);
glVertex3f(-140.0,100.0,-295.0);
glVertex3f(-120.0,100.0,-285.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-140.0,-10.0,-295.0);
glVertex3f(-160.0,-10.0,-310.0);
glVertex3f(-160.0,100.0,-310.0);
glVertex3f(-140.0,100.0,-295.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-160.0,-10.0,-310.0);
glVertex3f(-180.0,-10.0,-330.0);
glVertex3f(-180.0,100.0,-330.0);
glVertex3f(-160.0,100.0,-310.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-180.0,-10.0,-330.0);
glVertex3f(-200.0,-10.0,-355.0);
glVertex3f(-200.0,100.0,-355.0);
glVertex3f(-180.0,100.0,-330.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-200.0,-10.0,-355.0);
glVertex3f(-220.0,-10.0,-390.0);
glVertex3f(-220.0,100.0,-390.0);
glVertex3f(-200.0,100.0,-355.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-220.0,-10.0,-390.0);
glVertex3f(-240.0,-10.0,-430.0);
glVertex3f(-240.0,100.0,-430.0);
glVertex3f(-220.0,100.0,-390.0);
glEnd();

////

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-240.0,-10.0,-430.0);
glVertex3f(-240.0,-10.0,-550.0);
glVertex3f(-240.0,100.0,-550.0);
glVertex3f(-240.0,100.0,-430.0);
glEnd();

////

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-240.0,-10.0,-550.0);
glVertex3f(-220.0,-10.0,-515.0);
glVertex3f(-220.0,100.0,-515.0);
glVertex3f(-240.0,100.0,-550.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-220.0,-10.0,-515.0);
glVertex3f(-200.0,-10.0,-485.0);
glVertex3f(-200.0,100.0,-485.0);
glVertex3f(-220.0,100.0,-515.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-200.0,-10.0,-485.0);
glVertex3f(-180.0,-10.0,-460.0);
glVertex3f(-180.0,100.0,-460.0);
glVertex3f(-200.0,100.0,-485.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-180.0,-10.0,-460.0);
glVertex3f(-160.0,-10.0,-440.0);
glVertex3f(-160.0,100.0,-440.0);
glVertex3f(-180.0,100.0,-460.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-160.0,-10.0,-440.0);
glVertex3f(-140.0,-10.0,-425.0);
glVertex3f(-140.0,100.0,-425.0);
glVertex3f(-160.0,100.0,-440.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-140.0,-10.0,-425.0);
glVertex3f(-120.0,-10.0,-415.0);
glVertex3f(-120.0,100.0,-415.0);
glVertex3f(-140.0,100.0,-425.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(173/225.f,172/255.f,172/255.f);
glVertex3f(-120.0,-10.0,-415.0);
glVertex3f(-100.0,-10.0,-410.0);
glVertex3f(-100.0,100.0,-410.0);
glVertex3f(-120.0,100.0,-415.0);
glEnd();

////

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-100.0,100.0,-410.0);
glVertex3f(-120.0,100.0,-415.0);
glVertex3f(-120.0,100.0,-285.0);
glVertex3f(-100.0,100.0,-280.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-120.0,100.0,-415.0);
glVertex3f(-140.0,100.0,-425.0);
glVertex3f(-140.0,100.0,-295.0);
glVertex3f(-120.0,100.0,-285.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-140.0,100.0,-425.0);
glVertex3f(-160.0,100.0,-440.0);
glVertex3f(-160.0,100.0,-310.0);
glVertex3f(-140.0,100.0,-295.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-160.0,100.0,-440.0);
glVertex3f(-180.0,100.0,-460.0);
glVertex3f(-180.0,100.0,-330.0);
glVertex3f(-160.0,100.0,-310.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-180.0,100.0,-460.0);
glVertex3f(-200.0,100.0,-485.0);
glVertex3f(-200.0,100.0,-355.0);
glVertex3f(-180.0,100.0,-330.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-200.0,100.0,-485.0);
glVertex3f(-220.0,100.0,-515.0);
glVertex3f(-220.0,100.0,-390.0);
glVertex3f(-200.0,100.0,-355.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-220.0,100.0,-515.0);
glVertex3f(-240.0,100.0,-550.0);
glVertex3f(-240.0,100.0,-430.0);
glVertex3f(-220.0,100.0,-390.0);
glEnd();

////


////gedung depan


glBegin(GL_QUADS);
glColor3f(100.0,0.0,0.0);
glVertex3f(-80.0,-10.0,-270.0);
glVertex3f(-80.0,-10.0,-240.0);
glVertex3f(-80.0,40.0,-240.0);
glVertex3f(-80.0,40.0,-270.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,1.0,0.0);
glVertex3f(-80.0,40.0,-240.0);
glVertex3f(120.0,40.0,-240.0);
glVertex3f(120.0,40.0,-270.0);
glVertex3f(-80.0,40.0,-270.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,1.0,0.0);
glVertex3f(-80.0,-10.0,-270.0);
glVertex3f(120.0,-10.0,-270.0);
glVertex3f(120.0,40.0,-270.0);
glVertex3f(-80.0,40.0,-270.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,1.0,0.0);
glVertex3f(-80.0,-10.0,-240.0);
glVertex3f(120.0,-10.0,-240.0);
glVertex3f(120.0,40.0,-240.0);
glVertex3f(-80.0,40.0,-240.0);
glEnd();



glBegin(GL_QUADS);
glColor3f(100.0,0.0,0.0);
glVertex3f(120.0,-10.0,-270.0);
glVertex3f(120.0,-10.0,-240.0);
glVertex3f(120.0,40.0,-240.0);
glVertex3f(120.0,40.0,-270.0);
glEnd();


////

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-50.0,-10.0,-240.0);
glVertex3f(90.0,-10.0,-240.0);
glVertex3f(90.0,20.0,-240.0);
glVertex3f(-50.0,20.0,-240.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-50.0,-10.0,-240.0);
glVertex3f(-50.0,-10.0,-220.0);
glVertex3f(-50.0,20.0,-220.0);
glVertex3f(-50.0,20.0,-240.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(90.0,-10.0,-240.0);
glVertex3f(90.0,-10.0,-220.0);
glVertex3f(90.0,20.0,-220.0);
glVertex3f(90.0,20.0,-240.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-50.0,-10.0,-220.0);
glVertex3f(90.0,-10.0,-220.0);
glVertex3f(90.0,20.0,-220.0);
glVertex3f(-50.0,20.0,-220.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-50.0,20.0,-240.0);
glVertex3f(90.0,20.0,-240.0);
glVertex3f(90.0,20.0,-220.0);
glVertex3f(-50.0,20.0,-220.0);
glEnd();

////

glBegin(GL_QUADS);
glColor3f(0.0,0.0,1.0);
glVertex3f(-30.0,-10.0,-220.0);
glVertex3f(70.0,-10.0,-220.0);
glVertex3f(70.0,10.0,-220.0);
glVertex3f(-30.0,10.0,-220.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,0.0,1.0);
glVertex3f(-30.0,-10.0,-220.0);
glVertex3f(-30.0,-10.0,-210.0);
glVertex3f(-30.0,10.0,-210.0);
glVertex3f(-30.0,10.0,-220.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,0.0,1.0);
glVertex3f(70.0,-10.0,-220.0);
glVertex3f(70.0,-10.0,-210.0);
glVertex3f(70.0,10.0,-210.0);
glVertex3f(70.0,10.0,-220.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,0.0,1.0);
glVertex3f(-30.0,-10.0,-210.0);
glVertex3f(70.0,-10.0,-210.0);
glVertex3f(70.0,10.0,-210.0);
glVertex3f(-30.0,10.0,-210.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,0.0,1.0);
glVertex3f(-30.0,10.0,-220.0);
glVertex3f(70.0,10.0,-220.0);
glVertex3f(70.0,10.0,-210.0);
glVertex3f(-30.0,10.0,-210.0);
glEnd();


////

glBegin(GL_QUADS);
glColor3f(0.0,0.0,1.0);
glVertex3f(160.0,-10.0,-280.0);
glVertex3f(160.0,-10.0,-250.0);
glVertex3f(160.0,40.0,-250.0);
glVertex3f(160.0,40.0,-280.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,0.0,1.0);
glVertex3f(160.0,40.0,-280.0);
glVertex3f(300.0,40.0,-280.0);
glVertex3f(300.0,40.0,-250.0);
glVertex3f(160.0,40.0,-250.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,0.0,1.0);
glVertex3f(300.0,-10.0,-280.0);
glVertex3f(300.0,-10.0,-250.0);
glVertex3f(300.0,40.0,-250.0);
glVertex3f(300.0,40.0,-280.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.0,0.0,1.0);
glVertex3f(160.0,-10.0,-250.0);
glVertex3f(300.0,-10.0,-250.0);
glVertex3f(300.0,40.0,-250.0);
glVertex3f(160.0,40.0,-250.0);
glEnd();

//////// pintu depan
glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(170.0,-10.0,-249.0);
glVertex3f(180.0,-10.0,-249.0);
glVertex3f(180.0,20.0,-249.0);
glVertex3f(170.0,20.0,-249.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(190.0,-10.0,-249.0);
glVertex3f(200.0,-10.0,-249.0);
glVertex3f(200.0,20.0,-249.0);
glVertex3f(190.0,20.0,-249.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(210.0,-10.0,-249.0);
glVertex3f(220.0,-10.0,-249.0);
glVertex3f(220.0,20.0,-249.0);
glVertex3f(210.0,20.0,-249.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(230.0,-10.0,-249.0);
glVertex3f(240.0,-10.0,-249.0);
glVertex3f(240.0,20.0,-249.0);
glVertex3f(230.0,20.0,-249.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(250.0,-10.0,-249.0);
glVertex3f(260.0,-10.0,-249.0);
glVertex3f(260.0,20.0,-249.0);
glVertex3f(250.0,20.0,-249.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(270.0,-10.0,-249.0);
glVertex3f(280.0,-10.0,-249.0);
glVertex3f(280.0,20.0,-249.0);
glVertex3f(270.0,20.0,-249.0);
glEnd();


////
glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(-20.0,-10.0,-209.0);
glVertex3f(-10.0,-10.0,-209.0);
glVertex3f(-10.0,5.0,-209.0);
glVertex3f(-20.0,5.0,-209.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(0.0,-10.0,-209.0);
glVertex3f(10.0,-10.0,-209.0);
glVertex3f(10.0,5.0,-209.0);
glVertex3f(0.0,5.0,-209.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(20.0,-10.0,-209.0);
glVertex3f(30.0,-10.0,-209.0);
glVertex3f(30.0,5.0,-209.0);
glVertex3f(20.0,5.0,-209.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.0);
glVertex3f(40.0,-10.0,-209.0);
glVertex3f(50.0,-10.0,-209.0);
glVertex3f(50.0,5.0,-209.0);
glVertex3f(40.0,5.0,-209.0);
glEnd();

//jendela gedung 1 //

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,240.0,-279.0);
glVertex3f(200.0,240.0,-279.0);
glVertex3f(200.0,250.0,-279.0);
glVertex3f(180.0,250.0,-279.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,240.0,-279.0);
glVertex3f(220.0,240.0,-284.0);
glVertex3f(220.0,250.0,-284.0);
glVertex3f(200.0,250.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(220.0,240.0,-284.0);
glVertex3f(240.0,240.0,-294.0);
glVertex3f(240.0,250.0,-294.0);
glVertex3f(220.0,250.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(240.0,240.0,-294.0);
glVertex3f(260.0,240.0,-309.0);
glVertex3f(260.0,250.0,-309.0);
glVertex3f(240.0,250.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(260.0,240.0,-309.0);
glVertex3f(280.0,240.0,-334.0);
glVertex3f(280.0,250.0,-334.0);
glVertex3f(260.0,250.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(280.0,240.0,-334.0);
glVertex3f(300.0,240.0,-364.0);
glVertex3f(300.0,250.0,-364.0);
glVertex3f(280.0,250.0,-334.0);
glEnd();
//////

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(180.0,230.0,-279.0);
glVertex3f(200.0,230.0,-279.0);
glVertex3f(200.0,240.0,-279.0);
glVertex3f(180.0,240.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(200.0,230.0,-279.0);
glVertex3f(220.0,230.0,-284.0);
glVertex3f(220.0,240.0,-284.0);
glVertex3f(200.0,240.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(220.0,230.0,-284.0);
glVertex3f(240.0,230.0,-294.0);
glVertex3f(240.0,240.0,-294.0);
glVertex3f(220.0,240.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,230.0,-294.0);
glVertex3f(260.0,230.0,-309.0);
glVertex3f(260.0,240.0,-309.0);
glVertex3f(240.0,240.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,230.0,-309.0);
glVertex3f(280.0,230.0,-334.0);
glVertex3f(280.0,240.0,-334.0);
glVertex3f(260.0,240.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,230.0,-334.0);
glVertex3f(300.0,230.0,-364.0);
glVertex3f(300.0,240.0,-364.0);
glVertex3f(280.0,240.0,-334.0);
glEnd();
///////

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,220.0,-279.0);
glVertex3f(200.0,220.0,-279.0);
glVertex3f(200.0,230.0,-279.0);
glVertex3f(180.0,230.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,220.0,-279.0);
glVertex3f(220.0,220.0,-284.0);
glVertex3f(220.0,230.0,-284.0);
glVertex3f(200.0,230.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(220.0,220.0,-284.0);
glVertex3f(240.0,220.0,-294.0);
glVertex3f(240.0,230.0,-294.0);
glVertex3f(220.0,230.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,220.0,-294.0);
glVertex3f(260.0,220.0,-309.0);
glVertex3f(260.0,230.0,-309.0);
glVertex3f(240.0,230.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,220.0,-309.0);
glVertex3f(280.0,220.0,-334.0);
glVertex3f(280.0,230.0,-334.0);
glVertex3f(260.0,230.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,220.0,-334.0);
glVertex3f(300.0,220.0,-364.0);
glVertex3f(300.0,230.0,-364.0);
glVertex3f(280.0,230.0,-334.0);
glEnd();

/////////

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,210.0,-279.0);
glVertex3f(200.0,210.0,-279.0);
glVertex3f(200.0,220.0,-279.0);
glVertex3f(180.0,220.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,210.0,-279.0);
glVertex3f(220.0,210.0,-284.0);
glVertex3f(220.0,220.0,-284.0);
glVertex3f(200.0,220.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(220.0,210.0,-284.0);
glVertex3f(240.0,210.0,-294.0);
glVertex3f(240.0,220.0,-294.0);
glVertex3f(220.0,220.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,210.0,-294.0);
glVertex3f(260.0,210.0,-309.0);
glVertex3f(260.0,220.0,-309.0);
glVertex3f(240.0,220.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,210.0,-309.0);
glVertex3f(280.0,210.0,-334.0);
glVertex3f(280.0,220.0,-334.0);
glVertex3f(260.0,220.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,210.0,-334.0);
glVertex3f(300.0,210.0,-364.0);
glVertex3f(300.0,220.0,-364.0);
glVertex3f(280.0,220.0,-334.0);
glEnd();

/////


glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(180.0,200.0,-279.0);
glVertex3f(200.0,200.0,-279.0);
glVertex3f(200.0,210.0,-279.0);
glVertex3f(180.0,210.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(200.0,200.0,-279.0);
glVertex3f(220.0,200.0,-284.0);
glVertex3f(220.0,210.0,-284.0);
glVertex3f(200.0,210.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(220.0,200.0,-284.0);
glVertex3f(240.0,200.0,-294.0);
glVertex3f(240.0,210.0,-294.0);
glVertex3f(220.0,210.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,200.0,-294.0);
glVertex3f(260.0,200.0,-309.0);
glVertex3f(260.0,210.0,-309.0);
glVertex3f(240.0,210.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,200.0,-309.0);
glVertex3f(280.0,200.0,-334.0);
glVertex3f(280.0,210.0,-334.0);
glVertex3f(260.0,210.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,200.0,-334.0);
glVertex3f(300.0,200.0,-364.0);
glVertex3f(300.0,210.0,-364.0);
glVertex3f(280.0,210.0,-334.0);
glEnd();
////////////



glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,190.0,-279.0);
glVertex3f(200.0,190.0,-279.0);
glVertex3f(200.0,200.0,-279.0);
glVertex3f(180.0,200.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,190.0,-279.0);
glVertex3f(220.0,190.0,-284.0);
glVertex3f(220.0,200.0,-284.0);
glVertex3f(200.0,200.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(220.0,190.0,-284.0);
glVertex3f(240.0,190.0,-294.0);
glVertex3f(240.0,200.0,-294.0);
glVertex3f(220.0,200.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,190.0,-294.0);
glVertex3f(260.0,190.0,-309.0);
glVertex3f(260.0,200.0,-309.0);
glVertex3f(240.0,200.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,190.0,-309.0);
glVertex3f(280.0,190.0,-334.0);
glVertex3f(280.0,200.0,-334.0);
glVertex3f(260.0,200.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,190.0,-334.0);
glVertex3f(300.0,190.0,-364.0);
glVertex3f(300.0,220.0,-364.0);
glVertex3f(280.0,220.0,-334.0);
glEnd();

/////////

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,180.0,-279.0);
glVertex3f(200.0,180.0,-279.0);
glVertex3f(200.0,190.0,-279.0);
glVertex3f(180.0,190.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,180.0,-279.0);
glVertex3f(220.0,180.0,-284.0);
glVertex3f(220.0,190.0,-284.0);
glVertex3f(200.0,190.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(220.0,180.0,-284.0);
glVertex3f(240.0,180.0,-294.0);
glVertex3f(240.0,190.0,-294.0);
glVertex3f(220.0,190.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,180.0,-294.0);
glVertex3f(260.0,180.0,-309.0);
glVertex3f(260.0,190.0,-309.0);
glVertex3f(240.0,190.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,180.0,-309.0);
glVertex3f(280.0,180.0,-334.0);
glVertex3f(280.0,190.0,-334.0);
glVertex3f(260.0,190.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,180.0,-334.0);
glVertex3f(300.0,180.0,-364.0);
glVertex3f(300.0,190.0,-364.0);
glVertex3f(280.0,190.0,-334.0);
glEnd();

/////


glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(180.0,170.0,-279.0);
glVertex3f(200.0,170.0,-279.0);
glVertex3f(200.0,180.0,-279.0);
glVertex3f(180.0,180.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(200.0,170.0,-279.0);
glVertex3f(220.0,170.0,-284.0);
glVertex3f(220.0,180.0,-284.0);
glVertex3f(200.0,180.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(220.0,170.0,-284.0);
glVertex3f(240.0,170.0,-294.0);
glVertex3f(240.0,180.0,-294.0);
glVertex3f(220.0,180.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,170.0,-294.0);
glVertex3f(260.0,170.0,-309.0);
glVertex3f(260.0,180.0,-309.0);
glVertex3f(240.0,180.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,170.0,-309.0);
glVertex3f(280.0,170.0,-334.0);
glVertex3f(280.0,180.0,-334.0);
glVertex3f(260.0,180.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,170.0,-334.0);
glVertex3f(300.0,170.0,-364.0);
glVertex3f(300.0,180.0,-364.0);
glVertex3f(280.0,180.0,-334.0);
glEnd();


//////////////////////////////////////////////////////////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(180.0,160.0,-279.0);
glVertex3f(200.0,160.0,-279.0);
glVertex3f(200.0,170.0,-279.0);
glVertex3f(180.0,170.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(200.0,160.0,-279.0);
glVertex3f(220.0,160.0,-284.0);
glVertex3f(220.0,170.0,-284.0);
glVertex3f(200.0,170.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(220.0,160.0,-284.0);
glVertex3f(240.0,160.0,-294.0);
glVertex3f(240.0,170.0,-294.0);
glVertex3f(220.0,170.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,160.0,-294.0);
glVertex3f(260.0,160.0,-309.0);
glVertex3f(260.0,170.0,-309.0);
glVertex3f(240.0,170.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,160.0,-309.0);
glVertex3f(280.0,160.0,-334.0);
glVertex3f(280.0,170.0,-334.0);
glVertex3f(260.0,170.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,160.0,-334.0);
glVertex3f(300.0,160.0,-364.0);
glVertex3f(300.0,170.0,-364.0);
glVertex3f(280.0,170.0,-334.0);
glEnd();
///////

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,150.0,-279.0);
glVertex3f(200.0,150.0,-279.0);
glVertex3f(200.0,160.0,-279.0);
glVertex3f(180.0,160.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,150.0,-279.0);
glVertex3f(220.0,150.0,-284.0);
glVertex3f(220.0,160.0,-284.0);
glVertex3f(200.0,160.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(220.0,150.0,-284.0);
glVertex3f(240.0,150.0,-294.0);
glVertex3f(240.0,160.0,-294.0);
glVertex3f(220.0,160.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,150.0,-294.0);
glVertex3f(260.0,150.0,-309.0);
glVertex3f(260.0,160.0,-309.0);
glVertex3f(240.0,160.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,150.0,-309.0);
glVertex3f(280.0,150.0,-334.0);
glVertex3f(280.0,160.0,-334.0);
glVertex3f(260.0,160.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,150.0,-334.0);
glVertex3f(300.0,150.0,-364.0);
glVertex3f(300.0,160.0,-364.0);
glVertex3f(280.0,160.0,-334.0);
glEnd();

/////////

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,140.0,-279.0);
glVertex3f(200.0,140.0,-279.0);
glVertex3f(200.0,150.0,-279.0);
glVertex3f(180.0,150.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,140.0,-279.0);
glVertex3f(220.0,140.0,-284.0);
glVertex3f(220.0,150.0,-284.0);
glVertex3f(200.0,150.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(220.0,140.0,-284.0);
glVertex3f(240.0,140.0,-294.0);
glVertex3f(240.0,150.0,-294.0);
glVertex3f(220.0,150.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,140.0,-294.0);
glVertex3f(260.0,140.0,-309.0);
glVertex3f(260.0,150.0,-309.0);
glVertex3f(240.0,150.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,140.0,-309.0);
glVertex3f(280.0,140.0,-334.0);
glVertex3f(280.0,150.0,-334.0);
glVertex3f(260.0,150.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,140.0,-334.0);
glVertex3f(300.0,140.0,-364.0);
glVertex3f(300.0,150.0,-364.0);
glVertex3f(280.0,150.0,-334.0);
glEnd();

/////


glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(180.0,130.0,-279.0);
glVertex3f(200.0,130.0,-279.0);
glVertex3f(200.0,140.0,-279.0);
glVertex3f(180.0,140.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(200.0,130.0,-279.0);
glVertex3f(220.0,130.0,-284.0);
glVertex3f(220.0,140.0,-284.0);
glVertex3f(200.0,140.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(220.0,130.0,-284.0);
glVertex3f(240.0,130.0,-294.0);
glVertex3f(240.0,140.0,-294.0);
glVertex3f(220.0,140.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,130.0,-294.0);
glVertex3f(260.0,130.0,-309.0);
glVertex3f(260.0,140.0,-309.0);
glVertex3f(240.0,140.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,130.0,-309.0);
glVertex3f(280.0,130.0,-334.0);
glVertex3f(280.0,140.0,-334.0);
glVertex3f(260.0,140.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,130.0,-334.0);
glVertex3f(300.0,130.0,-364.0);
glVertex3f(300.0,140.0,-364.0);
glVertex3f(280.0,140.0,-334.0);
glEnd();
////////////



glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,120.0,-279.0);
glVertex3f(200.0,120.0,-279.0);
glVertex3f(200.0,130.0,-279.0);
glVertex3f(180.0,130.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,120.0,-279.0);
glVertex3f(220.0,120.0,-284.0);
glVertex3f(220.0,130.0,-284.0);
glVertex3f(200.0,130.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(220.0,120.0,-284.0);
glVertex3f(240.0,120.0,-294.0);
glVertex3f(240.0,130.0,-294.0);
glVertex3f(220.0,130.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,120.0,-294.0);
glVertex3f(260.0,120.0,-309.0);
glVertex3f(260.0,130.0,-309.0);
glVertex3f(240.0,130.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,120.0,-309.0);
glVertex3f(280.0,120.0,-334.0);
glVertex3f(280.0,130.0,-334.0);
glVertex3f(260.0,130.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,120.0,-334.0);
glVertex3f(300.0,120.0,-364.0);
glVertex3f(300.0,130.0,-364.0);
glVertex3f(280.0,130.0,-334.0);
glEnd();

/////////

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,110.0,-279.0);
glVertex3f(200.0,110.0,-279.0);
glVertex3f(200.0,120.0,-279.0);
glVertex3f(180.0,120.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,110.0,-279.0);
glVertex3f(220.0,110.0,-284.0);
glVertex3f(220.0,120.0,-284.0);
glVertex3f(200.0,120.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(220.0,110.0,-284.0);
glVertex3f(240.0,110.0,-294.0);
glVertex3f(240.0,120.0,-294.0);
glVertex3f(220.0,120.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,110.0,-294.0);
glVertex3f(260.0,110.0,-309.0);
glVertex3f(260.0,120.0,-309.0);
glVertex3f(240.0,120.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,110.0,-309.0);
glVertex3f(280.0,110.0,-334.0);
glVertex3f(280.0,120.0,-334.0);
glVertex3f(260.0,120.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,110.0,-334.0);
glVertex3f(300.0,110.0,-364.0);
glVertex3f(300.0,120.0,-364.0);
glVertex3f(280.0,120.0,-334.0);
glEnd();

/////


glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(180.0,100.0,-279.0);
glVertex3f(200.0,100.0,-279.0);
glVertex3f(200.0,110.0,-279.0);
glVertex3f(180.0,110.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(200.0,100.0,-279.0);
glVertex3f(220.0,100.0,-284.0);
glVertex3f(220.0,110.0,-284.0);
glVertex3f(200.0,110.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(220.0,100.0,-284.0);
glVertex3f(240.0,100.0,-294.0);
glVertex3f(240.0,110.0,-294.0);
glVertex3f(220.0,110.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,100.0,-294.0);
glVertex3f(260.0,100.0,-309.0);
glVertex3f(260.0,110.0,-309.0);
glVertex3f(240.0,110.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,100.0,-309.0);
glVertex3f(280.0,100.0,-334.0);
glVertex3f(280.0,110.0,-334.0);
glVertex3f(260.0,110.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,100.0,-334.0);
glVertex3f(300.0,100.0,-364.0);
glVertex3f(300.0,110.0,-364.0);
glVertex3f(280.0,110.0,-334.0);
glEnd();

////////////////////////////////////////////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(18, 18, 12);
glVertex3f(180.0,90.0,-279.0);
glVertex3f(200.0,90.0,-279.0);
glVertex3f(200.0,100.0,-279.0);
glVertex3f(180.0,100.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 18, 12);
glVertex3f(200.0,90.0,-279.0);
glVertex3f(220.0,90.0,-284.0);
glVertex3f(220.0,100.0,-284.0);
glVertex3f(200.0,100.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(220.0,90.0,-284.0);
glVertex3f(240.0,90.0,-294.0);
glVertex3f(240.0,100.0,-294.0);
glVertex3f(220.0,100.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,90.0,-294.0);
glVertex3f(260.0,90.0,-309.0);
glVertex3f(260.0,100.0,-309.0);
glVertex3f(240.0,100.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,90.0,-309.0);
glVertex3f(280.0,90.0,-334.0);
glVertex3f(280.0,100.0,-334.0);
glVertex3f(260.0,100.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,90.0,-334.0);
glVertex3f(300.0,90.0,-364.0);
glVertex3f(300.0,100.0,-364.0);
glVertex3f(280.0,100.0,-334.0);
glEnd();

///////////////////////////////////////////////////


glBegin(GL_QUADS);
glColor3f(18, 18, 12);
glVertex3f(180.0,80.0,-279.0);
glVertex3f(200.0,80.0,-279.0);
glVertex3f(200.0,90.0,-279.0);
glVertex3f(180.0,90.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 18, 12);
glVertex3f(200.0,80.0,-279.0);
glVertex3f(220.0,80.0,-284.0);
glVertex3f(220.0,90.0,-284.0);
glVertex3f(200.0,90.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(220.0,80.0,-284.0);
glVertex3f(240.0,80.0,-294.0);
glVertex3f(240.0,90.0,-294.0);
glVertex3f(220.0,90.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(240.0,80.0,-294.0);
glVertex3f(260.0,80.0,-309.0);
glVertex3f(260.0,90.0,-309.0);
glVertex3f(240.0,90.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(260.0,80.0,-309.0);
glVertex3f(280.0,80.0,-334.0);
glVertex3f(280.0,90.0,-334.0);
glVertex3f(260.0,90.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,80.0,-334.0);
glVertex3f(300.0,80.0,-364.0);
glVertex3f(300.0,90.0,-364.0);
glVertex3f(280.0,90.0,-334.0);
glEnd();

/////////////////////////////////////////////////////////////



glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(180.0,70.0,-279.0);
glVertex3f(200.0,70.0,-279.0);
glVertex3f(200.0,80.0,-279.0);
glVertex3f(180.0,80.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(200.0,70.0,-279.0);
glVertex3f(220.0,70.0,-284.0);
glVertex3f(220.0,80.0,-284.0);
glVertex3f(200.0,80.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(220.0,70.0,-284.0);
glVertex3f(240.0,70.0,-294.0);
glVertex3f(240.0,80.0,-294.0);
glVertex3f(220.0,80.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,70.0,-294.0);
glVertex3f(260.0,70.0,-309.0);
glVertex3f(260.0,80.0,-309.0);
glVertex3f(240.0,80.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,70.0,-309.0);
glVertex3f(280.0,70.0,-334.0);
glVertex3f(280.0,80.0,-334.0);
glVertex3f(260.0,80.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,70.0,-334.0);
glVertex3f(300.0,70.0,-364.0);
glVertex3f(300.0,80.0,-364.0);
glVertex3f(280.0,80.0,-334.0);
glEnd();

///////////////////////////////////////////////////


glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,60.0,-279.0);
glVertex3f(200.0,60.0,-279.0);
glVertex3f(200.0,70.0,-279.0);
glVertex3f(180.0,70.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,60.0,-279.0);
glVertex3f(220.0,60.0,-284.0);
glVertex3f(220.0,70.0,-284.0);
glVertex3f(200.0,70.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(19, 12, 12);
glVertex3f(220.0,60.0,-284.0);
glVertex3f(240.0,60.0,-294.0);
glVertex3f(240.0,70.0,-294.0);
glVertex3f(220.0,70.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,60.0,-294.0);
glVertex3f(260.0,60.0,-309.0);
glVertex3f(260.0,70.0,-309.0);
glVertex3f(240.0,70.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,60.0,-309.0);
glVertex3f(280.0,60.0,-334.0);
glVertex3f(280.0,70.0,-334.0);
glVertex3f(260.0,70.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,60.0,-334.0);
glVertex3f(300.0,60.0,-364.0);
glVertex3f(300.0,70.0,-364.0);
glVertex3f(280.0,70.0,-334.0);
glEnd();

/////////////////////////////////////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,50.0,-279.0);
glVertex3f(200.0,50.0,-279.0);
glVertex3f(200.0,60.0,-279.0);
glVertex3f(180.0,60.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,50.0,-279.0);
glVertex3f(220.0,50.0,-284.0);
glVertex3f(220.0,60.0,-284.0);
glVertex3f(200.0,60.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(220.0,50.0,-284.0);
glVertex3f(240.0,50.0,-294.0);
glVertex3f(240.0,60.0,-294.0);
glVertex3f(220.0,60.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(240.0,50.0,-294.0);
glVertex3f(260.0,50.0,-309.0);
glVertex3f(260.0,60.0,-309.0);
glVertex3f(240.0,60.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(260.0,50.0,-309.0);
glVertex3f(280.0,50.0,-334.0);
glVertex3f(280.0,60.0,-334.0);
glVertex3f(260.0,60.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,50.0,-334.0);
glVertex3f(300.0,50.0,-364.0);
glVertex3f(300.0,60.0,-364.0);
glVertex3f(280.0,60.0,-334.0);
glEnd();
////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(180.0,40.0,-279.0);
glVertex3f(200.0,40.0,-279.0);
glVertex3f(200.0,50.0,-279.0);
glVertex3f(180.0,50.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(200.0,40.0,-279.0);
glVertex3f(220.0,40.0,-284.0);
glVertex3f(220.0,50.0,-284.0);
glVertex3f(200.0,50.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(220.0,40.0,-284.0);
glVertex3f(240.0,40.0,-294.0);
glVertex3f(240.0,50.0,-294.0);
glVertex3f(220.0,50.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,40.0,-294.0);
glVertex3f(260.0,40.0,-309.0);
glVertex3f(260.0,50.0,-309.0);
glVertex3f(240.0,50.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,40.0,-309.0);
glVertex3f(280.0,40.0,-334.0);
glVertex3f(280.0,50.0,-334.0);
glVertex3f(260.0,50.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,40.0,-334.0);
glVertex3f(300.0,40.0,-364.0);
glVertex3f(300.0,50.0,-364.0);
glVertex3f(280.0,50.0,-334.0);
glEnd();

/////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,50.0,-279.0);
glVertex3f(200.0,50.0,-279.0);
glVertex3f(200.0,60.0,-279.0);
glVertex3f(180.0,60.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,50.0,-279.0);
glVertex3f(220.0,50.0,-284.0);
glVertex3f(220.0,60.0,-284.0);
glVertex3f(200.0,60.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(220.0,50.0,-284.0);
glVertex3f(240.0,50.0,-294.0);
glVertex3f(240.0,60.0,-294.0);
glVertex3f(220.0,60.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(240.0,50.0,-294.0);
glVertex3f(260.0,50.0,-309.0);
glVertex3f(260.0,60.0,-309.0);
glVertex3f(240.0,60.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(260.0,50.0,-309.0);
glVertex3f(280.0,50.0,-334.0);
glVertex3f(280.0,60.0,-334.0);
glVertex3f(260.0,60.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,50.0,-334.0);
glVertex3f(300.0,50.0,-364.0);
glVertex3f(300.0,60.0,-364.0);
glVertex3f(280.0,60.0,-334.0);
glEnd();
////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,30.0,-279.0);
glVertex3f(200.0,30.0,-279.0);
glVertex3f(200.0,40.0,-279.0);
glVertex3f(180.0,40.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,30.0,-279.0);
glVertex3f(220.0,30.0,-284.0);
glVertex3f(220.0,40.0,-284.0);
glVertex3f(200.0,40.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(220.0,30.0,-284.0);
glVertex3f(240.0,30.0,-294.0);
glVertex3f(240.0,40.0,-294.0);
glVertex3f(220.0,40.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,30.0,-294.0);
glVertex3f(260.0,30.0,-309.0);
glVertex3f(260.0,40.0,-309.0);
glVertex3f(240.0,40.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,30.0,-309.0);
glVertex3f(280.0,30.0,-334.0);
glVertex3f(280.0,40.0,-334.0);
glVertex3f(260.0,40.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,30.0,-334.0);
glVertex3f(300.0,30.0,-364.0);
glVertex3f(300.0,40.0,-364.0);
glVertex3f(280.0,40.0,-334.0);
glEnd();
////////////////////////////////////////////////////////////////////


glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,20.0,-279.0);
glVertex3f(200.0,20.0,-279.0);
glVertex3f(200.0,30.0,-279.0);
glVertex3f(180.0,30.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,20.0,-279.0);
glVertex3f(220.0,20.0,-284.0);
glVertex3f(220.0,30.0,-284.0);
glVertex3f(200.0,30.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(220.0,20.0,-284.0);
glVertex3f(240.0,20.0,-294.0);
glVertex3f(240.0,30.0,-294.0);
glVertex3f(220.0,30.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(240.0,20.0,-294.0);
glVertex3f(260.0,20.0,-309.0);
glVertex3f(260.0,30.0,-309.0);
glVertex3f(240.0,30.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(260.0,20.0,-309.0);
glVertex3f(280.0,20.0,-334.0);
glVertex3f(280.0,30.0,-334.0);
glVertex3f(260.0,30.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,20.0,-334.0);
glVertex3f(300.0,20.0,-364.0);
glVertex3f(300.0,30.0,-364.0);
glVertex3f(280.0,30.0,-334.0);
glEnd();

//////////////////////////////////////////////////////



glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(180.0,10.0,-279.0);
glVertex3f(200.0,10.0,-279.0);
glVertex3f(200.0,20.0,-279.0);
glVertex3f(180.0,20.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(200.0,10.0,-279.0);
glVertex3f(220.0,10.0,-284.0);
glVertex3f(220.0,20.0,-284.0);
glVertex3f(200.0,20.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(220.0,10.0,-284.0);
glVertex3f(240.0,10.0,-294.0);
glVertex3f(240.0,20.0,-294.0);
glVertex3f(220.0,20.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,10.0,-294.0);
glVertex3f(260.0,10.0,-309.0);
glVertex3f(260.0,20.0,-309.0);
glVertex3f(240.0,20.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,10.0,-309.0);
glVertex3f(280.0,10.0,-334.0);
glVertex3f(280.0,20.0,-334.0);
glVertex3f(260.0,20.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,10.0,-334.0);
glVertex3f(300.0,10.0,-364.0);
glVertex3f(300.0,20.0,-364.0);
glVertex3f(280.0,20.0,-334.0);
glEnd();

/////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,0.0,-279.0);
glVertex3f(200.0,0.0,-279.0);
glVertex3f(200.0,10.0,-279.0);
glVertex3f(180.0,10.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,0.0,-279.0);
glVertex3f(220.0,0.0,-284.0);
glVertex3f(220.0,10.0,-284.0);
glVertex3f(200.0,10.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(220.0,0.0,-284.0);
glVertex3f(240.0,0.0,-294.0);
glVertex3f(240.0,10.0,-294.0);
glVertex3f(220.0,10.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,0.0,-294.0);
glVertex3f(260.0,0.0,-309.0);
glVertex3f(260.0,10.0,-309.0);
glVertex3f(240.0,10.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,0.0,-309.0);
glVertex3f(280.0,0.0,-334.0);
glVertex3f(280.0,10.0,-334.0);
glVertex3f(260.0,10.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,0.0,-334.0);
glVertex3f(300.0,0.0,-364.0);
glVertex3f(300.0,10.0,-364.0);
glVertex3f(280.0,10.0,-334.0);
glEnd();
///////////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(180.0,-10.0,-279.0);
glVertex3f(200.0,-10.0,-279.0);
glVertex3f(200.0,0.0,-279.0);
glVertex3f(180.0,0.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(200.0,-10.0,-279.0);
glVertex3f(220.0,-10.0,-284.0);
glVertex3f(220.0,0.0,-284.0);
glVertex3f(200.0,0.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18, 12, 12);
glVertex3f(220.0,-10.0,-284.0);
glVertex3f(240.0,-10.0,-294.0);
glVertex3f(240.0,0.0,-294.0);
glVertex3f(220.0,0.0,-284.0);
glEnd();

//
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(240.0,-10.0,-294.0);
glVertex3f(260.0,-10.0,-309.0);
glVertex3f(260.0,0.0,-309.0);
glVertex3f(240.0,0.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(260.0,-10.0,-309.0);
glVertex3f(280.0,-10.0,-334.0);
glVertex3f(280.0,0.0,-334.0);
glVertex3f(260.0,0.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(280.0,-10.0,-334.0);
glVertex3f(300.0,-10.0,-364.0);
glVertex3f(300.0,0.0,-364.0);
glVertex3f(280.0,0.0,-334.0);
glEnd();
//////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(180.0,290.0,-299.0);
glVertex3f(160.0,290.0,-304.0);
glVertex3f(160.0,300.0,-304.0);
glVertex3f(180.0,300.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(160.0,290.0,-304.0);
glVertex3f(140.0,290.0,-314.0);
glVertex3f(140.0,300.0,-314.0);
glVertex3f(160.0,300.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,290.0,-314.0);
glVertex3f(120.0,290.0,-329.0);
glVertex3f(120.0,300.0,-329.0);
glVertex3f(140.0,300.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,290.0,-329.0);
glVertex3f(100.0,290.0,-354.0);
glVertex3f(100.0,300.0,-354.0);
glVertex3f(120.0,300.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,290.0,-354.0);
glVertex3f(80.0,290.0,-384.0);
glVertex3f(80.0,300.0,-384.0);
glVertex3f(100.0,300.0,-354.0);
glEnd();
///////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,280.0,-299.0);
glVertex3f(160.0,280.0,-304.0);
glVertex3f(160.0,290.0,-304.0);
glVertex3f(180.0,290.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,280.0,-304.0);
glVertex3f(140.0,280.0,-314.0);
glVertex3f(140.0,290.0,-314.0);
glVertex3f(160.0,290.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(140.0,280.0,-314.0);
glVertex3f(120.0,280.0,-329.0);
glVertex3f(120.0,290.0,-329.0);
glVertex3f(140.0,290.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(120.0,280.0,-329.0);
glVertex3f(100.0,280.0,-354.0);
glVertex3f(100.0,290.0,-354.0);
glVertex3f(120.0,290.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(100.0,280.0,-354.0);
glVertex3f(80.0,280.0,-384.0);
glVertex3f(80.0,290.0,-384.0);
glVertex3f(100.0,290.0,-354.0);
glEnd();

//////////////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,270.0,-299.0);
glVertex3f(160.0,270.0,-304.0);
glVertex3f(160.0,280.0,-304.0);
glVertex3f(180.0,280.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,270.0,-304.0);
glVertex3f(140.0,270.0,-314.0);
glVertex3f(140.0,280.0,-314.0);
glVertex3f(160.0,280.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(140.0,270.0,-314.0);
glVertex3f(120.0,270.0,-329.0);
glVertex3f(120.0,280.0,-329.0);
glVertex3f(140.0,280.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,270.0,-329.0);
glVertex3f(100.0,270.0,-354.0);
glVertex3f(100.0,280.0,-354.0);
glVertex3f(120.0,280.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,270.0,-354.0);
glVertex3f(80.0,270.0,-384.0);
glVertex3f(80.0,280.0,-384.0);
glVertex3f(100.0,280.0,-354.0);
glEnd();

//////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,260.0,-299.0);
glVertex3f(160.0,260.0,-304.0);
glVertex3f(160.0,270.0,-304.0);
glVertex3f(180.0,270.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,260.0,-304.0);
glVertex3f(140.0,260.0,-314.0);
glVertex3f(140.0,270.0,-314.0);
glVertex3f(160.0,270.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,260.0,-314.0);
glVertex3f(120.0,260.0,-329.0);
glVertex3f(120.0,270.0,-329.0);
glVertex3f(140.0,270.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,260.0,-329.0);
glVertex3f(100.0,260.0,-354.0);
glVertex3f(100.0,270.0,-354.0);
glVertex3f(120.0,270.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,260.0,-354.0);
glVertex3f(80.0,260.0,-384.0);
glVertex3f(80.0,270.0,-384.0);
glVertex3f(100.0,270.0,-354.0);
glEnd();
////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,250.0,-299.0);
glVertex3f(160.0,250.0,-304.0);
glVertex3f(160.0,260.0,-304.0);
glVertex3f(180.0,260.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,250.0,-304.0);
glVertex3f(140.0,250.0,-314.0);
glVertex3f(140.0,260.0,-314.0);
glVertex3f(160.0,260.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(140.0,250.0,-314.0);
glVertex3f(120.0,250.0,-329.0);
glVertex3f(120.0,260.0,-329.0);
glVertex3f(140.0,260.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(120.0,250.0,-329.0);
glVertex3f(100.0,250.0,-354.0);
glVertex3f(100.0,260.0,-354.0);
glVertex3f(120.0,260.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(100.0,250.0,-354.0);
glVertex3f(80.0,250.0,-384.0);
glVertex3f(80.0,260.0,-384.0);
glVertex3f(100.0,260.0,-354.0);
glEnd();

/////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,240.0,-299.0);
glVertex3f(160.0,240.0,-304.0);
glVertex3f(160.0,250.0,-304.0);
glVertex3f(180.0,250.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,240.0,-304.0);
glVertex3f(140.0,240.0,-314.0);
glVertex3f(140.0,250.0,-314.0);
glVertex3f(160.0,250.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(140.0,240.0,-314.0);
glVertex3f(120.0,240.0,-329.0);
glVertex3f(120.0,250.0,-329.0);
glVertex3f(140.0,250.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,240.0,-329.0);
glVertex3f(100.0,240.0,-354.0);
glVertex3f(100.0,250.0,-354.0);
glVertex3f(120.0,250.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,240.0,-354.0);
glVertex3f(80.0,240.0,-384.0);
glVertex3f(80.0,250.0,-384.0);
glVertex3f(100.0,250.0,-354.0);
glEnd();
/////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,230.0,-299.0);
glVertex3f(160.0,230.0,-304.0);
glVertex3f(160.0,240.0,-304.0);
glVertex3f(180.0,240.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,230.0,-304.0);
glVertex3f(140.0,230.0,-314.0);
glVertex3f(140.0,240.0,-314.0);
glVertex3f(160.0,240.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,230.0,-314.0);
glVertex3f(120.0,230.0,-329.0);
glVertex3f(120.0,240.0,-329.0);
glVertex3f(140.0,240.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(120.0,230.0,-329.0);
glVertex3f(100.0,230.0,-354.0);
glVertex3f(100.0,240.0,-354.0);
glVertex3f(120.0,240.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,230.0,-354.0);
glVertex3f(80.0,230.0,-384.0);
glVertex3f(80.0,240.0,-384.0);
glVertex3f(100.0,240.0,-354.0);
glEnd();

////////////////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,220.0,-299.0);
glVertex3f(160.0,220.0,-304.0);
glVertex3f(160.0,230.0,-304.0);
glVertex3f(180.0,230.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,220.0,-304.0);
glVertex3f(140.0,220.0,-314.0);
glVertex3f(140.0,230.0,-314.0);
glVertex3f(160.0,230.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(140.0,220.0,-314.0);
glVertex3f(120.0,220.0,-329.0);
glVertex3f(120.0,230.0,-329.0);
glVertex3f(140.0,230.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(120.0,220.0,-329.0);
glVertex3f(100.0,220.0,-354.0);
glVertex3f(100.0,230.0,-354.0);
glVertex3f(120.0,230.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(100.0,220.0,-354.0);
glVertex3f(80.0,220.0,-384.0);
glVertex3f(80.0,230.0,-384.0);
glVertex3f(100.0,230.0,-354.0);
glEnd();

///////////////////////////////////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,210.0,-299.0);
glVertex3f(160.0,210.0,-304.0);
glVertex3f(160.0,220.0,-304.0);
glVertex3f(180.0,220.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,210.0,-304.0);
glVertex3f(140.0,210.0,-314.0);
glVertex3f(140.0,220.0,-314.0);
glVertex3f(160.0,220.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(140.0,210.0,-314.0);
glVertex3f(120.0,210.0,-329.0);
glVertex3f(120.0,220.0,-329.0);
glVertex3f(140.0,220.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,210.0,-329.0);
glVertex3f(100.0,210.0,-354.0);
glVertex3f(100.0,220.0,-354.0);
glVertex3f(120.0,220.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,210.0,-354.0);
glVertex3f(80.0,210.0,-384.0);
glVertex3f(80.0,220.0,-384.0);
glVertex3f(100.0,220.0,-354.0);
glEnd();

///////////////////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,200.0,-299.0);
glVertex3f(160.0,200.0,-304.0);
glVertex3f(160.0,210.0,-304.0);
glVertex3f(180.0,210.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,200.0,-304.0);
glVertex3f(140.0,200.0,-314.0);
glVertex3f(140.0,210.0,-314.0);
glVertex3f(160.0,210.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,200.0,-314.0);
glVertex3f(120.0,200.0,-329.0);
glVertex3f(120.0,210.0,-329.0);
glVertex3f(140.0,210.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,200.0,-329.0);
glVertex3f(100.0,200.0,-354.0);
glVertex3f(100.0,210.0,-354.0);
glVertex3f(120.0,210.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,200.0,-354.0);
glVertex3f(80.0,200.0,-384.0);
glVertex3f(80.0,210.0,-384.0);
glVertex3f(100.0,210.0,-354.0);
glEnd();

////////////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,190.0,-299.0);
glVertex3f(160.0,190.0,-304.0);
glVertex3f(160.0,200.0,-304.0);
glVertex3f(180.0,200.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,190.0,-304.0);
glVertex3f(140.0,190.0,-314.0);
glVertex3f(140.0,200.0,-314.0);
glVertex3f(160.0,200.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(140.0,190.0,-314.0);
glVertex3f(120.0,190.0,-329.0);
glVertex3f(120.0,200.0,-329.0);
glVertex3f(140.0,200.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(120.0,190.0,-329.0);
glVertex3f(100.0,190.0,-354.0);
glVertex3f(100.0,200.0,-354.0);
glVertex3f(120.0,200.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(100.0,190.0,-354.0);
glVertex3f(80.0,190.0,-384.0);
glVertex3f(80.0,200.0,-384.0);
glVertex3f(100.0,200.0,-354.0);
glEnd();

///////////////////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,180.0,-299.0);
glVertex3f(160.0,180.0,-304.0);
glVertex3f(160.0,190.0,-304.0);
glVertex3f(180.0,190.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,180.0,-304.0);
glVertex3f(140.0,180.0,-314.0);
glVertex3f(140.0,190.0,-314.0);
glVertex3f(160.0,190.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(140.0,180.0,-314.0);
glVertex3f(120.0,180.0,-329.0);
glVertex3f(120.0,190.0,-329.0);
glVertex3f(140.0,190.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,180.0,-329.0);
glVertex3f(100.0,180.0,-354.0);
glVertex3f(100.0,190.0,-354.0);
glVertex3f(120.0,190.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,180.0,-354.0);
glVertex3f(80.0,180.0,-384.0);
glVertex3f(80.0,190.0,-384.0);
glVertex3f(100.0,190.0,-354.0);
glEnd();

////////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,170.0,-299.0);
glVertex3f(160.0,170.0,-304.0);
glVertex3f(160.0,180.0,-304.0);
glVertex3f(180.0,180.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,170.0,-304.0);
glVertex3f(140.0,170.0,-314.0);
glVertex3f(140.0,180.0,-314.0);
glVertex3f(160.0,180.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,170.0,-314.0);
glVertex3f(120.0,170.0,-329.0);
glVertex3f(120.0,180.0,-329.0);
glVertex3f(140.0,180.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,170.0,-329.0);
glVertex3f(100.0,170.0,-354.0);
glVertex3f(100.0,180.0,-354.0);
glVertex3f(120.0,180.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,170.0,-354.0);
glVertex3f(80.0,170.0,-384.0);
glVertex3f(80.0,180.0,-384.0);
glVertex3f(100.0,180.0,-354.0);
glEnd();
//////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,160.0,-299.0);
glVertex3f(160.0,160.0,-304.0);
glVertex3f(160.0,170.0,-304.0);
glVertex3f(180.0,170.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,160.0,-304.0);
glVertex3f(140.0,160.0,-314.0);
glVertex3f(140.0,170.0,-314.0);
glVertex3f(160.0,170.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(140.0,160.0,-314.0);
glVertex3f(120.0,160.0,-329.0);
glVertex3f(120.0,170.0,-329.0);
glVertex3f(140.0,170.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(120.0,160.0,-329.0);
glVertex3f(100.0,160.0,-354.0);
glVertex3f(100.0,170.0,-354.0);
glVertex3f(120.0,170.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(100.0,160.0,-354.0);
glVertex3f(80.0,160.0,-384.0);
glVertex3f(80.0,170.0,-384.0);
glVertex3f(100.0,170.0,-354.0);
glEnd();
////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,150.0,-299.0);
glVertex3f(160.0,150.0,-304.0);
glVertex3f(160.0,160.0,-304.0);
glVertex3f(180.0,160.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,150.0,-304.0);
glVertex3f(140.0,150.0,-314.0);
glVertex3f(140.0,160.0,-314.0);
glVertex3f(160.0,160.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,150.0,-314.0);
glVertex3f(120.0,150.0,-329.0);
glVertex3f(120.0,160.0,-329.0);
glVertex3f(140.0,160.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,150.0,-329.0);
glVertex3f(100.0,150.0,-354.0);
glVertex3f(100.0,160.0,-354.0);
glVertex3f(120.0,160.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,150.0,-354.0);
glVertex3f(80.0,150.0,-384.0);
glVertex3f(80.0,160.0,-384.0);
glVertex3f(100.0,160.0,-354.0);
glEnd();

//////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,140.0,-299.0);
glVertex3f(160.0,140.0,-304.0);
glVertex3f(160.0,150.0,-304.0);
glVertex3f(180.0,150.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(160.0,140.0,-304.0);
glVertex3f(140.0,140.0,-314.0);
glVertex3f(140.0,150.0,-314.0);
glVertex3f(160.0,150.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,140.0,-314.0);
glVertex3f(120.0,140.0,-329.0);
glVertex3f(120.0,150.0,-329.0);
glVertex3f(140.0,150.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,140.0,-329.0);
glVertex3f(100.0,140.0,-354.0);
glVertex3f(100.0,150.0,-354.0);
glVertex3f(120.0,150.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,140.0,-354.0);
glVertex3f(80.0,140.0,-384.0);
glVertex3f(80.0,150.0,-384.0);
glVertex3f(100.0,150.0,-354.0);
glEnd();
/////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,130.0,-299.0);
glVertex3f(160.0,130.0,-304.0);
glVertex3f(160.0,140.0,-304.0);
glVertex3f(180.0,140.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,130.0,-304.0);
glVertex3f(140.0,130.0,-314.0);
glVertex3f(140.0,140.0,-314.0);
glVertex3f(160.0,140.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(140.0,130.0,-314.0);
glVertex3f(120.0,130.0,-329.0);
glVertex3f(120.0,140.0,-329.0);
glVertex3f(140.0,140.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(120.0,130.0,-329.0);
glVertex3f(100.0,130.0,-354.0);
glVertex3f(100.0,140.0,-354.0);
glVertex3f(120.0,140.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(100.0,130.0,-354.0);
glVertex3f(80.0,130.0,-384.0);
glVertex3f(80.0,140.0,-384.0);
glVertex3f(100.0,140.0,-354.0);
glEnd();
//////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,120.0,-299.0);
glVertex3f(160.0,120.0,-304.0);
glVertex3f(160.0,130.0,-304.0);
glVertex3f(180.0,130.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,120.0,-304.0);
glVertex3f(140.0,120.0,-314.0);
glVertex3f(140.0,130.0,-314.0);
glVertex3f(160.0,130.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,120.0,-314.0);
glVertex3f(120.0,120.0,-329.0);
glVertex3f(120.0,130.0,-329.0);
glVertex3f(140.0,130.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,120.0,-329.0);
glVertex3f(100.0,120.0,-354.0);
glVertex3f(100.0,130.0,-354.0);
glVertex3f(120.0,130.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,120.0,-354.0);
glVertex3f(80.0,120.0,-384.0);
glVertex3f(80.0,130.0,-384.0);
glVertex3f(100.0,130.0,-354.0);
glEnd();
//////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,110.0,-299.0);
glVertex3f(160.0,110.0,-304.0);
glVertex3f(160.0,120.0,-304.0);
glVertex3f(180.0,120.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(160.0,110.0,-304.0);
glVertex3f(140.0,110.0,-314.0);
glVertex3f(140.0,120.0,-314.0);
glVertex3f(160.0,120.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,110.0,-314.0);
glVertex3f(120.0,110.0,-329.0);
glVertex3f(120.0,120.0,-329.0);
glVertex3f(140.0,120.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,110.0,-329.0);
glVertex3f(100.0,110.0,-354.0);
glVertex3f(100.0,120.0,-354.0);
glVertex3f(120.0,120.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,110.0,-354.0);
glVertex3f(80.0,110.0,-384.0);
glVertex3f(80.0,120.0,-384.0);
glVertex3f(100.0,120.0,-354.0);
glEnd();

//////////////////////////////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,100.0,-299.0);
glVertex3f(160.0,100.0,-304.0);
glVertex3f(160.0,110.0,-304.0);
glVertex3f(180.0,110.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,100.0,-304.0);
glVertex3f(140.0,100.0,-314.0);
glVertex3f(140.0,110.0,-314.0);
glVertex3f(160.0,110.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(140.0,100.0,-314.0);
glVertex3f(120.0,100.0,-329.0);
glVertex3f(120.0,110.0,-329.0);
glVertex3f(140.0,110.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(120.0,100.0,-329.0);
glVertex3f(100.0,100.0,-354.0);
glVertex3f(100.0,110.0,-354.0);
glVertex3f(120.0,110.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(100.0,100.0,-354.0);
glVertex3f(80.0,100.0,-384.0);
glVertex3f(80.0,110.0,-384.0);
glVertex3f(100.0,110.0,-354.0);
glEnd();

///////////////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,90.0,-299.0);
glVertex3f(160.0,90.0,-304.0);
glVertex3f(160.0,100.0,-304.0);
glVertex3f(180.0,100.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,90.0,-304.0);
glVertex3f(140.0,90.0,-314.0);
glVertex3f(140.0,100.0,-314.0);
glVertex3f(160.0,100.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,90.0,-314.0);
glVertex3f(120.0,90.0,-329.0);
glVertex3f(120.0,100.0,-329.0);
glVertex3f(140.0,100.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,90.0,-329.0);
glVertex3f(100.0,90.0,-354.0);
glVertex3f(100.0,100.0,-354.0);
glVertex3f(120.0,100.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,90.0,-354.0);
glVertex3f(80.0,90.0,-384.0);
glVertex3f(80.0,100.0,-384.0);
glVertex3f(100.0,100.0,-354.0);
glEnd();
//////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,80.0,-299.0);
glVertex3f(160.0,80.0,-304.0);
glVertex3f(160.0,90.0,-304.0);
glVertex3f(180.0,90.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(160.0,80.0,-304.0);
glVertex3f(140.0,80.0,-314.0);
glVertex3f(140.0,90.0,-314.0);
glVertex3f(160.0,90.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,80.0,-314.0);
glVertex3f(120.0,80.0,-329.0);
glVertex3f(120.0,90.0,-329.0);
glVertex3f(140.0,90.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,80.0,-329.0);
glVertex3f(100.0,80.0,-354.0);
glVertex3f(100.0,90.0,-354.0);
glVertex3f(120.0,90.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,80.0,-354.0);
glVertex3f(80.0,80.0,-384.0);
glVertex3f(80.0,90.0,-384.0);
glVertex3f(100.0,90.0,-354.0);
/////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,70.0,-299.0);
glVertex3f(160.0,70.0,-304.0);
glVertex3f(160.0,80.0,-304.0);
glVertex3f(180.0,80.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,70.0,-304.0);
glVertex3f(140.0,70.0,-314.0);
glVertex3f(140.0,80.0,-314.0);
glVertex3f(160.0,80.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(140.0,70.0,-314.0);
glVertex3f(120.0,70.0,-329.0);
glVertex3f(120.0,80.0,-329.0);
glVertex3f(140.0,80.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(120.0,70.0,-329.0);
glVertex3f(100.0,70.0,-354.0);
glVertex3f(100.0,80.0,-354.0);
glVertex3f(120.0,80.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(100.0,70.0,-354.0);
glVertex3f(80.0,70.0,-384.0);
glVertex3f(80.0,80.0,-384.0);
glVertex3f(100.0,80.0,-354.0);
glEnd();
////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,60.0,-299.0);
glVertex3f(160.0,60.0,-304.0);
glVertex3f(160.0,70.0,-304.0);
glVertex3f(180.0,70.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,60.0,-304.0);
glVertex3f(140.0,60.0,-314.0);
glVertex3f(140.0,70.0,-314.0);
glVertex3f(160.0,70.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,60.0,-314.0);
glVertex3f(120.0,60.0,-329.0);
glVertex3f(120.0,70.0,-329.0);
glVertex3f(140.0,70.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,60.0,-329.0);
glVertex3f(100.0,60.0,-354.0);
glVertex3f(100.0,70.0,-354.0);
glVertex3f(120.0,70.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,60.0,-354.0);
glVertex3f(80.0,60.0,-384.0);
glVertex3f(80.0,70.0,-384.0);
glVertex3f(100.0,70.0,-354.0);
glEnd();
///////////////////////////////////////////////////////////////////

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,50.0,-299.0);
glVertex3f(160.0,50.0,-304.0);
glVertex3f(160.0,60.0,-304.0);
glVertex3f(180.0,60.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(160.0,50.0,-304.0);
glVertex3f(140.0,50.0,-314.0);
glVertex3f(140.0,60.0,-314.0);
glVertex3f(160.0,60.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,50.0,-314.0);
glVertex3f(120.0,50.0,-329.0);
glVertex3f(120.0,60.0,-329.0);
glVertex3f(140.0,60.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,50.0,-329.0);
glVertex3f(100.0,50.0,-354.0);
glVertex3f(100.0,60.0,-354.0);
glVertex3f(120.0,60.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,50.0,-354.0);
glVertex3f(80.0,50.0,-384.0);
glVertex3f(80.0,60.0,-384.0);
glVertex3f(100.0,60.0,-354.0);
glEnd();

/////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,40.0,-299.0);
glVertex3f(160.0,40.0,-304.0);
glVertex3f(160.0,50.0,-304.0);
glVertex3f(180.0,50.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,40.0,-304.0);
glVertex3f(140.0,40.0,-314.0);
glVertex3f(140.0,50.0,-314.0);
glVertex3f(160.0,50.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(140.0,40.0,-314.0);
glVertex3f(120.0,40.0,-329.0);
glVertex3f(120.0,50.0,-329.0);
glVertex3f(140.0,50.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(120.0,40.0,-329.0);
glVertex3f(100.0,40.0,-354.0);
glVertex3f(100.0,50.0,-354.0);
glVertex3f(120.0,50.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(100.0,40.0,-354.0);
glVertex3f(80.0,40.0,-384.0);
glVertex3f(80.0,50.0,-384.0);
glVertex3f(100.0,50.0,-354.0);
glEnd();
////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,30.0,-299.0);
glVertex3f(160.0,30.0,-304.0);
glVertex3f(160.0,40.0,-304.0);
glVertex3f(180.0,40.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,30.0,-304.0);
glVertex3f(140.0,30.0,-314.0);
glVertex3f(140.0,40.0,-314.0);
glVertex3f(160.0,40.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,30.0,-314.0);
glVertex3f(120.0,30.0,-329.0);
glVertex3f(120.0,40.0,-329.0);
glVertex3f(140.0,40.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,30.0,-329.0);
glVertex3f(100.0,30.0,-354.0);
glVertex3f(100.0,40.0,-354.0);
glVertex3f(120.0,40.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,30.0,-354.0);
glVertex3f(80.0,30.0,-384.0);
glVertex3f(80.0,40.0,-384.0);
glVertex3f(100.0,40.0,-354.0);
glEnd();
///////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,20.0,-299.0);
glVertex3f(160.0,20.0,-304.0);
glVertex3f(160.0,30.0,-304.0);
glVertex3f(180.0,30.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(160.0,20.0,-304.0);
glVertex3f(140.0,20.0,-314.0);
glVertex3f(140.0,30.0,-314.0);
glVertex3f(160.0,30.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,20.0,-314.0);
glVertex3f(120.0,20.0,-329.0);
glVertex3f(120.0,30.0,-329.0);
glVertex3f(140.0,30.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,20.0,-329.0);
glVertex3f(100.0,20.0,-354.0);
glVertex3f(100.0,30.0,-354.0);
glVertex3f(120.0,30.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,20.0,-354.0);
glVertex3f(80.0,20.0,-384.0);
glVertex3f(80.0,30.0,-384.0);
glVertex3f(100.0,30.0,-354.0);
glEnd();
////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,10.0,-299.0);
glVertex3f(160.0,10.0,-304.0);
glVertex3f(160.0,20.0,-304.0);
glVertex3f(180.0,20.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,10.0,-304.0);
glVertex3f(140.0,10.0,-314.0);
glVertex3f(140.0,20.0,-314.0);
glVertex3f(160.0,20.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(140.0,10.0,-314.0);
glVertex3f(120.0,10.0,-329.0);
glVertex3f(120.0,20.0,-329.0);
glVertex3f(140.0,20.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(120.0,10.0,-329.0);
glVertex3f(100.0,10.0,-354.0);
glVertex3f(100.0,20.0,-354.0);
glVertex3f(120.0,20.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(100.0,10.0,-354.0);
glVertex3f(80.0,10.0,-384.0);
glVertex3f(80.0,20.0,-384.0);
glVertex3f(100.0,20.0,-354.0);
glEnd();
///////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,0.0,-299.0);
glVertex3f(160.0,0.0,-304.0);
glVertex3f(160.0,10.0,-304.0);
glVertex3f(180.0,10.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(160.0,0.0,-304.0);
glVertex3f(140.0,0.0,-314.0);
glVertex3f(140.0,10.0,-314.0);
glVertex3f(160.0,10.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,0.0,-314.0);
glVertex3f(120.0,0.0,-329.0);
glVertex3f(120.0,10.0,-329.0);
glVertex3f(140.0,10.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,0.0,-329.0);
glVertex3f(100.0,0.0,-354.0);
glVertex3f(100.0,10.0,-354.0);
glVertex3f(120.0,10.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,0.0,-354.0);
glVertex3f(80.0,0.0,-384.0);
glVertex3f(80.0,10.0,-384.0);
glVertex3f(100.0,10.0,-354.0);
glEnd();
////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(180.0,-10.0,-299.0);
glVertex3f(160.0,-10.0,-304.0);
glVertex3f(160.0,0.0,-304.0);
glVertex3f(180.0,0.0,-299.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(160.0,-10.0,-304.0);
glVertex3f(140.0,-10.0,-314.0);
glVertex3f(140.0,0.0,-314.0);
glVertex3f(160.0,0.0,-304.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(140.0,-10.0,-314.0);
glVertex3f(120.0,-10.0,-329.0);
glVertex3f(120.0,0.0,-329.0);
glVertex3f(140.0,0.0,-314.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(120.0,-10.0,-329.0);
glVertex3f(100.0,-10.0,-354.0);
glVertex3f(100.0,0.0,-354.0);
glVertex3f(120.0,0.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.-10,0.0,-354.0);
glVertex3f(80.0,-10.0,-384.0);
glVertex3f(80.0,0.0,-384.0);
glVertex3f(100.0,0.0,-354.0);
glEnd();


//jendela gedung dua//
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,240.0,-254.0);
glVertex3f(20.0,240.0,-254.0);
glVertex3f(20.0,250.0,-254.0);
glVertex3f(0.0,250.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(20.0,240.0,-254.0);
glVertex3f(40.0,240.0,-259.0);
glVertex3f(40.0,250.0,-259.0);
glVertex3f(20.0,250.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(40.0,240.0,-259.0);
glVertex3f(60.0,240.0,-269.0);
glVertex3f(60.0,250.0,-269.0);
glVertex3f(40.0,250.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(60.0,240.0,-269.0);
glVertex3f(80.0,240.0,-284.0);
glVertex3f(80.0,250.0,-284.0);
glVertex3f(60.0,250.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(80.0,240.0,-284.0);
glVertex3f(100.0,240.0,-299.0);
glVertex3f(100.0,250.0,-299.0);
glVertex3f(80.0,250.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(100.0,240.0,-299.0);
glVertex3f(120.0,240.0,-329.0);
glVertex3f(120.0,250.0,-329.0);
glVertex3f(100.0,250.0,-299.0);
glEnd();
//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,240.0,-254.0);
glVertex3f(-20.0,240.0,-259.0);
glVertex3f(-20.0,250.0,-259.0);
glVertex3f(0.0,250.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,240.0,-259.0);
glVertex3f(-40.0,240.0,-269.0);
glVertex3f(-40.0,250.0,-269.0);
glVertex3f(-20.0,250.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,240.0,-269.0);
glVertex3f(-60.0,240.0,-284.0);
glVertex3f(-60.0,250.0,-284.0);
glVertex3f(-40.0,250.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,240.0,-284.0);
glVertex3f(-80.0,240.0,-299.0);
glVertex3f(-80.0,250.0,-299.0);
glVertex3f(-60.0,250.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,240.0,-299.0);
glVertex3f(-100.0,240.0,-329.0);
glVertex3f(-100.0,250.0,-329.0);
glVertex3f(-80.0,250.0,-299.0);
glEnd();
//////////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,230.0,-254.0);
glVertex3f(20.0,230.0,-254.0);
glVertex3f(20.0,240.0,-254.0);
glVertex3f(0.0,240.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,230.0,-254.0);
glVertex3f(40.0,230.0,-259.0);
glVertex3f(40.0,240.0,-259.0);
glVertex3f(20.0,240.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,230.0,-259.0);
glVertex3f(60.0,230.0,-269.0);
glVertex3f(60.0,240.0,-269.0);
glVertex3f(40.0,240.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,230.0,-269.0);
glVertex3f(80.0,230.0,-284.0);
glVertex3f(80.0,240.0,-284.0);
glVertex3f(60.0,240.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,230.0,-284.0);
glVertex3f(100.0,230.0,-299.0);
glVertex3f(100.0,240.0,-299.0);
glVertex3f(80.0,240.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(100.0,230.0,-299.0);
glVertex3f(120.0,230.0,-329.0);
glVertex3f(120.0,240.0,-329.0);
glVertex3f(100.0,240.0,-299.0);
glEnd();
//

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,230.0,-254.0);
glVertex3f(-20.0,230.0,-259.0);
glVertex3f(-20.0,240.0,-259.0);
glVertex3f(0.0,240.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-20.0,230.0,-259.0);
glVertex3f(-40.0,230.0,-269.0);
glVertex3f(-40.0,240.0,-269.0);
glVertex3f(-20.0,240.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-40.0,230.0,-269.0);
glVertex3f(-60.0,230.0,-284.0);
glVertex3f(-60.0,240.0,-284.0);
glVertex3f(-40.0,240.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-60.0,230.0,-284.0);
glVertex3f(-80.0,230.0,-299.0);
glVertex3f(-80.0,240.0,-299.0);
glVertex3f(-60.0,240.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-80.0,230.0,-299.0);
glVertex3f(-100.0,230.0,-329.0);
glVertex3f(-100.0,240.0,-329.0);
glVertex3f(-80.0,240.0,-299.0);
glEnd();
///////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,220.0,-254.0);
glVertex3f(20.0,220.0,-254.0);
glVertex3f(20.0,230.0,-254.0);
glVertex3f(0.0,230.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,220.0,-254.0);
glVertex3f(40.0,220.0,-259.0);
glVertex3f(40.0,230.0,-259.0);
glVertex3f(20.0,230.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,220.0,-259.0);
glVertex3f(60.0,220.0,-269.0);
glVertex3f(60.0,230.0,-269.0);
glVertex3f(40.0,230.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,220.0,-269.0);
glVertex3f(80.0,220.0,-284.0);
glVertex3f(80.0,230.0,-284.0);
glVertex3f(60.0,230.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,220.0,-284.0);
glVertex3f(100.0,220.0,-299.0);
glVertex3f(100.0,230.0,-299.0);
glVertex3f(80.0,230.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(100.0,220.0,-299.0);
glVertex3f(120.0,220.0,-329.0);
glVertex3f(120.0,230.0,-329.0);
glVertex3f(100.0,230.0,-299.0);
glEnd();
//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,220.0,-254.0);
glVertex3f(-20.0,220.0,-259.0);
glVertex3f(-20.0,230.0,-259.0);
glVertex3f(0.0,230.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,220.0,-259.0);
glVertex3f(-40.0,220.0,-269.0);
glVertex3f(-40.0,230.0,-269.0);
glVertex3f(-20.0,230.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,220.0,-269.0);
glVertex3f(-60.0,220.0,-284.0);
glVertex3f(-60.0,230.0,-284.0);
glVertex3f(-40.0,230.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,220.0,-284.0);
glVertex3f(-80.0,220.0,-299.0);
glVertex3f(-80.0,230.0,-299.0);
glVertex3f(-60.0,230.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,220.0,-299.0);
glVertex3f(-100.0,220.0,-329.0);
glVertex3f(-100.0,230.0,-329.0);
glVertex3f(-80.0,230.0,-299.0);
glEnd();
///////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,210.0,-254.0);
glVertex3f(20.0,210.0,-254.0);
glVertex3f(20.0,220.0,-254.0);
glVertex3f(0.0,220.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,210.0,-254.0);
glVertex3f(40.0,210.0,-259.0);
glVertex3f(40.0,220.0,-259.0);
glVertex3f(20.0,220.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,210.0,-259.0);
glVertex3f(60.0,210.0,-269.0);
glVertex3f(60.0,220.0,-269.0);
glVertex3f(40.0,220.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,210.0,-269.0);
glVertex3f(80.0,210.0,-284.0);
glVertex3f(80.0,220.0,-284.0);
glVertex3f(60.0,220.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,210.0,-284.0);
glVertex3f(100.0,210.0,-299.0);
glVertex3f(100.0,220.0,-299.0);
glVertex3f(80.0,220.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(100.0,210.0,-299.0);
glVertex3f(120.0,210.0,-329.0);
glVertex3f(120.0,220.0,-329.0);
glVertex3f(100.0,220.0,-299.0);
glEnd();
//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,210.0,-254.0);
glVertex3f(-20.0,210.0,-259.0);
glVertex3f(-20.0,220.0,-259.0);
glVertex3f(0.0,220.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,210.0,-259.0);
glVertex3f(-40.0,210.0,-269.0);
glVertex3f(-40.0,220.0,-269.0);
glVertex3f(-20.0,220.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,210.0,-269.0);
glVertex3f(-60.0,210.0,-284.0);
glVertex3f(-60.0,220.0,-284.0);
glVertex3f(-40.0,220.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,210.0,-284.0);
glVertex3f(-80.0,210.0,-299.0);
glVertex3f(-80.0,220.0,-299.0);
glVertex3f(-60.0,220.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,210.0,-299.0);
glVertex3f(-100.0,210.0,-329.0);
glVertex3f(-100.0,220.0,-329.0);
glVertex3f(-80.0,220.0,-299.0);
glEnd();
////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,200.0,-254.0);
glVertex3f(20.0,200.0,-254.0);
glVertex3f(20.0,210.0,-254.0);
glVertex3f(0.0,210.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,200.0,-254.0);
glVertex3f(40.0,200.0,-259.0);
glVertex3f(40.0,210.0,-259.0);
glVertex3f(20.0,210.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,200.0,-259.0);
glVertex3f(60.0,200.0,-269.0);
glVertex3f(60.0,210.0,-269.0);
glVertex3f(40.0,210.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,200.0,-269.0);
glVertex3f(80.0,200.0,-284.0);
glVertex3f(80.0,210.0,-284.0);
glVertex3f(60.0,210.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,200.0,-284.0);
glVertex3f(100.0,200.0,-299.0);
glVertex3f(100.0,210.0,-299.0);
glVertex3f(80.0,210.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(100.0,200.0,-299.0);
glVertex3f(120.0,200.0,-329.0);
glVertex3f(120.0,210.0,-329.0);
glVertex3f(100.0,210.0,-299.0);
glEnd();
//

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,200.0,-254.0);
glVertex3f(-20.0,200.0,-259.0);
glVertex3f(-20.0,210.0,-259.0);
glVertex3f(0.0,210.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-20.0,200.0,-259.0);
glVertex3f(-40.0,200.0,-269.0);
glVertex3f(-40.0,210.0,-269.0);
glVertex3f(-20.0,210.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-40.0,200.0,-269.0);
glVertex3f(-60.0,200.0,-284.0);
glVertex3f(-60.0,210.0,-284.0);
glVertex3f(-40.0,210.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-60.0,200.0,-284.0);
glVertex3f(-80.0,200.0,-299.0);
glVertex3f(-80.0,210.0,-299.0);
glVertex3f(-60.0,210.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-80.0,200.0,-299.0);
glVertex3f(-100.0,200.0,-329.0);
glVertex3f(-100.0,210.0,-329.0);
glVertex3f(-80.0,210.0,-299.0);
glEnd();
/////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,190.0,-254.0);
glVertex3f(20.0,190.0,-254.0);
glVertex3f(20.0,200.0,-254.0);
glVertex3f(0.0,200.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,190.0,-254.0);
glVertex3f(40.0,190.0,-259.0);
glVertex3f(40.0,200.0,-259.0);
glVertex3f(20.0,200.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,190.0,-259.0);
glVertex3f(60.0,190.0,-269.0);
glVertex3f(60.0,200.0,-269.0);
glVertex3f(40.0,200.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,190.0,-269.0);
glVertex3f(80.0,190.0,-284.0);
glVertex3f(80.0,200.0,-284.0);
glVertex3f(60.0,200.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,190.0,-284.0);
glVertex3f(100.0,190.0,-299.0);
glVertex3f(100.0,200.0,-299.0);
glVertex3f(80.0,200.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,190.0,-254.0);
glVertex3f(-20.0,190.0,-259.0);
glVertex3f(-20.0,200.0,-259.0);
glVertex3f(0.0,200.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,190.0,-259.0);
glVertex3f(-40.0,190.0,-269.0);
glVertex3f(-40.0,200.0,-269.0);
glVertex3f(-20.0,200.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,190.0,-269.0);
glVertex3f(-60.0,190.0,-284.0);
glVertex3f(-60.0,200.0,-284.0);
glVertex3f(-40.0,200.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,190.0,-284.0);
glVertex3f(-80.0,190.0,-299.0);
glVertex3f(-80.0,200.0,-299.0);
glVertex3f(-60.0,200.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,190.0,-299.0);
glVertex3f(-100.0,190.0,-329.0);
glVertex3f(-100.0,200.0,-329.0);
glVertex3f(-80.0,200.0,-299.0);
glEnd();
///////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,180.0,-254.0);
glVertex3f(20.0,180.0,-254.0);
glVertex3f(20.0,190.0,-254.0);
glVertex3f(0.0,190.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,180.0,-254.0);
glVertex3f(40.0,180.0,-259.0);
glVertex3f(40.0,190.0,-259.0);
glVertex3f(20.0,190.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,180.0,-259.0);
glVertex3f(60.0,180.0,-269.0);
glVertex3f(60.0,190.0,-269.0);
glVertex3f(40.0,190.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,180.0,-269.0);
glVertex3f(80.0,180.0,-284.0);
glVertex3f(80.0,190.0,-284.0);
glVertex3f(60.0,190.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,180.0,-284.0);
glVertex3f(100.0,180.0,-299.0);
glVertex3f(100.0,190.0,-299.0);
glVertex3f(80.0,190.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,180.0,-254.0);
glVertex3f(-20.0,180.0,-259.0);
glVertex3f(-20.0,190.0,-259.0);
glVertex3f(0.0,190.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,180.0,-259.0);
glVertex3f(-40.0,180.0,-269.0);
glVertex3f(-40.0,190.0,-269.0);
glVertex3f(-20.0,190.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,180.0,-269.0);
glVertex3f(-60.0,180.0,-284.0);
glVertex3f(-60.0,190.0,-284.0);
glVertex3f(-40.0,190.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,180.0,-284.0);
glVertex3f(-80.0,180.0,-299.0);
glVertex3f(-80.0,190.0,-299.0);
glVertex3f(-60.0,190.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,180.0,-299.0);
glVertex3f(-100.0,180.0,-329.0);
glVertex3f(-100.0,190.0,-329.0);
glVertex3f(-80.0,190.0,-299.0);
glEnd();
////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,170.0,-254.0);
glVertex3f(20.0,170.0,-254.0);
glVertex3f(20.0,180.0,-254.0);
glVertex3f(0.0,180.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,170.0,-254.0);
glVertex3f(40.0,170.0,-259.0);
glVertex3f(40.0,180.0,-259.0);
glVertex3f(20.0,180.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,170.0,-259.0);
glVertex3f(60.0,170.0,-269.0);
glVertex3f(60.0,180.0,-269.0);
glVertex3f(40.0,180.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,170.0,-269.0);
glVertex3f(80.0,170.0,-284.0);
glVertex3f(80.0,180.0,-284.0);
glVertex3f(60.0,180.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,170.0,-284.0);
glVertex3f(100.0,170.0,-299.0);
glVertex3f(100.0,180.0,-299.0);
glVertex3f(80.0,180.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,170.0,-254.0);
glVertex3f(-20.0,170.0,-259.0);
glVertex3f(-20.0,180.0,-259.0);
glVertex3f(0.0,180.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-20.0,170.0,-259.0);
glVertex3f(-40.0,170.0,-269.0);
glVertex3f(-40.0,180.0,-269.0);
glVertex3f(-20.0,180.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-40.0,170.0,-269.0);
glVertex3f(-60.0,170.0,-284.0);
glVertex3f(-60.0,180.0,-284.0);
glVertex3f(-40.0,180.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-60.0,170.0,-284.0);
glVertex3f(-80.0,170.0,-299.0);
glVertex3f(-80.0,180.0,-299.0);
glVertex3f(-60.0,180.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-80.0,170.0,-299.0);
glVertex3f(-100.0,170.0,-329.0);
glVertex3f(-100.0,180.0,-329.0);
glVertex3f(-80.0,180.0,-299.0);
glEnd();
/////////////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,160.0,-254.0);
glVertex3f(20.0,160.0,-254.0);
glVertex3f(20.0,170.0,-254.0);
glVertex3f(0.0,170.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,160.0,-254.0);
glVertex3f(40.0,160.0,-259.0);
glVertex3f(40.0,170.0,-259.0);
glVertex3f(20.0,170.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,160.0,-259.0);
glVertex3f(60.0,160.0,-269.0);
glVertex3f(60.0,170.0,-269.0);
glVertex3f(40.0,170.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,160.0,-269.0);
glVertex3f(80.0,160.0,-284.0);
glVertex3f(80.0,170.0,-284.0);
glVertex3f(60.0,170.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,160.0,-284.0);
glVertex3f(100.0,160.0,-299.0);
glVertex3f(100.0,170.0,-299.0);
glVertex3f(80.0,170.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,160.0,-254.0);
glVertex3f(-20.0,160.0,-259.0);
glVertex3f(-20.0,170.0,-259.0);
glVertex3f(0.0,170.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,160.0,-259.0);
glVertex3f(-40.0,160.0,-269.0);
glVertex3f(-40.0,170.0,-269.0);
glVertex3f(-20.0,170.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,160.0,-269.0);
glVertex3f(-60.0,160.0,-284.0);
glVertex3f(-60.0,170.0,-284.0);
glVertex3f(-40.0,170.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,160.0,-284.0);
glVertex3f(-80.0,160.0,-299.0);
glVertex3f(-80.0,170.0,-299.0);
glVertex3f(-60.0,170.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,160.0,-299.0);
glVertex3f(-100.0,160.0,-329.0);
glVertex3f(-100.0,170.0,-329.0);
glVertex3f(-80.0,170.0,-299.0);
glEnd();
///////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,150.0,-254.0);
glVertex3f(20.0,150.0,-254.0);
glVertex3f(20.0,160.0,-254.0);
glVertex3f(0.0,160.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,150.0,-254.0);
glVertex3f(40.0,150.0,-259.0);
glVertex3f(40.0,160.0,-259.0);
glVertex3f(20.0,160.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,150.0,-259.0);
glVertex3f(60.0,150.0,-269.0);
glVertex3f(60.0,160.0,-269.0);
glVertex3f(40.0,160.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,150.0,-269.0);
glVertex3f(80.0,150.0,-284.0);
glVertex3f(80.0,160.0,-284.0);
glVertex3f(60.0,160.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,150.0,-284.0);
glVertex3f(100.0,150.0,-299.0);
glVertex3f(100.0,160.0,-299.0);
glVertex3f(80.0,160.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,150.0,-254.0);
glVertex3f(-20.0,150.0,-259.0);
glVertex3f(-20.0,160.0,-259.0);
glVertex3f(0.0,160.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,150.0,-259.0);
glVertex3f(-40.0,150.0,-269.0);
glVertex3f(-40.0,160.0,-269.0);
glVertex3f(-20.0,160.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,150.0,-269.0);
glVertex3f(-60.0,150.0,-284.0);
glVertex3f(-60.0,160.0,-284.0);
glVertex3f(-40.0,160.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,150.0,-284.0);
glVertex3f(-80.0,150.0,-299.0);
glVertex3f(-80.0,160.0,-299.0);
glVertex3f(-60.0,160.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,150.0,-299.0);
glVertex3f(-100.0,150.0,-329.0);
glVertex3f(-100.0,160.0,-329.0);
glVertex3f(-80.0,160.0,-299.0);
glEnd();
/////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,140.0,-254.0);
glVertex3f(20.0,140.0,-254.0);
glVertex3f(20.0,150.0,-254.0);
glVertex3f(0.0,150.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,140.0,-254.0);
glVertex3f(40.0,140.0,-259.0);
glVertex3f(40.0,150.0,-259.0);
glVertex3f(20.0,150.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,140.0,-259.0);
glVertex3f(60.0,140.0,-269.0);
glVertex3f(60.0,150.0,-269.0);
glVertex3f(40.0,150.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,140.0,-269.0);
glVertex3f(80.0,140.0,-284.0);
glVertex3f(80.0,150.0,-284.0);
glVertex3f(60.0,150.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,140.0,-284.0);
glVertex3f(100.0,140.0,-299.0);
glVertex3f(100.0,150.0,-299.0);
glVertex3f(80.0,150.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,140.0,-254.0);
glVertex3f(-20.0,140.0,-259.0);
glVertex3f(-20.0,150.0,-259.0);
glVertex3f(0.0,150.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-20.0,140.0,-259.0);
glVertex3f(-40.0,140.0,-269.0);
glVertex3f(-40.0,150.0,-269.0);
glVertex3f(-20.0,150.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-40.0,140.0,-269.0);
glVertex3f(-60.0,140.0,-284.0);
glVertex3f(-60.0,150.0,-284.0);
glVertex3f(-40.0,150.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-60.0,140.0,-284.0);
glVertex3f(-80.0,140.0,-299.0);
glVertex3f(-80.0,150.0,-299.0);
glVertex3f(-60.0,150.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-80.0,140.0,-299.0);
glVertex3f(-100.0,140.0,-329.0);
glVertex3f(-100.0,150.0,-329.0);
glVertex3f(-80.0,150.0,-299.0);
glEnd();
//////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,130.0,-254.0);
glVertex3f(20.0,130.0,-254.0);
glVertex3f(20.0,140.0,-254.0);
glVertex3f(0.0,140.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,130.0,-254.0);
glVertex3f(40.0,130.0,-259.0);
glVertex3f(40.0,140.0,-259.0);
glVertex3f(20.0,140.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,130.0,-259.0);
glVertex3f(60.0,130.0,-269.0);
glVertex3f(60.0,140.0,-269.0);
glVertex3f(40.0,140.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,130.0,-269.0);
glVertex3f(80.0,130.0,-284.0);
glVertex3f(80.0,140.0,-284.0);
glVertex3f(60.0,140.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,130.0,-284.0);
glVertex3f(100.0,130.0,-299.0);
glVertex3f(100.0,140.0,-299.0);
glVertex3f(80.0,140.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,130.0,-254.0);
glVertex3f(-20.0,130.0,-259.0);
glVertex3f(-20.0,140.0,-259.0);
glVertex3f(0.0,140.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,130.0,-259.0);
glVertex3f(-40.0,130.0,-269.0);
glVertex3f(-40.0,140.0,-269.0);
glVertex3f(-20.0,140.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,130.0,-269.0);
glVertex3f(-60.0,130.0,-284.0);
glVertex3f(-60.0,140.0,-284.0);
glVertex3f(-40.0,140.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,130.0,-284.0);
glVertex3f(-80.0,130.0,-299.0);
glVertex3f(-80.0,140.0,-299.0);
glVertex3f(-60.0,140.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,130.0,-299.0);
glVertex3f(-100.0,130.0,-329.0);
glVertex3f(-100.0,140.0,-329.0);
glVertex3f(-80.0,140.0,-299.0);
glEnd();

///////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,120.0,-254.0);
glVertex3f(20.0,120.0,-254.0);
glVertex3f(20.0,130.0,-254.0);
glVertex3f(0.0,130.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,120.0,-254.0);
glVertex3f(40.0,120.0,-259.0);
glVertex3f(40.0,130.0,-259.0);
glVertex3f(20.0,130.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,120.0,-259.0);
glVertex3f(60.0,120.0,-269.0);
glVertex3f(60.0,130.0,-269.0);
glVertex3f(40.0,130.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,120.0,-269.0);
glVertex3f(80.0,120.0,-284.0);
glVertex3f(80.0,130.0,-284.0);
glVertex3f(60.0,130.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,120.0,-284.0);
glVertex3f(100.0,120.0,-299.0);
glVertex3f(100.0,130.0,-299.0);
glVertex3f(80.0,130.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,120.0,-254.0);
glVertex3f(-20.0,120.0,-259.0);
glVertex3f(-20.0,130.0,-259.0);
glVertex3f(0.0,130.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,120.0,-259.0);
glVertex3f(-40.0,120.0,-269.0);
glVertex3f(-40.0,130.0,-269.0);
glVertex3f(-20.0,130.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,120.0,-269.0);
glVertex3f(-60.0,120.0,-284.0);
glVertex3f(-60.0,130.0,-284.0);
glVertex3f(-40.0,130.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,120.0,-284.0);
glVertex3f(-80.0,120.0,-299.0);
glVertex3f(-80.0,130.0,-299.0);
glVertex3f(-60.0,130.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,120.0,-299.0);
glVertex3f(-100.0,120.0,-329.0);
glVertex3f(-100.0,130.0,-329.0);
glVertex3f(-80.0,130.0,-299.0);
glEnd();
//////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,110.0,-254.0);
glVertex3f(20.0,110.0,-254.0);
glVertex3f(20.0,120.0,-254.0);
glVertex3f(0.0,120.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,110.0,-254.0);
glVertex3f(40.0,110.0,-259.0);
glVertex3f(40.0,120.0,-259.0);
glVertex3f(20.0,120.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,110.0,-259.0);
glVertex3f(60.0,110.0,-269.0);
glVertex3f(60.0,120.0,-269.0);
glVertex3f(40.0,120.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,110.0,-269.0);
glVertex3f(80.0,110.0,-284.0);
glVertex3f(80.0,120.0,-284.0);
glVertex3f(60.0,120.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,110.0,-284.0);
glVertex3f(100.0,110.0,-299.0);
glVertex3f(100.0,120.0,-299.0);
glVertex3f(80.0,120.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,110.0,-254.0);
glVertex3f(-20.0,110.0,-259.0);
glVertex3f(-20.0,120.0,-259.0);
glVertex3f(0.0,120.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-20.0,110.0,-259.0);
glVertex3f(-40.0,110.0,-269.0);
glVertex3f(-40.0,120.0,-269.0);
glVertex3f(-20.0,120.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-40.0,110.0,-269.0);
glVertex3f(-60.0,110.0,-284.0);
glVertex3f(-60.0,120.0,-284.0);
glVertex3f(-40.0,120.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-60.0,110.0,-284.0);
glVertex3f(-80.0,110.0,-299.0);
glVertex3f(-80.0,120.0,-299.0);
glVertex3f(-60.0,120.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-80.0,110.0,-299.0);
glVertex3f(-100.0,110.0,-329.0);
glVertex3f(-100.0,120.0,-329.0);
glVertex3f(-80.0,120.0,-299.0);
glEnd();
///////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,100.0,-254.0);
glVertex3f(20.0,100.0,-254.0);
glVertex3f(20.0,110.0,-254.0);
glVertex3f(0.0,110.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,100.0,-254.0);
glVertex3f(40.0,100.0,-259.0);
glVertex3f(40.0,110.0,-259.0);
glVertex3f(20.0,110.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,100.0,-259.0);
glVertex3f(60.0,100.0,-269.0);
glVertex3f(60.0,110.0,-269.0);
glVertex3f(40.0,110.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,100.0,-269.0);
glVertex3f(80.0,100.0,-284.0);
glVertex3f(80.0,110.0,-284.0);
glVertex3f(60.0,110.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,100.0,-284.0);
glVertex3f(100.0,100.0,-299.0);
glVertex3f(100.0,110.0,-299.0);
glVertex3f(80.0,110.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,100.0,-254.0);
glVertex3f(-20.0,100.0,-259.0);
glVertex3f(-20.0,110.0,-259.0);
glVertex3f(0.0,110.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,100.0,-259.0);
glVertex3f(-40.0,100.0,-269.0);
glVertex3f(-40.0,110.0,-269.0);
glVertex3f(-20.0,110.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,100.0,-269.0);
glVertex3f(-60.0,100.0,-284.0);
glVertex3f(-60.0,110.0,-284.0);
glVertex3f(-40.0,110.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,100.0,-284.0);
glVertex3f(-80.0,100.0,-299.0);
glVertex3f(-80.0,110.0,-299.0);
glVertex3f(-60.0,110.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,100.0,-299.0);
glVertex3f(-100.0,100.0,-329.0);
glVertex3f(-100.0,110.0,-329.0);
glVertex3f(-80.0,110.0,-299.0);
glEnd();
////////////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,90.0,-254.0);
glVertex3f(20.0,90.0,-254.0);
glVertex3f(20.0,100.0,-254.0);
glVertex3f(0.0,100.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(20.0,90.0,-254.0);
glVertex3f(40.0,90.0,-259.0);
glVertex3f(40.0,100.0,-259.0);
glVertex3f(20.0,100.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(40.0,90.0,-259.0);
glVertex3f(60.0,90.0,-269.0);
glVertex3f(60.0,100.0,-269.0);
glVertex3f(40.0,100.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,90.0,-269.0);
glVertex3f(80.0,90.0,-284.0);
glVertex3f(80.0,100.0,-284.0);
glVertex3f(60.0,100.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,90.0,-284.0);
glVertex3f(100.0,90.0,-299.0);
glVertex3f(100.0,100.0,-299.0);
glVertex3f(80.0,100.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,90.0,-254.0);
glVertex3f(-20.0,90.0,-259.0);
glVertex3f(-20.0,100.0,-259.0);
glVertex3f(0.0,100.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,90.0,-259.0);
glVertex3f(-40.0,90.0,-269.0);
glVertex3f(-40.0,100.0,-269.0);
glVertex3f(-20.0,100.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,90.0,-269.0);
glVertex3f(-60.0,90.0,-284.0);
glVertex3f(-60.0,100.0,-284.0);
glVertex3f(-40.0,100.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,90.0,-284.0);
glVertex3f(-80.0,90.0,-299.0);
glVertex3f(-80.0,100.0,-299.0);
glVertex3f(-60.0,100.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,90.0,-299.0);
glVertex3f(-100.0,90.0,-329.0);
glVertex3f(-100.0,100.0,-329.0);
glVertex3f(-80.0,100.0,-299.0);
glEnd();
///////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,80.0,-254.0);
glVertex3f(20.0,80.0,-254.0);
glVertex3f(20.0,90.0,-254.0);
glVertex3f(0.0,90.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,80.0,-254.0);
glVertex3f(40.0,80.0,-259.0);
glVertex3f(40.0,90.0,-259.0);
glVertex3f(20.0,90.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,80.0,-259.0);
glVertex3f(60.0,80.0,-269.0);
glVertex3f(60.0,90.0,-269.0);
glVertex3f(40.0,90.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,80.0,-269.0);
glVertex3f(80.0,80.0,-284.0);
glVertex3f(80.0,90.0,-284.0);
glVertex3f(60.0,90.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,80.0,-284.0);
glVertex3f(100.0,80.0,-299.0);
glVertex3f(100.0,90.0,-299.0);
glVertex3f(80.0,90.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,80.0,-254.0);
glVertex3f(-20.0,80.0,-259.0);
glVertex3f(-20.0,90.0,-259.0);
glVertex3f(0.0,90.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-20.0,80.0,-259.0);
glVertex3f(-40.0,80.0,-269.0);
glVertex3f(-40.0,90.0,-269.0);
glVertex3f(-20.0,90.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-40.0,80.0,-269.0);
glVertex3f(-60.0,80.0,-284.0);
glVertex3f(-60.0,90.0,-284.0);
glVertex3f(-40.0,90.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-60.0,80.0,-284.0);
glVertex3f(-80.0,80.0,-299.0);
glVertex3f(-80.0,90.0,-299.0);
glVertex3f(-60.0,90.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-80.0,80.0,-299.0);
glVertex3f(-100.0,80.0,-329.0);
glVertex3f(-100.0,90.0,-329.0);
glVertex3f(-80.0,90.0,-299.0);
glEnd();
////////////////////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,70.0,-254.0);
glVertex3f(20.0,70.0,-254.0);
glVertex3f(20.0,80.0,-254.0);
glVertex3f(0.0,80.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,70.0,-254.0);
glVertex3f(40.0,70.0,-259.0);
glVertex3f(40.0,80.0,-259.0);
glVertex3f(20.0,80.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,70.0,-259.0);
glVertex3f(60.0,70.0,-269.0);
glVertex3f(60.0,80.0,-269.0);
glVertex3f(40.0,80.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,70.0,-269.0);
glVertex3f(80.0,70.0,-284.0);
glVertex3f(80.0,80.0,-284.0);
glVertex3f(60.0,80.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,70.0,-284.0);
glVertex3f(100.0,70.0,-299.0);
glVertex3f(100.0,80.0,-299.0);
glVertex3f(80.0,80.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,70.0,-254.0);
glVertex3f(-20.0,70.0,-259.0);
glVertex3f(-20.0,80.0,-259.0);
glVertex3f(0.0,80.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,70.0,-259.0);
glVertex3f(-40.0,70.0,-269.0);
glVertex3f(-40.0,80.0,-269.0);
glVertex3f(-20.0,80.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,70.0,-269.0);
glVertex3f(-60.0,70.0,-284.0);
glVertex3f(-60.0,80.0,-284.0);
glVertex3f(-40.0,80.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,70.0,-284.0);
glVertex3f(-80.0,70.0,-299.0);
glVertex3f(-80.0,80.0,-299.0);
glVertex3f(-60.0,80.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,70.0,-299.0);
glVertex3f(-100.0,70.0,-329.0);
glVertex3f(-100.0,80.0,-329.0);
glVertex3f(-80.0,80.0,-299.0);
glEnd();
////////////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,60.0,-254.0);
glVertex3f(20.0,60.0,-254.0);
glVertex3f(20.0,70.0,-254.0);
glVertex3f(0.0,70.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(20.0,60.0,-254.0);
glVertex3f(40.0,60.0,-259.0);
glVertex3f(40.0,70.0,-259.0);
glVertex3f(20.0,70.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(40.0,60.0,-259.0);
glVertex3f(60.0,60.0,-269.0);
glVertex3f(60.0,70.0,-269.0);
glVertex3f(40.0,70.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,60.0,-269.0);
glVertex3f(80.0,60.0,-284.0);
glVertex3f(80.0,70.0,-284.0);
glVertex3f(60.0,70.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,60.0,-284.0);
glVertex3f(100.0,60.0,-299.0);
glVertex3f(100.0,70.0,-299.0);
glVertex3f(80.0,70.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,60.0,-254.0);
glVertex3f(-20.0,60.0,-259.0);
glVertex3f(-20.0,70.0,-259.0);
glVertex3f(0.0,70.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,60.0,-259.0);
glVertex3f(-40.0,60.0,-269.0);
glVertex3f(-40.0,70.0,-269.0);
glVertex3f(-20.0,70.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,60.0,-269.0);
glVertex3f(-60.0,60.0,-284.0);
glVertex3f(-60.0,70.0,-284.0);
glVertex3f(-40.0,70.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,60.0,-284.0);
glVertex3f(-80.0,60.0,-299.0);
glVertex3f(-80.0,70.0,-299.0);
glVertex3f(-60.0,70.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,60.0,-299.0);
glVertex3f(-100.0,60.0,-329.0);
glVertex3f(-100.0,70.0,-329.0);
glVertex3f(-80.0,70.0,-299.0);
glEnd();
///////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,50.0,-254.0);
glVertex3f(20.0,50.0,-254.0);
glVertex3f(20.0,60.0,-254.0);
glVertex3f(0.0,60.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,50.0,-254.0);
glVertex3f(40.0,50.0,-259.0);
glVertex3f(40.0,60.0,-259.0);
glVertex3f(20.0,60.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,50.0,-259.0);
glVertex3f(60.0,50.0,-269.0);
glVertex3f(60.0,60.0,-269.0);
glVertex3f(40.0,60.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,50.0,-269.0);
glVertex3f(80.0,50.0,-284.0);
glVertex3f(80.0,60.0,-284.0);
glVertex3f(60.0,60.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,50.0,-284.0);
glVertex3f(100.0,50.0,-299.0);
glVertex3f(100.0,60.0,-299.0);
glVertex3f(80.0,60.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,50.0,-254.0);
glVertex3f(-20.0,50.0,-259.0);
glVertex3f(-20.0,60.0,-259.0);
glVertex3f(0.0,60.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-20.0,50.0,-259.0);
glVertex3f(-40.0,50.0,-269.0);
glVertex3f(-40.0,60.0,-269.0);
glVertex3f(-20.0,60.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-40.0,50.0,-269.0);
glVertex3f(-60.0,50.0,-284.0);
glVertex3f(-60.0,60.0,-284.0);
glVertex3f(-40.0,60.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-60.0,50.0,-284.0);
glVertex3f(-80.0,50.0,-299.0);
glVertex3f(-80.0,60.0,-299.0);
glVertex3f(-60.0,60.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-80.0,50.0,-299.0);
glVertex3f(-100.0,50.0,-329.0);
glVertex3f(-100.0,60.0,-329.0);
glVertex3f(-80.0,60.0,-299.0);
glEnd();

///////////////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,40.0,-254.0);
glVertex3f(20.0,40.0,-254.0);
glVertex3f(20.0,50.0,-254.0);
glVertex3f(0.0,50.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,40.0,-254.0);
glVertex3f(40.0,40.0,-259.0);
glVertex3f(40.0,50.0,-259.0);
glVertex3f(20.0,50.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,40.0,-259.0);
glVertex3f(60.0,40.0,-269.0);
glVertex3f(60.0,50.0,-269.0);
glVertex3f(40.0,50.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,40.0,-269.0);
glVertex3f(80.0,40.0,-284.0);
glVertex3f(80.0,50.0,-284.0);
glVertex3f(60.0,50.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,40.0,-284.0);
glVertex3f(100.0,40.0,-299.0);
glVertex3f(100.0,50.0,-299.0);
glVertex3f(80.0,50.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,40.0,-254.0);
glVertex3f(-20.0,40.0,-259.0);
glVertex3f(-20.0,50.0,-259.0);
glVertex3f(0.0,50.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,40.0,-259.0);
glVertex3f(-40.0,40.0,-269.0);
glVertex3f(-40.0,50.0,-269.0);
glVertex3f(-20.0,50.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,40.0,-269.0);
glVertex3f(-60.0,40.0,-284.0);
glVertex3f(-60.0,50.0,-284.0);
glVertex3f(-40.0,50.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,40.0,-284.0);
glVertex3f(-80.0,40.0,-299.0);
glVertex3f(-80.0,50.0,-299.0);
glVertex3f(-60.0,50.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,40.0,-299.0);
glVertex3f(-100.0,40.0,-329.0);
glVertex3f(-100.0,50.0,-329.0);
glVertex3f(-80.0,50.0,-299.0);
glEnd();
////////////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,30.0,-254.0);
glVertex3f(20.0,30.0,-254.0);
glVertex3f(20.0,40.0,-254.0);
glVertex3f(0.0,40.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(20.0,30.0,-254.0);
glVertex3f(40.0,30.0,-259.0);
glVertex3f(40.0,40.0,-259.0);
glVertex3f(20.0,40.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(40.0,30.0,-259.0);
glVertex3f(60.0,30.0,-269.0);
glVertex3f(60.0,40.0,-269.0);
glVertex3f(40.0,40.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,30.0,-269.0);
glVertex3f(80.0,30.0,-284.0);
glVertex3f(80.0,40.0,-284.0);
glVertex3f(60.0,40.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,30.0,-284.0);
glVertex3f(100.0,30.0,-299.0);
glVertex3f(100.0,40.0,-299.0);
glVertex3f(80.0,40.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,30.0,-254.0);
glVertex3f(-20.0,30.0,-259.0);
glVertex3f(-20.0,40.0,-259.0);
glVertex3f(0.0,40.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,30.0,-259.0);
glVertex3f(-40.0,30.0,-269.0);
glVertex3f(-40.0,40.0,-269.0);
glVertex3f(-20.0,40.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,30.0,-269.0);
glVertex3f(-60.0,30.0,-284.0);
glVertex3f(-60.0,40.0,-284.0);
glVertex3f(-40.0,40.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,30.0,-284.0);
glVertex3f(-80.0,30.0,-299.0);
glVertex3f(-80.0,40.0,-299.0);
glVertex3f(-60.0,40.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,30.0,-299.0);
glVertex3f(-100.0,30.0,-329.0);
glVertex3f(-100.0,40.0,-329.0);
glVertex3f(-80.0,40.0,-299.0);
glEnd();
////////////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,20.0,-254.0);
glVertex3f(20.0,20.0,-254.0);
glVertex3f(20.0,30.0,-254.0);
glVertex3f(0.0,30.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,20.0,-254.0);
glVertex3f(40.0,20.0,-259.0);
glVertex3f(40.0,30.0,-259.0);
glVertex3f(20.0,30.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,20.0,-259.0);
glVertex3f(60.0,20.0,-269.0);
glVertex3f(60.0,30.0,-269.0);
glVertex3f(40.0,30.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,20.0,-269.0);
glVertex3f(80.0,20.0,-284.0);
glVertex3f(80.0,30.0,-284.0);
glVertex3f(60.0,30.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,20.0,-284.0);
glVertex3f(100.0,20.0,-299.0);
glVertex3f(100.0,30.0,-299.0);
glVertex3f(80.0,30.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,20.0,-254.0);
glVertex3f(-20.0,20.0,-259.0);
glVertex3f(-20.0,30.0,-259.0);
glVertex3f(0.0,30.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-20.0,20.0,-259.0);
glVertex3f(-40.0,20.0,-269.0);
glVertex3f(-40.0,30.0,-269.0);
glVertex3f(-20.0,30.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-40.0,20.0,-269.0);
glVertex3f(-60.0,20.0,-284.0);
glVertex3f(-60.0,30.0,-284.0);
glVertex3f(-40.0,30.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-60.0,20.0,-284.0);
glVertex3f(-80.0,20.0,-299.0);
glVertex3f(-80.0,30.0,-299.0);
glVertex3f(-60.0,30.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-80.0,20.0,-299.0);
glVertex3f(-100.0,20.0,-329.0);
glVertex3f(-100.0,30.0,-329.0);
glVertex3f(-80.0,30.0,-299.0);
glEnd();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,10.0,-254.0);
glVertex3f(20.0,10.0,-254.0);
glVertex3f(20.0,20.0,-254.0);
glVertex3f(0.0,20.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,10.0,-254.0);
glVertex3f(40.0,10.0,-259.0);
glVertex3f(40.0,20.0,-259.0);
glVertex3f(20.0,20.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,10.0,-259.0);
glVertex3f(60.0,10.0,-269.0);
glVertex3f(60.0,20.0,-269.0);
glVertex3f(40.0,20.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,10.0,-269.0);
glVertex3f(80.0,10.0,-284.0);
glVertex3f(80.0,20.0,-284.0);
glVertex3f(60.0,20.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,10.0,-284.0);
glVertex3f(100.0,10.0,-299.0);
glVertex3f(100.0,20.0,-299.0);
glVertex3f(80.0,20.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,10.0,-254.0);
glVertex3f(-20.0,10.0,-259.0);
glVertex3f(-20.0,20.0,-259.0);
glVertex3f(0.0,20.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,10.0,-259.0);
glVertex3f(-40.0,10.0,-269.0);
glVertex3f(-40.0,20.0,-269.0);
glVertex3f(-20.0,20.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,10.0,-269.0);
glVertex3f(-60.0,10.0,-284.0);
glVertex3f(-60.0,20.0,-284.0);
glVertex3f(-40.0,20.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,10.0,-284.0);
glVertex3f(-80.0,10.0,-299.0);
glVertex3f(-80.0,20.0,-299.0);
glVertex3f(-60.0,20.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,10.0,-299.0);
glVertex3f(-100.0,10.0,-329.0);
glVertex3f(-100.0,20.0,-329.0);
glVertex3f(-80.0,20.0,-299.0);
glEnd();
////////////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,0.0,-254.0);
glVertex3f(20.0,0.0,-254.0);
glVertex3f(20.0,10.0,-254.0);
glVertex3f(0.0,10.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(20.0,0.0,-254.0);
glVertex3f(40.0,0.0,-259.0);
glVertex3f(40.0,10.0,-259.0);
glVertex3f(20.0,10.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(40.0,0.0,-259.0);
glVertex3f(60.0,0.0,-269.0);
glVertex3f(60.0,10.0,-269.0);
glVertex3f(40.0,10.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,0.0,-269.0);
glVertex3f(80.0,0.0,-284.0);
glVertex3f(80.0,10.0,-284.0);
glVertex3f(60.0,10.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,0.0,-284.0);
glVertex3f(100.0,0.0,-299.0);
glVertex3f(100.0,10.0,-299.0);
glVertex3f(80.0,10.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(0.0,0.0,-254.0);
glVertex3f(-20.0,0.0,-259.0);
glVertex3f(-20.0,10.0,-259.0);
glVertex3f(0.0,10.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-20.0,0.0,-259.0);
glVertex3f(-40.0,0.0,-269.0);
glVertex3f(-40.0,10.0,-269.0);
glVertex3f(-20.0,10.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-40.0,0.0,-269.0);
glVertex3f(-60.0,0.0,-284.0);
glVertex3f(-60.0,10.0,-284.0);
glVertex3f(-40.0,10.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-60.0,0.0,-284.0);
glVertex3f(-80.0,0.0,-299.0);
glVertex3f(-80.0,10.0,-299.0);
glVertex3f(-60.0,10.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-80.0,0.0,-299.0);
glVertex3f(-100.0,0.0,-329.0);
glVertex3f(-100.0,10.0,-329.0);
glVertex3f(-80.0,10.0,-299.0);
glEnd();
///////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,-10.0,-254.0);
glVertex3f(20.0,-10.0,-254.0);
glVertex3f(20.0,0.0,-254.0);
glVertex3f(0.0,0.0,-254.0);
glEnd();


glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(20.0,-10.0,-254.0);
glVertex3f(40.0,-10.0,-259.0);
glVertex3f(40.0,0.0,-259.0);
glVertex3f(20.0,0.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(40.0,-10.0,-259.0);
glVertex3f(60.0,-10.0,-269.0);
glVertex3f(60.0,0.0,-269.0);
glVertex3f(40.0,0.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(60.0,-10.0,-269.0);
glVertex3f(80.0,-10.0,-284.0);
glVertex3f(80.0,0.0,-284.0);
glVertex3f(60.0,0.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(80.0,-10.0,-284.0);
glVertex3f(100.0,-10.0,-299.0);
glVertex3f(100.0,0.0,-299.0);
glVertex3f(80.0,0.0,-284.0);
glEnd();


//

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(0.0,-10.0,-254.0);
glVertex3f(-20.0,-10.0,-259.0);
glVertex3f(-20.0,0.0,-259.0);
glVertex3f(0.0,0.0,-254.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-20.0,-10.0,-259.0);
glVertex3f(-40.0,-10.0,-269.0);
glVertex3f(-40.0,0.0,-269.0);
glVertex3f(-20.0,0.0,-259.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-40.0,-10.0,-269.0);
glVertex3f(-60.0,-10.0,-284.0);
glVertex3f(-60.0,0.0,-284.0);
glVertex3f(-40.0,0.0,-269.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-60.0,-10.0,-284.0);
glVertex3f(-80.0,-10.0,-299.0);
glVertex3f(-80.0,0.0,-299.0);
glVertex3f(-60.0,0.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-80.0,-10.0,-299.0);
glVertex3f(-100.0,-10.0,-329.0);
glVertex3f(-100.0,0.0,-329.0);
glVertex3f(-80.0,0.0,-299.0);
glEnd();

//jendela gedung ketiga//
glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-100.0,90.0,-279.0);
glVertex3f(-100.0,90.0,-409.0);
glVertex3f(-100.0,100.0,-409.0);
glVertex3f(-100.0,100.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-100.0,90.0,-279.0);
glVertex3f(-120.0,90.0,-284.0);
glVertex3f(-120.0,100.0,-284.0);
glVertex3f(-100.0,100.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-120.0,90.0,-284.0);
glVertex3f(-140.0,90.0,-294.0);
glVertex3f(-140.0,100.0,-294.0);
glVertex3f(-120.0,100.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-140.0,90.0,-294.0);
glVertex3f(-160.0,90.0,-309.0);
glVertex3f(-160.0,100.0,-309.0);
glVertex3f(-140.0,100.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-160.0,90.0,-309.0);
glVertex3f(-180.0,90.0,-329.0);
glVertex3f(-180.0,100.0,-329.0);
glVertex3f(-160.0,100.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-180.0,90.0,-329.0);
glVertex3f(-200.0,90.0,-354.0);
glVertex3f(-200.0,100.0,-354.0);
glVertex3f(-180.0,100.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-200.0,90.0,-354.0);
glVertex3f(-220.0,90.0,-389.0);
glVertex3f(-220.0,100.0,-389.0);
glVertex3f(-200.0,100.0,-354.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-220.0,90.0,-390.0);
glVertex3f(-240.0,90.0,-430.0);
glVertex3f(-240.0,100.0,-430.0);
glVertex3f(-220.0,100.0,-390.0);
glEnd();
////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,80.0,-279.0);
glVertex3f(-100.0,80.0,-409.0);
glVertex3f(-100.0,90.0,-409.0);
glVertex3f(-100.0,90.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,80.0,-279.0);
glVertex3f(-120.0,80.0,-284.0);
glVertex3f(-120.0,90.0,-284.0);
glVertex3f(-100.0,90.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-120.0,80.0,-284.0);
glVertex3f(-140.0,80.0,-294.0);
glVertex3f(-140.0,90.0,-294.0);
glVertex3f(-120.0,90.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-140.0,80.0,-294.0);
glVertex3f(-160.0,80.0,-309.0);
glVertex3f(-160.0,90.0,-309.0);
glVertex3f(-140.0,90.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-160.0,80.0,-309.0);
glVertex3f(-180.0,80.0,-329.0);
glVertex3f(-180.0,90.0,-329.0);
glVertex3f(-160.0,90.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-180.0,80.0,-329.0);
glVertex3f(-200.0,80.0,-354.0);
glVertex3f(-200.0,90.0,-354.0);
glVertex3f(-180.0,90.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-200.0,80.0,-354.0);
glVertex3f(-220.0,80.0,-389.0);
glVertex3f(-220.0,90.0,-389.0);
glVertex3f(-200.0,90.0,-354.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-220.0,80.0,-390.0);
glVertex3f(-240.0,80.0,-430.0);
glVertex3f(-240.0,90.0,-430.0);
glVertex3f(-220.0,90.0,-390.0);
glEnd();
////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,70.0,-279.0);
glVertex3f(-100.0,70.0,-409.0);
glVertex3f(-100.0,80.0,-409.0);
glVertex3f(-100.0,80.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,70.0,-279.0);
glVertex3f(-120.0,70.0,-284.0);
glVertex3f(-120.0,80.0,-284.0);
glVertex3f(-100.0,80.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-120.0,70.0,-284.0);
glVertex3f(-140.0,70.0,-294.0);
glVertex3f(-140.0,80.0,-294.0);
glVertex3f(-120.0,80.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-140.0,70.0,-294.0);
glVertex3f(-160.0,70.0,-309.0);
glVertex3f(-160.0,80.0,-309.0);
glVertex3f(-140.0,80.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-160.0,70.0,-309.0);
glVertex3f(-180.0,70.0,-329.0);
glVertex3f(-180.0,80.0,-329.0);
glVertex3f(-160.0,80.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-180.0,70.0,-329.0);
glVertex3f(-200.0,70.0,-354.0);
glVertex3f(-200.0,80.0,-354.0);
glVertex3f(-180.0,80.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-200.0,70.0,-354.0);
glVertex3f(-220.0,70.0,-389.0);
glVertex3f(-220.0,80.0,-389.0);
glVertex3f(-200.0,80.0,-354.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-220.0,70.0,-390.0);
glVertex3f(-240.0,70.0,-430.0);
glVertex3f(-240.0,80.0,-430.0);
glVertex3f(-220.0,80.0,-390.0);
glEnd();
///////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,60.0,-279.0);
glVertex3f(-100.0,60.0,-409.0);
glVertex3f(-100.0,70.0,-409.0);
glVertex3f(-100.0,70.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,60.0,-279.0);
glVertex3f(-120.0,60.0,-284.0);
glVertex3f(-120.0,70.0,-284.0);
glVertex3f(-100.0,70.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-120.0,60.0,-284.0);
glVertex3f(-140.0,60.0,-294.0);
glVertex3f(-140.0,70.0,-294.0);
glVertex3f(-120.0,70.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-140.0,60.0,-294.0);
glVertex3f(-160.0,60.0,-309.0);
glVertex3f(-160.0,70.0,-309.0);
glVertex3f(-140.0,70.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-160.0,60.0,-309.0);
glVertex3f(-180.0,60.0,-329.0);
glVertex3f(-180.0,70.0,-329.0);
glVertex3f(-160.0,70.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-180.0,60.0,-329.0);
glVertex3f(-200.0,60.0,-354.0);
glVertex3f(-200.0,70.0,-354.0);
glVertex3f(-180.0,70.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-200.0,60.0,-354.0);
glVertex3f(-220.0,60.0,-389.0);
glVertex3f(-220.0,70.0,-389.0);
glVertex3f(-200.0,70.0,-354.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-220.0,60.0,-390.0);
glVertex3f(-240.0,60.0,-430.0);
glVertex3f(-240.0,70.0,-430.0);
glVertex3f(-220.0,70.0,-390.0);
glEnd();
/////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,50.0,-279.0);
glVertex3f(-100.0,50.0,-409.0);
glVertex3f(-100.0,60.0,-409.0);
glVertex3f(-100.0,60.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,50.0,-279.0);
glVertex3f(-120.0,50.0,-284.0);
glVertex3f(-120.0,60.0,-284.0);
glVertex3f(-100.0,60.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-120.0,50.0,-284.0);
glVertex3f(-140.0,50.0,-294.0);
glVertex3f(-140.0,60.0,-294.0);
glVertex3f(-120.0,60.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-140.0,50.0,-294.0);
glVertex3f(-160.0,50.0,-309.0);
glVertex3f(-160.0,60.0,-309.0);
glVertex3f(-140.0,60.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-160.0,50.0,-309.0);
glVertex3f(-180.0,50.0,-329.0);
glVertex3f(-180.0,60.0,-329.0);
glVertex3f(-160.0,60.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-180.0,50.0,-329.0);
glVertex3f(-200.0,50.0,-354.0);
glVertex3f(-200.0,60.0,-354.0);
glVertex3f(-180.0,60.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-200.0,50.0,-354.0);
glVertex3f(-220.0,50.0,-389.0);
glVertex3f(-220.0,60.0,-389.0);
glVertex3f(-200.0,60.0,-354.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-220.0,50.0,-390.0);
glVertex3f(-240.0,50.0,-430.0);
glVertex3f(-240.0,60.0,-430.0);
glVertex3f(-220.0,60.0,-390.0);
glEnd();
////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,40.0,-279.0);
glVertex3f(-100.0,40.0,-409.0);
glVertex3f(-100.0,50.0,-409.0);
glVertex3f(-100.0,50.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,40.0,-279.0);
glVertex3f(-120.0,40.0,-284.0);
glVertex3f(-120.0,50.0,-284.0);
glVertex3f(-100.0,50.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-120.0,40.0,-284.0);
glVertex3f(-140.0,40.0,-294.0);
glVertex3f(-140.0,50.0,-294.0);
glVertex3f(-120.0,50.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-140.0,40.0,-294.0);
glVertex3f(-160.0,40.0,-309.0);
glVertex3f(-160.0,50.0,-309.0);
glVertex3f(-140.0,50.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-160.0,40.0,-309.0);
glVertex3f(-180.0,40.0,-329.0);
glVertex3f(-180.0,50.0,-329.0);
glVertex3f(-160.0,50.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-180.0,40.0,-329.0);
glVertex3f(-200.0,40.0,-354.0);
glVertex3f(-200.0,50.0,-354.0);
glVertex3f(-180.0,50.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-200.0,40.0,-354.0);
glVertex3f(-220.0,40.0,-389.0);
glVertex3f(-220.0,50.0,-389.0);
glVertex3f(-200.0,50.0,-354.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-220.0,40.0,-390.0);
glVertex3f(-240.0,40.0,-430.0);
glVertex3f(-240.0,50.0,-430.0);
glVertex3f(-220.0,50.0,-390.0);
glEnd();
///////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,30.0,-279.0);
glVertex3f(-100.0,30.0,-409.0);
glVertex3f(-100.0,40.0,-409.0);
glVertex3f(-100.0,40.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,30.0,-279.0);
glVertex3f(-120.0,30.0,-284.0);
glVertex3f(-120.0,40.0,-284.0);
glVertex3f(-100.0,40.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-120.0,30.0,-284.0);
glVertex3f(-140.0,30.0,-294.0);
glVertex3f(-140.0,40.0,-294.0);
glVertex3f(-120.0,40.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-140.0,30.0,-294.0);
glVertex3f(-160.0,30.0,-309.0);
glVertex3f(-160.0,40.0,-309.0);
glVertex3f(-140.0,40.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-160.0,30.0,-309.0);
glVertex3f(-180.0,30.0,-329.0);
glVertex3f(-180.0,40.0,-329.0);
glVertex3f(-160.0,40.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-180.0,30.0,-329.0);
glVertex3f(-200.0,30.0,-354.0);
glVertex3f(-200.0,40.0,-354.0);
glVertex3f(-180.0,40.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-200.0,30.0,-354.0);
glVertex3f(-220.0,30.0,-389.0);
glVertex3f(-220.0,40.0,-389.0);
glVertex3f(-200.0,40.0,-354.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-220.0,30.0,-390.0);
glVertex3f(-240.0,30.0,-430.0);
glVertex3f(-240.0,40.0,-430.0);
glVertex3f(-220.0,40.0,-390.0);
glEnd();
////////////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,20.0,-279.0);
glVertex3f(-100.0,20.0,-409.0);
glVertex3f(-100.0,30.0,-409.0);
glVertex3f(-100.0,30.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,20.0,-279.0);
glVertex3f(-120.0,20.0,-284.0);
glVertex3f(-120.0,30.0,-284.0);
glVertex3f(-100.0,30.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-120.0,20.0,-284.0);
glVertex3f(-140.0,20.0,-294.0);
glVertex3f(-140.0,30.0,-294.0);
glVertex3f(-120.0,30.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-140.0,20.0,-294.0);
glVertex3f(-160.0,20.0,-309.0);
glVertex3f(-160.0,30.0,-309.0);
glVertex3f(-140.0,30.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-160.0,20.0,-309.0);
glVertex3f(-180.0,20.0,-329.0);
glVertex3f(-180.0,30.0,-329.0);
glVertex3f(-160.0,30.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-180.0,20.0,-329.0);
glVertex3f(-200.0,20.0,-354.0);
glVertex3f(-200.0,30.0,-354.0);
glVertex3f(-180.0,30.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-200.0,20.0,-354.0);
glVertex3f(-220.0,20.0,-389.0);
glVertex3f(-220.0,30.0,-389.0);
glVertex3f(-200.0,30.0,-354.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-220.0,20.0,-390.0);
glVertex3f(-240.0,20.0,-430.0);
glVertex3f(-240.0,30.0,-430.0);
glVertex3f(-220.0,30.0,-390.0);
glEnd();
///////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,10.0,-279.0);
glVertex3f(-100.0,10.0,-409.0);
glVertex3f(-100.0,20.0,-409.0);
glVertex3f(-100.0,20.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,10.0,-279.0);
glVertex3f(-120.0,10.0,-284.0);
glVertex3f(-120.0,20.0,-284.0);
glVertex3f(-100.0,20.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-120.0,10.0,-284.0);
glVertex3f(-140.0,10.0,-294.0);
glVertex3f(-140.0,20.0,-294.0);
glVertex3f(-120.0,20.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-140.0,10.0,-294.0);
glVertex3f(-160.0,10.0,-309.0);
glVertex3f(-160.0,20.0,-309.0);
glVertex3f(-140.0,20.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-160.0,10.0,-309.0);
glVertex3f(-180.0,10.0,-329.0);
glVertex3f(-180.0,20.0,-329.0);
glVertex3f(-160.0,20.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-180.0,10.0,-329.0);
glVertex3f(-200.0,10.0,-354.0);
glVertex3f(-200.0,20.0,-354.0);
glVertex3f(-180.0,20.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-200.0,10.0,-354.0);
glVertex3f(-220.0,10.0,-389.0);
glVertex3f(-220.0,20.0,-389.0);
glVertex3f(-200.0,20.0,-354.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-220.0,10.0,-390.0);
glVertex3f(-240.0,10.0,-430.0);
glVertex3f(-240.0,20.0,-430.0);
glVertex3f(-220.0,20.0,-390.0);
glEnd();
///////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,0.0,-279.0);
glVertex3f(-100.0,0.0,-409.0);
glVertex3f(-100.0,10.0,-409.0);
glVertex3f(-100.0,10.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,0.0,-279.0);
glVertex3f(-120.0,0.0,-284.0);
glVertex3f(-120.0,10.0,-284.0);
glVertex3f(-100.0,10.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-120.0,0.0,-284.0);
glVertex3f(-140.0,0.0,-294.0);
glVertex3f(-140.0,10.0,-294.0);
glVertex3f(-120.0,10.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-140.0,0.0,-294.0);
glVertex3f(-160.0,0.0,-309.0);
glVertex3f(-160.0,10.0,-309.0);
glVertex3f(-140.0,10.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-160.0,0.0,-309.0);
glVertex3f(-180.0,0.0,-329.0);
glVertex3f(-180.0,10.0,-329.0);
glVertex3f(-160.0,10.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-180.0,0.0,-329.0);
glVertex3f(-200.0,0.0,-354.0);
glVertex3f(-200.0,10.0,-354.0);
glVertex3f(-180.0,10.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-200.0,0.0,-354.0);
glVertex3f(-220.0,0.0,-389.0);
glVertex3f(-220.0,10.0,-389.0);
glVertex3f(-200.0,10.0,-354.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(18,12,12);
glVertex3f(-220.0,0.0,-390.0);
glVertex3f(-240.0,0.0,-430.0);
glVertex3f(-240.0,10.0,-430.0);
glVertex3f(-220.0,10.0,-390.0);
glEnd();
////////////////////////////////////////////////////////////////////////////////////////////////
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,-10.0,-279.0);
glVertex3f(-100.0,-10.0,-409.0);
glVertex3f(-100.0,0.0,-409.0);
glVertex3f(-100.0,0.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-100.0,-10.0,-279.0);
glVertex3f(-120.0,-10.0,-284.0);
glVertex3f(-120.0,0.0,-284.0);
glVertex3f(-100.0,0.0,-279.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-120.0,-10.0,-284.0);
glVertex3f(-140.0,-10.0,-294.0);
glVertex3f(-140.0,0.0,-294.0);
glVertex3f(-120.0,0.0,-284.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-140.0,-10.0,-294.0);
glVertex3f(-160.0,-10.0,-309.0);
glVertex3f(-160.0,0.0,-309.0);
glVertex3f(-140.0,0.0,-294.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-160.0,-10.0,-309.0);
glVertex3f(-180.0,-10.0,-329.0);
glVertex3f(-180.0,0.0,-329.0);
glVertex3f(-160.0,0.0,-309.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-180.0,-10.0,-329.0);
glVertex3f(-200.0,-10.0,-354.0);
glVertex3f(-200.0,0.0,-354.0);
glVertex3f(-180.0,0.0,-329.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-200.0,-10.0,-354.0);
glVertex3f(-220.0,-10.0,-389.0);
glVertex3f(-220.0,0.0,-389.0);
glVertex3f(-200.0,0.0,-354.0);
glEnd();

glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex3f(-220.0,-10.0,-390.0);
glVertex3f(-240.0,-10.0,-430.0);
glVertex3f(-240.0,0.0,-430.0);
glVertex3f(-220.0,0.0,-390.0);
glEnd();

pohon();
kolam();
kursi();
chair();
meja();
tempatTidur();
barang();

glPopMatrix();
glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
    case 'w': //maju
    case 'W':
            glTranslatef(0.0,0.0,3.0);
            break;
    case 'd': //kanan
    case 'D':
            glTranslatef(3.0,0.0,0.0);
            break;
    case 's': //mundur
    case 'S':
            glTranslatef(0.0,0.0,-3.0);
            break;
    case 'a': //kiri
    case 'A':
            glTranslatef(-3.0,0.0,0.0);
            break;
    case '7': //atas
            glTranslatef(0.0,3.0,0.0);
            break;
    case '9'://turun
            glTranslatef(0.0,-3.0,0.0);
            break;
    case '2': //mutar ke depan
            glRotatef(2.0,1.0,0.0,0.0);
            break;
    case '8': //mutar ke depan
            glRotatef(-2.0,1.0,0.0,0.0);
            break;
    case '6': //mutar samping kiri
            glRotatef(2.0,0.0,1.0,0.0);
            break;
    case '4': //mutar samping kanan
            glRotatef(-2.0,0.0,1.0,0.0);
            break;
    case '1': //mutar guling kiri
            glRotatef(2.0,0.0,0.0,1.0);
            break;
    case '3': //mutar guling kanan
            glRotatef(-2.0,0.0,0.0,1.0);
            break;
    case '5': // on off keyboard
        if(is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void idle()
    {
        if(!mouseDown){
            xrot += 0.3f;
            yrot += 0.5f;
        }
    glutPostRedisplay();
    }
    void mouse(int button, int state, int x, int y){
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
            mouseDown = true;
            xdiff = x - yrot; //memutar mouse
            ydiff = -y + xrot; //memutar mouse
        }
        else
        mouseDown =false;
    }
    void mouseMotion(int x, int y){
        if(mouseDown){
            yrot = x - xdiff; //memutar mouse
            xrot = y + ydiff; //memutar mouse

            glutPostRedisplay();
        }
    }

void ukuran(int lebar, int tinggi){
    glViewport(0, 0, lebar, tinggi);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0,(float)lebar/(float)tinggi,5.0,1000.0);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}


