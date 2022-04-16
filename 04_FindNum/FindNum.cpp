//
// Created by zhouchangyue on 2022/4/16.
//

#include "FindNum.h"


/*
 * 1  2  8  9
 * 2  4  9  12
 * 4  7  10 13
 * 6  8  11 15
 */
int FindNum::findNumInVector(const std::vector<std::vector<int>> & vec, int num) {
    if (vec.empty())
        return -1;

    bool found = false;

    auto row = 0;
    auto rows = vec.size() - 1;
    auto column = vec[0].size() - 1;
    auto columns = vec[0].size() - 1;

    while (row <= rows && columns >=0) {
        if (vec[row][column] == num) {
            found = true;
            break;
        } else if (vec[row][column] > num) {
            --column;
        } else {
            ++row;
        }
    }
    return found;
}
