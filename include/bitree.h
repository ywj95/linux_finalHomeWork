
#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX_SIZE 30
#define QUEUE_MAX_SIZE 30
typedef char elemType;
struct BTreeNode
{
    elemType data;
    struct BTreeNode *left;
    struct BTreeNode *right;
};
// 1.初始化二叉树
void initBTree(struct BTreeNode**bt);
// 2.建立二叉树(根据a所指向的二叉树广义表字符串建立)
void createBTree(struct BTreeNode**bt, char *a);
/* 3.检查二叉树是否为空，为空则返回1,否则返回0 */
int emptyBTree(struct BTreeNode *bt);
/* 4.求二叉树深度 */
int BTreeDepth(struct BTreeNode *bt);
/* 5.从二叉树中查找值为x的结点，若存在则返回元素存储位置，否则返回空值 */
elemType *findBTree(struct BTreeNode *bt, elemType x);
/* 6.输出二叉树(前序遍历) */
void printBTree(struct BTreeNode *bt);
/* 7.清除二叉树，使之变为一棵空树 */
void clearBTree(struct BTreeNode**bt);
/* 8.前序遍历 */
void preOrder(struct BTreeNode *bt);
/* 9.前序遍历 */
void inOrder(struct BTreeNode *bt);
/* 10.后序遍历 */
void postOrder(struct BTreeNode *bt);
/* 11.按层遍历 */
void levelOrder(struct BTreeNode *bt);


