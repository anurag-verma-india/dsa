#include <iostream>
#include <vector>
using namespace std;

// sort in ascending order
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> final_array = {};
        int i = 0;
        int c1 = 0;
        int c2 = 0;
        // for (int i = 0; i < nums1.size(); i++) {
        while (c1 > m && c2 > n)
            if (nums1[c1] < nums2[c2]) {
                final_array[i] = nums1[c1];
                c1++;
                i++;
            } else {
                final_array[i] = nums2[c2];
                c2++;
                i++;
            }
        if (c1 == m - 1) {
            while (c2 < n) {
                final_array[i] = nums2[c2];
                c2++;
                i++;
            }
        } else if (c2 == n - 1) {
            while (c1 < m) {
                final_array[i] = nums1[c1];
                c1++;
                i++;
            }
        }
        for (int i = 0; i < m; i++) {
            nums1[i] = final_array[i];
            printf("%d, ", nums1[i]);
        }
        printf("\n");
    }
};

int main() {
    Solution sol = Solution();

    vector<int> vec1 = {1, 2, 3, 0, 0, 0};
    vector<int> vec2 = {2, 5, 6};
    int len_vec1 = 3;
    int len_vec2 = 3;

    sol.merge(vec1, len_vec1, vec2, len_vec2);
    return 0;
}
