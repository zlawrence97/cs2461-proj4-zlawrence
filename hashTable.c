#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

#include "hashTable.h"
#include "LinkedList.h"

int main(){
	
	printf("Enter number of buckets: ");
	scanf(" %d", &buckets);

	printf("\n Enter bucket capcity: ");
	scanf(" %d", &capacity);
	
	if(buckets > capacity){
			int temp = capacity;
			capacity = buckets;
			buckets = temp;
	}
	
	training();
	getKeyWords();
	stopHashing();
	return 0; 
}

void getKeyWords(){
	while(end != 1){
		if(roundOfQuery > 0){
			printf("Press 'S' to search and 'X' to Exit: ");
			roundOfQuery++;
			getQuery();
		}
		
		//Chech the Keywords and return the 
		if(inwords[0] == 'X' || inwords[0] == 'x'){
			end = 1;
		}
		else {
			printf("Enter a set of key words (separated by spaces), \npress enter when done.\n ");
			getQuery();
			read_query(inwords);
			match();
			clearQuery();
		}
	}
}

void stopHashing(){
	int i; 
	for(i = 0; i< buckets; i++  ){
		clearLinkedList(hashTable[i]);
	}

	free(hashTable);
	printf("Hashing OVER! \n");
}

void training(){
	int i;
	hashTable = (struct LinkedList **)malloc(sizeof(struct LinkedList *)* buckets);

	for(i= 0 ; i< buckets; i++){
		hashTable[i] = create();
	}

	readFile("D1.txt", 1);
	readFile("D2.txt", 2);
	readFile("D3.txt", 3);
}

void readFile(char *file, int doc){
    int len = 0;
    int inLen = 0;

		char *temp = NULL;
    char *tok;

    char buffer[128];

    FILE *afile; 

    afile = fopen(file,"r");

    do{
    	fgets(buffer, 128, afile);
    	len = strlen(buffer);
    	inLen = inLen + len;
    	temp = realloc(temp, inLen++);
    	strcat(temp, buffer);
    }while(len == 127);
    tok = strtok(temp, " ");

    while(tok != NULL){
    	hash_table_insert(tok,doc);
    	tok = strtok(NULL, " ");
    }

	fclose(afile);
}

void hash_table_insert(char *word, int doc){
	int bucketKey = hash_code(word);
	add(word,doc,bucketKey);
}

void add(char *word, int doc, int bucket){
	struct Node *temp = newNode(word, doc, bucket);

	if(hashTable[bucket]-> size >= capacity){
		printf("Capacity is met or exceeded...\n Program ending...\n Done.");
		stopHashing();
	}	
}

void read_query(char* inwords){
   	char* tok;
   	tok = strtok(inwords, " ");

    while(tok != NULL){		
    	query++;
    	rank(tok, hashTable[hash_code(inwords)], inwords);
    	tok = strtok(NULL, " ");
    }
}

void match(){
	if (roundOfQuery == 0){
		roundOfQuery++;
	}else if(scoresheet[1] == 0 && scoresheet[2] == 0 &&  scoresheet[3] == 0){
		printf("Sorry but none of the three documents match the inputed query. \n");
	}else{
		printf("Document with the most matches at the top: \n");
		int bol1 = 0;
		int bol2 = 0;
		int bol3 = 0; 
		int count =0;
		while(scoresheet[1] + scoresheet[2] + scoresheet[3] > 0 || bol1 + bol2 + bol3 < 3){

			//check to see if document 3 has the most words if it does set it to 0 after 
			//printing the document number and score 
			if (bol3 == 0 && count < 3 && scoresheet[3] >= scoresheet[2] && scoresheet[3] >= scoresheet[1]){
				printf("D3.txt has %d matches.\n", scoresheet[3]);
				scoresheet[3]=0;
				count++;
				bol3 = 1;
			}

			//check to see if document 2 has the most words if it does set it to 0 after 
			//printing the document number and score
			if (bol2 == 0 && count < 3 && scoresheet[2]>= scoresheet[1] && scoresheet[2] >= scoresheet[3]){
				printf("D2.txt has %d matches.\n", scoresheet[2]);
				scoresheet[2] = 0;
				count++;
				bol2 = 1;
			}

			//check to see if document 1 has the most words if it does set it to 0 after 
			//printing the document number and score
			if (bol1 == 0 && count < 3 && scoresheet[1] >= scoresheet[2] && scoresheet[1] >= scoresheet[3]){
				printf("D1.txt has %d matches.\n", scoresheet[1]);
				scoresheet[1] = 0;
				count++;
				bol1 = 1;
			}
		}
	}	
}

void rank(char *inwords, struct LinkedList *list, char * word){
	struct Node *temp;

	if(list -> head != NULL){
		temp = list-> head; 
		while(temp-> next != NULL){
			if(strcmp(temp->word, word)==0){
				int doc = temp -> doc; 
				scoresheet[doc]= (scoresheet[doc])+1;
			}
			temp = temp-> next; 
		}

		if(strcmp(temp->word, word)==0){
			int doc = temp -> doc; 
			scoresheet[doc]= (scoresheet[doc])+1;
		}
	}
}


void getQuery(){
   	int enter = 0;
    int i; 

		inwords = calloc(1,1);

    char strBuff[200];
  

    while(fgets(strBuff, 200, stdin)){

		for(i=0; i<strlen(strBuff); i++){
    		if(strBuff[i] == '\n'){
   				enter++;
				strBuff[i] = '\0';
    		}
    	}

    	inwords = realloc(inwords, strlen(strBuff)+strlen(inwords)+1);
    	
    	if(inwords){
    		strcat(inwords, strBuff);

		}else{
   			return ;
   		}

    	if(enter == 1){
   			break;
   		}
	}
}

void clearQuery(){
	int i;
	for(i = 1; i<=3;i++){
		scoresheet[i]=0;
	}
	query = 0; 
}

int hash_code(char* word){
	int bucketKey = 0 ;
	int i; 
	for( i = 0 ; i < strlen(word); i++){
		bucketKey = bucketKey + word[i];
	}

	return bucketKey = bucketKey % buckets;
}
