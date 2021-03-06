#include <stdio.h>
#include <stdlib.h>
void print_magic_square(int n, int magic_square[n][n]){  
  int r, c;
  for(r=0;r<n;r++){
    for(c=0;c<n;c++){
      printf("%7d",magic_square[r][c]);
    }
    printf("\n");
  }
  printf("\n");
}

void create_magic_square(int n, int magic_square[n][n]){
  int c=(n/2), Max=n*n, r=0, t;
  for(t=1; t<=Max; ++t){
    magic_square[r][c]=t;
    r--;
    c++;
    if(t%n==0){
      r=r+2;
      c=c-1;
    }
    else{
      if(c==n){
	c=c-n;
      }
      else if(r<0){
	r=r+n;
      }
    }
  }
  print_magic_square(n, magic_square);
}
int main(){

  int n;
  int matrix[99][99];
  printf("Enter the size of magic square:");
  scanf("%d",&n);
  if (n%2==0){
    printf("Please enter odd number\n");
    exit(-1);
  }
  create_magic_square(n, matrix);
}

  

