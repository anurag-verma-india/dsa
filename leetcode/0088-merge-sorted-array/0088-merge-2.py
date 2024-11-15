# ascending array
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """

        """
        compare n1 and n2's c1 and c2 elements
        start from 0 and each and compare upto the m-1 and n-1 th element
        
        """
        if m == 0:
            nums1 = [i for i in nums2]
        elif n == 0:
            return
        else:
            farr = []
            c1 = 0
            c2 = 0
            for i in range(len(nums1)):
                if nums1[c1] < nums2[c2]:
                    farr.append(nums1[c1])
                    c1 += 1
                else:
                    farr.append(nums2[c2])
                    c2 += 1
                if c1 == m:
                    # print("First array over")
                    while c2 < n:
                        farr.append(nums2[c2])
                        c2 += 1
                    nums1 = [i for i in farr]
                    break
                elif c2 == n:
                    # print("Second array over")
                    while c1 < m:
                        farr.append(nums1[c1])
                        c1 += 1
                    nums1 = [i for i in farr]
                    break


class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """

        """
        compare n1 and n2's c1 and c2 elements
        start from 0 and each and compare upto the m-1 and n-1 th element
        
        """
        if m == 0:
            # return nums2
            self.nums1 = [i for i in nums2]
        elif n == 0:
            return
        else:
            farr = []
            c1 = 0
            c2 = 0
            # while (c1 <= m and c2 <= n):
            for i in range(len(nums1)):
                if nums1[c1] < nums2[c2]:
                    farr.append(nums1[c1])
                    c1 += 1
                else:
                    farr.append(nums2[c2])
                    c2 += 1
                if c1 == m:
                    # print("First array over")
                    while c2 < n:
                        farr.append(nums2[c2])
                        c2 += 1
                    # print("farr: ", farr)
                    self.nums1 = [i for i in farr]
                    # print("nums1: ", nums1)
                    break
                elif c2 == n:
                    # print("Second array over")
                    while c1 < m:
                        farr.append(nums1[c1])
                        c1 += 1
                    # print("farr: ", farr)
                    self.nums1 = [i for i in farr]
                    # print("nums1: ", nums1)
                    break

sol = Solution()

arr1 = [1, 2, 3, 0, 0, 0]
arr2 = [2, 5, 6]
m = 3
n = 3

sol.merge(arr1, m, arr2, n)
print(sol.nums1)

