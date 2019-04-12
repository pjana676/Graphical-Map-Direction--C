#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
void border();
void point();
union REGS i, o;

int initmouse()
{
   i.x.ax = 0;
   int86(0X33, &i, &o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33, &i, &o);
}

void hidemopuseptr()
{
   i.x.ax = 2;
   int86(0X33,&i,&o);
}

void getmousepos(int *x, int *y, int &cl)
{
   i.x.ax = 3;
   int86(0X33, &i, &o);
   *x = o.x.cx;
   *y = o.x.dx;
   cl=o.x.bx;

}

void movemouseptr(int x, int y)
{
   i.x.ax = 4;
   i.x.cx = x;
   i.x.dx = y;
   int86(0X33, &i, &o);
}


void main()
{
   int gdriver = DETECT, gmode, errorcode,gm;
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
   //cleardevice();
   border();
   point();


   closegraph();
  // getch();
//   return 0;
}
void point()
{
   int x,y,midx,midy,tempx,tempy;
    if(!initmouse())
   {
      closegraph();
      exit(1);
   }

   midx = getmaxx()/2;
   midy = getmaxy()/2;

   showmouseptr();


   x = tempx = midx;
   y = tempy = midy;
   int cl;
   while(!kbhit())
   {
      getmousepos(&x, &y, cl);
/*      gotoxy(40,12);
      printf("%d",x);
      gotoxy(40,13);
      printf("%d",y);
      gotoxy(40,14);
      printf("%d",cl);*/
      if(cl==1)
      {
       printf("dfsdfs");
      }
      else
      {
       //cleardevice();
       border();
       point();
      }


   }

}



