//
// Created by Administrator on 2019/12/25.
//


/**
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

int main() {
    int A[] = {0, 1, 2};
    sort(A, 2, 1);
    return 0;
}