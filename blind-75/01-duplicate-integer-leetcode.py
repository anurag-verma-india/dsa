"""
class Solution:
    def hasDuplicate(self, nums: list[int]) -> bool:
        check_nums:list[int] = []
        for num in nums:
            if num in check_nums:
                return True
            else:
                check_nums.append(num)
        return False
"""

         

class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        check_nums:list[int] = []
        for num in nums:
            if num in check_nums:
                return True
            else:
                check_nums.append(num)
        return False
        
sol = Solution();
print("first list: ", sol.containsDuplicate([1,2,3,4]))
print("second list: ", sol.containsDuplicate([1,2,3,4,4]))

