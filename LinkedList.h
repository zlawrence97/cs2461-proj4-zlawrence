#ifndef LinkedListFile
#define LinkedListFile

 struct Node{
	char *word;
	int *doc;
	int *bucket; 
	struct Node *next;
}; 

 struct LinkedList{
	struct Node *head;
	int size; 
};


struct LinkedList *create();

 
struct Node *newNode(char *word, int doc, int bucket); 


void clearLinkedList();

#endif
