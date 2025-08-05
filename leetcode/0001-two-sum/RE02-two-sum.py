# https://leetcode.com/problems/two-sum/

"""
input:
    int arr: an array of numbers to search in
    int target: the values should add up to this

output:
    int arr: with 2 numbers, that are the indices that add up to the target value

approach:
    convert list to set

    for each element in the list

        subtract that from the target

    ---
    make a hashmap (number -> index)

    for each element
        subtract that element from the target
        find the remainder
        if found
            return it's index and current index
        otherwise
            add the elements to the dictionary (curr element -> curr index)

---
complexity
time:
    O(n)

space:
    O(n)

int main() {return 0;}

"""


from typing import List, Dict


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        val_to_idx: Dict[int, int] = {}
        for idx, val in enumerate(nums):
            if target - val in val_to_idx:
                return [val_to_idx[target - val], idx]
            else:
                val_to_idx[val] = idx
        return []


if __name__ == "__main__":
    sol = Solution()
    # input_file = open("./input.txt", "r")
    # print(input_file)

    arr = [2, 7, 11, 15]
    t = 9

    print(f"indices that add up to {t} are: {sol.twoSum(arr, t)}")

    pass
