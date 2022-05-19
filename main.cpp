#include <iostream>
#include <thread>
#include "SingletonLazy/SingletonLazy.h"
#include "03_FindDuplicate/FindDuplicate.h"
#include "04_FindNum/FindNum.h"
#include "05_ReplaceBlank/ReplaceBlank.h"
#include "06_PrintListReversingly/PrintListReversingly.h"
#include "07_Tree/Tree.h"
#include "09_StackToQueue/StackToQueue.h"
#include "10_Fibonacci/Fibonacci.h"
#include "LRU/LRUCache.h"
#include "Sort/Sort.h"
#include "ThreadAndLock/ThreadAndSafe.h"
#include "TestRandom/StructInClass.h"
#include "Dynamic-Programming/KingAndGold.h"
#include "Dynamic-Programming/TriangleMaxPathSum.h"

void getSingletonObject(){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "inside thread :: ID = " << std::this_thread::get_id() << std::endl;
    SingletonLazy * instance = &SingletonLazy::getSingletonLazy();
}

std::uintptr_t getUInt(int * data) { return reinterpret_cast<std::uintptr_t>(data); }
int * getPtr(std::uintptr_t data) { return reinterpret_cast<int *>(data); }

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

    std::cout << "==============Test Tree===========" << std::endl;
    //get a tree
    TreeNode *pRoot = new TreeNode(10);
    pRoot->pLeft = new TreeNode(6);
    pRoot->pRight = new TreeNode(14);
    pRoot->pLeft->pLeft = new TreeNode(4);
    pRoot->pLeft->pRight = new TreeNode(8);
    pRoot->pRight->pLeft = new TreeNode(12);
    pRoot->pRight->pRight = new TreeNode(16);
    std::cout << "Pre Order: ";
    Tree::preOrder(pRoot);
    std::cout << std::endl;
    std::cout << "In Order: ";
    Tree::inOrder(pRoot);
    std::cout << std::endl;
    std::cout << "Post Order: ";
    Tree::postOrder(pRoot);
    std::cout << std::endl;
    std::cout << "Pre Order(Loop): ";
    Tree::preOrderLoop(pRoot);
    std::cout << std::endl;
    std::cout << "In Order(Loop): ";
    Tree::inOrderLoop(pRoot);
    std::cout << std::endl;
    std::cout << "Post Order(Loop): ";
    Tree::postOrderLoop(pRoot);
    std::cout << std::endl;

    std::cout << "==============Test Tree::buildTree===========" << std::endl;
    std::vector<int> preOrder = {3,9,20,15,7};
    std::vector<int> inOrder = {9,3,15,20,7};
    TreeNode * pTree = Tree::buildTree(preOrder, inOrder);
    std::cout << "Pre Order: ";
    Tree::preOrder(pTree);
    std::cout << std::endl;
    std::cout << "In Order: ";
    Tree::inOrder(pTree);
    std::cout << std::endl;
    std::cout << "==============Test Tree::buildTree===========" << std::endl;

    std::cout << "==============Test Tree===========" << std::endl;

    /*
    std::cout << "==============Test Stack to Queue===========" << std::endl;
    StackToQueue<int> stackToQueue;
    stackToQueue.appendTail(1);
    stackToQueue.appendTail(2);
    stackToQueue.appendTail(3);
    stackToQueue.appendTail(4);
    stackToQueue.appendTail(5);
    for (int i  = 0; i < 5; ++i) {
        std::cout << "deleteHead: " << stackToQueue.deleteHead() << std::endl;
    }
    std::cout << "==============Test Stack to Queue===========" << std::endl;
     */

    std::cout << "==============Test Fibonacci===========" << std::endl;
    std::cout << "fibonacci: " << Fibonacci::fibonacci(2) << std::endl;
    std::cout << "fibonacci: " << Fibonacci::fibonacci(3) << std::endl;
    std::cout << "fibonacci: " << Fibonacci::fibonacci(4) << std::endl;
    std::cout << "fibonacci: " << Fibonacci::fibonacci(5) << std::endl;
    std::cout << "fibonacci: " << Fibonacci::fibonacci(6) << std::endl;
    std::cout << "==============Test Fibonacci===========" << std::endl;

    std::cout << "==============Test LRU===========" << std::endl;
    LRUCache lru(1);
    lru.put(2, 1);
    std::cout << "lru.get(2) = " << lru.get(2) << std::endl;
    std::cout << "==============Test LRU===========" << std::endl;

    std::cout << "==============Test Sort===========" << std::endl;
    std::vector<int> sortVec = {3, 29, 7, 56, 13, 6, 33, 66};
    Sort::QuickSort(sortVec);
    std::cout << "sortVec: ";
    for (auto ite : sortVec)
        std::cout << ite << " ";
    std::cout << std::endl;
    std::cout << "==============Test Sort===========" << std::endl;

    //ThreadAndSafe::testUniqueLock();

    std::cout << "==============Test Heap Sort===========" << std::endl;
    std::vector<int> vecHeapSort = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    Sort::HeapSort(vecHeapSort);
    for (auto ite : vecHeapSort)
        std::cout << ite << " ";
    std::cout << std::endl;
    std::cout << "==============Test Heap Sort===========" << std::endl;

    std::cout << "==============Test std::make_unique===========" << std::endl;
    auto ptr = std::make_unique<FindNum>();
    ptr->findNumInVector(vec2, 6);
    std::cout << "==============Test std::make_unique===========" << std::endl;

    std::cout << "==============Test use uintptr_t as marker===========" << std::endl;
    std::uintptr_t IS_NEED = 1;
    std::uintptr_t IS_FINISHED = 2;
    std::uintptr_t mark = IS_FINISHED | IS_NEED;
    std::uintptr_t used_mark = ~mark;

    used_mark = used_mark | IS_NEED;
    std::cout << "used_mark = " << used_mark << std::endl;
    if (IS_NEED & used_mark)
        std::cout << "IS_NEED & used_mark = 1" << std::endl;
    else
        std::cout << "IS_NEED & used_mark = 0" << std::endl;

    if (IS_FINISHED & used_mark)
        std::cout << "IS_FINISHED & used_mark = 1" << std::endl;
    else
        std::cout << "IS_FINISHED & used_mark = 0" << std::endl;
    std::cout << "==============Test use uintptr_t as marker===========" << std::endl;

    std::cout << "==============Test use uintptr_t===========" << std::endl;
    int num = 1;
    std::uintptr_t data = getUInt(&num);
    std::cout << "data: " << data << std::endl;
    int * testPtr = getPtr(data);
    std::cout << "testPtr: " << testPtr << std::endl;
    std::cout << "*testPtr: " << *testPtr << std::endl;
    std::cout << "==============Test use uintptr_t===========" << std::endl;

    std::cout << "==============Test struct in class===========" << std::endl;
    StructInClass::node * pNode = new StructInClass::node(1);
    std::cout << "pNode->num = " << pNode->num << std::endl;
    std::cout << "==============Test struct in class===========" << std::endl;

    std::cout << "==============Test DP King And Gold===========" << std::endl;
    KingAndGold kingAndGold;
    std::vector<int> gold = {400, 500, 200, 300, 350};
    std::vector<int> person = {5, 5, 3, 4, 3};
    std::cout << "[Recursion]Max value: " << kingAndGold.KingAndGoldRecursion(5, 10, gold, person) << std::endl;
    std::cout << "[DP]Max value: " << kingAndGold.getMostGold(5, 10, gold, person) << std::endl;
    std::cout << "[DP-Optimization]Max value: " << kingAndGold.getMostGoldOptimization(5, 10, gold, person) << std::endl;
    std::cout << "==============Test DP King And Gold===========" << std::endl;

    std::cout << "==============Test DP Triangle Max Path Sum===========" << std::endl;
    std::vector<std::vector<int>> vecTriangle = {{7}, {3,8}, {8,1,0}, {2,7,4,4}, {4,5,2,6,5}};
    TriangleMaxPathSum triangleMaxPathSum;
    std::cout << "Max Path Sum: " << triangleMaxPathSum.getMaxPathSumRecursion(vecTriangle, 0, 0) << std::endl;
    std::cout << "Max Path Sum: " << triangleMaxPathSum.getMaxPathSumDp(vecTriangle) << std::endl;
    std::cout << "Max Path Sum: " << triangleMaxPathSum.getMaxPathSumDpOptimizatioin(vecTriangle) << std::endl;
    std::cout << "==============Test DP Triangle Max Path Sum===========" << std::endl;

    return  0;
}