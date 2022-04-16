//
// Created by zhouchangyue on 2022/4/16.
//

#ifndef XEALOUS_SINGLETONLAZY_H
#define XEALOUS_SINGLETONLAZY_H


#include <iostream>

/*
 * 单例模式 Lazy
 * 利用Magic static 特性
 */
class SingletonLazy {
public:
    SingletonLazy(const SingletonLazy &) = delete;
    SingletonLazy & operator = (const SingletonLazy &) = delete;
    static SingletonLazy & getSingletonLazy() {
        static SingletonLazy instance;
        std::cout << "++num = " << ++num << std::endl;
        return instance;
    }

private:
    SingletonLazy() {
        std::cout << "SingletonLazy::SingletonLazy()" << std::endl;
    }
    static int num;
};


#endif //C__TEST_SINGLETONLAZY_H
