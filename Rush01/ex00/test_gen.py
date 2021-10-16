import random

SIZE = 7


def is_full(arr):
    for a in arr:
        for i in a:
            if i == 0:
                return 0
    return 1


def generate_sudoku(arr, s):
    if is_full(arr):
        return 1
    x = s // SIZE
    y = s % SIZE
    ret = set([i for i in range(1, SIZE + 1)])
    rows = set(arr[x][:])
    cols = set([arr[i][y] for i in range(SIZE)])
    cand = ret - rows - cols
    while cand:
        cur = random.choice(list(cand))
        arr[x][y] = cur
        if generate_sudoku(arr, s + 1):
            return 1
        arr[x][y] = 0
        cand.remove(cur)
    return 0


def count_boxes(a):
    if not a:
        return 0
    mx = 0
    cnt = 0
    for i in range(SIZE):
        if mx > a[i]:
            continue
        mx = a[i]
        cnt += 1
    return cnt


def generate_constraints(arr):
    res = []
    for j in range(SIZE):
        res.append(count_boxes([arr[i][j] for i in range(SIZE)]))
    for j in range(SIZE):
        res.append(count_boxes([arr[i][j] for i in range(SIZE)][::-1]))
    for i in range(SIZE):
        res.append(count_boxes(arr[i][:]))
    for i in range(SIZE):
        res.append(count_boxes(arr[i][:][::-1]))
    return res


A = [[0 for _ in range(SIZE)] for _ in range(SIZE)]

if generate_sudoku(A, 0):

    file = open("./test_case_result", 'w')
    for a in A:
        file.write(' '.join(map(str, a)) + '\n')
        # print(*a)
    file.close()
    # print("===================")
    constraints = generate_constraints(A)
    con = open("./test_case_constraints", 'w')
    con.write(' '.join(map(str, constraints)))
    print(' '.join(map(str, constraints)), end='')
else:
    raise RuntimeError('Generate Failed!!')
