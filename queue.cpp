#include "function.h"
/* ---------------------- 带头结点的队列 ---------------------- */

/*队列初始化*/
void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}
/*判断队列是否为空*/
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}
/*入队操作*/
void EnQueue(LinkQueue &Q, ElemType x) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}
/*出队操作*/
bool DeQueue(LinkQueue &Q, ElemType &x) {
    if (Q.front == Q.rear) return false;
    LinkNode *p = Q.front->next;//头结点什么都没存，所以头结点的下一个节点才有数据
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
}
/*求队列的长度*/
int SizeQueue(LinkQueue &Q) {
    int size = 0;
    if (Q.front == Q.rear) {
        return size;
    }
    LinkNode *p = Q.front;//头结点什么都没存，所以头结点的下一个节点才有数据
    while (p != Q.rear) {
        p = p->next;
        size++;
    }
    return size;
}
