#include<stdio.h>
#include<math.h>
int main(void){
int a,b,rez;
a=0;
b=0;
printf("Vvedite a");
scanf("%d",&a); 
printf("Vvedite b");
scanf("%d",&b);
rez=pow(a,b); 
printf("%d",rez);
printf("\n");
return 0;
}
