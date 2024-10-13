#include <bits/stdc++.h>
using namespace std;

bool ok(int x)
{
    return x >= 100 ? true : false;
}

int main()
{
    int x = -1, z = 1000, b = 0;
    for (b = z; b >= 1; b /= 2)
    {
        while (!ok(x + b))
            x += b;
    }
    int k = x+1;
    cout << "Smallest number for which function is true is " << k << "\n";

    return 0;
}