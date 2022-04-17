//
// Created by zhouchangyue on 2022/4/17.
//

#include "Tree.h"

void Tree::preOrder(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return;

    std::cout << pRoot->value << " ";
    preOrder(pRoot->pLeft);
    preOrder(pRoot->pRight);
}

void Tree::inOrder(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return;

    inOrder(pRoot->pLeft);
    std::cout << pRoot->value << " ";
    inOrder(pRoot->pRight);
}

void Tree::postOrder(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return;

    postOrder(pRoot->pLeft);
    postOrder(pRoot->pRight);
    std::cout << pRoot->value << " ";
}

void Tree::preOrderLoop(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return;

    std::stack<TreeNode *> stack;
    TreeNode * pTree = pRoot;
    while (pTree != nullptr || !stack.empty()) {
        while (pTree != nullptr) {
            std::cout << pTree->value << " ";
            stack.push(pTree);
            pTree = pTree->pLeft;
        }

        if (!stack.empty()) {
            pTree = stack.top();
            stack.pop();
            pTree = pTree->pRight;
        }
    }
}

void Tree::inOrderLoop(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return;

    std::stack<TreeNode *> stack;
    TreeNode * pTree = pRoot;
    while (pTree != nullptr || !stack.empty()) {
        while (pTree != nullptr) {
            stack.push(pTree);
            pTree = pTree->pLeft;
        }

        if (!stack.empty()) {
            pTree = stack.top();
            stack.pop();
            std::cout << pTree->value << " ";
            pTree = pTree->pRight;
        }
    }
}

void Tree::postOrderLoop(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return;

    std::stack<TreeNode *> stack;
    TreeNode * pTree = pRoot;
    TreeNode * pMark = nullptr;
    while (pTree != nullptr || !stack.empty()) {
        while (pTree != nullptr) {
            stack.push(pTree);
            pTree = pTree->pLeft;
        }

        if (!stack.empty()) {
            pTree = stack.top();
            if (pTree->pRight == nullptr || pTree->pRight == pMark) {
                std::cout << pTree->value << " ";
                stack.pop();
                pMark = pTree;
                pTree = nullptr;
            } else {
                pTree = pTree->pRight;
            }
        }
    }
}
