#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
  free(head->next);
  return val;
}

int delete(node *head, int val){
  node *a = head->next;
  while(a->next != NULL){
    if(a->val == val){
      connect(a->prev, a->next);
      free(a);
      return val;
    }
    a = a->next;
  }
  return -1;
}

void display(node *head){
  node *a = head->next;
  while(a->next != NULL){
    printf("%d, ", a->val);
    a = a->next;
  }
  printf("\n");
}

int main(){
  srand((unsigned int)time(NULL));
  int n = 100;
  node *head, *tail;
  int i, a;
  head = (node *)malloc(sizeof(node));
  tail = (node *)malloc(sizeof(node));
  tail->next = NULL;
  connect(head, tail);
  if(get(head)==-1) printf("This Queue is initial state.\n");
  printf("Add numbers in the following.\n");
  /*
  for(i=0; i<10; i++){
    put(tail, i);
    printf("%d, ", i);
  }
  printf("\nThis Queue includes the following.\n");
  display(head);
  printf("Delete odds.\n");
  for(i=0; i<5; i++) delete(head, 2*i+1);
  display(head);
  printf("11 isn't includes, so return %d\n", delete(head, 11));
  printf("get first term %d\n", get(head));
  display(head);
  for(i=0; i<4; i++) get(head);
  if(get(head)==-1) printf("free all.\n");
  */
  for(i=0; i<n; i++){
    a = rand() % n;
    put(tail, a);
    printf("%d, ", a);
  }
  printf("\nThis Queue includes the following.\n");
  display(head);
  for(i=0; i<n/10; i++){
    a = rand() % n;
    printf("Run 'delete(%d)' -> ", a);
    if(delete(head, a)==-1) printf("This Queue doesn't include %d.\n", a);
    else printf("Delete %d.\n", a);
  }
  printf("This Queue includes the following.\n");
  display(head);
  printf("Get 10 terms from the head.\n");
  for(i=0; i<10; i++){
    printf("%d, ", get(head));
  }
  printf("\nDisplay the remaining.\n");
  display(head);
  a = 0;
  while(a!=-1) a = get(head);
  printf("Free all.\n");
  free(head);
  return 0;
}
