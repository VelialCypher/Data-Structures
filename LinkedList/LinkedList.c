#include <stdlib.h>
#include "LinkedList.h"

typedef struct LinkedList {
	LinkedListNode_t* head;
	int length;
} LinkedList_t;

typedef struct LinkedListNode {
	int data;
	LinkedListNode_t* next;
} LinkedListNode_t;

LinkedListNode_t* LinkedListNode_new(int data) {
	LinkedListNode_t* node = (LinkedListNode_t*)malloc(sizeof(LinkedListNode_t));
	node -> data = data;
	node -> next = NULL;
	return node;
}

LinkedList_t* LinkedList_new() {
	LinkedList_t* lk = (LinkedList_t*)malloc(sizeof(LinkedList_t));
	lk -> length = 0;
	lk -> head = NULL;
}

void LinkedList_addToTheEnd(LinkedList_t* lk, int value) {
	if(lk -> length == 0) {
		lk -> head = LinkedListNode_new(value);
	} else {
		LinkedListNode_t* current = lk -> head;

		while (current -> next) {
			current = current -> next;
		}
		
		current -> next = LinkedListNode_new(value);
	}

	lk -> length++;
}

int main(int argc, char const *argv[]) {
	LinkedList_t* lk = LinkedList_new();
	LinkedList_addToTheEnd(lk, 5);
	LinkedList_addToTheEnd(lk, 6);
	LinkedList_addToTheEnd(lk, 7);
	return 0;
}
