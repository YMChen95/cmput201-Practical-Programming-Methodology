#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool is_palindorm(const char* string){
  size_t len = strlen(string);
  
  if (len == 0) return 0;
  if (len == 1) return 1;
  
  const char *ptr1 = string;
  const char *ptr2 = string + len - 1;
  //printf("%s\n", string + len -1);
  while(ptr2 >= ptr1) {
    if (!isalpha(*ptr2)) {
      ptr2--;
      continue;
    }
    if (!isalpha(*ptr1)) {
      ptr1++;
      continue;
    }
    if( tolower(*ptr1) != tolower(*ptr2)) {
      return false;
    }
    ptr1++; ptr2--;
  }
  return true;
}

int main(){
  char str,string[99];
  int i=0;
  printf("Enter a message: ");
  while (i < 128 && (str = getchar()) != '\n')
    if (isalpha(str))
      string[i++] = tolower(str);
  string[i]='\0';
  if(is_palindorm(string)==1){
    printf("Palindrome\n");
  }
  else
    printf("Not palindrome\n");
}