void border()
{
 gotoxy(10,1);
 printf(".");
 gotoxy(11,1);
 printf("~");
 gotoxy(12,0);
 printf(".");
 gotoxy(13,0);
 printf(".");
 gotoxy(14,0);
 printf("~");
 gotoxy(15,1);
 printf("~");
 gotoxy(16,1);
 printf(".");
 gotoxy(17,1);
 printf(".");
 gotoxy(18,1);
 printf("~");
 gotoxy(19,2);
 printf(".");
 gotoxy(20,3);
 printf("~");
 gotoxy(21,2);
 printf(".");
 gotoxy(22,1);
 printf(".");
 gotoxy(23,1);
 printf("*");
 gotoxy(24,1);
 printf(".");
 gotoxy(25,1);
 printf(".");
 gotoxy(26,1);
 printf("*");
 gotoxy(27,2);
 printf("~");
 gotoxy(27,2);
 printf(".");
 gotoxy(26,3);
 printf("`");
 gotoxy(27,3);
 printf(".");
 gotoxy(27,4);
 printf("~");
 gotoxy(26,4);
 printf(".");
 gotoxy(26,5);
 printf("'");
 gotoxy(26,5);
 printf(".");
 gotoxy(27,5);
 printf("*");
 gotoxy(28,5);
 printf(".");
 gotoxy(28,5);
 printf(".");
 gotoxy(28,6);
 printf("*");
 gotoxy(28,7);
 printf(",");
 gotoxy(29,7);
 printf("*");
 gotoxy(30,7);
 printf(",");
 gotoxy(31,7);
 printf(".");
 gotoxy(32,7);
 printf("*");
 gotoxy(33,8);
 printf("~");
 gotoxy(34,8);
 printf("*");
 gotoxy(35,8);
 printf(".");
 gotoxy(36,9);
 printf("~");
 gotoxy(37,9);
 printf("~");
 gotoxy(38,9);
 printf("~");
 gotoxy(39,9);
 printf("~");
 gotoxy(40,8);
 printf(".");
 gotoxy(41,7);
 printf(".");
 gotoxy(42,7);
 printf("*");
 gotoxy(42,6);
 printf(".");
 gotoxy(43,6);
 printf("~");
 gotoxy(43,7);
 printf("~");
 gotoxy(44,7);
 printf("*");
 gotoxy(45,7);
 printf("*");
 gotoxy(46,7);
 printf("*");
 gotoxy(47,7);
 printf("~");
 gotoxy(47,6);
 printf(".");
 gotoxy(48,6);
 printf("*");
 gotoxy(49,6);
 printf("~");
 gotoxy(50,5);
 printf(".");
 gotoxy(51,5);
 printf("*");
 gotoxy(52,5);
 printf("*");
 gotoxy(53,5);
 printf("~");
 gotoxy(54,5);
 printf("*");
 gotoxy(55,5);
 printf(".");
 gotoxy(56,5);
 printf(".");
 gotoxy(57,5);
 printf(".");
 gotoxy(57,6);
 printf("~");
 gotoxy(56,7);
 printf("~");
 gotoxy(56,8);
 printf("*");
 gotoxy(56,9);
 printf("*");
 gotoxy(56,10);
 printf("*");
 gotoxy(56,11);
 printf("~");
 gotoxy(55,12);
 printf("~");
 gotoxy(55,13);
 printf("*");
 gotoxy(55,14);
 printf(".");
 gotoxy(54,13);
 printf(".");
 gotoxy(54,12);
 printf("*");
 gotoxy(53,13);
 printf("*");
 gotoxy(53,12);
 printf("*");
 gotoxy(53,11);
 printf(".");
 gotoxy(53,10);
 printf(" ");
 gotoxy(52,10);
 printf(".");
 gotoxy(51,10);
 printf("*");
 gotoxy(50,10);
 printf("*");
 gotoxy(49,10);
 printf("*");
 gotoxy(48,10);
 printf("~");
 gotoxy(48,9);
 printf(".");
 gotoxy(47,9);
 printf("*");
 gotoxy(46,9);
 printf("*");
 gotoxy(45,9);
 printf("~");
 gotoxy(45,10);
 printf("*");
 gotoxy(45,11);
 printf("*");
 gotoxy(46,12);
 printf("*");
 gotoxy(46,13);
 printf("*");
 gotoxy(47,14);
 printf("*");

 for(int i=46,j=14;i>=29;i=i-2,j++)
 {
  gotoxy(i,j);
  printf("*");
 }
 gotoxy(29,21);
 printf("*");
 gotoxy(29,22);
 printf("*");
 gotoxy(28,23);
 printf("*");
 gotoxy(28,24);
 printf("*");
 gotoxy(27,24);
 printf("*");
 gotoxy(26,25);
 printf("*");

 gotoxy(25,25);
 printf(".");

 for(i=24,j=24;j>=14;j--,i--)
 {
  gotoxy(i,j);
  printf("*");
 }
 gotoxy(12,15);
 printf("*");
 gotoxy(11,16);
 printf("~");
 gotoxy(10,15);
 printf("*");
 gotoxy(8,14);
 printf("*");
 gotoxy(10,14);
 printf("~");
 gotoxy(8,13);
 printf("*");
 gotoxy(7,12);
 printf("*");
 gotoxy(9,12);
 printf("~");
 gotoxy(10,11);
 printf(".");
 gotoxy(11,10);
 printf("*");
 gotoxy(12,9);
 printf("*");
 gotoxy(9,8);
 printf("*");
 gotoxy(12,7);
 printf("~");
 gotoxy(15,5);
 printf("*");
 gotoxy(13,4);
 printf("*");
 gotoxy(10,2);
 printf("*");


 //Delhi
 gotoxy(21,8);
 printf("@Delhi");
 //Kolkata
 gotoxy(43,13);
 printf("@");
 gotoxy(38,14);
 printf("Kolkata");
 //Mumbai
 gotoxy(18,17);
 printf("@Mumbai");
 //Chennai
 gotoxy(28,22);
 printf("@");
 gotoxy(29,22);
 printf("Chennai");
 //Bangalore
 gotoxy(24,21);
 printf("@Bangalore");
 //Ahmedabad
 gotoxy(14,14);
 printf("@Ahmedabad");


}
