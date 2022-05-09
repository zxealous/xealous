//
// Created by zhouchangyue on 2022/5/9.
//

#ifndef XEALOUS_CAS_H
#define XEALOUS_CAS_H

#include <atomic>

class lock_free_stack {
public:
    struct node {
        int num;
        node * next;

        node(int val) {
            num = val;
            next = nullptr;
        }
    };
public:
    std::atomic<node *> head;

    void push(int value) {
        node * pNode = new node(value);
        pNode->next = head;
        // 如果此时，刚将pNode->next 赋值为head，就没有了时间片，其他线程向栈顶成功插入一个node后，当该线程再获得到时间片则会将刚才的
        // 线程的操作给抹掉，栈顶为pNode，pNode->next为老head，而不是另外一个线程插入的新node
        // 使用compare_exchange_weak后，如果pNode->next不是head，则代表有其他线程插入成功过一次，
        // 则会令pNode->next值为当前的head值,即其他线程插入成功后的node，然后再令head为pNode(当前线程新建的pNode)
        while (!head.compare_exchange_weak(pNode->next, pNode));
    }
};

#endif //XEALOUS_CAS_H
