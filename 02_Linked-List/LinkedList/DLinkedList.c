#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List *plist) {
    plist->head = (Node*)malloc(sizeof(Node)); // create dummy Node
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

void FInsert(List *plist, LData data) {
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = data;

    new->next = plist->head->next;
    plist->head = new;
    
    plist->numOfData++;
}

void LInsert(List *plist, LData data) {
    if(plist->comp == NULL) {
        FInsert(plist, data);
    } else {
        SInsert(plist, data);
    }
}

