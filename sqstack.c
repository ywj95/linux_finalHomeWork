#include <stdlib.h>
#include<stdio.h>
#include<malloc.h>
#define MaxSize 50
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int  stacksize;
    ElemType   *base;
    int top;                       //栈顶指针
} SqStack;                        //顺序栈顶类型定义

//初始化栈
void InitStack(SqStack *s)
{
    s->base=(ElemType *)malloc(MaxSize*sizeof(ElemType));
    if(!s->base)    exit (-1);
    s->top=-1;
    s->stacksize = MaxSize;
}

//销毁栈
void ClearStack(SqStack *s)
{
    free(s);
}

//求栈的长度
int StackLength(SqStack *s)
{
    return(s->top+1);
}

//判断栈是否为空
int StackEmpty(SqStack *s)
{
    return(s->top==-1);
}

//进栈
int Push(SqStack *s,ElemType *e)
{
    if(s->top==MaxSize-1)
        return 0;
    s->top++;
    s->data[s->top]=e;
    return 1;
}

//出栈
int Pop(SqStack *s,ElemType *e)
{
    if(s->top==-1)
        return 0;
    printf("%c",s->data[s->top]);
    s->top--;
    return 1;
}

//取出栈顶元素
int GetTop(SqStack *s, ElemType *e)
{
    if(s->top==-1)
        return 0;
    printf(" 显示栈顶元素：%c",s->data[s->top]);
    return 1;
}

//显示栈中元素
void DispStack(SqStack *s)
{
    int j;
    for(j=s->top; j>8; j--)
        printf("%c ",s->data[j]);
    printf("\n");

}

