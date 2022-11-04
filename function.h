#include <stdio.h>
#include <stdlib.h>
/*定义二叉树结点存放的是char类型*/
typedef char BiElemType;
/*二叉树的链式存储*/
typedef struct BiTNode{
    BiElemType data;//
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;


typedef BiTree ElemType;
/*队列结点, 数据域存放二叉树结点*/
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
/*队列的链式存储, 采用带头结点的队列*/
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;
/*队列操作的函数声明*/
void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q,ElemType x);
bool DeQueue(LinkQueue &Q,ElemType &x);
int SizeQueue(LinkQueue &Q);
