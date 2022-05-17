//
// Created by zhouchangyue on 2022/5/17.
//

#ifndef XEALOUS_TRIANGLEMAXPATHSUM_H
#define XEALOUS_TRIANGLEMAXPATHSUM_H
#include <iostream>
#include <vector>

/* 题目：数字三角形最大路径
 * 描述：在上面的数字三角形中寻找一条从顶部到底边的路径，使得路径上所经过的数字之和最大。路径上的每一步都只能往 左下 或 右下 走。
 *      只需要求出这个最大和即可，不必给出具体路径。
 *     7
 *    3  8
 *   8  1  0
 *  2  7  4  4
 * 4  5  2  6  5
 *
 * 分析：
 * 7
 * 3 8
 * 8 1 0
 * 2 7 4 4
 * 4 5 2 6 5
 * 相当于只能往 `下` or `右下`两个方向走
 * 最优子结构：
 * F[5] = F[4] + max(vec[5][n], vec[5][n+1])
 * 边界：1 如：vec[0] = 7
 */
class TriangleMaxPathSum {
public:
    /*
     * 当做一个错误示例吧，这种递归方式相当于是临界点是00，也就是相当与从00位置开始 每次判断下方还是下右的值比较大
     * 实际上应该从最大行和最大列的点开始，从三角形的右下角向左上角
    int getMaxPathSumRecursion(std::vector<std::vector<int>> vec, int n, int & pos) {
        if (n == 1) {
            pos = 0;
            return vec[0][0];
        }

        int tmp = getMaxPathSumRecursion(vec, n-1, pos);
        if (vec[n - 1][pos] > vec[n - 1][pos + 1])
            return tmp + vec[n - 1][pos];
        else
            return tmp + vec[n - 1][++pos];
    }
    */
};

#endif //XEALOUS_TRIANGLEMAXPATHSUM_H
