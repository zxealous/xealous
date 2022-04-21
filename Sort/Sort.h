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

    /*
     *             3
     *          /     \
     *        29       7
     *       /  \     /  \
     *      56  13   6    33
     *     /
     *    66
     */
    //std::vector<int> vec = {3, 29, 7, 56, 13, 6, 33, 66};
    static void buildMaxHeap(std::vector<int> & vec, int start, int end) {
        int dad = start;
        int son = start * 2 + 1;
        while (son <= end) {
            if (son + 1 <= end && vec[son + 1] > vec[son])
                ++son;
            if (vec[dad] > vec[son])
                return;
            else {
                std::swap(vec[dad], vec[son]);
                dad = son;
                son = dad * 2 + 1;
            }
        }
    }

    static void HeapSort(std::vector<int> & vec) {
        if (vec.empty())
            return;

        //build max heap from last dad
        for (int i = vec.size() / 2 - 1; i >= 0; --i)
            buildMaxHeap(vec, i, vec.size() - 1);

        for (int i = vec.size() - 1; i > 0; --i) {
            std::swap(vec[0], vec[i]);
            //build max heap from root because it swap with last node
            buildMaxHeap(vec, 0, i - 1);
        }
    }
};

#endif //XEALOUS_SORT_H
