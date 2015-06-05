#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
int main()
{ int driver=0, mode = 0, maloi;

   initgraph(&driver,&mode,"C:/TC/BGI");

   if ( (maloi=graphresult()) !=0 )
     {
     printf("khong the khoi dong do hoa \n");
     printf("ma loi : &d \nnguyen nhan loi %s ",maloi, grapherrormsg(maloi) );
     getch();
     exit(1);
     }
   randomize(); // kh?i t?o hàm radom (cho s? ng?u nhiên)
  int i=0;

  while (i<200)
  {
   putpixel(random(639), random(476), WHITE); /* random(639) t?c là cho s? ng?u nhiên trong kho?ng 0->639,  v? m?t di?m có to? d? x,y cho ng?u nhiên v?i màu tr?ng */
  i++;
  }
getch();
int mau=getpixel(100,100); /* l?y màu c?a di?m ?nh trên màn hình t?i v? trí có to? d? (100,100)  */
closegraph();

printf("mau cua diem anh tai vi tri co toa do (100,100) la : %d",mau);
getch();
}
