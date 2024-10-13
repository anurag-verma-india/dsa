#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]), x = 5;

    auto r = equal_range(arr, arr + n, x);
    cout << (r.second) - (r.first) << "\n";
    cout << "Index of " << x << " is " << r.first - arr << "\n";

    return 0;
}