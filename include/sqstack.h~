#ifndef _CALC_H
#define _CALC_H
#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int  stacksize;
    ElemType   *base;
    int top;                       //栈顶指针
} SqStack;                        //顺序栈顶类型定义

void InitStack(SqStack *s);
void ClearStack(SqStack *s);
int StackLength(SqStack *s);
int StackEmpty(SqStack *s);
int Push(SqStack *s,ElemType *e);
int Pop(SqStack *s,ElemType *e);
int GetTop(SqStack *s, ElemType *e);
void DispStack(SqStack *s);




#endif //_CALC_H
