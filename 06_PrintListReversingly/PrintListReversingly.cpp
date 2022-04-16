//
// Created by zhouchangyue on 2022/4/17.
//

#include <iostream>
#include <stack>
#include "PrintListReversingly.h"


void PrintListReversingly::printListReversingly(std::list<int> list) {
    std::stack<int> stack;

    for (auto ite : list) {
        stack.push(ite);
    }

    while (!stack.empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
}
