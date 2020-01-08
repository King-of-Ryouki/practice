#include "../../_pch.hpp"

// ******************************
// *
// * date     : 2019/11/26
// *
// * author   : 施冠年
// * mail     : Co6901251@gmail.com
// *
// * function :
// *
// * 廣度優先搜尋(Breadth-First-Search, BFS)
// *
// ******************************

struct Node {

    int data_;

    Node *LeftNode;
    Node *RightNode;
};

int main() {

    std::queue<Node *> unvisited; // 未訪問

    const int kTreeSize = 9; // 樹的大小
    Node node[ kTreeSize ];
    Node *CurNode;

    unvisited.push(&node[ 0 ]); // root

    while (!unvisited.empty()) {

        CurNode = unvisited.front(); // 提取未訪問
        unvisited.pop();             // 釋放未訪問

        // 入隊列
        if (CurNode->LeftNode != nullptr) { unvisited.push(CurNode->LeftNode); }
        if (CurNode->RightNode != nullptr) { unvisited.push(CurNode->RightNode); }

        cout << CurNode->data_ << endl;
    }

    system("pause");
    return 0;
}