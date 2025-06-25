#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    int k = 0, n = vec.size(), x = 2;
    for (int b = n / 2; b >= 1; b /= 2)
    {
        while (k + b < n && vec[k + b] <= x)
            k += b;
    }
    if (vec[k] == x)
    {
        cout << "\nElement found at index " << k << "\n";
    }
    return 0;
}

