//
// Created by zhouchangyue on 2022/5/16.
//

#ifndef XEALOUS_KINGANDGOLD_H
#define XEALOUS_KINGANDGOLD_H

#include <iostream>
#include <vector>

/* 题目: 国王和金矿
 * 有一个国家发现了5座金矿，每座金矿的黄金储量不同，需要参与挖掘的工人数也不同。参与挖矿工人的总数是10人。每座金矿要么全挖，要么不挖，
 * 不能派出一半人挖取一半金矿。要求用程序求解出，要想得到尽可能多的黄金，应该选择挖取哪几座金矿？
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
    int getMostGold(int n, int w, const std::vector<int> & g, const std::vector<int> & p) {
        std::vector<int> vecTmp;
        std::vector<std::vector<int> > vec;

        // 关于n个人 与数组从0开始不对应 需要仔细思考

        // 外层循环为遍历不同金矿时的场景，金矿个数从0 -> n
        for (int i = 0; i < n; ++i) {
            // 内层循环为遍历不同工人时的场景
            for (int j = 0; j < w; ++j) {
                if (i == 0 && j+1 < p[i]) {
                    vecTmp.push_back(0);
                    continue;
                }
                if (i == 0 && j+1 >= p[i]) {
                    vecTmp.push_back(g[i]);
                    continue;
                }
                if (j+1 < p[i])
                    vecTmp.push_back(vec[i-1][j]);
                if (j+1 >= p[i]) {
                    vecTmp.push_back(std::max(vec[i-1][j], vec[i-1][j+1-p[i]] + g[i]));
                    //std::cout << "vec[i-1][j]: " << vec[i-1][j] << std::endl;
                    //std::cout << "vec[i-1][j-p[i]] + g[i]: " << vec[i-1][j-p[i]] + g[i] << std::endl;
                }

            }
            for (auto ite : vecTmp) {
                std::cout << ite << " ";
            }
            std::cout << std::endl;
            vec.emplace_back(std::move(vecTmp));
        }

        return vec[n-1][w-1];
    }
};

#endif //XEALOUS_KINGANDGOLD_H
