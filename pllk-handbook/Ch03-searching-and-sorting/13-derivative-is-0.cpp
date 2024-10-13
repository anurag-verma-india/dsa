// Does not work

#include <bits/stdc++.h>
using namespace std;

int f(int x)
{
    // switch (x) {
    //     case 1: return 1;
    //     case 2: return 2;
    //     ...
    //     case 100: return 100;
    //     case 101: return 99;
    //     case 102; return 98
    // }
    if (x >= 100)
        return x;
    else
        return ((100 * 2) - x);
}

int main()
{
    int z = 1000, x = -1;
    for (int b = z; b >= 1; b /= 2)
    {
        // cout << "x is " << x << " f(x+b) is " << f(x + b) << ", b is " << b << "\n";
        while (f(x + b) < f(x + b + 1))
            x += b;
    }
    int k = x + 1;
    cout << "Inflection point is " << k << "\n";

    return 0;
}