#include <stdio.h>
#include "DLinkedList.h"

int Compare(int d1, int d2) {
    if(d1 > d2) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    List list;
    int data;
    ListInit(&list);

    SetSortRule(&list, Compare);

    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    printf("num of data : %d\n", LCount(&list));

    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    }
    printf("\n\n");

    if(LFirst(&list, &data)) {
        if(data == 22) {
            LRemove(&list);
        }
        while(LNext(&list, &data)) {
            if(data == 22) {
                LRemove(&list);
            }
        }
    }
    printf("num of data after remove data : %d\n", LCount(&list));

    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    }
    printf("\n\n");

    return 0;
}