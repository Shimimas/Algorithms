def check(b_array, w_array):
    for el in w_array:
        if (el[0] + 1, el[1] + 1) in b_array and (el[0] + 2, el[1] + 2) not in b_array and (el[0] + 2, el[1] + 2) not in w_array:
            if el[0] + 2 <= n and el[1] + 2 <= m:
                return "YES"
                break
        elif (el[0] - 1, el[1] - 1) in b_array and (el[0] - 2, el[1] - 2) not in b_array and (el[0] - 2, el[1] - 2) not in w_array:
            if el[0] - 2 >= 1 and el[1] - 2 >= 1:
                return "YES"
                break
        elif (el[0] + 1, el[1] - 1) in b_array and (el[0] + 2, el[1] - 2) not in b_array and (el[0] + 2, el[1] - 2) not in w_array:
            if el[0] + 2 <= n and el[1] - 2 >= 1:
                return "YES"
                break
        elif (el[0] - 1, el[1] + 1) in b_array and (el[0] - 2, el[1] + 2) not in b_array and (el[0] - 2, el[1] + 2) not in w_array:
            if el[0] - 2 >= 1 and el[1] + 2 <= m:
                return "YES"
                break
    return "NO"


n, m = tuple(map(int, input().split()))
w = int(input())
w_array = set()
for i in range(w):
    w_array.add(tuple(map(int, input().split())))
b = int(input())
b_array = set()
for i in range(b):
    b_array.add(tuple(map(int, input().split())))
if input() == "white":
    print(check(b_array, w_array))
else:
    print(check(w_array, b_array))