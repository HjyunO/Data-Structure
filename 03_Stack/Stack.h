#ifndef __STACK_H__
#define __STACK_H__

#define TRUE 1
#define FALSE 0

#define STACK_LEN 100
typedef int SData;

typedef struct __Stack {
    SData arr[STACK_LEN];
    int numOfData;
    int top;
} Stack;

void StackInit(Stack* pStack);
void push(Stack* pStack, SData data);
SData pop(Stack* pStack);
int count(Stack* pStack);

#endif