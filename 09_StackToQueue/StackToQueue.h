//
// Created by zhouchangyue on 2022/4/18.
//

#ifndef XEALOUS_STACKTOQUEUE_H
#define XEALOUS_STACKTOQUEUE_H

#include <iostream>
#include <stack>
#include <queue>

/*
 * stack to queue
 * debug failed in main function
 */

template <typename T>
class StackToQueue {
public:
    void appendTail(T  node);
    T deleteHead();
    StackToQueue() {
        stack1 = {};
        stack2 = {};
    }

public:
    std::stack<T> stack1;
    std::stack<T> stack2;
};



#endif //XEALOUS_STACKTOQUEUE_H
