class RemoveDuplicatesFromSortedArray:
    """
        in-place removal of duplicates without using extra space
    """

    @staticmethod
    def remove_duplicates_linear_time(nums):
        """
            O(n) Algo:
        :param nums: Array
        :return: length of updated nums array and updated nums array
        """
        p1 = 0
        p2 = 1
        while p2 < len(nums):
            if nums[p1] != nums[p2]:
                p1 += 1
                nums[p1] = nums[p2]
            p2 += 1

        return p1+1, nums[:p1+1]

    @staticmethod
    def remove_duplicates_quad_time(nums):
        """
            O(n2) Algo:
        :param nums: Array
        :return: length of updated nums array and updated nums array
        """
        nums_size = len(nums)
        i = 1
        while i < nums_size:
            if nums[i - 1] == nums[i]:
                # shift_swap_end
                for j in range(i + 1, nums_size):
                    temp = nums[j]
                    nums[j] = nums[j - 1]
                    nums[j - 1] = temp
                nums_size -= 1
                i -= 1
            i += 1
        return nums_size, nums[:nums_size]


solve = RemoveDuplicatesFromSortedArray()

# new_len, new_nums = solve.remove_duplicates_quad_time(nums=[1, 1, 2])

new_len, new_nums = solve.remove_duplicates_linear_time(nums=[0, 0, 1, 1, 1, 2, 2, 3, 3, 4])
print(new_len, new_nums)
