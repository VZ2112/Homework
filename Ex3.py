def prod(arr):
    res = 1
    for i in arr: res *= i
    return res

def ans(nums):
    tmp = prod(nums)
    return [tmp / i for i in nums]

nums = [1, 2, 3, 4]
print(ans(nums))
