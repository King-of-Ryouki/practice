#include "_pch.hpp"

#include "bubble_sort.hpp"
#include "cocktail_sort.hpp"
#include "heap_sort.hpp"
#include "insertion_sort.hpp"
// #include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "radix_sort.hpp"
#include "selection_sort.hpp"
#include "shell_sort.hpp"

int main() {

    // * 輸入的陣列

    int arr_1[]    = { 33, 22, 55, 11, 44 };
    int arr_1_size = static_cast<int>(sizeof(arr_1) / sizeof(arr_1[ 0 ]));

    cout << "arr_1 : ";
    for (int i = 0; i < arr_1_size; ++i) { cout << arr_1[ i ] << ", "; }
    cout << "\n"
         << endl;

    // * 排序

    cout << " 1 : bubble_sort\n"
         << " 2 : cocktail_sort\n"
         << " 3 : heap_sort\n"
         << " 4 : insertion_sort\n"
         << " 5 : merge_sort\n"
         << " 6 : quick_sort\n"
         << " 7 : radix_sort\n"
         << " 8 : selection_sort\n"
         << " 9 : shell_sort\n"
         << " which : ";

    int input = 0;
    cin >> input;

    switch (input) {

        case 1: {
            cout << "bubble_sort : ";
            BubbleSort(arr_1, arr_1_size);
            break;
        }
        case 2: {
            cout << "cocktail_sort : " << endl;
            CocktailSort(arr_1, arr_1_size);
            break;
        }
        case 3: {
            cout << "heap_sort : " << endl;
            HeapSort_Recursive(arr_1, arr_1_size);
            break;
        }
        case 4: {
            cout << "insertion_sort : " << endl;
            // InsertionSort(arr_1, arr_1_size);
            BinaryInsertionSort(arr_1, arr_1_size);
            break;
        }
        case 5: {
            cout << "merge_sort : " << endl;
            break;
        }
        case 6: {
            cout << "quick_sort : " << endl;
            // QuickSortRecursive(arr_1, arr_1_size);
            QuickSortRecursive2(arr_1, arr_1_size);
            break;
        }
        case 7: {
            cout << "radix_sort : " << endl;
            RadixSort(arr_1);
            break;
        }
        case 8: {
            cout << "selection_sort : " << endl;
            SelectionSort(arr_1, arr_1_size);
            break;
        }
        case 9: {
            cout << "shell_sort : " << endl;
            ShellSort(arr_1, arr_1_size);
            // shellsort(arr_1, arr_1_size);
            break;
        }

        default: {}
    }

    for (int i = 0; i < arr_1_size; ++i) { cout << arr_1[ i ] << ", "; }
    cout << endl;

    system("pause");
    return 0;
}