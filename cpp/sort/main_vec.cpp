#include "_pch.hpp"

#include "bubble_sort.hpp"
#include "cocktail_sort.hpp"
#include "heap_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "radix_sort.hpp"
#include "selection_sort.hpp"
#include "shell_sort.hpp"

int main() {

    // * 輸入的向量

    vector<int> vec_1{ 33, 22, 55, 11, 44 };
    int vec_1_size = vec_1.size();

    cout << "vec_1 : ";
    for (int i = 0; i < vec_1_size; ++i) { cout << vec_1[ i ] << ", "; }
    cout << "\n"
         << endl;

    // * 排序

    cout << " 1 : bubble_sort\n"
         << " 4 : insertion_sort\n"
         << " 5 : merge_sort\n"
         << " 6 : quick_sort\n"
         << " 7 : radix_sort\n"
         << " 8 : selection_sort\n"
         << " 9 : shell_sort\n"
         << " 輸入排序 : "
         << endl;

    int input = 0;
    cin >> input;

    switch (input) {

        case 1: {
            cout << "bubble_sort : ";
        }
        case 2: {
            cout << "cocktail_sort : " << endl;
        }
        case 3: {
            cout << "heap_sort : " << endl;
        }
        case 4: {
            cout << "insertion_sort : " << endl;
        }
        case 5: {
            cout << "merge_sort : " << endl;
        }
        case 6: {
            cout << "quick_sort : " << endl;
        }
        case 7: {
            cout << "radix_sort : " << endl;
        }
        case 8: {
            cout << "selection_sort : " << endl;
        }
        case 9: {
            cout << "shell_sort : " << endl;
        }
    }

    for (int i = 0; i < vec_1_size; ++i) { cout << vec_1[ i ] << ", "; }
    cout << endl;

    system("pause");
    return 0;
}