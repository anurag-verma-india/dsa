#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr)
    {
        // code here...
        cout << "\n";
        int sum = 0, best = 0, n = sizeof(arr) / sizeof(arr.at(0));
        for (int k = 0; k < n; k++)
        {
            cout << "Element at " << k << " is " << arr.at(k) << "\n";
            sum = max(arr.at(k), sum + arr.at(k));
            best = max(sum, best);
        }
        cout << "\n";
        return best;
    }
};

int
main()
{
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
        return 0;
    }
}