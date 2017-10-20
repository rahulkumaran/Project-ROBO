#include <graphics.h>
#include <stdio.h>

float BX=320,BY=240,FX,FY;
void DDALine(float x1,float y1,float x2,float y2)
{
  if(x1>x2 || y1>y2)
  {
    float temp=x1;x1=x2;x2=temp;
    temp=y1;y1=y2;y2=temp;
  }
  float x,y,dx,dy,step;
  dx=abs(x2-x1);dy=abs(y2-y1);
  if(dx>=dy)
    step=dx;
  else
    step=dy;
  dx/=step;dy/=step;
  x=x1;y=y1;
  for(int i=0;i<=step;i++)
  {
    putpixel(x,y,WHITE);
    x+=dx;y+=dy;
  }
}
void DDARect(float x1,float y1,float x2,float y2)
{
  DDALine(x1,y1,x2,y1);DDALine(x2,y1,x2,y2);
  DDALine(x2,y2,x1,y2);DDALine(x1,y1,x1,y2);
}
void main( )
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"NULL");
  //--Head
  FX=BX;FY=BY-60;
  //Cap
  circle(FX,FY-40,5);
  DDARect(FX-2.5,FY-25,FX+2.5,FY-35);
  arc(FX,FY-20,180,360,5);
  //Face
  DDARect(FX-20,FY+20,FX+20,FY-20);//Face Outline
  DDARect(FX-15,FY,FX-5,FY-10);//LEFT_EYE
  DDARect(FX+5,FY,FX+15,FY-10);//RIGHT_EYE
  //Mouth
  DDARect(FX-10,FY+15,FX+10,FY+10);
  //TEETH
  DDARect(FX-2,FY+15,FX+2,FY+10);
  DDARect(FX-6,FY+15,FX+6,FY+10);
  //LEFT_EAR
  DDARect(FX-25,FY,FX-20,FY-10);
  DDARect(FX-30,FY-2.5,FX-25,FY-7.5);
  //RIGHT_EAR
  DDARect(FX+25,FY,FX+20,FY-10);
  DDARect(FX+25,FY-2.5,FX+30,FY-7.5);
  //--BODY
  DDARect(BX-5,BY-30,BX+5,BY-40);//Neck
  DDARect(BX-20,BY+15,BX+20,BY-20);//Body Square
  DDARect(BX-30,BY+30,BX+30,BY-30);//Body
  DDARect(BX-25,BY+70,BX-10,BY+30);//LLeg
  arc(BX-17.5,BY+70,180,360,7.5);
  DDARect(BX+25,BY+70,BX+10,BY+30);//RLeg
  arc(BX+17.5,BY+70,180,360,7.5);
  //Left_Hand
  DDALine(BX-30,BY-15,BX-47,BY-5);
  DDALine(BX-30,BY-5,BX-47,BY+5);
  circle(BX-47,BY,5);
  //Right_Hand
  DDALine(BX+47,BY-5,BX+30,BY-15);
  DDALine(BX+47,BY+5,BX+30,BY-5);
  circle(BX+47,BY,5);

  delay(5000);
  getch();
}
