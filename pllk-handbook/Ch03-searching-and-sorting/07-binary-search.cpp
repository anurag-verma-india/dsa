#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {2, 8, 0, -1, 3, 6, 4};
    int a = 0, b = vec.size() - 1, k, x;
    sort(vec.begin(), vec.end());
    cout << "\nSorted int vector: ";
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\nEnter the number to search in this array: ");
    scanf(" %d", &x);

    while (a <= b)
    {
        k = (int)(a + b) / 2;
        if (vec[k] == x)
        {
            printf("\nIndex of %d is %d\n", x, k);
            return 0;
        }
        if (vec[k] > x)
            b = k - 1;
        if (vec[k] < x)
            a = k + 1;
    }
}