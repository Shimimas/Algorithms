text = input()
if len(text) == 0 or len(text) == 1:
    print(0)
else:
    first_price = 0
    second_price = 0
    if len(text) % 2 == 0:
        s = len(text) // 2
        f = s - 1
    else:
        s = len(text) // 2 + 1
        f = s - 2
    for i in range(f + 1):
        if text[i] != text[-1 - i]:
            first_price += 1
    f_tmp = f
    for i in range(s, len(text)):
        if text[i] != text[f_tmp]:
            second_price += 1
        f_tmp-= 1
    print(min(second_price, first_price))