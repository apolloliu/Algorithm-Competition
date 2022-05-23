import math

a, b = map(int, input().split())


def is_prime(x):
	arr = [i for i in range(2, int(math.sqrt(x * 1.) + 1))]

	for i in arr:
		if x % i == 0:
			# print(i)
			return False

	return True


def calc(x):
	arr = [i for i in range(2, int(math.sqrt(x * 1.) + 1))]

	res = list()
	for i in arr:
		if x % i == 0:
			res.append(i)
			if i != int(x / i):
				res.append(int(x / i))
	res.append(x)

	return sorted(res)

def binarySearch (arr, l, r, x): 
  
    # 基本判断
    if r >= l: 
  
        mid = int(l + (r - l)/2)
  
        # 元素整好的中间位置
        if arr[mid] == x: 
            return mid 
          
        # 元素小于中间位置的元素，只需要再比较左边的元素
        elif arr[mid] > x: 
            return binarySearch(arr, l, mid-1, x) 
  
        # 元素大于中间位置的元素，只需要再比较右边的元素
        else: 
            return binarySearch(arr, mid+1, r, x) 
  
    else: 
        # 不存在
        return -1

def check(arr):
	res = 0
	for x in arr:
		if x == 1:
			continue
		y = int(math.sqrt(x))
		if y * y == x:
			# print('y: ', y)
			res += 2

	return res

if a != b and is_prime(a) is True and is_prime(b) is True:
	x = int(math.sqrt(a * b))
	if (a * b) % (x * x) == 0:
		# print('x: ', x)
		print("no credit")
	else:
		print("full credit")
else:
	sa = calc(a)
	sb = calc(b)

	res = 0
	res += check(sa)
	res += check(sb)


	for x in sa:
		if binarySearch(sb, 0, len(sb) - 1, x) != -1:
			res += 2
			break

	x = int(math.sqrt(a * b))

	if res < 2:
		print("partial credit")
	else:
		print("no credit")

