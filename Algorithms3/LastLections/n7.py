def toSecond(array):
    return array[0] * 3600 + array[1] * 60 + array[2]

def fromSecond(second):
    a = second // 3600
    a %= 24
    second %= 3600
    b = second // 60
    second %= 60
    c = second
    f_el = ''
    s_el = ''
    t_el = ''
    if len(str(a)) == 1:
        f_el = f'0{a}'
    else:
        f_el = str(a)
    if len(str(b)) == 1:
        s_el = f'0{b}'
    else:
        s_el = str(b)
    if len(str(c)) == 1:
        t_el = f'0{c}'
    else:
        t_el = str(c)
    return f'{f_el}:{s_el}:{t_el}'

A = list(map(int, input().split(':')))
B = list(map(int, input().split(':')))
C = list(map(int, input().split(':')))
a_sec = toSecond(A)
b_sec = toSecond(B)
c_sec = toSecond(C)
if a_sec > c_sec:
    c_sec += 3600 * 24
delta = round((c_sec - a_sec - 1) // 2 + 1)
print(fromSecond(b_sec + delta))
