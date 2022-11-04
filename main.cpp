#include "function.h"

/* ---------------------- 按层次顺序创建二叉树 ---------------------- */
/*思路:  树的层次遍历(BFS)*/
void createTree(BiTree &root) {
    char charArr[100] = {0};
    int size = 0;//size为存放的字符串元素个数,包括'#'
    while (scanf("%c", &charArr[size]) != EOF) {
        if (charArr[size] == '\n') {
            break;
        }
        size++;
    }
    int i = 0;
    LinkQueue Q;            //声明一个辅助队列, 存放二叉树层次遍历的结点
    InitQueue(Q);
    BiTNode *fatherNode;      //建树过程中的新建结点的父结点
    while (i < size) {
        if (i == 0) {
            /*calloc申请空间并对空间进行初始化，赋值为0,
         * 相当于malloc后再对成员中指针赋NULL*/
            root = (BiTree) malloc(sizeof(BiTree));
            root->data = charArr[i]; //将读入的数据放入树结点的数据域中
            root->lchild = NULL;
            root->rchild = NULL;
            i++;
            EnQueue(Q, root);
            continue;
        }
        LinkNode *qHead = Q.front->next;
        fatherNode = qHead->data; //每次循环都将队头(头结点的下一个结点)赋值给:将要建立的结点的父结点
        if (charArr[i] == '#') {    //按输入顺序，奇数为左结点
            if (i % 2 == 1) {
                fatherNode->lchild = NULL;
            } else {                //按输入顺序，偶数为右结点(i % 2 == 0)
                fatherNode->rchild = NULL;
                DeQueue(Q, fatherNode); //每一次建完右结点，其父亲结点就没用了出队列
            }
            i++;
        } else {
            BiTNode *newTreeNode = (BiTNode *) malloc(sizeof(BiTNode *));
            newTreeNode->data = charArr[i];
            newTreeNode->lchild = NULL;
            newTreeNode->rchild = NULL;
            if (i % 2 == 1) {//左
                fatherNode->lchild = newTreeNode;
            } else {//右
                fatherNode->rchild = newTreeNode;
                DeQueue(Q, fatherNode);//每一次建完右结点，其祖先结点就没用了，出队列
            }
            EnQueue(Q, newTreeNode);//将建立的结点入队列，charArr[i]=‘#’的空结点不用入
            i++;
        }
    }
}

/* ---------------------- 层次遍历 ---------------------- */
void LevelOrder(BiTree T) {
    LinkQueue Q;             //辅助队列
    InitQueue(Q);        //初始化队列
    BiTree p;
    EnQueue(Q, T);      //树根入队
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);//出队当前结点并打印
        putchar(p->data);
        if (p->lchild != NULL) //入队左孩子
            EnQueue(Q, p->lchild);
        if (p->rchild != NULL)  //入队右孩子
            EnQueue(Q, p->rchild);
    }
}

/* ---------------------- 计算二叉树的高度 ---------------------- */
/*(递归)分解问题的思路(DFS) */
int treeDepth(BiTree T) {
    //base case
    if (T == NULL) {
        return 0;
    }
    /*后序遍历框架*/
    int l = treeDepth(T->lchild);
    int r = treeDepth(T->rchild);
    return l > r ? l + 1 : r + 1; //树深度 = Max(左子树深度, 右子树深度) + 1
}
/* ---------------------- 计算二叉树的宽度 ---------------------- */
/*迭代思路(BFS)*/
int maxWidth(BiTree &T) {
    //base case
    if (T == NULL) {
        return 0;
    }
    int max = 0;            //树的最大高度
    LinkQueue Q;            //声明一个辅助队列, 存放二叉树层次遍历的结点
    InitQueue(Q);
    EnQueue(Q, T);
    while (!IsEmpty(Q)) {
        int width = SizeQueue(Q);
        for (int i = 0; i < width; ++i) {
            LinkNode *s = Q.front->next;//获得队首结点
            BiTNode *headTNode = s->data;
            DeQueue(Q, s->data);
            if (headTNode->lchild) {
                EnQueue(Q, headTNode->lchild);
            }
            if (headTNode->rchild) {
                EnQueue(Q, headTNode->rchild);
            }
        }
        max = max > width ? max : width; //宽度更新
    }
    return max;
}

int main() {
    /*①关闭缓冲区, 解决printf不出来的问题*/
    setbuf(stdout, NULL);
//    ②setvbuf(stdout, NULL, _IONBF, 0);
    printf("请输入二叉树的结点值!\n");
    /*解决一行行printf不出来的问题: 手动刷新缓冲区*/
//    ③fflush(stdout);

    /* ---------------------- 层次遍历顺序创建二叉树 ---------------------- */
    BiTree tree = NULL;    //声明树根结点的指针
    createTree(tree);
    printf("按层次顺序创建二叉树成功!\n\n");
    printf("层序遍历已经建立的二叉树如下 : \n");

    LevelOrder(tree);
    /* ---------------------- 计算二叉树的高度 ---------------------- */
    int height = treeDepth(tree);
    printf("\n该树的高度为: %d\n", height);

    /* ---------------------- 计算二叉树的宽度 ---------------------- */
    int width = maxWidth(tree);
    printf("该树的宽度为: %d\n", width);
    if (height == width) {
        printf("这棵树是\"正方形\"二叉树\n");
    } else {
        printf("这棵树不是\"正方形\"二叉树\n");
    }
    return 0;
}
/*总结: 本道题核心是树的BFS和DFS*/
//样例1:      ABCD#EF
//样例2:      ABCDEFGHI
//样例3:      ABCDE#F###G

