numbers = list(map(int, input().split()))
one_time = set()
many_times = set()
for el in numbers:
    if el not in one_time and el not in many_times:
        one_time.add(el)
    else:
        one_time.discard(el)
        many_times.add(el)
res_text = ''
for el in numbers:
    if el in one_time:
        res_text += str(el) + ' '
print(res_text)