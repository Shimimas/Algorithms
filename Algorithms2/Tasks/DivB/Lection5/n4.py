text = input()
l = 0
flag = True
for el in text:
    if el == '(':
        l += 1
    else:
        l -= 1
    if l < 0:
        flag = False
        break
if l != 0:
    flag = False
if flag:
    print("YES")
else:
    print("NO")