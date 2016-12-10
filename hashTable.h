
#ifndef hashTableFile
#define hashTableFile

#include "LinkedList.h"

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

/*This file reads in three documents named 
"D1.txt", "D2.txt" and "D3.txt" these three documents 
are required in order for the program to run. 
*/


int buckets;
char* inwords;
int scoresheet[4];
struct LinkedList** hashTable; 
int end = 0;
int query = 0;
int roundOfQuery = 1; 
int capacity; 


int main();


void getKeyWords();

void stopHashing();

void training();

void readFile(char *file, int doc);

void hash_table_insert(char *word, int doc);


void add(char *word, int doc, int bucket);

void read_query(char * inputWords);

void rank(char *inwords, struct LinkedList *list, char * word);

void getQuery();


void match();

 
void clearQuery();

int hash_code(char* word);

#endif

