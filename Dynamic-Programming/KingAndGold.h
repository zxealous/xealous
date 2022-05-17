//
// Created by zhouchangyue on 2022/5/16.
//

#ifndef XEALOUS_KINGANDGOLD_H
#define XEALOUS_KINGANDGOLD_H

#include <iostream>
#include <vector>

/* 题目: 国王和金矿
 * 描述：有一个国家发现了5座金矿，每座金矿的黄金储量不同，需要参与挖掘的工人数也不同。参与挖矿工人的总数是10人。每座金矿要么全挖，要么不挖，
 *      不能派出一半人挖取一半金矿。要求用程序求解出，要想得到尽可能多的黄金，应该选择挖取哪几座金矿？
 */

class KingAndGold {
public:
    // 递归  忽略命名
    int KingAndGoldRecursion(int n, int w, const std::vector<int> & g, const std::vector<int> & p) {
        if (n <= 1 && w < p[0])
            return 0;
        if (n == 1 && w >= p[0])
            return g[0];
        if (w < p[n-1])
            return KingAndGoldRecursion(n-1, w, g, p);
        else
            return std::max(KingAndGoldRecursion(n-1, w, g, p), KingAndGoldRecursion(n-1, w-p[n-1], g, p) + g[n-1]);
    }

    // 动态规划
    /* 实际上可以通过最右子结构观察到，每次计算的时候只用到了上一行的数据，即计算金矿为1时的最大收益只会用到金矿为0时的数据，因此下面的
     * 实现多记录了很多数据，实际上只记录上一行就可以了，后面再写一个优化的版本吧
     */
    int getMostGold(int n, int w, const std::vector<int> & g, const std::vector<int> & p) {
        std::vector<int> vecTmp;
        std::vector<std::vector<int> > vec;

        // 关于n个人 与数组从0开始不对应 需要仔细思考

        // 外层循环为遍历不同金矿时的场景，金矿个数从0 -> n
        for (int i = 0; i < n; ++i) {
            // 内层循环为遍历不同工人时的场景，j代表工人个数，所以j <= w，j = 0代表有0个工人
            for (int j = 0; j <= w; ++j) {
                 if (i == 0 && j < p[i]) {
                     vecTmp.push_back(0);
                     continue;
                 }
                 if (i == 0 && j >= p[i]) {
                     vecTmp.push_back(g[i]);
                     continue;
                 }
                 // j 代表工人数，同时代表下标，j = 1代表有一个工人
                 if (j < p[i])
                     vecTmp.push_back(vec[i-1][j]);
                 else // vec[i-1][j - p[i]] 这里由于是下标  所以应该是j - p[i] 而不是j+1 - p[i]
                     vecTmp.push_back(std::max(vec[i-1][j], vec[i-1][j - p[i]] + g[i]));
            }

            vec.emplace_back(std::move(vecTmp));
        }

        return vec[n-1][w];
    }

    int getMostGoldOptimization(int n, int w, const std::vector<int> & g, const std::vector<int> & p) {
        // 首先先把第一行 金矿数为1时的边界处理好
        std::vector<int> preVec;
        std::vector<int> vec;

        // 填充preVec，即当有1坐金矿的时候
        for (int i = 0; i <= w; ++i) {
            if (i < p[0])
                preVec.push_back(0);
            else
                preVec.push_back(g[0]);
        }

        // 外层循环为金矿数量
        for (int i = 0; i < n; ++i) {
            // 内层循环为工人总数
            for (int j = 0; j <= w; ++j) {
                if (j < p[i])
                    vec.push_back(preVec[j]);
                else
                    vec.push_back(std::max(preVec[j], preVec[j - p[i]] + g[i]));
            }
            preVec = std::move(vec);
        }
        return preVec[w];
    }
};

#endif //XEALOUS_KINGANDGOLD_H
