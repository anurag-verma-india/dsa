#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

   public:
    string swap_vow(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !isVowel(s[left])) left++;
            while (left < right && !isVowel(s[right])) right--;

            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

int main() {
    string s = "aabiouo";

    Solution sol;

    string new_s = sol.swap_vow(s);
    cout << s << endl;
    cout << new_s << endl;


    return 0;
}