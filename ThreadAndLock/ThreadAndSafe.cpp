//
// Created by zhouchangyue on 2022/4/20.
//

#include <thread>
#include "ThreadAndSafe.h"

int ThreadAndSafe::num = 0;
std::mutex myMutex;

void ThreadAndSafe::testUniqueLock() {
    std::thread mythread[50];
    for (int i = 0; i < 50; ++i) {
        mythread[i] = std::thread([]{
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::unique_lock<std::mutex> lock(myMutex);
            std::cout << "num: " << ++num << std::endl;
        });
    }

    for (int i = 0; i < 50; ++i) {
        mythread[i].join();
    }
}
