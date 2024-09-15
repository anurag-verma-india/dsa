class Solution:
    def insertionSort(self, array):
        n = len(array)
        res = []

        for i in range(n):
            j = i - 1
            while j >= 0 and array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
                j -= 1
            res.append(array[:])
        return res


sol = Solution()

# array = [3, 3, 2]

array = [2,4,4,6,1,8,3]

solution = sol.insertionSort(array)

for step in solution:
    print(step)
    