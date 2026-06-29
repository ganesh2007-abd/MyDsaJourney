/*

Approach

1)Use 2 pointer i,j initially place them at 0 index
2)use j to track the non zero elements and i to track the position in which the non zero element to be inserted
3)increment i and j accordingly


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void moveZerosToEnd(int arr[], int n)
    {

        int i = 0;
        int j = 0;

        while (j < n)
        {
            if (arr[j] != 0)
            {
                // arr[i++] = arr[j];
                // arr[j]=0;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
            }
            j++;
        }
    }
};