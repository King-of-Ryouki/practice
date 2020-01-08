#include "_pch.hpp"

// ******************************
// *
// * 插入排序(Insertion sort)：
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

// 插入排序是一種簡單直觀的排序演算法。它的工作原理是通過構建有序序列，
// 對於未排序資料，在已排序序列中從後向前掃描，找到相應位置並插入。插入排序在實現上，
// 通常採用in-place排序（即只需用到 O(1) 的額外空間的排序），因而在從後向前掃描過程中，
// 需要反覆把已排序元素逐步向後挪位，為最新元素提供插入空間。

// * 插入排序(Insertion sort)
template <typename T>
void InsertionSort(T arr[], int &arr_size) {

    if (arr_size <= 0) { return; }

    for (int i = 0; i < arr_size - 1; ++i) {

        int tmp = arr[ i + 1 ];
        int j   = i;

        while ((j >= 0) && (arr[ j ] > tmp)) {
            arr[ j + 1 ] = arr[ j ]; // 大於的就右移
            --j;
        }

        arr[ j + 1 ] = tmp; // --j + 1 == j
    }
}

// * 折半插入排序(Binary insertion sort)
void BinaryInsertionSort(int arr[], int arr_size) {

    if (arr_size <= 0) { return; }

    for (int i = 0; i < arr_size - 1; ++i) {

        int tmp = arr[ i + 1 ];

        int begin = 0;
        int end   = i;

        while (begin <= end) { // 二分搜尋

            int mid = begin + (end - begin) / 2;

            (arr[ mid ] > tmp)
                ? end   = mid - 1
                : begin = mid + 1;
        }

        for (int j = i; j >= begin; --j) {
            arr[ j + 1 ] = arr[ j ]; // 大於的就右移
        }

        arr[ begin ] = tmp;
    }
}