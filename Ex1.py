def stat(nums):
    n = len(nums)
    tmp = sorted(nums)
    freq = {}
    mean = variance = 0
    median = tmp[n // 2] if n % 2 else (tmp[n // 2] + tmp[n // 2 - 1]) / 2
    for i in nums:
        mean += i
        variance += i * i
        if i in freq.keys(): freq[i] += 1
        else: freq[i] = 1
    mean /= n
    variance /= n
    variance -= mean * mean
    mode = nums[0]
    maxf = freq[nums[0]]
    for i in freq.keys():
        if freq[i] > maxf:
            maxf = freq[i]
            mode = i
    return mean, median, mode, variance

data = [1, 1, 1, 2, 3, 4]
print(stat(data))
    
