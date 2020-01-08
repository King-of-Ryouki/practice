#include "_pch.hpp"

// ******************************
// *
// * 希爾排序(Shell sort)：
// * 在已排序序列中從後向前掃描，找到相應位置並插入
// *
// * 時間複雜度：
// * 最壞時間複雜度 根據步長序列的不同而不同。已知最好的 O(n log^2 n)
// * 最佳時間複雜度 O(n)
// *
// * 空間複雜度：
// * 最壞空間複雜度 O(n)
// *
// ******************************

// 希爾排序（Shellsort），也稱遞減增量排序演算法，是插入排序的一種更高效的改進版本。希爾排序是非穩定排序演算法。
//
// 希爾排序是基於插入排序的以下兩點性質而提出改進方法的：
// 插入排序在對幾乎已經排好序的資料操作時，效率高，即可以達到線性排序的效率
// 但插入排序一般來說是低效的，因為插入排序每次只能將資料移動一位

// 步長的選擇是希爾排序的重要部分。只要最終步長為1任何步長序列都可以工作。
// 演算法最開始以一定的步長進行排序。然後會繼續以一定步長進行排序，最終演算法以步長為1進行排序。
// 當步長為1時，演算法變為普通插入排序，這就保證了資料一定會被排序。

// * 希爾排序(Shell sort)
template <typename T>
void ShellSort(T arr[], int arr_size) {

    int rand = 1;
    while (rand < arr_size / 3) {
        rand = 1 + rand * 3;
        cout << "rand : " << rand << endl;
    }

    while (rand >= 1) {
        for (int i = rand; i < arr_size; ++i) {
            for (int j = i; j >= rand && arr[ j ] < arr[ j - rand ]; j -= rand) {

                std::swap(arr[ j ], arr[ j - rand ]);
            }
        }

        rand = rand / 3;
    }
}

// 從小到大排序
void shellsort(int arr[], int arr_size) {

    int step_len = arr_size / 2; // 間隔

    while (step_len > 0) {

        for (int i = step_len; i < arr_size; ++i) {

            int tmp = arr[ i ];
            int j   = i - step_len;

            while ((j >= 0) && (arr[ j ] > tmp)) {
                arr[ j + step_len ] = arr[ j ];
                j -= step_len;
            }

            arr[ j + step_len ] = tmp;
        }

        step_len /= 2;
    }
}