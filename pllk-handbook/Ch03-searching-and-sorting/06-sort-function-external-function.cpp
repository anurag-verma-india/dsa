#include <bits/stdc++.h>
using namespace std;

class cartesianPoint
{
public:
    int x;

public:
    int y;
};

bool trueIfFirstIsSmall(cartesianPoint a, cartesianPoint b)
{
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}

int main()
{
    cartesianPoint a, b, c;
    vector<cartesianPoint> vecP;
    a.x = 1, a.y = 2, b.x = 1, b.y = 3, c.x = 2, c.y =3;
    vecP.push_back(c);
    vecP.push_back(b);
    vecP.push_back(a);
    // printf("\na.x = %d\na.y = %d\n", a.x, a.y);
    sort(vecP.begin(),vecP.end(), trueIfFirstIsSmall);
    printf("\n");

    for (unsigned int i = 0; i < vecP.size(); i++) {
        printf("Number %d point is {%d, %d}\n", i, vecP[i].x, vecP[i].y);
    }

    return 0;
}