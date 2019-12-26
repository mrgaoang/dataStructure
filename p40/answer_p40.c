//
// Created by Administrator on 2019/12/26.
//
#include <stdlib.h>

/**
 * 设计一个算法，将顺序表中的所有元素逆置。
 * @param A
 * @param length
 */
void revert(int A[], int length) {
    int temp;
    int p = 0;
    int q = length - 1;
    while (p < q) {
        temp = A[p];
        A[p] = A[q];
        A[q] = temp;
        p++;
        q--;
    }
}

/**
 * （4）设计一个算法，从一给定的顺序表L中删除下标i~j（i≤j，包括j）的所有元素，假定i、j都是合法的。
 * 删除顺序表中下标i到j的所有元素，包括i，j，i<=j ，假定i，j合法
 * @param A 
 * @param i 
 * @param j 
 */
void delete(int A[], int i, int j, int length) {
    int p;
    for (p = i; p + j - i + 1 < length; ++p) {
        // 将j后面的值放到i后面，直接覆盖
        A[p] = A[p + j - i + 1];
        p++;
    }
    // 修改顺序表长度
    length = length - (p - i);
}

/**
 * （5）有一个顺序表L，其元素为整型数据，设计一个算法，将L中所有小于表头元素的整数放在前半部分，大于表头元素的整数放在后半部分。
 * @param L
 */
void halfMove(int L[], int length) {
    // 中间值
    int temp = L[0];
    // 左边指针
    int p = 0;
    // 右边指针
    int q = length - 1;
    while (p < q) {
        // 指针从右往左，找到第一个小于temp的值
        while (p < q && L[q] > temp)
            q--;
        if (p < q) { // 很重要的一步，我就忘了，因为上面 对q的值进行了修改，有可能不满足条件了
            // q的值放到p上
            L[p] = L[q];
            // p右移一位
            p++;
        }
        // 指针从左往右，找到第一个大于temp的值
        while (p < q && L[p] < temp) {
            p++;
        }
        if (p < q) {// 很重要的一步，我就忘了，因为上面 对p的值进行了修改，有可能不满足条件了
            // p的值放到q上
            L[q] = L[p];
            // q左移一位
            q--;
        }
    }
    // temp 归位
    L[p] = temp;
}

/**
 * 单链表
 */
typedef struct LNode {
    // 数据域
    int data;
    // 后继
    struct LNode *next;
} LNode;


/**
 * （6）有一个递增非空单链表，设计一个算法删除值域重复的结点。例如，{1，1，2，3，3，3，4，4，7，7，7，9，9，9}经过删除后变成{1，2，3，4，7，9
 */
void deleteReapedLNode(LNode *L) {
    // L有头结点，指向数据节点
    LNode *p = L->next;
    // 用于释放空间的变量
    LNode *r;
    while (p->next != NULL) {
        // 若p 的下一个节点与p相同，则删除下一个节点
        while (p->next->data != NULL && p->data == p->next->data) {
            r = p->next;
            p->next = p->next->next;
            free(r);
        }
        // 后移p
        p = p->next;
    }

}

/**
 * （7）设计一个算法删除单链表L（有头结点）中的个最小值结点。
 */
void deleteMinLNode(LNode *L) {
    LNode *p = L->next;
    // 最小节点的前驱
    LNode *minPre = L;
    // 遍历链表，结束后找到最小节点的前驱minPre
    while (p->next != NULL) {
        // 如果p->next小则替换minPre
        if (minPre->next->data > p->next->data) {
            minPre = p;
        }
        // p后移
        p = p->next;
    }
    // 若最小值是最后一个节点，直接释放
    if (minPre->next->next == NULL) {
        free(minPre->next);
        minPre->next = NULL;
    }
        // 删除minPre->next
    else {
        // 存放用于释放的节点
        p = minPre->next;
        // 断链
        minPre->next = minPre->next->next;
        // 释放
        free(p);
    }


}