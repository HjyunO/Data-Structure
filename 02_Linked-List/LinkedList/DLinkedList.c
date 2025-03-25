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
    plist->head->next = new;
    
    plist->numOfData++;
}

void SInsert(List *plist, LData data) {
    Node *new = (Node*)malloc(sizeof(Node));
    Node *pred = plist->head;
    new->data = data;

    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
        pred = pred->next;
    }

    new->next = pred->next;
    pred->next = new;

    plist->numOfData++;
}

void LInsert(List *plist, LData data) {
    if(plist->comp == NULL) {
        FInsert(plist, data);
    } else {
        SInsert(plist, data);
    }
}

int LFirst(List *plist, LData *data) {
    if (plist->head->next == NULL) {
        return FALSE;
    }

    plist->before = plist->head;
    plist->cur = plist->head->next;

    *data = plist->cur->data;

    return TRUE;
}

int LNext(List *plist, LData *data) {
    if(plist->cur->next == NULL) {
        return FALSE; 
    }

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *data = plist->cur->data;

    return TRUE;
}

LData LRemove(List *plist) {
    Node *rpos = plist->cur;
    LData rdata = rpos->data;
    
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    plist->numOfData--;
    
    return rdata;
}

int LCount(List *plist) {
    return plist->numOfData;
}

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2)) {
    plist->comp = comp;
}

// 전체 리스트 제거(메모리 해제) 함수