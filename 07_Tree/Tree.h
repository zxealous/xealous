//
// Created by zhouchangyue on 2022/4/17.
//

#ifndef XEALOUS_TREE_H
#define XEALOUS_TREE_H

#include <iostream>
#include <stack>

/*
 * 二叉树相关，三中遍历的递归非递归、重建二叉树
 */

struct TreeNode {
    int value;
    struct TreeNode * pLeft;
    struct TreeNode * pRight;
public:
    explicit TreeNode(int a) {
        value = a;
        pLeft = nullptr;
        pRight = nullptr;
    }
};

class Tree {
public:
    static void preOrder(TreeNode * pRoot);
    static void inOrder(TreeNode * pRoot);
    static void postOrder(TreeNode * pRoot);

    static void preOrderLoop(TreeNode * pRoot);
    static void inOrderLoop(TreeNode * pRoot);
    static void postOrderLoop(TreeNode * pRoot);
};


#endif //XEALOUS_TREE_H
