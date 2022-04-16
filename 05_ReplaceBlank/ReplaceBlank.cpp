//
// Created by zhouchangyue on 2022/4/16.
//

#include "ReplaceBlank.h"

void ReplaceBlank::replaceBlank(char str[], int length) {
    if (str == nullptr)
        return;

    int strIndex = 0;
    int numberOfBlank = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        ++strIndex;

        if (str[i] == ' ')
            ++numberOfBlank;
    }

    int newStrIndex = strIndex + numberOfBlank * 2;
    if (newStrIndex > length)
        return;
    while (strIndex >= 0 && newStrIndex > strIndex) {
        if (str[strIndex] == ' '){
            str[newStrIndex--] = '0';
            str[newStrIndex--] = '2';
            str[newStrIndex--] = '%';
        } else {
            str[newStrIndex--] = str[strIndex];
        }

        --strIndex;
    }
}
