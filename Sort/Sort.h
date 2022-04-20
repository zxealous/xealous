//
// Created by zhouchangyue on 2022/4/20.
//

#ifndef XEALOUS_SORT_H
#define XEALOUS_SORT_H

#include <iostream>
#include <vector>
#include <algorithm>

class Sort {
public:
    static void QuickSort(std::vector<int> & vec) {
        QuickSort(vec, 0, vec.size() - 1);
    }

    static void QuickSort(std::vector<int> & vec, int low, int high) {
        if (low < high) {
            int pos = partition(vec, low, high);
            QuickSort(vec, low, pos - 1);
            QuickSort(vec, pos + 1, high);
        }
    }

    static int partition(std::vector<int> & vec, int low, int high) {
        int pivot = vec[low];
        while (low < high) {
            while (low < high && vec[high] > pivot)
                --high;
            while (low < high && vec[low] < pivot)
                ++low;
            std::swap(vec[low], vec[high]);
        }
        std::swap(vec[low], pivot);
        return low;
    }
};

#endif //XEALOUS_SORT_H
