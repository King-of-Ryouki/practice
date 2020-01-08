#include "_pch.hpp"

// * 桶 0 ~ 9, 先與個位數綁定(LSD)
// * 依序進位
template <typename T>
void RadixSort(T arr[], const int &arr_size) {

    int order[ arr_size ]                               = { 0 }; // [ 深度 ]
    int tmp[ 10 ][ sizeof(order) / sizeof(order[ 0 ]) ] = { 0 }; // [ 桶 0 ~ 9 ][ 深度 ]

    int bit = 1; // 位數
    while (bit <= 10) {

        // 放入桶中
        for (int i = 0; i < arr_size; ++i) {
            int lsd                    = (arr[ i ] / bit) % 10; // LSD // 依序進位
            tmp[ lsd ][ order[ lsd ] ] = arr[ i ];
            ++order[ lsd ];
        }

        // 排序
        int k = 0;

        for (int i = 0; i < arr_size; ++i) {

            if (order[ i ] != 0) {
                for (int j = 0; j < order[ i ]; j++, k++) {
                    arr[ k ] = tmp[ i ][ j ];
                }
            }

            order[ i ] = 0;
        }

        bit *= 10; // * 向左一個位數
    }
}

int main() {

    // int arr_1[]    = { 55, 44, 33, 22, 11 };
    int arr_1[]    = { 33, 22, 55, 11, 44 };
    int arr_1_size = static_cast<int>(sizeof(arr_1) / sizeof(arr_1[ 0 ]));

    cout << "Before sort : ";
    for (int i = 0; i < arr_1_size; ++i) { cout << arr_1[ i ] << ", "; }
    cout << endl;

    //

    RadixSort(arr_1, arr_1_size);
    cout << "After  sort : ";
    for (int i = 0; i < arr_1_size; ++i) { cout << arr_1[ i ] << ", "; }
    cout << "\n"
         << endl;

    system("pause");
    return 0;
}