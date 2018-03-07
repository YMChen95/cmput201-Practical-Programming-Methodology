#include <stdio.h>
#include <math.h>

int main(void){

  double a, x, y;
printf("Enter a positive number:");
  scanf("%lf", &a);
  if(a==0){
    y=a;
  } 
  else{
    x=1;
    y=a;
    while(fabs(x-y) >= 0.00001){    
      x=y;
      y=(x+a/x)/2;
    }
  }
  printf("Square root: %lf\n",y);
}

