#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int palindrome(char a[100], int n)
{
  int left, right;
  for (left=0,right=n;left <= right; left++, right--)
    if (a[left] != a[right]){
      return 0;
    }
  return 1;
} 

int main(){
  char str, message[100];
  
  int i = 0;
  printf("Enter a message: ");

  while (i < 128 && (str = getchar()) != '\n')
    if (isalpha(str))
      message[i++] = tolower(str);

  if (palindrome(message,i - 1)==1){
    printf("Palindrome.\n");
  }
  else
    printf("Not palindrome.\n");

  return 0;
}

                                                                                  
