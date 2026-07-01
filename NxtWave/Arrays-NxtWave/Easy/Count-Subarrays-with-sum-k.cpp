/*

Approach

1)we store prefixes sum of every index in hash map so we can can look up in O(1) time
2)at each iteration of chcking..do the prefix sum and check ift sum equal to target -- accordingly count++ --
3)we should aslo find the wheather there are any before prefix sums with value sum-target in the hash map if yeas add how many of them are there to count
4)at every iteration increase the occurence of that prefix sum by 1 in hashmap


*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int countSubarrays(vector<int> &arr, int target)
    {
        // Write your code here...
        int count = 0;
        int n = arr.size();
        // for(int i=0;i<n;i++){
        //     int sum = arr[i];
        //     for(int j=i+1;j<n;j++){
        //         if(sum == target){
        //             count++;
        //         }
        //         sum += arr[j];
        //     }
        //     if(sum == target){
        //         count++;
        //     }
        // }
        // return count;
        unordered_map<int, int> mpp;
        int sum = 0;
        // int count=0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == target)
                count++;
            if (mpp.find(sum - target) != mpp.end())
            {
                count += mpp[sum - target];
            }
            mpp[sum]++;
        }
        return count;
    }
};