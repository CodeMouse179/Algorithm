#include <iostream>

#define LEN(arr) (sizeof(arr) / sizeof(arr[0]))

int partition(int* arr, int startIndex, int endIndex)
{
    int pivot = arr[startIndex];
    int left = startIndex;
    int right = endIndex;
    while (left != right)
    {
        while (left < right && arr[right] >= pivot)
        {
            right--;
        }
        while (left < right && arr[left] <= pivot)
        {
            left++;
        }
        if (left < right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    int temp = arr[left];
    arr[left] = arr[startIndex];
    arr[startIndex] = temp;
    return left;
}

void quick_sort(int* arr, int startIndex, int endIndex)
{
    if (startIndex >= endIndex) return;
    int pivotIndex = partition(arr, startIndex, endIndex);
    quick_sort(arr, startIndex, pivotIndex - 1);
    quick_sort(arr, pivotIndex + 1, endIndex);
}

int main()
{
    int arr[] = {0, 2, 1, 5, 8, 4, 10, 2};
    quick_sort(arr, 0, LEN(arr) - 1);
    for (int i = 0; i < LEN(arr); i++)
    {
        std::cout << arr[i] << "\n";
    }
    return 0;
}