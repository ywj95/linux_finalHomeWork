#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>


#include "include/bitree.h"
#include "include/mgraph.h"
#include "include/sqstack.h"
#include "include/linkqueue.h"
int main(int argc, char *argv[])
{

printf("\n\n          测试图\n\n\n");
  graph ga;
    int i1,j;
    createGraph(&ga);
    printf("无向图的邻接矩阵：\n");
for(i1=0;i1<ga.vexnum;i1++)
{
        for(j=0;j<ga.vexnum;j++)
            printf("%3d",ga.arcs[i1][j]);
        printf("\n");
    }
    init_visit();
    tdfs(&ga);
    init_visit();
    tbfs(&ga);



printf("\n\n          测试二叉树\n\n\n");
struct BTreeNode *bt; /* 指向二叉树根结点的指针 */
char *b;    /* 用于存入二叉树广义表的字符串 */
elemType x, *px;
initBTree(&bt);
printf("输入二叉树广义表的字符串：");
b = "a(b(c), d(e(f, g), h(, i)))";
printf("%s\n", b);
createBTree(&bt, b);
printf("以广义表的形式输出：");
printBTree(bt);   /* 以广义表的形式输出二叉树 */
printf("\n");
printf("先序：");  /* 先序遍历 */
preOrder(bt);
printf("\n");
printf("中序：");  /* 中序遍历 */
inOrder(bt);
printf("\n");
printf("后序：");  /* 后序遍历 */
postOrder(bt);
printf("\n");
printf("按层：");  /* 按层遍历 */
levelOrder(bt);
printf("\n");
printf("二叉树的深度为：");
printf("%d\n", BTreeDepth(bt));
/* 从二叉树中查找一个元素结点 */
printf("输入一个待查找的字符：");
scanf(" %c", &x);  /* 格式串中的空格跳过空白字符 */
px = findBTree(bt, x);
if(px)
{
    printf("查找成功：%c\n", *px);
}
else
{
    printf("查找失败！\n");
}

clearBTree(&bt);




   
char n;
printf("\n\n          测试队列\n\n\n");
    linkqueue Q;
    printf(" 初始化队列Q\n");
    initqueue(&Q);
    printf("一次进队列元素a,b,c,d;\n");
    printf("依次输出队列元素：");
    enqueue(&Q,'a');
    enqueue(&Q,'b');
    enqueue(&Q,'c');
    enqueue(&Q,'d');
    dequeue(&Q,&n);
    printf("%c",n);
    dequeue(&Q,&n);
    printf("%c",n);
    dequeue(&Q,&n);
    printf("%c",n);
    dequeue(&Q,&n);
    printf("%c\n",n);


printf("\n\n          测试栈\n\n\n");
    ElemType e;
    SqStack s;
    printf(" 初始化栈s\n");
    InitStack(&s);
    printf(" 栈S为%s\n",(StackEmpty(&s)?"空":"非空"));
    printf(" 一次进栈元素a,b,c,d,e;\n");
    Push(&s,'a');
    Push(&s,'b');
    Push(&s,'c');
    Push(&s,'d');
    Push(&s,'e');
    printf(" 栈S为%s\n",(StackEmpty(&s)?"空":"非空"));
    printf(" 输出栈长度S=%d：\n",StackLength(&s));
    printf(" 输出从栈顶到栈底的元素：");
    DispStack(&s);
    GetTop(&s,&e);//显示栈顶元素
    printf("\n");
    printf(" 输出出栈序列：");
    while (!StackEmpty(&s))
    {
        Pop(&s,&e);
    }
    printf("\n");
    printf(" 栈S为%s\n",(StackEmpty(&s)?"空":"非空"));
    printf(" 销毁栈\n");
    ClearStack(&s);

    return 0;
}





