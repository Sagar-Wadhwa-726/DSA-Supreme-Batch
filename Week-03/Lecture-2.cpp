// https://en.cppreference.com/w/cpp/container/vector
// https://cplusplus.com/reference/vector/vector/
// Slides not available

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>
#include <cstring>
#include <limits>
#include <vector>
using namespace std;

/*Usage of vectors instead of creating arrays on our own*/

// int main()
// {
//     system("cls");

//     // The default capacity and the size of the vector is 0

//     // Different ways of declaring a vector

//     vector<int> arr1{10, 20, 30}; // Normal declaration
//     vector<int> arr2(10, -1);     // Declare a vector of size 10 with all the default elements as -1,
//     vector<int> arr3(10);         // All the elements are set to 0 in this case

//     // int n;
//     // cin>>n;
//     // vector<int> arr3(n); // This is a good practice here since it is a dynamic array

//     return 0;
// }

/*Find unique element in the vector*/

// int main()
// {
//     system("cls");
//     vector<int> arr{1, 2, 4, 2, 1, 3, 6, 5, 5, 6, 4};

//     // Anything xored with 0 has no effect (result remains the same)
//     int xorSum = 0;
//     for (auto element : arr)
//     {
//         xorSum = xorSum ^ element;
//     }
//     cout << "The unique element in the array is : " << xorSum;
//     return 0;
// }

/*Union of two arrays --> SIMPLE & EASY*/

/*Intersection of two arrays --> SIMPLE & EASY*/

/*Union of two arrays considering duplicates */

// int main()
// {
//     system("cls");
//     vector<int> arr1{1, 2, 4, 6, 8, 10};
//     vector<int> arr2{3, 4, 5, 6};
//     vector<int> ans;

//     // Cancelling the duplicates first
//     for (int i = 0; i < arr1.size(); i++)
//     {
//         int element = arr1[i];
//         for (int j = 0; j < arr2.size(); j++)
//         {
//             if (arr2[j] == element)
//             {
//                 arr2[j] = INT8_MIN;
//             }
//         }
//     }

//     for (int i = 0; i < arr1.size(); i++)
//     {
//         ans.push_back(arr1[i]);
//     }

//     for (int i = 0; i < arr2.size(); i++)
//     {
//         if (arr2[i] != INT8_MIN)
//             ans.push_back(arr2[i]);
//     }
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     return 0;
// }

/*Pair sum*/

// https://leetcode.com/problems/two-sum/submissions/1105989794/

/*Triplet Sum*/

// int main()
// {
//     vector<int> arr{10, 20, 30, 40};
//     int target = 80;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         for (int j = i + 1; j < arr.size(); j++)
//         {
//             for (int k = j + 1; k < arr.size(); k++)
//             {
//                 if (arr[i] + arr[j] + arr[k] == target)
//                 {
//                     cout << arr[i] << " " << arr[j] << " " << arr[k] << "\n";
//                 }
//             }
//         }
//     }
// }

/*Sort 0's and 1's*/

// int main()
// {
//     vector<int> arr{0, 1, 1, 0, 1, 0, 1, 0, 1};
//     int start = 0;
//     int end = arr.size() - 1;
//     int i = 0;
//     while (i != end)
//     {
//         if (arr[i] == 0)
//         {
//             swap(arr[start], arr[i]);
//             i++;
//             start++;
//         }
//         else
//         {
//             swap(arr[i], arr[end]);
//             end--;
//             // no i++ since the swapped value can again be a 1 in the ith position
//         }
//     }
//     for (auto x : arr)
//     {
//         cout << x << " ";
//     }
// }

/*Homework questions

1. Left rotate an array by 1 element
2. Majority element in an array
3. Buy and sell stock (Level-1)

*/