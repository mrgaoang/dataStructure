//
// Created by Administrator on 2019/12/25.
//
#include <stdarg.h>
#include "../basic/shortListMerge.h"
#include <stdlib.h>

/**
 * p35 第一题
 * 设A[] ，表中元素前m个递增有序，后n个递增有序，设计一个算法使整个表递增有序
 * 时间复杂度 若后n个元素整体小于前m个元素，那么每次比较时都会移动m次，共循环n次，故时间负责度为O(mn)
 * 空间复杂度 由于只开辟了一个temp用于存储，空间大小与初始量级无关，故空间复杂度为O(1)
 * @param A
 * @param m
 * @param n
 */
void sort(int A[], int m, int n) {
    int i; // 右边数组的下标
    int j; // 用于比较的下标
    int temp;// 存放右边数组用于比较的数
    // 初始化时 从右边数组开始循环
    for (i = m; i < m + n; ++i) {
        temp = A[i];//把要比较的数放入临时变量
        // 从右往左对比，若临时变量小于当前数，则把后移该数
        for (int j = i - 1; i >= 0 && temp < A[j]; --j)
            A[j + 1] = A[j];
        // 直到临时变量小于时则放入合适位置
        A[j + 1] = temp;
    }
}


/**
 * 第二题
 * 题目：已知递增有序的单链表A、B（元素个数分班为m、n，有头结点）
 * 设计算法求出两个集合A和B的差集（仅由在A中出现而不再B中出现的元素所构成的集合）
 * ，将差集保存在单链表A中，并保持元素的递增有序性
 * 思路:用两个指针p、q分别指向A、B，如果p小于q则p后移，如果q小于p则q后移，若相等则移除p，直到q或p为null
 *
 * 时间复杂度为O(m+n)
 * 空间复杂度为O(1)
 * @return
 */
int difference(LNode *A, LNode *B) {
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *pre = A;
    LNode *r;
    while (p->data != NULL && q->data != NULL) {
        // p 后移
        if (p->data < q->data) {
            pre = p;
            p = p->next;
        }
            // q 后移
        else if (p->data > q->data) {
            q = q->next;
        }
            // p 和 q相等，释放p
        else {
            pre->next = p->next;
            // 不能把p给释放了，要用r来释放节点
            r = p;
            p = p->next;
            free(r);
        }
    }
    return 1;
}

int main() {
    int A[] = {0, 1, 2};
    sort(A, 2, 1);
    return 0;
}

