#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist){
    plist->numOfData = 0;
    plist->curPosition = -1;
}

void LInsert(List *plist, LData data){
    if(plist->numOfData == LIST_LEN) {
        puts("데이터 저장 공간 초과.");
        return;
    }

    plist->arr[plist->numOfData] = data;
    plist->numOfData++;
}

int LFirst(List *plist, LData *pdata){
    if(plist->numOfData == 0) {
        puts("저장된 데이터 없음.");
        return FALSE;
    }

    plist->curPosition = 0;
    *pdata = plist->arr[plist->curPosition];

    return TRUE;
}

int LNext(List *plist, LData *pdata){
    if((plist->curPosition)+1 >= plist->numOfData){
        puts("저장된 데이터 없음.");
        return FALSE;
    }

    *pdata = plist->arr[++plist->curPosition];

    return TRUE;
}

LData LRemove(List *plist){
    if(plist->numOfData == 0) {
        puts("저장된 데이터 없음.");
        return -1;
    } else if(plist->curPosition == -1) {
        puts("참조된 데이터 없음.");
        return -1;
    }

    LData rdata = plist->arr[plist->curPosition];

    int rpos = plist->curPosition;
    int num = plist->numOfData;

    if(plist->curPosition == 0) {
        for(int i = rpos; i < num-1; i++) {
            plist->arr[i] = plist->arr[i+1];
        }
        plist->numOfData--;
        return rdata;
    } else {
        for(int i = rpos; i < num-1; i++) {
            plist->arr[i] = plist->arr[i+1];
        }

        plist->curPosition--;
        plist->numOfData--;
        return rdata;
    }
}

int LCount(List *plist){
    return plist->numOfData;
}