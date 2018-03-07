/*Mengyang Chen 
  1412408*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
  int digit;
  struct node *next;
};


struct node * create_list(int num) {
  struct node *root = NULL;
  if (num==0){
    struct node *cur = malloc(sizeof(struct node));
    cur->digit = num;
    cur->next = root;
    return cur;
  }
  else{
    while (num != 0) {
      struct node *cur = (struct node*)malloc(sizeof(struct node));
      cur->next = root;
      cur->digit = num % 10;
      root = cur;
      num /= 10;
    }
    return root;
  }
}

int convert_list_2_int(struct node * root) {
  int sum = 0;
  while (root) {
    sum *= 10;
    sum += root->digit; 
    root = root->next;
  }
  return sum;
}


struct node *diff(struct node *num1, struct node *num2) {
  int n1 = convert_list_2_int(num1);
  int n2 = convert_list_2_int(num2);
  int n3 = abs(n1 - n2);

  return create_list(n3);
}


void print_list(struct node *root) {
  while (root) {
    printf("%d", root->digit);
    root = root->next;
  }
  printf("\n");
}

int main(int argc, char** argv) {
  int num1, num2;
  scanf("%d%d", &num1, &num2);
  struct node *l1 = create_list(num1);
  struct node *l2 = create_list(num2);
  struct node *l3 = diff(l1, l2);
  //print_list(l1);
  //print_list(l2);
  print_list(l3);
  free(l1);
  free(l2);
  free(l3);
  return 0;
}
