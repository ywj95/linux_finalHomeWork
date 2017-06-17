#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX_SIZE 30
#define QUEUE_MAX_SIZE 30
//#ifndef elemType
typedef char elemType;
//#endif

struct BTreeNode
{
    elemType data;
    struct BTreeNode *left;
    struct BTreeNode *right;
};
// 1.初始化二叉树
void initBTree(struct BTreeNode**bt)
{
    *bt = NULL;
    return;
}
// 2.建立二叉树(根据a所指向的二叉树广义表字符串建立)
void createBTree(struct BTreeNode**bt, char *a)
{
    struct BTreeNode *p;
    struct BTreeNode *s[STACK_MAX_SIZE];/* 定义s数组为存储根结点指针的栈使用 */
    int top = -1; /* 定义top作为s栈的栈顶指针，初值为-1,表示空栈 */
    int k1; /* 用k作为处理结点的左子树和右子树，k = 1处理左子树，k = 2处理右子树 */
    int i1 = 0; /* 用i扫描数组a中存储的二叉树广义表字符串，初值为0 */
    *bt = NULL; /* 把树根指针置为空，即从空树开始建立二叉树 */
    /* 每循环一次处理一个字符，直到扫描到字符串结束符\0为止 */
    while(a[i1] != '\0')
    {
        switch(a[i1])
        {
        case ' ':
            break;  /* 对空格不作任何处理 */
        case '(':
            if(top == STACK_MAX_SIZE - 1)
            {
                printf("栈空间太小！\n");
                exit(1);
            }
            top++;
            s[top] = p;
            k1 = 1;
            break;
        case ')':
            if(top == -1)
            {
                printf("二叉树广义表字符串错误!\n");
                exit(1);
            }
            top--;
            break;
        case ',':
            k1 = 2;
            break;
        default:
            p = malloc(sizeof(struct BTreeNode));
            p->data = a[i1];
            p->left = p->right = NULL;
            if(*bt == NULL)
            {
                *bt = p;
            }
            else
            {
                if( k1 == 1)
                {
                    s[top]->left = p;
                }
                else
                {
                    s[top]->right = p;
                }
            }
        }
        i1++;  /* 为扫描下一个字符修改i值 */
    }
    return;
}
/* 3.检查二叉树是否为空，为空则返回1,否则返回0 */
int emptyBTree(struct BTreeNode *bt)
{
    if(bt == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/* 4.求二叉树深度 */
int BTreeDepth(struct BTreeNode *bt)
{
    if(bt == NULL)
    {
        return 0;  /* 对于空树，返回0结束递归 */
    }
    else
    {
        int dep1 = BTreeDepth(bt->left);  /* 计算左子树的深度 */
        int dep2 = BTreeDepth(bt->right);  /* 计算右子树的深度 */
        if(dep1 > dep2)
        {
            return dep1 + 1;
        }
        else
        {
            return dep2 + 1;
        }
    }
}
/* 5.从二叉树中查找值为x的结点，若存在则返回元素存储位置，否则返回空值 */
elemType *findBTree(struct BTreeNode *bt, elemType x)
{
    if(bt == NULL)
    {
        return NULL;
    }
    else
    {
        if(bt->data == x)
        {
            return &(bt->data);
        }
        else   /* 分别向左右子树递归查找 */
        {
            elemType *p;
            if(p = findBTree(bt->left, x))
            {
                return p;
            }
            if(p = findBTree(bt->right, x))
            {
                return p;
            }
            return NULL;
        }
    }
}
/* 6.输出二叉树(前序遍历) */
void printBTree(struct BTreeNode *bt)
{
    /* 树为空时结束递归，否则执行如下操作 */
    if(bt != NULL)
    {
        printf("%c", bt->data);  /* 输出根结点的值 */
        if(bt->left != NULL || bt->right != NULL)
        {
            printf("(");
            printBTree(bt->left);
            if(bt->right != NULL)
            {
                printf(",");
            }
            printBTree(bt->right);
            printf(")");
        }
    }
    return;
}
/* 7.清除二叉树，使之变为一棵空树 */
void clearBTree(struct BTreeNode**bt)
{
    if(*bt != NULL)
    {
        clearBTree(&((*bt)->left));
        clearBTree(&((*bt)->right));
        free(*bt);
        *bt = NULL;
    }
    return;
}
/* 8.前序遍历 */
void preOrder(struct BTreeNode *bt)
{
    if(bt != NULL)
    {
        printf("%c ", bt->data);  /* 访问根结点 */
        preOrder(bt->left);    /* 前序遍历左子树 */
        preOrder(bt->right);   /* 前序遍历右子树 */
    }
    return;
}

/* 9.前序遍历 */
void inOrder(struct BTreeNode *bt)
{
    if(bt != NULL)
    {
        inOrder(bt->left);    /* 中序遍历左子树 */
        printf("%c ", bt->data);  /* 访问根结点 */
        inOrder(bt->right);    /* 中序遍历右子树 */
    }
    return;
}
/* 10.后序遍历 */
void postOrder(struct BTreeNode *bt)
{
    if(bt != NULL)
    {
        postOrder(bt->left);   /* 后序遍历左子树 */
        postOrder(bt->right);   /* 后序遍历右子树 */
        printf("%c ", bt->data);  /* 访问根结点 */
    }
    return;
}
/* 11.按层遍历 */
void levelOrder(struct BTreeNode *bt)
{
    struct BTreeNode *p;
    struct BTreeNode *q[QUEUE_MAX_SIZE];
    int front = 0, rear = 0;
    /* 将树根指针进队 */
    if(bt != NULL)
    {
        rear = (rear + 1) % QUEUE_MAX_SIZE;
        q[rear] = bt;
    }
    while(front != rear)   /* 队列非空 */
    {
        front = (front + 1) % QUEUE_MAX_SIZE; /* 使队首指针指向队首元素 */
        p = q[front];
        printf("%c ", p->data);
        /* 若结点存在左孩子，则左孩子结点指针进队 */
        if(p->left != NULL)
        {
            rear = (rear + 1) % QUEUE_MAX_SIZE;
            q[rear] = p->left;
        }
        /* 若结点存在右孩子，则右孩子结点指针进队 */
        if(p->right != NULL)
        {
            rear = (rear + 1) % QUEUE_MAX_SIZE;
            q[rear] = p->right;
        }
    }
    return;
}

