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
// * 深度優先搜尋(Depth-First-Search, DFS)
// *
// ******************************

struct Node {

    int data_;

    Node *LeftNode;
    Node *RightNode;
};

int main() {

    std::stack<Node *> unvisited; // 未訪問

    const int kTreeSize = 9; // 樹的大小
    Node node[ kTreeSize ];
    Node *CurNode;

    // 初始化樹
    for (int i = 0; i < kTreeSize; ++i) {

        node[ i ].data_ = i; // 歷遍資料

        int child = (i << 2) + 1; // * 最左子樹

        (child < kTreeSize) ? node[ i ].LeftNode  = &node[ child ] // 左子樹
                            : node[ i ].LeftNode  = nullptr;
        (child < kTreeSize) ? node[ i ].RightNode = &node[ ++child ] // 右子樹
                            : node[ i ].RightNode = nullptr;
    }

    unvisited.push(&node[ 0 ]); // root

    while (!unvisited.empty()) {

        CurNode = unvisited.top(); // 提取未訪問
        unvisited.pop();           // 釋放未訪問

        // 右子樹先入堆疊
        if (CurNode->RightNode != nullptr) { unvisited.push(CurNode->RightNode); }
        if (CurNode->LeftNode != nullptr) { unvisited.push(CurNode->LeftNode); }

        cout << CurNode->data_ << endl;
    }

    system("pause");
    return 0;
}