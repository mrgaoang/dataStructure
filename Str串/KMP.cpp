//
// kmp算法学习过程
//

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char ch[50];
    int length;
} Str;

/**
 * 获取模式串的next
 * @param substr
 * @param next
 */
void getNext(Str substr, int next[]) {
    // 模式串下标从1开始存值
    int j = 1, t = 0;
    // 第一个字符的next必然是0
    next[1] = 0;
    while (j < substr.length) {// 因为求的是j+1的next，所以j不能等于length
        if (t == 0 || substr.ch[j] == substr.ch[t]) {// 若当前假主串和假模式串相等，则下一个模式串的next为当前假模式串next的值加1
            if (substr.ch[j] != substr.ch[t + 1]) {// 若模式串的下一个字符 t+1 处字符和主串不相等，正常进行t的增
                next[j + 1] = t + 1;
            } else {// 若模式串的下一个字符 t+1 处字符和主串相等，则下一个模式串的next应该为与 t + 1 处的next相等（回溯到已经算的位置）
                next[j + 1] = next[t + 1];
            }
            ++j;// j 和 t 都增加一位
            ++t;
        } else {// 若当前假主串和假模式串不相等 则t回到 next[t]中存储的位置
            t = next[t];
        }
    }
}

/**
 * 默写
 * @param substr
 * @param next
 */
void getNextMy(Str substr, int next[]) {
    int j = 1, t = 0;
    next[1] = 1;
    while (j < substr.length) {
        if (t == 0 || substr.ch[j] == substr.ch[t]) {
            if (substr.ch[j] != substr.ch[t + 1]) {
                next[j + 1] = t + 1;
            } else {
                next[j + 1] = next[t + 1];
            }
            ++j;
            ++t;
        } else {
            t = next[t];
        }
    }
}

/**
 * 默写2
 * @param substr
 * @param next
 */
void getNextMy2(Str substr, int next[]) {
    int j = 1, t = 0;
    next[1] = 1;
    while (j < substr.length) {
        if (t == 0 || substr.ch[j] == substr.ch[t]) {
            if (substr.ch[j] != substr.ch[t + 1]) {
                next[j + 1] = t + 1;
            } else {
                next[j + 1] = next[t + 1];
            }
            ++j;
            ++t;
        } else {
            t = next[t + 1];
        }
    }
}

/**
 * kmp算法
 * @param mainStr 主串
 * @param modeStr 模式串
 * @param next next数组
 * @return
 */
int KMP(Str mainStr, Str modeStr, int next[]) {
    getNextMy(modeStr, next);
    int i = 1, j = 1;
    // 循环i、j；i为主串下标 j为模式串下标
    while (i <= mainStr.length && j <= modeStr.length) {
        // 当主串和模式串相等时 后移
        if (mainStr.ch[i] == mainStr.ch[j]) {
            ++i;
            ++j;
        } else {// 不相等时模式串j前移到next[j]的位置
            j = next[j];
        }
    }
    // j> 字符串长度 则成功匹配上
    if (j > modeStr.length) {
        return i - modeStr.length;
    }
    // 匹配失败
    return 0;
}