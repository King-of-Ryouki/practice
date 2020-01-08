#include "_pch.hpp"

// ******************************
// *
// * 選擇排序(Selection sort)：
// * 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
// *
// * 時間複雜度：
// * 最壞時間複雜度 O(n^2)
// * 最佳時間複雜度 O(n^2)
// * 平均時間複雜度 O(n^2)
// *
// * 空間複雜度：
// * 最壞空間複雜度
// * 總共 O(n)
// * 輔助 O(1)
// *
// ******************************

// 選擇排序(Selection sort) 是一種簡單直觀的排序演算法。它的工作原理如下。
// 首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
// 然後，再從剩餘未排序元素中繼續尋找最小（大）元素，然後放到已排序序列的末尾。
// 以此類推，直到所有元素均排序完畢。

// 選擇排序的主要優點與資料移動有關。如果某個元素位於正確的最終位置上，則它不會被移動。
// 選擇排序每次交換一對元素，它們當中至少有一個將被移到其最終位置上，
// 因此對 n 個元素的表進行排序總共進行至多 n-1 次交換。
// 在所有的完全依靠交換去移動元素的排序方法中，選擇排序屬於非常好的一種。

// 選擇排序法的比較複雜度固定式O(n^2)，不過交換次數則是O(n)，在最佳情況可以到O(0)，
// 比起氣泡排序法的比較次數少很多，所以效能上會比較好。

// * 選擇排序(Selection sort)
template <typename T>
void SelectionSort(T arr[], const int &arr_size) {

    for (int i = 0; i < arr_size; ++i) { // 次數與位置

        int min = i;

        for (int j = i + 1; j < arr_size; ++j) { // 找到最小的值
            if (arr[ j ] < arr[ min ]) {
                min = j;
            }
        }

        std::swap(arr[ i ], arr[ min ]);
    }
}

template <typename T>
void SelectionSort(std::vector<T> &arr) {

    for (int i = 0; i < arr.size(); ++i) { // 次數與位置

        int min = i;

        for (int j = i + 1; j < arr.size(); ++j) { // 找到最小的值
            if (arr[ j ] < arr[ min ]) {
                min = j;
            }
        }

        std::swap(arr[ i ], arr[ min ]);
    }
}