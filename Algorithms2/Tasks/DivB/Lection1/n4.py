n = int(input())
if n > 0:
    array = list(map(int, input().split()))
    print(array[len(array) // 2])
else:
    print(0)