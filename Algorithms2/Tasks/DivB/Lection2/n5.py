n = int(input())
array = list(map(int, input().split()))
array.sort()
array = array[:-1]
time = sum(array)
print(time)