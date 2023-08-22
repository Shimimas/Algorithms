numbers = set()
array = list(map(int, input().split()))
for el in array:
    if el in numbers:
        print("YES")
    else:
        numbers.add(el)
        print("NO")