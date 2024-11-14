# Sort in ascending order (non desending)
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        c1 = 0
        c2 = 0
        i = 0
        final_arr = []
        while c1 < m and c2 < n:
            if nums1[c1] < nums2[c2]:
                # final_arr[i] = nums1[c1]
                final_arr.append(nums1[c1])
                c1 += 1
                i += 1
            else:
                # final_arr[i] = nums2[c2]
                final_arr.append(nums2[c2])
                c2 += 1
                i += 1

            if (c1 == m):
                while c2 < n:
                    # final_arr[i] = nums2[c2]
                    final_arr.append(nums2[c2])
                    c2 += 1
                    i += 1
            elif (c2 == n):
                while c1 < m:
                    # final_arr[i] = nums1[c1]
                    final_arr.append(nums1[c1])
                    c1 += 1
                    i += 1
                    
        # for ele in final_arr:
        #     print(f"{ele}, ", end="")
        # print()
        # print(final_arr)
        for i in range(len(nums1)-1):
            nums1[i] = final_arr[i]
        print(nums1)



sol = Solution()

arr1 = [1, 2, 3, 0, 0, 0]
arr2 = [2, 5, 6]
m = 3
n = 3

sol.merge(arr1, m, arr2, n)
