#include "_pch.hpp"

// ******************************
// *
// * 冒泡排序(Bubble sort)：
// * 判斷的數字會優先移到最(頂/底)端
// *
// * 時間複雜度：
// * 最壞時間複雜度 O(n^2)
// * 最佳時間複雜度 O(n)
// * 平均時間複雜度 O(n^2)
// *
// * 空間複雜度：
// * 最壞空間複雜度
// * 總共 O(n)
// * 輔助 O(1)
// *
// ******************************

// 冒泡排序，有時也被稱做沉降排序，是一種比較簡單的排序演算法。
// 這種演算法的實現是透過遍歷要排序的列表，把相鄰兩個不符合排列規則的數據項交換位置，
// 然後重複遍歷列表，直到不再出現需要交換的數據項。
// 當沒有數據項需要交換時，則表明該列表已排序。

// * 冒泡排序(Bubble sort)
template <typename T>
void BubbleSort(T arr[], int &arr_size) {

    if (arr_size <= 0) { return; }

    for (int i = 0; i < arr_size; ++i) { // 次數

        bool is_swapped = false; // 判斷是否有交換，最佳解 O(n^2) => O(n)

        for (int j = 0; j < arr_size - i - 1; ++j) { // 從右側開始
            if (arr[ j ] > arr[ j + 1 ]) {
                std::swap(arr[ j ], arr[ j + 1 ]);
                is_swapped = true;
            }
        }

        if (is_swapped == false) { break; }
    }
}

// vector 迭代器
template <typename T>
void BubbleSortVector(T iter_begin,
                      T iter_end) { // T = vector<int>::iterator

    for (auto i = iter_begin; i != iter_end; ++i) {

        bool is_swapped = false;

        for (auto j = iter_begin; j != iter_end - 1; ++j) {

            if (*j > *(j + 1)) {
                swap(*j, *(j + 1));
                is_swapped = true; // 表示此轮循环进行了交换
            }
        }

        if (is_swapped == false) { break; }
    }
}