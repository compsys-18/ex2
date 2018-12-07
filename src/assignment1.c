#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
  int val;
  struct _node *next;
  struct _node *prev;
}node;

void connect(node *a, node *b){
  a->next = b;
  b->prev = a;
}

int put(node *tail, int val){
  node *new;
  new = (node *)malloc(sizeof(node));
  if(new == NULL || tail == NULL || tail->prev == NULL) return -1;
  new->val = val;
  connect(tail->prev, new);
  connect(new, tail);
  return 0;
}

int get(node *head){
  node *second = head->next->next;
  if(head == NULL || head->next == NULL || second == NULL) return -1;
  int val = head->next->val;
  connect(head, second);
  return val;
}

int delete(node *head, int val){
  return 0;
}

void display(node *head){
}

int main(){
  return 0;
}