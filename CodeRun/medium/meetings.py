def time_to_minets(start):
    return int(start[:2]) * 60 + int(start[3:])

def appoint(day, start, duration, k, names):
    st = time_to_minets(start)
    en = st + int(duration)
    fail_people = []
    if day not in times:
        times[day] = {}
    can_res = True
    for name in names:
        if name not in times[day]:
            times[day][name] = []
        for el in times[day][name]:
            st_tmp = time_to_minets(el['time'])
            en_tmp = st_tmp + int(el['duration'])
            if not (en <= st_tmp or st >= en_tmp):
                can_res = False
                if name not in fail_people:
                    fail_people.append(name)
    if can_res:
        print("OK")
        for name in names:
            times[day][name].append({'time': start, 'duration': duration, 'names': names})
    else:
        print("FAIL")
        for el in fail_people:
            print(el, end=' ')
        print()

def output(day, name):
    if day in times and name in times[day]:
        for el in sorted(times[day][name], key=lambda dictionary: time_to_minets(dictionary['time'])):
            print(el['time'], el['duration'], end=' ')
            for name in el['names']:
                print(name, end=' ')
            print()

n = int(input())
times = {}
for i in range(n):
    s = input().split()
    if s[0] == "APPOINT":
        appoint(s[1], s[2], s[3], s[4], s[5:])
    else:
        output(s[1], s[2])
