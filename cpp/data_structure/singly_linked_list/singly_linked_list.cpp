#include "singly_linked_list.hpp"

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

int main() {

    // * init

    SinglyLinkedListNode *HeadNode = new SinglyLinkedListNode; // ! 頭節點內容捨棄不用, 僅用於紀錄位址
    // HeadNode->NextNode             = new SinglyLinkedListNode;
    // SinglyLinkedListNode *OperNode = HeadNode->NextNode; // 用於操作
    SinglyLinkedListNode *OperNode = HeadNode; // 用於操作

    SinglyLinkedList SinglyLinkedList;

    // * Main

    while (true) {

        OperNode = HeadNode;
        // OperNode = HeadNode->NextNode;

        OperExplain(); // 操作顯示

        int input_status;
        cin >> input_status;
        cout << endl;

        switch (input_status) {

            case 0: return 0;

            case 1: SinglyLinkedList.Create(OperNode); break; // 建立鏈表
            case 2: SinglyLinkedList.Print(OperNode); break;  // 印出鏈表
            case 3: SinglyLinkedList.Insert(OperNode); break; // 插入鏈表

            case 4: SinglyLinkedList.DeleteOne(OperNode); break; // 刪除單個鏈表
            case 5: SinglyLinkedList.DeleteAll(OperNode); break; // 刪除所有鏈表

            case 6: SinglyLinkedList.SearchNodeIdByData(OperNode); break; // 用 data 找 id
            case 7: SinglyLinkedList.SearchDataByNodeId(OperNode); break; // 用 id 找 data
        }
    }

    system("pause");
    return 0;
}