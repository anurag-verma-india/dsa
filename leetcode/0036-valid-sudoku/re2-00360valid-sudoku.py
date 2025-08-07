# t 82, m 69
# https://leetcode.com/problems/valid-sudoku/description/
# https://leetcode.com/problems/valid-sudoku/solutions/5272799/video-keep-number-we-found-and-find-dupl-4unj/
"""
input:
    2d array of strings: board

output:
    boolean: is_board_valid

approach:
    for each row, col and box
        create a defaultdict of sets (key value pair, index -> set)

    for each element check if it's present in the set of corresponding row, col or box:
        if no add that
        else return false

    return true at the end (all rows, cols, and boxes checked no duplicates found)
----
complexity:
time:

space:

"""

from typing import List
from collections import defaultdict


class Solution:
    def isValidSudoku(
        self, board: List[List[str]]
    ) -> bool:  # pyright: ignore[reportReturnType]

        rows = defaultdict(set)
        cols = defaultdict(set)
        boxes = defaultdict(set)

        for i in range(0, 9):
            for j in range(0, 9):
                curr_ele = board[i][j]
                if curr_ele == ".":
                    continue
                # Checking rows
                if curr_ele in rows[i]:
                    return False
                else:
                    rows[i].add(curr_ele)

                # Checking cols
                if curr_ele in cols[j]:
                    return False
                else:
                    cols[j].add(curr_ele)

                # Checking boxes
                if (curr_ele) in boxes[(i // 3, j // 3)]:
                    return False
                else:
                    boxes[(i // 3, j // 3)].add(curr_ele)

        return True


if __name__ == "__main__":
    sol = Solution()
    # ["5"],

    board = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]

    print(sol.isValidSudoku(board))
