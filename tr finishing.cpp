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

//Tekan Tombol 5 pada kaybord untuk menggerakkan keyboard dan untuk melihat isi dari rumah tersebut
//untuk kembali lagi ke mouse tekan lima kembali maka rumah hanya terlihat dari luar saja
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
	glutCreateWindow("tr grafkom - 672018296");
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
///////bagian vinia codingan object taruh situ ya makasih ////


//////////////////////////////////////////////////////////////
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

