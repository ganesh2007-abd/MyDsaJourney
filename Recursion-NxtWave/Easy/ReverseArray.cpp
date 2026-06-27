#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void recursive(int arr[], int n, int i, int j)
    {
        if (i >= j)
            return;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        recursive(arr, n, i + 1, j - 1);
    }

    void reverse(int arr[], int n)
    {
        recursive(arr, n, 0, n - 1);
    }
};