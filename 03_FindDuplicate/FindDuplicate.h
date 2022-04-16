//
// Created by zhouchangyue on 2022/4/16.
//

#ifndef XEALOUS_FINDDUPLICATE_H
#define XEALOUS_FINDDUPLICATE_H

#include <vector>

/*
 * 查找重复的值
 */

class FindDuplicate {
public:
    static bool isDuplicate(std::vector<int> vec);
    static int getDuplicate(const std::vector<int> & vec);
    static int countNum(const std::vector<int> & vec, int start, int end);
};


#endif //C__TEST_FINDDUPLICATE_H
