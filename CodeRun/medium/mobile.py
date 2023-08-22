import heapq

def equal_skills(number, skill, point):
    k = number - 1
    if skill == 1:
        array_1[k] += point
        heapq.heappush(first_team, [array_1[k] - array_2[k], k, array_1[k], array_2[k]])
    else:
        array_2[k] += point
        heapq.heappush(second_team, [array_2[k] - array_1[k], k, array_1[k], array_2[k]])
    return point


def not_equal_skills(number, skill, point):
    k = number - 1
    if skill == 1:
        while first_team[0] in deleted:
            heapq.heappop(first_team)
        old_task = [array_2[k] - array_1[k], k, array_1[k], array_2[k]]
        array_1[k] += point
        deleted.add(old_task)
        new_task = [array_2[k] - array_1[k], k, array_1[k], array_2[k]]
        if first_team[0][0] < -1 * new_task[0]:
            tmp_el = heapq.heappop(first_team)
            id[k] = 1
            id[tmp_el[1]] = 2
            tmp_el[0] *= -1
            heapq.heappush(second_team, tmp_el)
            new_task[0] *= -1
            heapq.heappush(first_team, new_task)
            return (new_task[2] + tmp_el[3]) - (tmp_el[2] + old_task[3])
        else:
            heapq.heappush(second_team, new_task)
    else:
        while second_team[0] in deleted:
            heapq.heappop(second_team)
        old_task = [array_2[k] - array_1[k], k, array_1[k], array_2[k]]
        deleted.add(old_task)
        array_2[k] += point
        new_task = [array_1[k] - array_2[k], k, array_1[k], array_2[k]]
        if -1 * second_team[0][0] > new_task[0]:
            tmp_el = heapq.heappop(second_team)
            id[k] = 2
            id[tmp_el[1]] = 1
            tmp_el[0] *= -1
            heapq.heappush(first_team, tmp_el)
            new_task[0] *= -1
            heapq.heappush(second_team, new_task)
            return (new_task[3] + tmp_el[2]) - (tmp_el[3] + new_task[2])
        else:
            heapq.heappush(first_team, new_task)
    return 0


n = int(input())
array_1 = list(map(int, input().split()))
array_2 = list(map(int, input().split()))
new_array = sorted([(array_1[i] - array_2[i], i) for i in range(n)], reverse=True)
id = {}
sum = 0
deleted = set()
sums = []
first_team = []
second_team = []
mid = n // 2
for i in range(n):
    idx = new_array[i][1]
    if i < mid:
        first_team.append([new_array[i][0], idx, array_1[idx], array_2[idx]])
        id[idx] = 1
        sum += array_1[idx]
    else:
        second_team.append([-1 * new_array[i][0], idx, array_1[idx], array_2[idx]])
        id[idx] = 2
        sum += array_2[idx]
heapq.heapify(first_team)
heapq.heapify(second_team)
m = int(input())
for i in range(m):
    number, skill, point = map(int, input().split())
    if skill == id[number - 1]:
        sum += equal_skills(number, skill, point)
    else:
        sum += not_equal_skills(number, skill, point)
    sums.append(sum)
for el in sums:
    print(el)