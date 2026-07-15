n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
res = []
for k in range((n + 1) // 2):
    s = 0
    tp, bt = k, n - 1 - k
    l, r = k, n - 1 - k
    if tp == bt and l == r:
        s = a[tp][l]
    else:
        for j in range(l, r + 1):
            s += a[tp][j]
        for j in range(l, r + 1):
            s += a[bt]
        for i in range(tp + 1, bt):
            s += a[i][l]
        for i in range(tp + 1, bt):
            s += a[i][r]
    res.append(s)
print(*res)
