#include <iostream>

#define LEN(arr) (sizeof(arr) / sizeof(arr[0]))

void bubble_sort(int* arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {0, 2, 1, 5, 8, 4, 10, 2};
    bubble_sort(arr, LEN(arr));
    for (int i = 0; i < LEN(arr); i++)
    {
        std::cout << arr[i] << "\n";
    }
    return 0;
}