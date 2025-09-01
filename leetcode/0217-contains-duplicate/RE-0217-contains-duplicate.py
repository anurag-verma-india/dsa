# t: 13ms,65%; s: 32mb, 28.6%;
# https://leetcode.com/problems/contains-duplicate/

from typing import List

"""
input: 
    int[] nums: an array of numbers
    
output: 
    bool ans: true if array contains duplicate numbers

approach: 
    keep a set of all encountered unique numbers
    
    loop over the given array
    for each number check if it exists in our set 
    if yes then 
        return true
    otherwise add current value to the set 
    
    if all values are over and we found no duplicate then return false

---
complexity: 
time: 

space: 

"""

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        unique_num_set = set([])

        for num in nums:
            if num in unique_num_set:
                return True
            else:
                unique_num_set.add(num)
        return False


# Driver Code
if __name__ == "__main__":
    sol = Solution()

    # arr = [1, 2, 3]
    arr = [1, 2, 3, 1]
    # arr = [1,2,3,4]
    # arr = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]

    ans = sol.containsDuplicate(arr)

    print("Contains Duplicate:", ans)
