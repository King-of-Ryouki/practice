import java.util.*;

public class QuickSort {

    /**
     * @param args
     */
    public static void main(String[] args) {

        QuickSort quickSort = new QuickSort();

        int arr[] = new int[] { 33, 22, 55, 11, 44 };

        quickSort.Sort(arr, 0);
        System.out.println(Arrays.toString(arr));
    }

    // Func

    public void Sort(int[] arr, int arr_start, int arr_end) {

        if (arr_start >= arr_end || arr == null || arr.length <= 1) { return; }

        int left  = arr_start;
        int right = arr_end;

        int arr_mid = arr[ arr_start + (arr_end - arr_start) / 2 ];

        while (left <= right) {

            while (arr[ left ] < arr_mid) { ++left; }
            while (arr_mid < arr[ right ]) { --right; }

            if (left < right) {

                int tmp      = arr[ left ];
                arr[ left ]  = arr[ right ];
                arr[ right ] = tmp;

                ++left;
                --right;

            } else if (left == right) {
                ++left;
            }
        }

        Sort(arr, arr_start, right);
        Sort(arr, left, arr_end);
    }

    public void Sort(int[] arr, int arr_start) {
        Sort(arr, arr_start, arr.length - 1);
    }
}