#include <iostream>
#include <vector>
using namespace std;

// sort in ascending order
class Solution {
//    public:
//     void add_rest(vector<int>& resulting_vec, vector<int>& add_from_this, int start_from, int curr_i) {
//         for (int i = 0; i < add_from_this.size(); i++) {
//             resulting_vec[curr_i] = add_from_this[start_from];
//         }
//     }

   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int bigger_array_len = n;
        // if(bigger_array_len < m) bigger_array_len = m;

        vector<int> final_array = {};
        int c1 = 0;
        int c2 = 0;
        bool nums1_over;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[c1] < nums2[c2]) {
                final_array[i] = nums1[c1];
                c1++;
            } else {
                final_array[i] = nums2[c2];
                c2++;
            }
            if (c1 == m) {
                // nums1 over
                // add_rest(final_array, nums2, c2, i);

                for (int i = 0; i < m; i++) {
                    final_array[i] = nums2[c2];
                }

                break;
            }
            if (c2 == n) {
                // nums2 over
                // add_rest(final_array, nums1, c1, i);
                for (int i = 0; i < n; i++) {
                    final_array[i] = nums1[c1];
                }
                break;
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = final_array[i];
        }

        cout << endl;
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
