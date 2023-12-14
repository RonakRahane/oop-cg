#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
using namespace std;
int main()
{
int gd=DETECT,gm, i,j;
initgraph(&gd,&gm,NULL);
line(20,380,580,380);
line(25,380,35,340);
line(45,380,35,340);
line(35,310,25,330);
line(35,380,35,340);
line(35,310,40,330);
line(35,340,35,310);
circle(35,300,10);
line(35,310,50,330);
line(50,330,50,280);
line(15,280,85,280);
arc(50,280,180,360,35);
arc(55,330,360,180,5);
delay(10000);
getch();
return 0;
}
