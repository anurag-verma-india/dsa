#include <bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> vec = {1,2,3,4,5};
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]), x = 10;
    int k = (int)(lower_bound(arr, arr + n, x) - arr);
    printf("Element at %d is %d", k, arr[k]);
    if (k < n && arr[k] == x)
    {
        cout << "\nElement found at index " << k << "\n";
    }
    else
    {
        cout << "\nElement " << x << "is not present in the list";
    }
    return 0;
}