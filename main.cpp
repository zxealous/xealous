#include <iostream>
#include <thread>
#include "SingletonLazy/SingletonLazy.h"
#include "03_FindDuplicate/FindDuplicate.h"
#include "04_FindNum/FindNum.h"
#include "05_ReplaceBlank/ReplaceBlank.h"
#include "06_PrintListReversingly/PrintListReversingly.h"

void getSingletonObject(){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "inside thread :: ID = " << std::this_thread::get_id() << std::endl;
    SingletonLazy * instance = &SingletonLazy::getSingletonLazy();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "You are so great!" << std::endl;
/*
    for (int i = 0; i < 100; ++i) {
        std::thread threadObject(getSingletonObject);
        //threadObject.join();
        threadObject.detach();
    }

    std::this_thread::sleep_for(std::chrono::seconds(5));
    */
    // Test FindDuplicate::isDuplicate
    std::cout << "==============Test FindDuplicate::isDuplicate===========" << std::endl;
    std::vector<int> vec = {3, 1, 4, 2, 5, 4, 6};
    std::string res =  FindDuplicate::isDuplicate(vec) ? "true" : "false";
    std::cout << "vec is duplicate ? " << res << std::endl;
    std::cout << "==============Test FindDuplicate::isDuplicate===========" << std::endl;

    // Test FindDuplicate::getDuplicate
    std::cout << "==============Test FindDuplicate::getDuplicate===========" << std::endl;
    int duplicateNum = FindDuplicate::getDuplicate(vec);
    std::cout << "duplicateNum: " << duplicateNum << std::endl;
    std::cout << "==============Test FindDuplicate::getDuplicate===========" << std::endl;

    // Test FindNum::findNumInVector
    std::cout << "==============Test FindNum::findNumInVector===========" << std::endl;
    std::vector<std::vector<int>> vec2{{1, 2, 8, 9},
                                       {3, 4, 9, 12},
                                       {4, 7, 10, 13},
                                       {6, 8, 11, 15}};
    res = FindNum::findNumInVector(vec2, 6) ? "true" : "false";
    std::cout << "find number in vector: " << res << std::endl;
    std::cout << "==============Test FindNum::findNumInVector===========" << std::endl;

    // Test ReplaceBlank::replaceBlank
    std::cout << "==============Test ReplaceBlank::replaceBlank===========" << std::endl;
    char str[] = " hello world  ";
    ReplaceBlank::replaceBlank(str, 100);
    std::cout << "str change to \"" << str << "\"" << std::endl;
    std::cout << "==============Test ReplaceBlank::replaceBlank===========" << std::endl;

    // Test PrintListReversingly::printListReversingly
    std::cout << "==============Test PrintListReversingly::printListReversingly===========" << std::endl;
    std::list<int> list;
    for (int i = 1; i <= 5; ++i) {
        list.push_back(i);
    }
    PrintListReversingly::printListReversingly(list);
    std::cout << "==============Test PrintListReversingly::printListReversingly===========" << std::endl;

    return 0;
}