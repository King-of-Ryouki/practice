#include "_pch.hpp"

// ******************************
// *
// * 堆積排序(Heap sort)
// * 在已排序序列中從後向前掃描，找到相應位置並插入
// *
// * 時間複雜度：
// * 最壞時間複雜度 O(n^2)
// * 最佳時間複雜度 O(n)
// * 平均時間複雜度 O(n^2)
// *
// * 空間複雜度：
// * 最壞空間複雜度 O(1)
// *
// ******************************

// 堆積排序(Heap sort) 是指利用堆積這種資料結構所設計的一種排序演算法。
// 堆積是一個近似完全二元樹的結構，並同時滿足堆積的性質：
// 即子節點的鍵值或索引總是小於（或者大於）它的父節點。

// 若以升序排序說明，把陣列轉換成最大堆積(Max-Heap Heap)，這是一種滿足最大堆積性質(Max-Heap Property)的二元樹：
// 對於除了根之外的每個節點i, A[parent(i)] ≥ A[i]。
//
// 重複從最大堆積取出數值最大的結點(把根結點和最後一個結點交換，把交換後的最後一個結點移出堆)，
// 並讓殘餘的堆積維持最大堆積性質。

// 堆積排序法為選擇排序法的改良

// * 堆積排序(Heap sort)
inline void MaxHeap(int arr[], const int &arr_begin, const int &arr_end) {

    // 從小到大逆著堆積(root 最終為最大)
    int root = arr_begin;
    int sub  = (root << 1) + 1;

    while (sub <= arr_end) {

        // * 比較左右子節點大小
        if ((sub + 1 <= arr_end) && (arr[ sub ] < arr[ sub + 1 ])) {
            ++sub;
        }

        // * 最大堆積(root 最大)
        if (arr[ root ] > arr[ sub ]) {
            return;
        } else {
            swap(arr[ root ], arr[ sub ]);

            root = sub;
            sub  = (root << 1) + 1;
        }
    }
}

void HeapSort_Recursive(int arr[], const int &arr_size) {

    // 從小到大逆著堆積(root 最終為最大)
    for (int i = (arr_size / 2) - 1; i >= 0; --i) {
        MaxHeap(arr, i, arr_size - 1);
    }

    // 尾部 從最大元素開始逆排序
    // 先將第一個元素和已经排好的元素前一位做交換，再重新調整(刚调整的元素之前的元素)，直到排序完畢
    for (int i = arr_size - 1; i > 0; --i) {
        swap(arr[ 0 ], arr[ i ]);
        MaxHeap(arr, 0, i - 1);
    }
}