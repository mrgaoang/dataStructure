#include <stdlib.h>
#include <stdio.h>

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
void delete(
int A[],
int i,
int j,
int length
) {
int p;
for (
p = i;
p + j - i + 1 <
length;
++p) {
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
        if (p->next != NULL && p->data == p->next->data) {
            r = p->next;
            p->next = p->next->next;
            free(r);
        }
        // 后移p
        p = p->next;
    }

}

/**
 * 删除链表最小点
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

/**
 * 删除链表最小点 [参考答案]
 * （7）设计一个算法删除单链表L（有头结点）中的个最小值结点。
 */
void deleteMinLNodeFinal(LNode *L) {
    // 移动指针的前驱，移动指针，最小节点，最小节点的前驱
    LNode *pre = L, *p = pre->next, *minp = p, *minpre = pre;
    while (p != NULL) {
        // 比较最小值
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;// 后移
        p = p->next;// 后移
    }
    minpre->next = minp->next;    // 删除最小值
    free(minp);// 释放
}

/**
 * 逆置链表
 * （8）有一个线性表，采用带头结点的单链表L来存储。设计一个算法将其逆置。要求不能建立新结点，只能通过表中已有结点的重新组合来完成。
 * 思路：遍历链表然后用头插法
 */
void revertLNode(LNode *L) {
    // 固定的头节点
    LNode *h = L;
    // p从第二个数据节点开始
    LNode *p = L->next->next;
    // p的下一个节点，临时存放
    LNode *pn;
    // 遍历L 用p进行头插法
    while (p->next != NULL) {
        pn = p->next; // 存放p->next
        p->next = h->next; // p指向原来的第一个节点
        h->next = p;// 头指针指向p
        p = pn;// 找回p的下一个节点
    }
}

/**
 * 逆置链表[参考答案]
 * （8）有一个线性表，采用带头结点的单链表L来存储。设计一个算法将其逆置。要求不能建立新结点，只能通过表中已有结点的重新组合来完成。
 */
void revertLNodeFinal(LNode *L) {
    //L始终是头节点
    // p在往后移动，同时每次都让他链接在L的后面
    LNode *p = L->next;
    L->next = NULL;
    // p的下一个节点
    LNode *q;
    // 遍历L 用p进行头插法
    while (p != NULL) {
        q = p->next; // q辅助存放p的后继
        p->next = L->next; // p指向原来的第一个节点 头插关键1
        L->next = p;// 头指针指向p 头插的关键2
        p = q;// q中存的是原来p的后继，所以相当于p后移
    }
}

/**
 * （9）设计一个算法，将一个头结点为A的单链表（其数据域为整数）分解成两个单链表A和B，使得A链表只含有原来链表中data域为奇数的结点，而B链表只含有原链表中data域为偶数的结点，且保持原来的相对顺序。
 *
 */
void splitLNode(LNode *A, LNode *B) {
    LNode *p = A; // A的头结点
    LNode *q = B; // B的头节点
    LNode *m;
    while (p->next->next != NULL) {
        // p的next为偶数
        if (p->next->data % 2 == 0) {
            m = p->next;// 目标节点
            q->next = m;// 目标节点迁移
            q = q->next; // q后移一位
        }
        p = p->next;// p后移
    }
    // 处理最后一个节点
    if (p->next != NULL && p->next->data % 2 == 0) {
        q->next = p->next;
    }
}

/**
 * （9）设计一个算法，将一个头结点为A的单链表（其数据域为整数）分解成两个单链表A和B，使得A链表只含有原来链表中data域为奇数的结点，而B链表只含有原链表中data域为偶数的结点，且保持原来的相对顺序。
 * 此解为参考答案
 */
void splitLNodeFinal(LNode *A, LNode *B) {
    B = (LNode *) malloc(sizeof(B));
    B->next = NULL;
    LNode *p = A; // A的头结点
    LNode *q = B; // B的头节点
    LNode *m;// 临时节点
    while (p->next != NULL) {
        // p的next为偶数
        if (p->next->data % 2 == 0) {
            m = p->next;// 目标节点
            p->next = m->next; // 取下节点m
            m->next = NULL;
            q->next = m;// 目标节点迁移
            q = m; // q后移一位  q = q->next; 也行
        } else
            p = p->next; // p后移，检查下一个节点

    }

}


/**
 * 2 、 思考题
 */

/**
 * [参考答案]
 * （1）有N个个位正整数存放在int型数组A[0，…，N-1]中，N为已定义的常量且N≤9，数组A[]
    的长度为N，另给一个int型变量i，要求只用上述变量（A[0]~A[N-1]与i，这N+1个整型变量）写一个算法，找出这N个整数中的最小者，并且要求不能破坏数组A[]中的数据。
    分析：此题的难点在于只有一个变量i，但是我们需要两个变量，一个用于循环，一个用于记录最小值。可以把i的十位用来循环，个位用来记录最小值
    总结：这个题的思路不说破的话，按照正常思维一般不容易想到，如果说破就很简单，后面的学习中也要举一反三，一个变量多个用途，甚至可以把百位、千位都用上，实现一个变量N个用途。
    但实际企业开发中不会这样做，内存的成本十分低廉，而这种运用增加了很多的算术运算，用时间换空间，十分的不划算。仅限于极小内存的单片机、物联网设备中会使用这种方式来节约内存
 */
