#include <stdio.h>
#include "ArrayList.h"

int main() {
    List List;
    int Data[] = {1, 1, 2, 2, 3, 3, 4, 4, 1, 1, 2, 2};
    
    ListInit(&List);
    printf("set List\nnumOfData : %d\ncurPosition : %d\n", List.numOfData, List.curPosition);
    
    for(int i = 0; i < sizeof(Data)/4; i++) {
        LInsert(&List, Data[i]);
    }
    printf("After Insert Data\nnumOfData : %d\ncurPosition : %d\n", List.numOfData, List.curPosition);

    int sum = 0;
    LFirst(&List, &sum);
    for(int i = 0; i < sizeof(Data)/4 - 1; i++) {
        int tmp = 0; 
        LNext(&List, &tmp);
        sum += tmp;
    }
    printf("sum of List : %d\n", sum);
    printf("reference List\nnumOfData : %d\ncurPosition : %d\n", List.numOfData, List.curPosition);

    int data;
    if(LFirst(&List, &data)) {
        while(1){
            if(data == 1) {
                LRemove(&List);
                LFirst(&List, &data);
            } else {
                break;
            }
        }
        while(LNext(&List, &data)) {
            if(data == 1) {
                LRemove(&List);
        }
       }
    }

    int print; 
    LFirst(&List, &print);
    printf("After delete data\n%d ",print);
    for(int i = 0; i < LCount(&List) -1; i++){
        int tmp;
        LNext(&List, &tmp);
        printf("%d ", tmp);
    }

    return 0;
}