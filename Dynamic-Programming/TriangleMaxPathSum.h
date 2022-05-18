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
     * 当做一个错误示例吧，这种递归方式相当于是临界点是00(递归栈底为00)，也就是相当与从位置开始 每次判断下方还是下右的值比较大
     * 实际上应该从00开始，每次取下一行j,j+1两个值为起点时的最大路径，直至取到最大行。
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
    /* 正确思路为：
     * 从顶点00开始，每次取下一行j,j+1两个值为起点时的最大路径(此处为递归)，直至最大行
     * vec: 传入的三角形
     * i: 起始行(当前行)
     * j: 起始列(当前列)
     */
    int getMaxPathSumRecursion(std::vector<std::vector<int>> vec, int i, int j) {
        if (i == vec.size() - 1)
            return vec[i][j];

        return std::max(getMaxPathSumRecursion(vec, i+1, j), getMaxPathSumRecursion(vec, i+1, j+1)) + vec[i][j];
    }

    int getMaxPathSumDp(std::vector<std::vector<int>> vec) {
        std::vector<std::vector<int>> res(vec.size());
        std::vector<int> tmp;
        int vecSize = vec.size();
        // 首先处理边界，也就是i为最大行时
        for (int m = 0; m < vecSize; ++m) {
            tmp.push_back(vec[vecSize - 1][m]);
        }
        res[vecSize - 1] = std::move(tmp);

        for (int m = vecSize - 2; m >= 0; --m) {
            for (int n = 0; n <= m; ++n) {
                tmp.push_back(vec[m][n] + std::max(res[m+1][n], res[m+1][n+1]));
            }
            res[m] = std::move(tmp);
        }

        /*
        for (int i = 0; i < vecSize; ++i) {
            for (int j = 0; j <= i; ++j) {
                std::cout << res[i][j] << " ";
            }
            std::cout << std::endl;
        }
        */

        return res[0][0];
    }
};

#endif //XEALOUS_TRIANGLEMAXPATHSUM_H
