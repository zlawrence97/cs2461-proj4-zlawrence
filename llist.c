//Zuri Lawrence
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

struct LList* createLList() {
  /* Create an empty linked list. */
  /* DO NOT MODIFY THIS CODE */
  struct LList* list = malloc(sizeof(struct LList));
  list->head = NULL;
  return list;
}

void printList(struct LList *list)
{
  /* Print a list from head to tail. */
  /* DO NOT MODIFY THIS CODE */
  struct LNode *entry;
  if(list == NULL) {
    printf("List has not been initialized!\n");
    return;
  }
  entry = list->head;
  printf("List Contents:\n");
  while(entry != NULL)
  {
    printf("  %s is at %f, %f\n", entry->name, entry->latitude, entry->longitude);
    entry = entry->next;
  }
}


int addNode(struct LList *list, char* name, double lat, double lon) {
    struct LNode* newNode = malloc(sizeof(struct LNode));
    newNode->name = name;
    newNode->longitude = lon;
    newNode->latitude = lat;
    newNode->next = NULL;
  
    if(list==NULL){
      struct LList* nlist = malloc(sizeof(struct LList));
      list->head = newNode;
      return 0;
    }
  
    if(list->head == NULL){
      list->head = newNode;
      return 0;
    }
  
    struct LNode* currentNode = malloc(sizeof(struct LNode));
    currentNode = list->head;
    int counter = 1;
    while(currentNode->next!=NULL){
      currentNode = currentNode->next;
      counter++;
    }
    currentNode->next = newNode;
    return counter;

  return 0;
}


int remNode(struct LList *list, char* name){
    if(list==NULL){
      return -1;
    }
    if(list->head==NULL){
      return -1;
    }
    struct LNode* currentNode = malloc(sizeof(struct LNode));
    currentNode = list->head;
    if((strcmp(currentNode->name,name)==0) && currentNode->next==NULL){
      list->head = NULL;
      return 0;
    }
  
    if(strcmp(currentNode->name,name)==0){
      list->head = currentNode->next;
      return 0;
    }
  
    int j=1;
    while(currentNode->next!=NULL){
      currentNode = currentNode->next;
      j++;
    }
    if(strcmp(currentNode->name,name)==0){
      currentNode = NULL;
      return j;
    }
  
    currentNode = list->head;
    struct LNode* nextNode = malloc(sizeof(struct LNode));
    nextNode = currentNode->next;
    int b=1;
    while(nextNode->next!=NULL){
      if(strcmp(nextNode->name,name)==0){
        nextNode = nextNode->next;
        currentNode->next = NULL;
        currentNode->next = nextNode;
        return b;
      }
      nextNode = nextNode->next;
      currentNode = currentNode->next;
      b++;
    }
}

int addSortedNode(struct LList *list, char* name, double lat, double lon){
  
    struct LNode* newNode = malloc(sizeof(struct LNode));
    newNode->name = name;
    newNode->latitude = lat;
    newNode->longitude = lon;
    newNode->next = NULL;

  
    if(list==NULL){
      return -1;
    }
  
    if(list->head==NULL){
      list->head = newNode;
      return 0;
    }
  
    if(list->head->longitude > newNode->longitude){
      struct LNode* tempNode = malloc(sizeof(struct LNode));
      tempNode = list->head;
      list->head = newNode;
      newNode = tempNode;
      return 0;
    }
  
    if(list->head->next==NULL && list->head->next < newNode){
      list->head->next = newNode;
    }
    else{
      newNode->next = list->head;
      list->head = newNode;
    }
  
    struct LNode* currentNode = malloc(sizeof(struct LNode));
    currentNode = list->head;
  
    //checks if newNode is greatest
    int i=0;
    while(currentNode->next!=NULL){
      i++;
      currentNode = currentNode->next;
    }
    if(currentNode->longitude < newNode->longitude){
      currentNode->next = newNode;
      return i++;
    }
  
    int counter = 1;
    currentNode = list->head;
    struct LNode* nextNode = malloc(sizeof(struct LNode));
    nextNode = currentNode->next;
  
    //before accesssing next nodes longitude, check whether next node is null or not
    while(nextNode->next!=NULL){
      if(nextNode->longitude >= newNode->longitude){
        currentNode->next = newNode;
        newNode->next = nextNode;
        return counter;
      }else{
      nextNode = nextNode->next;
      currentNode = currentNode->next;
      counter++;
      }
    }
    return counter;
}


int clearList(struct LList *list) 
{
  if(list==NULL){
      return 0;
    }
    if(list->head==NULL){
      return 0;
    }
    if(list->head->next==NULL){
      list->head = NULL;
      return 1;
    }
    struct LNode* currentNode = malloc(sizeof(struct LNode));
    currentNode = list->head;
    int count = 1;
    while(currentNode->next!=NULL){
      currentNode = currentNode->next;
      count++;
    }
    list->head = currentNode;
    list->head = NULL;
    return count;
}