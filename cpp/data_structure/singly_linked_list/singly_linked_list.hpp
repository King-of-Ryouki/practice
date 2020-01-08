#ifndef _SINGLY_LINKED_LIST_HPP_
#define _SINGLY_LINKED_LIST_HPP_

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// ******************************
// *
// * Date     : 2019/08/21
// *
// * Author   : 施冠年
// * Mail     : Co6901251@gmail.com
// *
// * Function :
// *
// * 單鏈表實現
// *
// ******************************

// 單鏈表節點
class SinglyLinkedListNode {
public:
    SinglyLinkedListNode() : NextNode(nullptr) {} // 單鏈表
    // SinglyLinkedListNode() : LastNode(nullptr), NextNode(nullptr) {} // 雙鏈表
    ~SinglyLinkedListNode() {}

    void set_data(int data) { data_ = data; }
    int get_data() { return data_; }

    // SinglyLinkedListNode *LastNode; // 前節點
    SinglyLinkedListNode *NextNode; // 後節點

private:
    int data_;
};

// 單鏈表
class SinglyLinkedList {
public:
    void Create(SinglyLinkedListNode *&OperNode); // 建立鏈表
    void Print(SinglyLinkedListNode *&OperNode);  // 印出鏈表
    void Insert(SinglyLinkedListNode *&OperNode); // 插入鏈表

    void SearchNodeIdByData(SinglyLinkedListNode *&OperNode); // 用 data 找 id
    void SearchDataByNodeId(SinglyLinkedListNode *&OperNode); // 用 id 找 data

    void DeleteOne(SinglyLinkedListNode *&OperNode); // 刪除單個鏈表
    void DeleteAll(SinglyLinkedListNode *&OperNode); // 刪除所有鏈表
};

// ******************************
// *
// * 找出尾端，新增資料
// *
// ******************************
void SinglyLinkedList::Create(SinglyLinkedListNode *&OperNode) {

    cout << "----- Input \"Ctrl + D\" to end -----\n\n";
    cout << "Add : ";

    while (OperNode->NextNode != nullptr) { OperNode = OperNode->NextNode; } // 找尾端

    int input_data;
    while (cin >> input_data) { // * Ctrl + D 结束输入

        SinglyLinkedListNode *NewNode = new SinglyLinkedListNode; // 新節點

        NewNode->set_data(input_data);           // * 1. 存入資料
        OperNode->NextNode = NewNode;            // * 2. 鏈表指向新節點
        OperNode           = OperNode->NextNode; // * 3. 新結點成為鏈表尾節點

        cout << "Add : ";

        // 清理輸入
        cin.clear();
        cin.sync();
    }
}

// ******************************
// *
// * 歷遍，印出
// *
// ******************************
void SinglyLinkedList::Print(SinglyLinkedListNode *&OperNode) {

    int i = 0;
    while (OperNode->NextNode != nullptr) {
        OperNode = OperNode->NextNode;
        cout << "SinglyLinkedList_" << i << " data : " << OperNode->get_data() << endl;
        ++i;
    }
}

// ******************************
// *
// * 歷遍，找 id
// * 若沒有找到 id 則資料新增至尾端
// *
// ******************************
void SinglyLinkedList::Insert(SinglyLinkedListNode *&OperNode) {

    cout << "insert node id   : ";
    int insert_node_id;
    cin >> insert_node_id;

    cout << "insert node data : ";
    int insert_node_data;
    cin >> insert_node_data;

    int i = 0;
    while (OperNode->NextNode != nullptr && insert_node_id != i) {
        OperNode = OperNode->NextNode;
        ++i;
    }

    SinglyLinkedListNode *NewNode = new SinglyLinkedListNode;

    NewNode->set_data(insert_node_data);     // * 1. 存入資料
    NewNode->NextNode  = OperNode->NextNode; // * 2. 新節點指向後節點
    OperNode->NextNode = NewNode;            // * 3. 前節點指向新節點
}

// * Search

// ******************************
// *
// * 歷遍，找出與輸入相同的資料
// *
// ******************************
void SinglyLinkedList::SearchNodeIdByData(SinglyLinkedListNode *&OperNode) {

    cout << "Search node id by data : ";
    int input_data;
    cin >> input_data;

    int node_id  = 0;
    int found_id = false;

    while (OperNode->NextNode != nullptr) {

        OperNode = OperNode->NextNode;

        if (input_data == OperNode->get_data()) {
            found_id = true;
            break;
        }

        ++node_id;
    }

    if (found_id == true) {
        cout << "The data \"" << OperNode->get_data() << "\" "
             << "is at node id : " << node_id << endl;
    } else {
        cout << "Id not found." << endl;
    }
}

// ******************************
// *
// * 歷遍，找出與輸入相同的 id
// *
// ******************************
void SinglyLinkedList::SearchDataByNodeId(SinglyLinkedListNode *&OperNode) {

    cout << "Search data by node id : ";
    int input_id;
    cin >> input_id;

    int node_id    = 0;
    int found_data = false;

    while (OperNode->NextNode != nullptr) {

        OperNode = OperNode->NextNode;

        if (input_id == node_id) {
            found_data = true;
            break;
        }

        ++node_id;
    }

    if (found_data == true) {
        cout << "The data at Node id " << node_id
             << " is : \"" << OperNode->get_data() << "\"" << endl;
    } else {
        cout << "Data not found." << endl;
    }
}

// * Delete

// ******************************
// *
// * 找到 id, delete
// *
// ******************************
void SinglyLinkedList::DeleteOne(SinglyLinkedListNode *&OperNode) {

    cout << "Delete data at position : ";
    int pos;
    cin >> pos;

    int i = 0;
    while (OperNode->NextNode != nullptr && i != pos) {
        OperNode = OperNode->NextNode;
        ++i;
    }

    SinglyLinkedListNode *DeleteNode = OperNode->NextNode; // ! 不能先指向 OperNode 本體
    OperNode->NextNode               = OperNode->NextNode->NextNode;
    delete DeleteNode;
}

// ******************************
// *
// * 歷遍， delete
// *
// ******************************
void SinglyLinkedList::DeleteAll(SinglyLinkedListNode *&OperNode) {

    cout << "Delete all singie llinked list !" << endl;

    while (OperNode->NextNode != nullptr) {
        SinglyLinkedListNode *DeleteNode = OperNode->NextNode; // ! 不能先指向 OperNode 本體
        OperNode->NextNode               = OperNode->NextNode->NextNode;
        delete DeleteNode;
    }
}

// * other function

// 操作顯示
void OperExplain() {

    cout << "\n------------------------------\n\n"
         << "Singly linked list status : \n\n"
         << "1. Create\n"
         << "2. Print\n"
         << "3. Insert\n"
         << "4. DeleteOne\n"
         << "5. DeleteAll\n"
         << "6. Search node id by data\n"
         << "7. Search data by node id\n" // 順序查找
         << "0. Exit\n"
         << endl
         << "Input status : ";

    // 清理輸入
    cin.clear();
    cin.sync();
}

#endif // _SINGLY_LINKED_LIST_HPP_