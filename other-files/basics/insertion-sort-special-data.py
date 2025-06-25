class Pair:
    def __init__(self, key, value):
        self.key = key
        self.value = value


class Solution:
    def insertionSort(self, pairs):
        n = len(pairs)
        res = []

        for i in range(n):
            j = i - 1
            while j >= 0 and pairs[j].key > pairs[j + 1].key:
                pairs[j], pairs[j + 1] = pairs[j + 1], pairs[j]
                j -= 1

            res.append(pairs[:])

        return res


# pairs = [(3, "cat"), (3, "bird"), (2, "dog")]

pairs = [Pair(3, "cat"), Pair(3, "bird"), Pair(2, "dog")]
sol = Solution()
print(sol.insertionSort(pairs))
