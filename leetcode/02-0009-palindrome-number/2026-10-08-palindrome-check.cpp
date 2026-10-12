#include<iostream>
using namespace std;

/*
Check if a number is palindrome or not
 */
class Solution  {
    /*
    input: 
        int num

    output: 
        bool isPalindrome

    approach: 
        calculate rev, if rev = original num-> true : false

    alalysis:

     */
    public:
        bool isPalindrome(int num) {
            int original_num = num;
            int rev = 0;

            while(num){ 
                rev = rev * 10 + num % 10;
                num /= 10;
            }

            if (rev == original_num) { 
                return true;
            }

            return false;
        }

};

int main() {
    Solution sol;
    int num = 771177;
    bool ans = sol.isPalindrome(num);
    cout << endl;
    cout << "Num (" << num << ") is palindrome: " << (ans ? "true" : "false");
    cout << endl;
}
