//Zuri Lawrence
#ifndef LL_H
#define LL_H
/* The code above is magic to prevent this library from being included more than once */

struct LList
{
  struct LNode* head;
};

struct LNode {
  char* name;
  double latitude;
  double longitude;
  struct LNode* next;
};

struct LList* createLList();

void printList(struct LList *list);

int addNode(struct LList *list, char* name, double lat, double lon);

int remNode(struct LList *list, char* name);

int addSortedNode(struct LList *list, char* name, double lat, double lon);

int clearList(struct LList *list);

#endif