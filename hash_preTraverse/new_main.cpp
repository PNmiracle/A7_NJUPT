#include <stdio.h>
#include <cstdlib>

#define MAXN 10000
int width[MAXN], height, max_width;
typedef char ElemType;
/*定义二叉树的结构体*/
typedef struct BinNode {
    ElemType data;
    struct BinNode *lchild, *rchild;
} BinNode, *BiTree;

void PreCreateBt(BiTree *T) {
    ElemType c;
    scanf("%c", &c);
    if (c == '#') {
        *T = NULL;
    } else {
        *T = (BinNode *) malloc(sizeof(BinNode));
        (*T)->data = c;
        PreCreateBt(&(*T)->lchild);
        PreCreateBt(&(*T)->rchild);
    }
}

/*前序遍历二叉树*/
void PreOrderTransverse(BiTree T, int depth) {
    if (T) {
        if (depth > height) width[++height] = 0;
        width[depth] += 1;
        if (max_width < width[depth]) max_width = width[depth];
        PreOrderTransverse(T->lchild, depth + 1);
        PreOrderTransverse(T->rchild, depth + 1);
    }
}


int main() {
    setbuf(stdout, NULL);
    printf("请输入一个二叉树\n");
    printf("如过结点为空, 请用'#'号替代\n");
    printf("样例: ABC###DE##F##\n");
    BiTree T = NULL;
    height = 0;
    max_width = 0;
    PreCreateBt(&T);
    PreOrderTransverse(T, 1);
    printf("高度: %d, 宽度: %d\n", height, max_width);
    if (max_width == height) printf("这棵树是\"正方形\"二叉树\n");
    else printf("这棵树不是\"正方形\"二叉树\n");
    return 0;
}
// ABC###DE##F##
// ABCD####EF##G##

