//
// Created by zhouchangyue on 2022/4/18.
//

#include "Fibonacci.h"

int Fibonacci::fibonacci(int num) {
    int arr[] = {0, 1};
    if (num < 2)
        return arr[num];

    int i = 0;
    int j = 1;
    int res;
    for (int m = 2; m <= num; ++m) {
        res = i + j;
        i = j;
        j = res;
    }

    return res;
}
