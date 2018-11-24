#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
char str1[]="Computer Graphics Mini Project";
char str2[]="Mobile Device Handoff Mechanism";
char str3[]="Submitted By:";
char str4[]="Shikshan Chandrashekar               4VP15CS074";
char str5[]="Sudarshan T                                   4VP15CS083";
char headr[]="DEPARTMENT OF COMPUTER SCIENCE AND ENGG.";
void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	glRasterPos2f(140,900);
	int len=strlen(str1);
	int i;
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str1[i]);
	glColor3f(0,0,1);
	glRasterPos2f(100,830);
	len=strlen(str2);
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str2[i]);
	glColor3f(0,0,0);
	glRasterPos2f(230,150);
	len=strlen(str3);
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str3[i]);
	glRasterPos2f(90,100);
	len=strlen(str4);
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str4[i]);
	glRasterPos2f(90,50);
	len=strlen(str5);
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str5[i]);
	glColor3f(1,0,0);
	glRasterPos2f(70,1400);
	len=strlen(headr);
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,headr[i]);
	glFlush();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,1800);
	glutCreateWindow("Front Page");
	gluOrtho2D(0,500,0,1500);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
