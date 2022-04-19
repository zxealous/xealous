//
// Created by zhouchangyue on 2022/4/19.
//

#ifndef XEALOUS_LRUCACHE_H
#define XEALOUS_LRUCACHE_H

#include <unordered_map>
#include <iostream>

struct DLinkedNode {
    int key, value;
    DLinkedNode* pPre;
    DLinkedNode* pNext;
    DLinkedNode(): key(0), value(0), pPre(nullptr), pNext(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), pPre(nullptr), pNext(nullptr) {}
};

class LRUCache {
public:
    std::unordered_map<int, DLinkedNode *> cache;
    DLinkedNode * pHead = nullptr;
    DLinkedNode * pEnd = nullptr;
    int size;
    int capacity;
    LRUCache(int capacity) {
        pHead = new DLinkedNode();
        pEnd = new DLinkedNode();
        pHead->pNext = pEnd;
        pEnd->pPre = pHead;
        size = 0;
        this->capacity = capacity;
    }

    int get(int key) {
        if (!cache.count(key))
            return -1;

        DLinkedNode * pNode = cache[key];

        moveToHead(pNode);
        return pNode->value;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            DLinkedNode * pNode = cache[key];
            pNode->value = value;

            moveToHead(pNode);
        } else {
            DLinkedNode * pNode = new DLinkedNode(key, value);
            cache[key] = pNode;
            //std::cout << "cache don't have key, will add a new to lru" << std::endl;
            addToHead(pNode);
            if (size > capacity) {
                deleteEnd();
            }
            /*
            for (DLinkedNode * pNode = pHead; pNode != nullptr; pNode = pNode->pNext) {
                std::cout << "pNode->key: " << pNode->key << " pNode->value: " << pNode->value << std::endl;
            }
             */
        }
    }

    void moveToHead(DLinkedNode * pNode) {
        pNode->pPre->pNext = pNode->pNext;
        pNode->pNext->pPre = pNode->pPre;

        pNode->pNext = pHead->pNext;
        pNode->pPre = pHead;

        pNode->pNext->pPre = pNode;

        pHead->pNext = pNode;
    }

    void deleteEnd() {
        DLinkedNode *pNode = pEnd->pPre;
        pNode->pPre->pNext = pEnd;
        pEnd->pPre = pNode->pPre;
        pNode->pPre = nullptr;
        pNode->pNext = nullptr;
        --size;

        cache.erase(pNode->key);
        delete pNode;
        pNode = nullptr;
    }

    void addToHead(DLinkedNode * pNode) {
        pNode->pNext = pHead->pNext;
        pNode->pNext->pPre = pNode;

        pNode->pPre = pHead;
        pHead->pNext = pNode;
        ++size;
    }
};

#endif //XEALOUS_LRUCACHE_H
