//
// Created by zhouchangyue on 2022/4/20.
//

#ifndef XEALOUS_THREADANDSAFE_H
#define XEALOUS_THREADANDSAFE_H

#include <iostream>

class ThreadAndSafe {
public:
    static void testUniqueLock();
    static void func();
private:
    static int num;
};


#endif //XEALOUS_THREADANDSAFE_H
