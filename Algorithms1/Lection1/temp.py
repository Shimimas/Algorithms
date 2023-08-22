def get_p_n(k, m, apparts_floor):
    p = (k - 1) // (apparts_floor * m) + 1
    n = (k - (p - 1) * apparts_floor * m - 1) // apparts_floor + 1
    return p, n


def decision_2(k1, m, k2, p2, n2):
    offset = (p2 - 1) * m + (n2 - 1)

    apparts_floor_max = (k2 - 1) // offset

    if apparts_floor_max == 0 or (k2 - 1) // apparts_floor_max != offset:
        return -1, -1

    apparts_floor_min = (k2 - 1) // (offset + 1) + 1

    if (k2 - 1) // apparts_floor_min != offset:
        apparts_floor_max = apparts_floor_min

    p1_1, n1_1 = get_p_n(k1, m, apparts_floor_min)
    p1_2, n1_2 = get_p_n(k1, m, apparts_floor_max)

    return 0 if p1_1 != p1_2 else p1_1, 1 if m == 1 else (0 if n1_1 != n1_2 else n1_1)


k1, m, k2, p2, n2 = map(int, input().split())


if n2 > m:
    print(-1, -1)
elif n2 == 1 and p2 == 1:
    if k1 > k2:
        print(1 if k1 <= m else 0, 1 if m == 1 else 0)
    else:
        print(p2, n2)
else:
    print(*decision_2(k1, m, k2, p2, n2))