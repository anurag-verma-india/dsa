#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> temp(m + n, 0);
        int m1 = 0, n1 = 0, i;
        for (i = 0; i < n + m; i++)
        {
            if (nums1[m1] < nums2[n1] && m1 < m)
            {
                temp[i] = nums1[m1];
                m1 += 1;
            }
            else
            {
                temp[i] = nums2[n1];
                n1 += 1;
            }
        }
        for (i = 0; i <= m + n; i++)
        {
            nums1[i] = temp[i];
        }
    }
};

int main()
{
    cout << endl;

    int m = 3, n = 3;
    vector<int> vector1 = {1, 2, 3, 0, 0, 0};
    vector<int> vector2 = {2, 5, 6};

    Solution sol = Solution();

    sol.merge(vector1, m, vector2, n);

    cout << "The merged vector is: ";
    for (int i = 0; i < m + n; i++)
    {
        if (i == m + n - 1)
        {
            cout << "\n Last element: ";
        }
        if(i == m+n) cout << "\nStill running";
        cout << vector1[i] << " ";
    }

    cout << endl;
}

