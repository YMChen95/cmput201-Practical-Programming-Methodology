#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int palindorm(char* string){
  int len = strlen(string);

  //printf("%d\n",len);
  if (len == 0) return 0;
  if (len == 1) return 1;
  
  char *ptr1 = string;
  char *ptr2 = string + len-1 ;
  //printf("%s %s\n",string,string+len);
  //printf("%p %p\n",ptr1, ptr2);
  while(ptr2 >= ptr1) {
    if (!isalpha(*ptr1)) {
      ptr1++;
      continue;
    }
    if (!isalpha(*ptr2)) {
      ptr2--;
      continue;
    }

    if( tolower(*ptr1) != tolower(*ptr2)) {
      return 0;
    }
    ptr1++; 
    ptr2--;
  }
  return 1;
}

int main(){
  char str,string[99];
  int i=0;
  printf("Enter a message: ");
  while (i < 128 && (str = getchar()) != '\n')
    if (isalpha(str))
      string[i++] = tolower(str);
  string[i]='\0';
  if(palindorm(string)==1){
    printf("Palindrome\n");
  }
  else
    printf("Not palindrome\n");
}
