#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     vector<int> builtinSort(vector<int> &vec) {
//         sort(vec.begin(), vec.end());
//         return vec;
//     }
// };

int main() {
    // Solution op;
    // op.builtinSort(vec1);
    // for (int i = 0; i < vec.)
    vector <int> vec1  = {2, 1, -1 ,0, 2};
    sort(vec1.begin(), vec1.end());
    printf("\n");
    for(unsigned int i = 0; i < vec1.size() ; i++) {
        printf("The element at %d is %d\n", i, vec1[i]);
    }
    printf("\nSorting in reverse\n\n");
    sort(vec1.rbegin(), vec1.rend());
    for(unsigned int i = 0; i < vec1.size() ; i++) {
        printf("The element at %d is %d\n", i, vec1[i]);
    }
    printf("\nSorting a String\n\n");
    string s = "bbaaBBAA";
    sort(s.begin(), s.end());
    for(unsigned int i = 0; i < s.size() ; i++) {
        printf("The element at %d is %d\n", i, s[i]);
    }
    return 0;
}