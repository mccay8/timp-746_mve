#include<stdio.h>
int main(void){
int n,x,k;
n=0;
x=0;
k=0;
printf("Vvedite n"); 
scanf("%d",&n);
for(int i=1; i<=n;i++){
printf("Vvedite x"); 
scanf("%d",&x);
if (x>0)
k=k+1;
}
printf("Tchisel bol'she 0 : ");
printf("%d",k); 
printf("\n"); 
return 0; 
}
 
