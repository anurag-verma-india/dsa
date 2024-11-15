// https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;

// void print_vec(vector<int> vec) {
//     for (auto v : vec) {
//         cout << v << " ";
//     }
//     cout << "\n";
// }

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1.clear();
            for (auto num : nums2) {
                nums1.push_back(num);
            }
            // cout << "m = 0, nums1: ";
            // print_vec(nums1);
        } else if (n == 0) {
            // cout << "n =  0, nums1: ";
            // print_vec(nums1);
            return;
        } else {
            vector<int> fvec = {};
            int c1 = 0;
            int c2 = 0;
            while (true) {
                if (nums1[c1] < nums2[c2]) {
                    fvec.push_back(nums1[c1]);
                    c1++;
                } else {
                    fvec.push_back(nums2[c2]);
                    c2++;
                }
                if (c1 == m) {
                    for (; c2 < n; c2++) {
                        fvec.push_back(nums2[c2]);
                    }
                    // cout << "fvec: ";
                    // print_vec(fvec);

                    nums1.clear();
                    for (int i = 0; i < (int)fvec.size(); i++) {
                        nums1.push_back(fvec[i]);
                    }
                    // cout << "nums1: ";
                    // print_vec(nums1);
                    break;
                } else if (c2 == n) {
                    for (; c1 < m; c1++) {
                        fvec.push_back(nums1[c1]);
                    }
                    // cout << "fvec: ";
                    // print_vec(fvec);

                    nums1.clear();
                    for (int i = 0; i < (int)fvec.size(); i++) {
                        nums1.push_back(fvec[i]);
                    }
                    // cout << "nums1: ";
                    // print_vec(nums1);
                    break;
                }
            }
        }
        // cout << "final nums1: ";
        // print_vec(nums1);
    }
};

int main() {
    Solution sol = Solution();

    // vector<int> vec1 = {1, 2, 3, 0, 0, 0};
    // vector<int> vec2 = {2, 5, 6};
    // int len_vec1 = 3;
    // int len_vec2 = 3;

    // vector<int> vec1 = {0, 0, 0, 0, 0};
    // vector<int> vec2 = {1, 2, 3, 4, 5};
    // int len_vec1 = 0;
    // int len_vec2 = 5;

    vector<int> vec1 = {1, 2, 4, 5, 6, 0};
    vector<int> vec2 = {3};
    int len_vec1 = 5;
    int len_vec2 = 1;


    sol.merge(vec1, len_vec1, vec2, len_vec2);
    return 0;
}
