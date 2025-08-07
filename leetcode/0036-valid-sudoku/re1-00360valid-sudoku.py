# https://leetcode.com/problems/valid-sudoku/description/
"""
input:
    2d array of strings: board

output:
    boolean: is_board_valid

approach:
    create a set with values in 1-9 in values

    for each row col and 3x3 matrix check
    iterate for each value
        check if that value is in the set
            remove that
        if not
            return false

    return true (no invalid condition found)

----
complexity:
time:

space:

"""

from typing import List


class Solution:
    def isValidSudoku(
        self, board: List[List[str]]
    ) -> bool:  # pyright: ignore[reportReturnType]
        temp_num_set = {str(num) for num in range(1, 10)}
        num_set = temp_num_set
        # Check each Row

        for row in board:
            for ele in row:
                # print(ele, end=" ")
                if ele == ".":
                    continue
                if ele in temp_num_set:
                    temp_num_set.remove(ele)
                else:
                    return False
            # print()
            temp_num_set = num_set.copy()

            # for ele in row:
            #     if ele != ".":
            #         if ele in temp_num_set:
            #             temp_num_set.remove(ele)
            #         else:
            #             return False
            # temp_num_set = num_set
        return True
        # Check each col

        # check each 3x3 matrix

        # pass
        # for num in num_set:
        #     # print(num, end=" ")
        # print()


if __name__ == "__main__":
    sol = Solution()

    board = [
        # ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["5"],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        # [".", "9", "8", ".", ".", ".", ".", "6", "."],
        # ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        # ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        # ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        # [".", "6", ".", ".", ".", ".", "2", "8", "."],
        # [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        # [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]

    print(sol.isValidSudoku(board))
