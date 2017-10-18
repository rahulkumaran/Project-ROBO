#include <graphics.h>
#include <stdio.h>

float X=25,Y=25;
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
    putpixel(x,y,RED);
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
  DDARect(X-1.75,Y-6,X+1.75,Y+6);
  delay(500);
  getch();
}
