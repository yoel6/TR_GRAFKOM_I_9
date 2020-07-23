# TR_GRAFKOM_I_9
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

int main (int argc, char **argv)
{
	glutInit(& argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000,600);
	glutInitWindowPosition(350,100);
	glutCreateWindow("TR GRAFKOM");
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
	glClearColor (0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
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
    gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
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

int main (int argc, char **argv)
{
	glutInit(& argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000,600);
	glutInitWindowPosition(350,100);
	glutCreateWindow("TR GRAFKOM");
	init();
	setLighting();
	glutDisplayFunc(tampil);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);

	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);

	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;

}

void init(void){
	glClearColor (0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
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
    gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
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

void setLighting()
{
GLfloat lightIntensity[] = {0.7f,0.7f,0.7f,1.0f};//mensetting pencahayaan
GLfloat light_position[] = {2.0f,6.0f,3.0f,0.0f};
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
glLightfv(GL_LIGHT0,GL_POSITION,light_position);
}

void ukuran(int lebar, int tinggi){
	glViewport(0, 0, lebar, tinggi);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0,(float)lebar/(float)tinggi,5.0,1000.0);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


