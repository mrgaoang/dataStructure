//
// Created by Administrator on 2019/12/26.
//

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