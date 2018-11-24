#include<stdio.h>
#include<GL/glut.h>
#include<string.h>
char str[30]="Not Connected",ntcon[]="Not Connected",conbs11[]="Connected to BS1",conbs12[]="Weakly connected to BS1";
char hand12[]="Hand off between BS1 and BS2",hand23[]="Hand off between BS2 and BS3";
char conbs21[]="Connected to BS2",conbs22[]="Weakly connected to BS2";
char conbs31[]="Connected to BS3",conbs32[]="Weakly connected to BS3";
char info[120];
char str1[]="Computer Graphics Mini Project";
char str2[]="Mobile Device Handoff Mechanism",msc[]="BSC";
char str3[]="Submitted By:";
char str4[]="Shikshan Chandrashekar                4VP15CS074";
char str5[]="Sudarshan T.                                   4VP15CS083";
char str6[]="(Click 'n' to move to main page)";
char headr1[]="Vivekananda College of Engg. and Technology, Puttur";
char headr2[]="DEPARTMENT OF COMPUTER SCIENCE AND ENGG.";
int k1=10,k2=-40,k3=-90,r=150,R=0,G=0,B=0,mbx=75,mby=75,fb1=0,fb2=0,fb3=0,han1=0,han2=0,stat1=0,stat2=1,i,j;
int automove=0,appstate=0,dropmenu=1;
typedef float point[2];
point bs1={400,400},bs2={650,250},bs3={900,400},MSC={650,545};
typedef float color[3];
color c1,c2,c3;
void drawstring(int x,int y,char ch[])
{
    if((strcmp(ch,ntcon))==0)
        glColor3f(1,0,0);
    else if(han1||han2||(strcmp(ch,conbs12)==0)||(strcmp(ch,conbs22)==0)||(strcmp(ch,conbs32)==0))
        glColor3f(1,1,0);
    else
        glColor3f(0,0,1);
	glRasterPos2f(x,y);
	int len=strlen(ch);
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch[i]);
}
void drawline(int x1,int y1,int x2,int y2)
{
    //connection between points
    glPushAttrib(GL_ENABLE_BIT);
    glLineStipple(0, 0xCCCC);
    glEnable(GL_LINE_STIPPLE);
    glColor3f(0.5,0.5,0.5);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
    glPopAttrib();
}
void draw_pixel(GLint m,GLint n)
{
	glColor3f(R,G,B);
	glPointSize(1.0);
	glBegin(GL_POINTS);
	glVertex2i(m,n);
	glEnd();
}
void plotpixels(GLint h,GLint k,GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}
void circle(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
	if(r<=0)
    {
        if(r<=-150)
        {
            R=0;G=0;B=0;
        }
        else
        {
            R=0;G=0.5;B=1;
        }
    }
	plotpixels(h,k,x,y);
	while(y>x)
	{
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
		plotpixels(h,k,x,y);
	}
}
void BaseStation()
{
	glColor3f(1,1,1);
	//MSC
	glBegin(GL_POLYGON);
	glVertex2f(600,500);
	glVertex2f(700,500);
	glVertex2f(700,600);
	glVertex2f(600,600);
	glEnd();
	//Displaying MSC
	glColor3f(0,0,0);
	glRasterPos2f(623,550);
	for(i=0;i<3;i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msc[i]);
	glLineWidth(5.0);
	glColor3f(1,1,0);
	//Base Station 1
	glBegin(GL_LINE_LOOP);
	glVertex2f(250,400);
	glVertex2f(300,550);
	glVertex2f(500,550);
	glVertex2f(550,400);
	glVertex2f(500,250);
	glVertex2f(300,250);
	glEnd();
	//Base Station 2
	glBegin(GL_LINE_LOOP);
	glVertex2f(500,250);
	glVertex2f(550,400);
	glVertex2f(750,400);
	glVertex2f(800,250);
	glVertex2f(750,100);
	glVertex2f(550,100);
	glEnd();
	//Base Station 3
	glBegin(GL_LINE_LOOP);
	glVertex2f(750,400);
	glVertex2f(800,550);
	glVertex2f(1000,550);
	glVertex2f(1050,400);
	glVertex2f(1000,250);
	glVertex2f(800,250);
	glEnd();
    //Base station centers
	glColor3f(1,0,0);
	glPointSize(25.0);
	glBegin(GL_POINTS);
	glVertex2f(400,400);
	glVertex2f(650,250);
	glVertex2f(900,400);
	glEnd();
    //Mobile device
    glColor3f(0.5,0.5,0.5);
	glPointSize(15.0);
	glBegin(GL_POINTS);
	glVertex2f(mbx,mby);
	glEnd();
    //Wired connection between BSC ans BSs
	glLineWidth(10.0);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(MSC[0],MSC[1]);
	glVertex2f(bs1[0],bs1[1]);
	glVertex2f(MSC[0],MSC[1]);
	glVertex2f(bs2[0],bs2[1]);
	glVertex2f(MSC[0],MSC[1]);
	glVertex2f(bs3[0],bs3[1]);
	glEnd();
    //naming BSs
    glColor3f(1,1,1);
    glRasterPos2f(380,420);
    strcpy(info,"BS1");
	for(i=0;i<3;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,info[i]);
    glRasterPos2f(640,220);
    strcpy(info,"BS2");
	for(i=0;i<3;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,info[i]);
    glRasterPos2f(910,420);
    strcpy(info,"BS3");
	for(i=0;i<3;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,info[i]);
}
void displayCirc(point c,color col,int k)
{
    R=col[0];G=col[1];B=col[2];
    circle(c[0],c[1],k);
    circle(c[0],c[1],k-150);
    glFlush();
}
void menu(int id)
{
    switch(id)
    {
        case 1: automove=1;appstate=1;
                break;
        case 2: automove=0;appstate=1;
                break;
        case 3: if(appstate==2)
                        appstate=0;
                else
                        appstate=2;
                automove=0;
                break;
        case 4: exit(0);
                break;
    }
}
void mouse(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
    {
        mbx=x;mby=700-y;
    }
	glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
	    case 13 :appstate=1;//Enter key
             break;
	    case 27 :if(appstate>0)//Escape key
                    appstate-=1;
             break;
		case 'a':mbx-=5;
			 break;
        case 'A':mbx-=5;
			 break;
        case 'i':if(appstate==2)
                    appstate=0;
                 else
                    appstate=2;
                 break;
        case 'I':if(appstate==2)
                    appstate=0;
                 else
                    appstate=2;
                 break;
        case 49:mbx-=5;mby-=5;//Number key 1
			 break;
        case 51:mbx+=5;mby-=5;//Number key 3
			 break;
        case 52:mbx-=5;//Number key 4
			 break;
		case 'd':mbx+=5;
			 break;
        case 'D':mbx+=5;
			 break;
        case 54:mbx+=5;//Number key 6
			 break;
        case 55:mbx-=5;mby+=5;//Number key 7
			 break;
		case 'w':mby+=5;
			 break;
        case 'W':mby+=5;
			 break;
        case 56:mby+=5;//Number key 8
			 break;
        case 57:mbx+=5;mby+=5;//Number key 9
			 break;
		case 's':mby-=5;
			 break;
        case 'S':mby-=5;
			 break;
        case 50:mby-=5;//Number key 2
			 break;
        case 'n':
            if(appstate==0)
                appstate=1;
            else if(appstate==1)
                appstate=2;
             break;
        case 'N':
            if(appstate==0)
                appstate=1;
            else if(appstate==1)
                appstate=2;
             break;
        case 32 :appstate=1;//Space bar
                if(automove)
                    automove=0;
                else
                    automove=1;
                break;
        default:printf("%d\n",key);
	}
	glutPostRedisplay();
}
void delay()
{
	for(i=0;i<5000;i++)
	for(j=0;j<5000;j++)
	;
}
void setColor()
{
    if(mbx>=240&&mbx<=560&&mby>=240&&mby<=560)//Within weak BS1
    {
        fb1=0;han1=0;
        c1[0]=1;c1[1]=1;c1[2]=0;
        if(mbx>301&&mbx<499&&mby>260&&mby<540)//Within Strong BS1
        {
            c1[0]=0;c1[1]=0.5;c1[2]=1;
            fb1=1;
        }
        drawline(bs1[0],bs1[1],mbx,mby);
        drawline(bs1[0],bs1[1],MSC[0],MSC[1]);
        if(mbx>=500&&mbx<=825&&mby<=425&&mby>=75)//Handoff?
        {
            c2[0]=1;c2[1]=1;c2[2]=0;
            han1=1;
            drawline(bs2[0],bs2[1],MSC[0],MSC[1]);
            drawline(bs2[0],bs2[1],mbx,mby);
        }
        else
        {
            c2[0]=1;c2[1]=0;c2[2]=0;
        }
        c3[0]=1;c3[1]=0;c3[2]=0;
        if(fb1==1)
            strcpy(str,conbs11);
        else if(han1==1)
            strcpy(str,hand12);
        else
            strcpy(str,conbs12);
    }
    else if(mbx>=725&&mbx<=1075&&mby>=225&&mby<=575)//Within weak BS3
    {
        fb3=0;han2=0;
        c3[0]=1;c3[1]=1;c3[2]=0;
        if(mbx>=801&&mbx<=999&&mby>=260&&mby<=540)//Within strong BS3
        {
            c3[0]=0;c3[1]=0.5;c3[2]=1;
            fb3=1;
        }
        drawline(bs3[0],bs3[1],mbx,mby);
        drawline(bs3[0],bs3[1],MSC[0],MSC[1]);
        if(mbx>=500&&mbx<=801&&mby<=425&&mby>=75)//Handoff?
        {
            c2[0]=1;c2[1]=1;c2[2]=0;
            han2=1;
            drawline(bs2[0],bs2[1],MSC[0],MSC[1]);
            drawline(bs2[0],bs2[1],mbx,mby);
        }
        else
        {
            c2[0]=1;c2[1]=0;c2[2]=0;
        }
        c1[0]=1;c1[1]=0;c1[2]=0;
        if(fb3==1)
            strcpy(str,conbs31);
        else if(han2==1)
            strcpy(str,hand23);
        else
            strcpy(str,conbs32);
    }
    else if(mbx>=500&&mbx<=801&&mby<=425&&mby>=75)//Within weak BS2
    {
        fb2=0;han1=0;han2=0;
        c2[0]=1;c2[1]=1;c2[2]=0;
        if(mbx>=551&&mbx<=749&&mby>=95&&mby<=405)//Within strong BS2
        {
            c2[0]=0;c2[1]=0.5;c2[2]=1;
            fb2=1;
        }
        drawline(bs2[0],bs2[1],mbx,mby);
        drawline(bs2[0],bs2[1],MSC[0],MSC[1]);
        if(mbx>=240&&mbx<=560&&mby>=240&&mby<=560)//Handoff with BS1
        {
            c1[0]=1;c1[1]=1;c1[2]=0;han1=1;
            c3[0]=1;c3[1]=0;c3[2]=0;
            drawline(bs1[0],bs1[1],mbx,mby);
        }
        else if(mbx>=725&&mbx<=1075&&mby>=225&&mby<=575)//Handoff with BS3
        {
            c1[0]=1;c1[1]=0;c1[2]=0;han2=1;
            c3[0]=1;c3[1]=1;c3[2]=0;
            drawline(bs3[0],bs3[1],mbx,mby);
        }
        else
        {
            c1[0]=1;c1[1]=0;c1[2]=0;
            c3[0]=1;c3[1]=0;c3[2]=0;
        }
         if(fb2==1)
            strcpy(str,conbs21);
        else if(han1==1)
            strcpy(str,hand12);
        else if(han2==1)
            strcpy(str,hand23);
        else
            strcpy(str,conbs22);
    }
    else
    {
        c1[0]=1;c1[1]=0;c1[2]=0;
        c2[0]=1;c2[1]=0;c2[2]=0;
        c3[0]=1;c3[1]=0;c3[2]=0;
        strcpy(str,ntcon);
    }
}
void displayMain()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,0);
	BaseStation();
	setColor();

	drawstring(0,600,str);//Connection status
    //Outgoing concentric circles
    displayCirc(bs1,c1,k1);
    displayCirc(bs2,c2,k1);
    displayCirc(bs3,c3,k1);

    displayCirc(bs1,c1,k2);
    displayCirc(bs2,c2,k2);
    displayCirc(bs3,c3,k2);

    displayCirc(bs1,c1,k3);
    displayCirc(bs2,c2,k3);
    displayCirc(bs3,c3,k3);
    delay();
    glFlush();
}
void displayFront()
{
    glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
        glVertex2f(250,0);
        glVertex2f(950,0);
        glVertex2f(950,700);
        glVertex2f(250,700);
    glEnd();
	glColor3f(0,0,0);
	glRasterPos2f(440,450);
	int len=strlen(str1);
	int i;
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str1[i]);
	glColor3f(0,0,1);
	glRasterPos2f(400,420);
	len=strlen(str2);
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str2[i]);
	glColor3f(0,0,0);
	glRasterPos2f(550,150);
	len=strlen(str3);
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str3[i]);
	glRasterPos2f(390,100);
	len=strlen(str4);
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str4[i]);
	glRasterPos2f(390,70);
	len=strlen(str5);
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str5[i]);
    glColor3f(1,0,0);
	glRasterPos2f(370,550);
	len=strlen(headr1);
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,headr1[i]);
	glColor3f(1,0,0);
	glRasterPos2f(370,500);
	len=strlen(headr2);
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,headr2[i]);
    glColor3f(1,0,0);
	glRasterPos2f(460,30);
	len=strlen(str6);
	for(i=0;i<len;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str6[i]);
	glFlush();
}
void displayInfoTitleString(char info[],int x,int y)
{
    glRasterPos2f(x,y);
    j=strlen(info);
	for(i=0;i<j;i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,info[i]);
}
void displayInfoString(char info[],int x,int y)
{
    glRasterPos2f(x,y);
    j=strlen(info);
	for(i=0;i<j;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,info[i]);
}
void diplayInfo()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    strcpy(info,"Mobile Handoff");
    displayInfoTitleString(info,10,655);
    strcpy(info,"   The process of transferring an ongoing call/data session from one channel connected to a core network to another channel.");
    displayInfoString(info,10,630);
    strcpy(info,"Types of GSM Handoff(Based on cell)");
    displayInfoTitleString(info,10,580);
    strcpy(info,"* Intra-BS Handoff: Change of frequency/slot used by mobile during time of interference or other anamolies within current BS.");
    displayInfoString(info,10,550);
    strcpy(info,"* Inter-BS Intra-BSC Handoff***: Handoff process that occurs when mobile moves to area of one BS to another(within BSC).");
    displayInfoString(info,10,520);
    strcpy(info,"* Inter-BSC Handoff: Handoff process that occurs when mobile moves to area of one BSC to another(within MSC).");
    displayInfoString(info,10,490);
    strcpy(info,"* Inter-MSC Handoff: Handoff process that occurs when mobile moves to area of one MSC to another.");
    displayInfoString(info,10,460);
    strcpy(info,"Inter-BS Intra-BSC Handoff");
    displayInfoTitleString(info,10,410);
    strcpy(info,"   This is a GSM handoff that occurs when the mobile moves out of the coverage area of one BTS into another BTS of same BSC. In this instance,");
    displayInfoString(info,10,380);
    strcpy(info,"the BSC is able to perform the handoff and it assigns a new channel slot to mobile, before releasing the old BTS channel from communicating with");
    displayInfoString(info,10,350);
    strcpy(info,"the device.");
    displayInfoString(info,10,320);
	j=strlen(info);
    strcpy(info,"NOTE:");
    displayInfoTitleString(info,10,180);
    strcpy(info,"*** --> Demonstrated in this project");
    displayInfoString(info,10,150);
    strcpy(info,"BS  :  Base Station, also called Base Transceiver Station[BTS]");
    displayInfoString(info,10,120);
    strcpy(info,"BSC :  Base Station Control");
    displayInfoString(info,10,90);
    strcpy(info,"MSC :  Mobile Switching Center");
    displayInfoString(info,10,60);
    strcpy(info,"GSM :  Global System for Mobile communication");
    displayInfoString(info,10,30);
    glFlush();
}
void display()
{
    if(appstate==1)
        displayMain();
    else if(appstate==0)
        displayFront();
    else
        diplayInfo();
}
void idle()
{
    k1+=5;k2+=5;k3+=5;
    if(k1==145)
        k1=-10;
    if(k2==145)
        k2=-10;
    if(k3==145)
        k3=-10;
    glutPostRedisplay();
    if(automove)
    {
        //right to left
        if(stat1)
        {
            if(mbx>=200)
            {
                mbx-=5;
                glutPostRedisplay();
            }
            else
                stat1=0;
        }
        //left to right
        else
        {
            if(mbx<=1050)
            {
                mbx+=5;
                glutPostRedisplay();
            }
            else
                stat1=1;
        }
        if(stat2)
        {
            //Top to bottom
            if(mby>=200)
            {
                mby-=4;
                glutPostRedisplay();
            }
            else
                stat2=0;
        }
        else
        {
            //Bottom to top
            if(mby<=450)
            {
                mby+=4;
                glutPostRedisplay();
            }
            else
                stat2=1;
        }
    }
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1250,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Inter-BTS Intra-BSC Mobile Device Handoff Mechanism");
	glutDisplayFunc(display);
	dropmenu=glutCreateMenu(menu);
        glutAddMenuEntry("Start auto-movement",1);
        glutAddMenuEntry("Stop auto-movement",2);
        glutAddMenuEntry("Info",3);
        glutAddMenuEntry("Exit",4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glClearColor(0,0,0,0);
	gluOrtho2D(0,1250,0,700);
	glutMainLoop();
	return 0;
}
