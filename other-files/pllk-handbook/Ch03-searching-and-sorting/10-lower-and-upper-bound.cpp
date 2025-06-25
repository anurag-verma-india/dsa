#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]), x = 11;

    int *a = lower_bound(arr, arr + n, x);
    int *b = upper_bound(arr, arr + n, x);

    cout << "Number of occurrences of " << x << " is " << b - a << "\n";

    return 0;
}