#include <stdio.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "LinkedList.h"

struct LinkedList* create(){
	struct LinkedList *list = malloc(sizeof(struct LinkedList));
	list->head = NULL;
	return list; 
}

//create a node with a word, doc and bucket 
struct Node *newNode(char *word, int doc, int bucket){
	struct Node *node = malloc(sizeof(struct Node));
	node->word = word;
	node-> doc= doc;
	node-> bucket = bucket;
	node-> next = NULL;
	return node;  
}

//clear a list 
void clearLinkedList(struct LinkedList *list){
	list-> size= 0; 
	if(list -> head == NULL ){
		free(list-> head);
	}else if (list -> head != NULL){
		struct Node *cur = malloc(sizeof(struct Node));
		struct Node *curNxt = malloc(sizeof(struct Node));
		cur = list-> head ; 
		while(cur!= NULL){
			curNxt = cur-> next;
			cur= NULL;
			free(cur);
			cur= curNxt;
		}

		curNxt= NULL;
		free(curNxt);

		cur= NULL;
		free(cur);
		
		list-> head= NULL; 
		free(list-> head);
	}
}
