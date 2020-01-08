#include "_pch.hpp"

// ******************************
// *
// * 合併排序(MergeSortRecursive sort)：
// * 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
// *
// * 時間複雜度：
// * 最壞時間複雜度 O(n^2)
// * 最佳時間複雜度 O(n log n)
// * 平均時間複雜度 O(n log n)
// *
// * 空間複雜度：
// * 比較操作的次數介於 (n log n)/2 和 (n log n - n + 1}。
// * 賦值操作的次數是 (2n log n)。
// * 合併演算法的空間複雜度為 Theta (n)。
// *
// ******************************

// 合併排序（英語：Merge sort，或mergesort），是建立在合併操作上的一種有效的排序演算法，
// 效率為 O(n log n) 1945年由約翰·馮·紐曼首次提出。
// 該演算法是採用分治法（Divide and Conquer）的一個非常典型的應用，且各層分治遞迴可以同時進行。

// 合併操作（merge），也叫合併演算法，
// 指的是將兩個已經排序的序列合併成一個序列的操作。合併排序演算法依賴合併操作。

// 遞迴法（Top-down）
// 申請空間，使其大小為兩個已經排序序列之和，該空間用來存放合併後的序列
// 設定兩個指標，最初位置分別為兩個已經排序序列的起始位置
// 比較兩個指標所指向的元素，選擇相對小的元素放入到合併空間，並移動指標到下一位置
// 重複步驟3直到某一指標到達序列尾
// 將另一序列剩下的所有元素直接複製到合併序列尾

// 疊代法（Bottom-up）
// 原理如下（假設序列共有 n 個元素）：
// 將序列每相鄰兩個數字進行合併操作，形成 ceil(n/2) 個序列，排序後每個序列包含兩/一個元素
// 若此時序列數不是1個則將上述序列再次合併，形成 ceil(n/4) 個序列，每個序列包含四/三個元素
// 重複步驟2，直到所有元素排序完畢，即序列數為1

// * 合併排序(MergeSortRecursive sort)
// * 疊代版
template <typename T>
void MergeSort(T arr[], int &arr_size) {

    if (arr_size <= 0) { return; }

    T *arr_oper = new T[ arr_size ];

    for (int i = 1; i < arr_size; i *= 2) {         // * ^2
        for (int j = 0; j < arr_size; j += i * 2) { // * ^2^2

            int arr_iter       = j;
            int arr_left_iter  = j;
            int arr_right_iter = min((i + j), arr_size);
            int left_end       = min((i + j), arr_size);
            int right_end      = min((i * 2 + j), arr_size);

            // * 排大小
            while (arr_left_iter < left_end && arr_right_iter < right_end) {

                (arr[ arr_left_iter ] < arr[ arr_right_iter ])
                    ? arr_oper[ arr_iter++ ] = arr[ arr_left_iter++ ]
                    : arr_oper[ arr_iter++ ] = arr[ arr_right_iter++ ];
            }

            // * 多的往後補
            while (arr_left_iter < left_end) { arr_oper[ arr_iter++ ] = arr[ arr_left_iter++ ]; }
            while (arr_right_iter < right_end) { arr_oper[ arr_iter++ ] = arr[ arr_right_iter++ ]; }
        }

        std::swap(arr_oper, arr); // 交換位址開頭
    }

    delete[] arr_oper;
}

// * 遞迴版：
template <typename T>
void MergeSortRecursive(vector<T> &arr, int arr_begin, int arr_mid, int arr_end) {

    vector<T> left_sub(arr.begin() + arr_begin,
                       arr.begin() + arr_mid + 1);
    vector<T> right_sub(arr.begin() + arr_mid + 1,
                        arr.begin() + arr_end + 1);

    left_sub.insert(left_sub.end(), std::numeric_limits<T>::max());
    right_sub.insert(right_sub.end(), std::numeric_limits<T>::max());

    int left_iter  = 0;
    int right_iter = 0;
    for (int i = arr_begin; i <= arr_end; ++i) {

        (left_sub[ left_iter ] <= right_sub[ right_iter ])
            ? arr[ i ] = left_sub[ left_iter++ ]
            : arr[ i ] = right_sub[ right_iter++ ];
    }
}

template <typename T>
void MergeSortRecursive(vector<T> &arr, int arr_begin, int arr_end) {

    if (arr_begin < arr_end) {

        int arr_mid = arr_begin + (arr_end - arr_begin) / 2;

        MergeSortRecursive(arr, arr_begin, arr_mid);
        MergeSortRecursive(arr, arr_mid + 1, arr_end);
        MergeSortRecursive(arr, arr_begin, arr_mid, arr_end);
    }
}

template <typename T>
void MergeSortRecursive(T arr[], int &arr_begin, int &arr_mid, int &arr_end) {

    int arr_left_iter  = arr_mid - arr_begin + 1; // + [0]
    int arr_right_iter = arr_end - arr_mid;

    int *arr_left  = new int[ arr_left_iter ];
    int *arr_right = new int[ arr_right_iter ];

    arr_left[ arr_left_iter ]   = std::numeric_limits<T>::max();
    arr_right[ arr_right_iter ] = std::numeric_limits<T>::max();

    // ++arr_mid;
    for (int i = 0; i < arr_left_iter; ++i) { arr_left[ i ] = arr[ arr_begin + i ]; }
    for (int i = 0; i < arr_right_iter; ++i) { arr_right[ i ] = arr[ arr_mid + i ]; }

    int i = 0, j = 0;
    for (int k = arr_begin; k <= arr_end; ++k) {

        (arr_left[ i ] <= arr_right[ j ])
            ? arr[ k ] = arr_left[ i++ ]
            : arr[ k ] = arr_right[ j++ ];
    }
}

template <typename T>
void MergeSortRecursive(T arr[], int arr_begin, int arr_end) {

    if (arr_begin < arr_end) {

        int arr_mid = arr_begin + (arr_end - arr_begin) / 2;

        MergeSortRecursive(arr, arr_begin, arr_mid);
        MergeSortRecursive(arr, arr_mid + 1, arr_end);

        MergeSortRecursive(arr, arr_begin, arr_mid, arr_end); // 將左右兩個以排序好的子陣列合併
    }
}

int main() {

    // int arr_1[]    = { 55, 44, 33, 22, 11 };
    int arr_1[]    = { 33, 22, 55, 11, 44 };
    int arr_1_size = static_cast<int>(sizeof(arr_1) / sizeof(arr_1[ 0 ]));

    cout << "arr_1 : ";
    for (int i = 0; i < arr_1_size; ++i) { cout << arr_1[ i ] << ", "; }
    cout << endl;

    // vector<int> vec_1{ 33, 22, 55, 11, 44 };
    vector<int> vec_1(arr_1, arr_1 + arr_1_size);
    // cout << "vec_1 : ";
    // for (int i = 0; i < vec_1.size(); ++i) { cout << vec_1.at(i) << ", "; }
    cout << endl;

    // * -----

    cout << endl;
    cout << "MergeSort : ";
    // MergeSort(arr_1, arr_1_size);
    // MergeSortRecursive(arr_1, 0, arr_1_size);
    // for (int i = 0; i < arr_1_size; ++i) { cout << arr_1[ i ] << ", "; }
    // cout << endl;

    MergeSortRecursive(vec_1, 0, vec_1.size() - 1);
    for (int i = 0; i < vec_1.size(); ++i) { cout << vec_1[ i ] << ", "; }
    cout << endl;

    system("pause");
    return 0;
}