#include "_pch.hpp"

// ******************************
// *
// * 快速排序(Quick sort)：
// * 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
// *
// * 時間複雜度：
// * 最壞時間複雜度 O(n^2)
// * 最佳時間複雜度 O(n log n)
// * 平均時間複雜度 O(n log n)
// *
// * 空間複雜度：
// * 最壞空間複雜度 根據實現的方式不同而不同
// *
// ******************************

// 快速排序（Quicksort），又稱劃分交換排序（partition-exchange sort），簡稱快排。
// 在平均狀況下，排序n個項目要 O(n log n) 次比較。
// 在最壞狀況下則需要 O(n^2) 次比較，但這種狀況並不常見。
// 事實上，快速排序通常明顯比其他演算法更快，
// 因為它的內部迴圈（inner loop）可以在大部分的架構上很有效率地達成。

// * 快速排序(Quick sort)
// 疊代法
struct QuickSortArrayRange {

    QuickSortArrayRange(int start = 0, int end = 0)
        : start_(start),
          end_(end) {}

    int start_;
    int end_;
};

template <typename T>
void QuickSort(T arr[], const int &arr_size) {

    if (arr_size <= 0) { return; }

    stack<QuickSortArrayRange> StackArrayRange;
    StackArrayRange.push(QuickSortArrayRange(0, arr_size - 1));

    while (!StackArrayRange.empty()) {

        QuickSortArrayRange OperArray = StackArrayRange.top();
        StackArrayRange.pop();

        if (OperArray.start_ >= OperArray.end_) { continue; } // 越界, StackArrayRange[ --arr_iter ];

        int left  = OperArray.start_;
        int right = OperArray.end_;

        // * 依照大小左右分割
        while (left < right) {

            while (left < right && arr[ left ] < arr[ OperArray.end_ ]) { ++left; }    // 在左侧找比 mid 大的數
            while (left < right && arr[ OperArray.end_ ] <= arr[ right ]) { --right; } // 在右侧找比 mid 小的數

            std::swap(arr[ left ], arr[ right ]);
        }

        std::swap(arr[ left ], arr[ OperArray.end_ ]); // * arr_end  ==> mid

        StackArrayRange.push(QuickSortArrayRange(OperArray.start_, left - 1)); // 左邊再度分割
        StackArrayRange.push(QuickSortArrayRange(left + 1, OperArray.end_));   // 右邊再度分割
    }
}

// 遞迴法 1
template <typename T>
void QuickSortRecursive(T arr[], int arr_start, int arr_end) {

    if (arr_start >= arr_end || arr_start < 0 || arr_end < 1) { return; }

    int left  = arr_start;
    int right = arr_end;

    // 依照大小左右分割
    while (left < right) {

        while (left < right && arr[ left ] < arr[ arr_end ]) { ++left; }    // 在左侧找比 mid 大的數
        while (left < right && arr[ arr_end ] <= arr[ right ]) { --right; } // 在右侧找比 mid 小的數

        std::swap(arr[ left ], arr[ right ]);
    }

    std::swap(arr[ left ], arr[ arr_end ]); // * left == ++left == mid

    QuickSortRecursive(arr, arr_start, left - 1); // 左邊再度分割
    QuickSortRecursive(arr, left + 1, arr_end);   // 右邊再度分割
}

template <typename T>
void QuickSortRecursive(T arr[], int &arr_size) {
    QuickSortRecursive(arr, 0, arr_size - 1);
}

// 遞迴法 2
template <typename T>
void QuickSortRecursive2(T arr[], int arr_start, int arr_end) {

    if (arr_start >= arr_end || arr_start < 0 || arr_end < 1) { return; }

    int left  = arr_start;
    int right = arr_end;

    int arr_mid = arr[ arr_start + (arr_end - arr_start) / 2 ];

    while (left <= right) {

        while (arr[ left ] < arr_mid) { ++left; }
        while (arr_mid < arr[ right ]) { --right; }

        if (left < right) {

            std::swap(arr[ left ], arr[ right ]);

            ++left;
            --right;

        } else if (left == right) {
            ++left;
        }
    }

    QuickSortRecursive2(arr, arr_start, right);
    QuickSortRecursive2(arr, left, arr_end);
}

template <typename T>
void QuickSortRecursive2(T arr[], int &arr_size) {
    QuickSortRecursive2(arr, 0, arr_size - 1);
}