#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

#include "hashTable.h"
#include "linkedList.h"

int hash_code(char* w){
	int bKey = 0 ;
	int p; 
	for(p=0;p<len(w);i++){
		bKey = bKey+w[i];
	}
	return bKey = bKey % numBuckets;
}
