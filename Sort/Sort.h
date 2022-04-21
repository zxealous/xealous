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

    /*
     * 快速排序：
     * 原理：选择出一个元素作为数组内的"中心"，并调整该元素的左边均为比该元素小的值，右边均为比该元素大的值，再递归用该方法，将该元素的左右
     *      作为两个新的"子数组"用同样的方式处理。(相当于第一次排序好的元素是选择出的"中心")
     *
     * 步骤：1.选择出一个"中心元素"，并将其左边调整为左边元素小于该值，右边元素大于该值(即该元素位置为排序好的位置)
     *      2.递归处理该元素左右两边的子数组，按照步骤1调整
     *
     * 选择出一个"中心元素"，调整左边元素均小于该元素，右边元素均大于该元素：
     * 参数：包含全部元素的数组vec, 待处理子数组的起点low, 待处理子数组的终点high
     * 返回值："中心元素"偏移量
     *      1.选取数组最左边(low)的元素作为中心元素，并记录下该值(pivot)
     *      2.当循环条件low < high时
     *          1).从数组最右端(high)开始处理，如果元素 >= 中心元素，指针向左边偏移(--high)，否则将vec[high]放入vec[low]
     *          2).再从数组最左端[low]开始，如果元素 <= 中心元素，指针向右偏移(++low)，否则再将vec[low]放入vec[high]
     *      3.将pivot值放入vec[low]
     *      4.返回low的偏移量
     */
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
            vec[low] = vec[high];
            while (low < high && vec[low] < pivot)
                ++low;
            vec[high] = vec[low];
        }
        vec[low] = pivot;
        return low;
    }

    /*
     * 堆排序
     * 原理：将含有n个元素的数组构建一个大顶堆，将大顶堆的堆顶与数组第n个元素替换，再将数组的前n-1个元素再次构建成大顶堆，再将堆顶与数组的
     *      第n-1个元素进行替换，循环处理直至大顶堆中只剩一个元素。
     *
     * 步骤：1.从最后一个父亲节点开始循环构建大顶堆，直至所有父亲节点(根节点)都完成大顶堆构建。
     *      2.从vec.size() - 1(最后一个节点)开始逐渐向前遍历，将大顶堆堆顶与大顶堆最后一个节点替换(第一次是数组最后一个元素)，然后再重
     *        新构建大顶堆(元素为vec.size() - 2)，构建好之后再替换，循环处理。
     *
     * 构建大顶堆：
     * 入参：数组(vec)，待构建大顶堆的父节点偏移量(start)，待构建大顶堆最后一个节点的偏移量(end)
     * 步骤：1.定义父亲节点(dad)为传入的start，左孩子节点(son)为start * 2 + 1(因为要调整父亲节点为最大值)
     *      2.在孩子节点小于end的条件下循环处理
     *          1)如果父亲节点存在右孩子，在左右孩子中选择出一个最大的孩子节点
     *          2)将最大的孩子节点与父亲节点比较，如果父亲节点比孩子节点大，直接返回，如果孩子节点比父亲节点大，则交换父子的值，并令新父亲
     *            节点为孩子节点的位置，让孩子节点为新父亲节点的左孩子，继续循环处理。
     */

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
