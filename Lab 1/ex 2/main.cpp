#include <stdio.h>
#include <iostream>

using namespace std;

class Sorter
{
public:
    void swap(int *a, int *b)
    {
        int aux = *a;
        *a = *b;
        *b = aux;
    }

    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);
        int j;

        for(j = low; j <= high - 1; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pivot = partition(arr, low, high);

            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }

    void printArray(int arr[], int n)
    {
        int i;
        for (i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

};

int main()
{
    int arr[5] = { 10, 2, 22, 5, 1 };
    int n = 5;
    Sorter sorting;
    sorting.quickSort(arr, 0, n-1);
    sorting.printArray(arr, n);

    return 0;
}

