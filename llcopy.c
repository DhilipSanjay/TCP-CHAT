#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

struct Llist{
    int client_id;
    struct Llist *next;
};

struct Llist *head = NULL,*tail = NULL;


void create(int c_id){

 struct Llist *nn = (struct Llist*)malloc(sizeof(struct Llist));

 if(nn == NULL){
  printf("Error in allocating memory!");
  return;
 }

 nn->client_id = c_id;
 
 if(head == NULL && tail == NULL){
  head = nn; 
  tail = nn;
  nn->next = NULL;
 }else{
  tail->next = nn;
  tail = nn;
  tail->next = NULL;
 }
}

void findandremove(int c_id){
 
 if(head == NULL){
  printf("Linked list is empty!");
  return;
 }

 struct Llist *ptr = head;
 struct Llist *prevptr = NULL;
 
 while(ptr != NULL){
  if(ptr->client_id == c_id){
    
   if(prevptr == NULL){ //if present in head
     head = head->next;
     free(ptr);
     break;
   }else{
     prevptr->next = ptr->next;
     free(ptr);
     break;
   }
  }

  prevptr = ptr;
  ptr = ptr->next;
 }
}

void print(){
 
 struct Llist *ptr = head;
 
 while(ptr != NULL){
   
   printf("Client id = %d", ptr->client_id);
   ptr = ptr->next;
 }
}
