def find_len_of_lcis(nums: list) -> int:
    s = 1 if len(nums) > 0 else 0
    res = s
    for num_index in range(1, len(nums)):
        if nums[num_index] > nums[num_index - 1]:
            s += 1
            res = s if res < s else res
        else:
            res = s if res < s else res
            s = 1
        print(s, res)
    return res


# print(find_len_of_lcis([1, 3, 5, 4, 7]))


def max_sub_array(nums) -> int:
    maxm = nums[0]
    s = nums[0]
    for i in range(1, len(nums)):
        s = max(s + nums[i], nums[i])
        maxm = s if maxm < s else maxm
        print(s)
    return maxm


# print(max_sub_array([-2, 1, -3, 4, -1, 2, 1, -5, 4]))


def plus_one(nums) -> list:
    v = 0
    for i in range(len(nums) - 1, -1, -1):
        if nums[i] == 9 and (i == len(nums)-1 or v == 1):
            nums[i] = 0
            v = 1
        else:
            nums[i] = nums[i] + 1 if v == 1 or i == len(nums) - 1 else nums[i]
            v = 0
    if nums[0] == 0:
        nums = [1] + nums
    return nums


# print(plus_one([9, 9, 9]))


def merge_in_place(n1, m, n2, n):
    i = 0
    j = 0
    m1 = m
    nj = n
    while i < m1+n:
        if i < m1 and j < nj and n1[i] > n2[j]:
            # print(n1, n2, i, j, m1, n, n1[i], n2[j])
            # print('x')
            s = m1 if m1 < len(n1)-1 else len(n1)-1
            while s != i:
                n1[s] = n1[s-1]
                s -= 1
            n1[s] = n2[j]
            i += 1
            j += 1
            m1 += 1
            n -= 1

        elif i >= m1:
            print('x')
            n1[i] = n2[j]
            i += 1
            j += 1

        else:
            i += 1

    print(n1)


# merge_in_place([0, 0, 0], 0, [-2, -5, -6], 3)

def unique_occurrences(arr):
    dic = {}
    for num in arr:
        if num not in dic.keys():
            dic[num] = 1
        else:
            dic[num] += 1
    print(list(dic.keys()))
    counts = []
    for c in list(dic.keys())[0:]:
        counts.append(dic[c])

    return len(list(set(counts))) == len(list(dic.keys()))


# print(unique_occurrences([-5, -6, 2, 6, -5, -7, 5]))


def sum_to_zero(n: int):
    out = []
    for i in range(-(n//2), (n//2+1)):
        if n % 2 == 0 and i == 0:
            continue
        out.append(i)

    return out


# print(sum_to_zero(3))
