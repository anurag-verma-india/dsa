# t 7ms, s 18 mb
# https://leetcode.com/problems/valid-palindrome/
"""
input:
    sting s

output:
    boolean b: true if the given string is an palindrome

approach:

    take two points l and r
    l++ and r-- in each iteration

    while they don't cross each other keep checking

    if any character is not alpha numeric then skip that one (move it's pointer to next and continue the loop)

    if at any point the char at l is not equal to r then return false
    otherwise move both pointers


---
complexity
time: O(n)
space: O(1)


1 2 3 4 5 
^       ^
|       |


1 2 3 4 5 
  ^   ^
  |   |


"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        # print(s)
        l = 0
        r = len(s) - 1
        while l < r:
            if not s[l].isalnum():
                l += 1
                continue
            if not s[r].isalnum():
                r -= 1
                continue

            if not (s[l].lower() == s[r].lower()):
                return False

            l += 1
            r -= 1

        return True


if __name__ == "__main__":
    sol = Solution()

    s = "A man, a plan, a canal: Panama"
    # s = "A man, a plan, a canal: Pan"
    

    print(sol.isPalindrome(s))
