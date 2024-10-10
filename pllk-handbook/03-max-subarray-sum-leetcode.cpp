#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // cout << "\n";
        int sum = 0, best = 0, n = nums.size();
        // int sum = 0, best = 0, n = sizeof(nums) / sizeof(nums.at(0));
        if (n == 1)
            return nums[0];
        else
        {
            sum = nums[0], best = nums[0];
            for (unsigned int k = 1; k < n; k++)
            {
                // cout << "Element at " << k << " is " << nums.at(k) << "\n";
                sum = max(nums.at(k), sum + nums.at(k));
                best = max(sum, best);
            }
            // cout << "\n";
            return best;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> nums;
        string input;
        getline(cin, input); // Read the entire line for the numsay elements
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            nums.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubArray(nums) << endl;
        return 0;
    }

    // custom use case
    vector<int> nums = {-1};
    Solution ob;
    cout << ob.maxSubArray(nums) << "\n";
    return 0;
}
