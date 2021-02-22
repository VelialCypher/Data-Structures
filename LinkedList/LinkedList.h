#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct LinkedList LinkedList_t;
typedef struct LinkedListNode LinkedListNode_t;

LinkedListNode_t* LinkedListNode_new(int data);

LinkedList_t* LinkedList_new();

void LinkedList_addToTheEnd(LinkedList_t* lk, int value);

void LinkedList_insertInPosition(LinkedList_t* lk, int pos, int value);
LinkedList_t* LinkedList_getNodeByPosition(LinkedList_t* lk, int pos, int value);

LinkedList_t* LinkedList_removeFromEnd(LinkedList_t* lk);
LinkedList_t* LinkedList_removeFormPosition(LinkedList_t* lk, int pos);



#endif