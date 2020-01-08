#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// ******************************
// *
// * date     : 2019/09/12
// *
// * author   : 施冠年
// * mail     : Co6901251@gmail.com
// *
// * function :
// *
// * BinarySearch
// *
// * 二分搜尋法
// *
// ******************************

template <typename T>
int BinarySearch(T arr[], int begin, int end, const T &target) {

    if (begin > end || begin < 0) { return -1; }

    T res = -1;

    while (begin <= end) {

        int mid = begin + (end - begin) / 2; // ! int mid = (begin + end) / 2; 可能溢位

        if (target < arr[ mid ]) { // 小於
            end = mid - 1;
        } else if (arr[ mid ] < target) { // 大於
            begin = mid + 1;
        } else { // 相等
            res = mid;
            break;
        }
    }

    return res;
}

template <typename T>
int BinarySearch(T arr[], int end, const T &target) {
    return BinarySearch(arr, 0, end, target);
}

int main() {

    int arr_1[]    = { 0, 2, 4, 6, 8, 10 };
    int arr_1_size = static_cast<int>(sizeof(arr_1) / sizeof(arr_1[ 0 ]));

    // * 原始資料

    cout << "arr_1 : ";
    for (int i = 0; i < arr_1_size; ++i) { cout << arr_1[ i ] << ", "; }
    cout << endl;

    cout << "target : ";
    int target;
    cin >> target;
    cout << "BinarySearch : " << BinarySearch(arr_1, arr_1_size, target) << endl;
    cout << "BinarySearch : " << BinarySearch(arr_1, 0, arr_1_size, target) << endl;

    system("pause");
    return 0;
}