//
// Created by zhouchangyue on 2022/4/16.
//
#include <iostream>
#include "FindDuplicate.h"

bool FindDuplicate::isDuplicate(std::vector<int> vec) {
    if (vec.empty())
        return false;
    for(auto ite : vec) {
        if (ite < 0)
            return false;
        //std::cout << "ite: " << ite << std::endl;
    }

    for (int i = 0; i < vec.size(); ++i) {
        while (vec[i] != i) {
            if (vec[i] == vec[vec[i]])
                return true;

            int tmp = vec[i];
            vec[i] = vec[tmp];
            vec[tmp] = tmp;
        }
    }
    return false;
}

int FindDuplicate::getDuplicate(const std::vector<int> &vec) {
    if (vec.empty())
        return -1;

    int start = 1;
    int end = vec.size() - 1;
    while (start <= end) {
        int mid = ((end - start) / 2) + start;
        int count = countNum(vec, start, mid);
        if (start == mid) {
            if (count > 1)
                return start;
            else
                break;
        }
        if (count > (mid - start + 1)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int FindDuplicate::countNum(const std::vector<int> &vec, int start, int end) {
    int count = 0;
    for (auto ite : vec) {
        if (start <= ite && ite <= end)
            ++count;
    }

    return count;
}
