def runningSum(nums):
    output = []
    for i in range(len(nums)):
        run_sum = 0
        for j in range(i+1):
            run_sum += nums[j]
        output.append(run_sum)

    return output


running_sum = runningSum(nums=[1, 2, 3, 4])
print(running_sum)
