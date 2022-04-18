//
// Created by zhouchangyue on 2022/4/18.
//

#include "StackToQueue.h"

template<typename T>
void StackToQueue<T>::appendTail( T node) {
    stack1.push(node);
}

template<typename T>
T StackToQueue<T>::deleteHead() {
    while (stack1.size() != 1) {
        stack2.push(stack1.top());
        stack1.pop();
    }
    T res = stack1.top();
    stack1.pop();

    while (!stack2.empty()) {
        stack1.push(stack2.top());
        stack2.pop();
    }
    return res;
}

