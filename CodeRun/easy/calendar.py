days = {
    'Monday': 0,
    'Tuesday': 1,
    'Wednesday': 2,
    'Thursday': 3,
    'Friday': 4,
    'Saturday': 5,
    'Sunday': 6
}
n, day = input().split()
n = int(n)
actual = 0
for i in range(days[day]):
    print('..', end=' ')
    actual += 1
for i in range(1, n + 1):
    if len(str(i)) == 1:
        print(f'.{i}', end=' ')
    else:
        print(i, end=' ')
    actual += 1
    if actual == 7:
        print()
        actual = 0

