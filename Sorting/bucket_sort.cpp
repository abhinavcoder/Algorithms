/* Analysis : Bucket Sort
bucketSort(arr[], n)
1) Create n empty buckets (Or lists). .......................................... |
2) Do following for every array element arr[i].                                  |....O(n)
     a) Insert arr[i] into bucket[n*array[i]]................................... |
3) Sort individual buckets using insertion sort.......................................O(n) : if uniformly distributed
4) Concatenate all sorted buckets.....................................................O(n)
                                         Time = O(n) 
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n)
{
    // 1) Create n empty buckets
    vector<float> b[n];
    
    // 2) Put array elements in different buckets
    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i]; // Index in bucket
       b[bi].push_back(arr[i]);
    }
 
    // 3) Sort individual buckets
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());    // uses quicksort from sort function in  " algorithm "
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];
}
 
/* Driver program to test above funtion */
int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);
 
    cout << "Sorted array is \n";
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}