#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef int LData; 
// LData는 입력받을 데이터, 반환해줄 데이터를 의미함

typedef struct __ArrayList
{
    LData arr[LIST_LEN];
    int numOfData;
    int curPosition;
} ArrayList;

typedef ArrayList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);

#endif