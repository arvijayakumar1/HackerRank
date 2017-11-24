from functools import partial
from itertools import count

def dot(p, q):
    a, b = p
    c, d = q
    return a * c + b * d

dirs = {
    'n': (-1, 0),
    'e': (0, +1),
    's': (+1, 0),
    'w': (0, -1),
}

n = int(input())
grid = [[0]*n for i in range(n)]
sdirs = sorted(dirs.values(), key=partial(dot, dirs[input()]), reverse=True)
i, j = map(int, input().strip().split())
for tm in count(1):
    grid[i][j] = tm
    for di, dj in sdirs:
        ni, nj = i + di, j + dj
        if 0 <= ni < n and 0 <= nj < n and not grid[ni][nj]:
            i, j = ni, nj
            break
    else:
        break

for i in range(n):
    print(*grid[i])