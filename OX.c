#include<stdio.h>
#include<rgb.h>
#include<gl.h>

int MouseX=-100, MouseY=-100, flag[10]={0}, xx[10]={0}, yy[10]={0}, count=0, i[10]={0}, j, c, k;
char ox[10];

void hantei(int d){
	flag[d]=1;
	if(d==1||d==4||d==7) xx[d]=1;
	if(d==2||d==5||d==8) xx[d]=2;
	if(d==3||d==6||d==9) xx[d]=3;
	if(d==1||d==2||d==3) yy[d]=1;
	if(d==4||d==5||d==6) yy[d]=2;
	if(d==7||d==8||d==9) yy[d]=3;
	count++;
	i[d]=count;
}

void marubatsu(b){
	if(i[b]%2==1){
		if(flag[b]==1){
			glBegin(GL_LINE_LOOP);
			glVertex2i(80*xx[b]+10,80*yy[b]+10);
			glVertex2i(80*(xx[b]+1)-10,80*yy[b]+10);
			glVertex2i(80*(xx[b]+1)-10,80*(yy[b]+1)-10);
			glVertex2i(80*xx[b]+10,80*(yy[b]+1)-10);
			glEnd();
			ox[b]='o';
		}
	}
	else{
		if(flag[b]==1){
			glBegin(GL_LINES);
			glVertex2i(80*xx[b]+10,80*yy[b]+10);
			glVertex2i(80*(xx[b]+1)-10,80*(yy[b]+1)-10);
			glVertex2i(80*(xx[b]+1)-10,80*yy[b]+10);
			glVertex2i(80*xx[b]+10,80*(yy[b]+1)-10);
			glEnd();
			ox[b]='x';
		}
	}
}

void win(void){
	glBegin(GL_LINE_STRIP);
	glVertex2i(132,390);
	glVertex2i(132,360);
	glVertex2i(132,330);
	glVertex2i(172,330);
	glVertex2i(172,360);
	glVertex2i(132,360);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2i(180,330);
	glVertex2i(180,390);
	glVertex2i(200,330);
	glVertex2i(200,390);
	glVertex2i(220,330);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2i(268,330);
	glVertex2i(248,390);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2i(276,390);
	glVertex2i(296,330);
	glVertex2i(296,390);
	glVertex2i(316,330);
	glEnd();
}

void owin(void){
	glBegin(GL_LINE_STRIP);
	glVertex2i(124,330);
	glVertex2i(124,390);
	glEnd();
	win();
	c=1;
}

void xwin(void){
	glBegin(GL_LINE_STRIP);
	glVertex2i(84,330);
	glVertex2i(124,330);
	glVertex2i(124,360);
	glVertex2i(84,360);
	glVertex2i(84,390);
	glVertex2i(124,390);
	glEnd();
	win();
	c=1;
}

void display(void){	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int *x, *y;
	x = &MouseX;
	y = &MouseY;
	c=0;
	if(*x>80&&*x<160&&*y>80&&*y<160&&i[1]==0) hantei(1);
	if(*x>160&&*x<240&&*y>80&&*y<160&&i[2]==0) hantei(2);
	if(*x>240&&*x<320&&*y>80&&*y<160&&i[3]==0) hantei(3);
	if(*x>80&&*x<160&&*y>160&&*y<240&&i[4]==0) hantei(4);
	if(*x>160&&*x<240&&*y>160&&*y<240&&i[5]==0) hantei(5);
	if(*x>240&&*x<320&&*y>160&&*y<240&&i[6]==0) hantei(6);
	if(*x>80&&*x<160&&*y>240&&*y<320&&i[7]==0) hantei(7);
	if(*x>160&&*x<240&&*y>240&&*y<320&&i[8]==0) hantei(8);
	if(*x>240&&*x<320&&*y>240&&*y<320&&i[9]==0) hantei(9);
	for(k=1;k<10;k++){
		marubatsu(k);
	}
	if(ox[1]=='o'&&ox[4]=='o'&&ox[7]=='o') owin();
	if(ox[2]=='o'&&ox[5]=='o'&&ox[8]=='o') owin();
	if(ox[3]=='o'&&ox[6]=='o'&&ox[9]=='o') owin();
	if(ox[1]=='o'&&ox[2]=='o'&&ox[3]=='o') owin();
	if(ox[4]=='o'&&ox[5]=='o'&&ox[6]=='o') owin();
	if(ox[7]=='o'&&ox[8]=='o'&&ox[9]=='o') owin();
	if(ox[1]=='o'&&ox[5]=='o'&&ox[9]=='o') owin();
	if(ox[3]=='o'&&ox[5]=='o'&&ox[7]=='o') owin();

	if(ox[1]=='x'&&ox[4]=='x'&&ox[7]=='x') xwin();
	if(ox[2]=='x'&&ox[5]=='x'&&ox[8]=='x') xwin();
	if(ox[3]=='x'&&ox[6]=='x'&&ox[9]=='x') xwin();
	if(ox[1]=='x'&&ox[2]=='x'&&ox[3]=='x') xwin();
	if(ox[4]=='x'&&ox[5]=='x'&&ox[6]=='x') xwin();
	if(ox[7]=='x'&&ox[8]=='x'&&ox[9]=='x') xwin();
	if(ox[1]=='x'&&ox[5]=='x'&&ox[9]=='x') xwin();
	if(ox[3]=='x'&&ox[5]=='x'&&ox[7]=='x') xwin();

	glColor3f(0,0,0);
	glLineWidth(3);
	glBegin(GL_LINES);
	for(int i=0;i<4;i++){
		glVertex2i(80+80*i,320);
		glVertex2i(80+80*i,80);
		glVertex2i(80,80+80*i);
		glVertex2i(320,80+80*i);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(rgb(255), rgb(0), rgb(0));
	glVertex2i(340,340);
	glColor3d(rgb(0), rgb(255), rgb(0));
	glVertex2i(380,340);
	glColor3d(rgb(0), rgb(0), rgb(255));
	glVertex2i(380,380);
	glColor3d(rgb(255), rgb(255), rgb(0));
	glVertex2i(340,380);
	glColor3d(rgb(0), rgb(0), rgb(0));
	glEnd();
	
	if((*x>340&&*x<380&&*y>340&&*y<380)||c==1){
		for(j=0;j<10;j++){
		xx[j]=0;
		yy[j]=0;
		flag[j]=0;
		i[j]=0;
		ox[j]='a';
		}
		count=0;
		MouseX=-100;
		MouseY=-100;
	}
	glutSwapBuffers();
}

void mouse( int button, int state, int x, int y ){
	if( button==GLUT_LEFT_BUTTON && state==GLUT_DOWN ){
		MouseX=x;
		MouseY=y;
		glutPostRedisplay();
	}
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);	
	glutInitWindowSize(400,400);//ウィンドウの画面の幅と高さを指定
	glutInitWindowPosition(0, 0);//ウィンドウの場所を指定
	glutCreateWindow("ox");//ウィンドウの名前
	glClearColor(rgb(255), rgb(255), rgb(255), 1);//オセロ盤の色
	gluOrtho2D(0, 400, 400,0);//座標系の設定
	glutDisplayFunc(display);//描画関数を指定
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