void findMinUseOneTemp(int A[], int N, int i) {
    i = A[0];// 赋值第一个数放到i的个位
    i = i + 10; // 十位从下标1开始
    while (i / 10 < N) {// 用十位来循环
        if (A[i / 10] < i % 10)// 如果当前数小于i的个位
            i = i / 10 + A[i / 10];// i的个位数替换为本次循环的数
        i = i + 10; // 十位加1
    }
    i = i % 10;// 循环结束，把i的值还原
}

/**
 * （2）写一个函数，逆序打印单链表中的数据，假设指针L指向了单链表的开始结点。
 */
void revertPrintLNodeList(LNode *L) {
    // 增加一个头节点
    LNode *H = (LNode *) malloc(sizeof(LNode));
    H->data = NULL;
    H->next = L;

    // 逆置链表
    LNode *p = H->next;
    LNode *q;
    H->next = NULL;
    while (p != NULL) {
        q = p->next;
        p->next = H->next;
        H->next = p;
        p = q;
    }
    p = H->next;
    // 遍历链表打印
    while (p != NULL)
        printf((const char *) p->data);
    // 逆置回来
    p = H->next;
    H->next = NULL;
    while (p != NULL) {
        q = p->next;
        p->next = H->next;
        H->next = p;
        p = q;
    }
}

/**
 * [参考答案]
 * （2）写一个函数，逆序打印单链表中的数据，假设指针L指向了单链表的开始结点。
 * 本题可用递归的方法解决，在表不空的情况下先递归地逆序打印表中第一个数据之后的数据，然后打印第一个数据，即可实现单链表中数据的逆序打印。
本题代码如下：
 */
void reprint(LNode *L) {
    if (L != NULL) {
        reprint(L->next);
        printf((const char *) L->data);
    }
}

/**
 * min 和 max 应该为&min 和 &max，由于语法解析器没准备好~
 * （3）试编写个函数，以不多于3n/2的平均比较次数，在一个有n个整数的顺序表A中找出最大值和最小值。
 *
 *  分析：最坏情况：当表中n个整数按从大到小非递增排列时，数据比较次数为2（n-1）次。
最好情况：当表中n个整数按从小到大递增排列时，数据比较次数为n-1次。
A中数据的有序性可以认为是等可能的，因此最好和最坏情况的概率相同，都是1/2。
综上所述，数据平均比较次数为（2（n-1）+（n-1））/2=3n/2-3/2<3n/2。
 */
void findMinAndMax(int A[], int n, int min, int max) {
    min = A[0];
    max = A[0];
    for (int i = 1; i < n; ++i) {
        if (A[i] < min) {
            min = A[i];
        } else if (A[i] > max) {
            max = A[i];
        }
    }
}

/**
 * （4）设 A=（a1，a₂，…，am）和B=（b1，b2，…，bn）均为顺序表，A'和B'分别是除去最大公共
 * 前缀后的子表。例如，A=（b，e，i，j，i，n，g），B=（b，e，i，f，a，n，g），则两者的最大公共前缀
 * 为b、e、i，在两个顺序表中除去最大公共前缀后的子表分别为 A'=（j，i，n，g），B'=（f，a，n，g）。
 * 若A'=B'-空表，则A=B。若A'=空表且B'空表，或两者均不为空且 A'的第一个元素值小于B'的第一个
 * 元素值，则 A<B，否则 A>B。试编写一个函数，根据上述方法比较A和B的大小。
 * 此题略
 */




/**
 * 假设该链表只给出了头指针head，在不改变链表的前提下，请设计个尽可能高效的算法，
 * 查找链表中倒数第k（k为正整数）个位置上的结点。若查找成功，算法输出该结点的data值，并返回1：否则，只返回0
 * （1）给出算法的基本设计思想
 * 双指针同时移动，指针相隔k个节点，后面的指针到达尾部则另一指针为倒数k节点
（2）根据设计思想，来用C或C+语言描述算法，关键之处给出注释
（3）说明你所设计的算法的时间复杂度和空间复杂度。
 */

void findRightKNode(LNode *L, LNode *&F, int k) {
    LNode *p = L->next, *q = L->next;
    // q后移k-1位
    for (int i = 0; i < k - 1; ++i) {
        q = q->next;
    }
    // p和q相隔k-1位 ，同时后移
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    // 最终q到末尾，p就是倒数第k个节点
    f = p;
}

/**
 * 3.已知一个整数序列A2（a0,a1，…，am），其中0≤an（0≤i<n）若存在a-2…-mx且m>n2（0≤Pm,k≤m），
 * 则称x为A的主元素。例如，A=（0,5,5,3,5,7,5,5），则5为主元素x又如A\（0,5,5,3,5,1,5,7），
 * 则A中没有主元素。假设A中的n个元素保存在一个维数中请设计一个尽可能高效的算法，找出A的主元素，
 * 若存在主元素，则输出该元素：否则输出-14要求
 *
 */