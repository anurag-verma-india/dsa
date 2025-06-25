#include <bits/stdc++.h>
using namespace std;

// Defining a function x which is first increasing and then decreasing after a certain point
int f(int x)
{
    return x > 100 ? 1 : 0;
}

int main()
{

    int x = -1, z = 1000, b = 0;
    for (b = z; b >= 1; b /= 2)
    {
        while (f(x + b) < f(x + b + 1))
            x += b;
    }
    int k = x + 1;

    cout << "Function starts decreasing at " << k << "\n";
    return 0;
}