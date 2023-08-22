n = int(input())
k = int(input())
r = int(input())
v = int(input())
number_p = ((r - 1) * 2) + v
number_v_1 = number_p + k
number_v_2 = number_p - k
r1 = ((number_v_1 - 1) // 2) + 1
r2 = ((number_v_2 - 1) // 2) + 1
if number_v_1 % 2 == 1:
    v1 = 1
else:
    v1 = 2
if number_v_2 % 2 == 1:
    v2 = 1
else:
    v2 = 2
if number_v_1 >= 1 and number_v_1 <= n and number_v_2 >= 1 and number_v_2 <= n:
    if abs(r1 - r) <= abs(r2 - r):
        print(r1, v1)
    else:
        print(r2, v2)
elif number_v_1 >= 1 and number_v_1 <= n:
    print(r1, v1)
elif number_v_2 >= 1 and number_v_2 <= n:
    print(r2, v2)
else:
    print(-1)