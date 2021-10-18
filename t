tower-sudoku/                                                                                       000755  000765  000024  00000000000 14132763741 015410  5                                                                                                    ustar 00leesoungmook                    staff                           000000  000000                                                                                                                                                                         tower-sudoku/test_case_constraints                                                                  000644  000765  000024  00000000037 14132763741 021734  0                                                                                                    ustar 00leesoungmook                    staff                           000000  000000                                                                                                                                                                         2 1 2 3 2 3 2 1 2 3 1 4 2 2 2 1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 tower-sudoku/READEME.md                                                                             000644  000765  000024  00000000217 14132763741 016774  0                                                                                                    ustar 00leesoungmook                    staff                           000000  000000                                                                                                                                                                         # Rush 01 Tester

## 사용법

프로젝트 디렉토리에서 스크립트를 실행시키시면 자동으로 테스트가 진행됩니다.

                                                                                                                                                                                                                                                                                                                                                                                 tower-sudoku/constraints/                                                                           000755  000765  000024  00000000000 14132763741 017757  5                                                                                                    ustar 00leesoungmook                    staff                           000000  000000                                                                                                                                                                         tower-sudoku/sudoku_propagation.py                                                                  000644  000765  000024  00000004707 14132763741 021707  0                                                                                                    ustar 00leesoungmook                    staff                           000000  000000                                                                                                                                                                         import test_gen
from collections import defaultdict

COL_UP = 0
COL_DOWN = 1
ROW_LEFT = 2
ROW_RIGHT = 3
SIZE = 4


def init_board(size=4):
    candi = set(i for i in range(1, size + 1))
    arr = [candi for _ in range(size * size)]
    return arr


def init_units(size=4):
    peers = defaultdict()
    for i in range(size):
        for j in range(size):
            s = i * size + j
            if s not in peers:
                peers[s] = [[] for _ in range(4)]
            peers[s][COL_UP].extend(
                [k for k in range(size * size)
                 if k != i * size + j and (k % size == j)])
            peers[s][ROW_LEFT].extend(
                [k for k in range(size * size)
                 if k != i * size + j and (k // size == i)])
            peers[s][COL_DOWN] = peers[s][COL_UP][::-1]
            peers[s][ROW_RIGHT] = peers[s][ROW_LEFT][::-1]
    return peers


grid = init_board()
units = init_units()
c = test_gen.get_constraints()
constraints = []
for i in range(SIZE * SIZE):
    if i < SIZE * 2:
        constraints.append((c[i], COL_UP if i < SIZE else COL_DOWN))
    else:
        constraints.append((c[i], ROW_LEFT if i < SIZE * 3 else ROW_RIGHT))


def get_cross_dir(dir):
    if dir < 3:
        return (dir + 1) % 3
    return (dir + 1) % 5 + 3


def constraints_init():
    def constrain_cell(cell: set, val, dist):
        m = SIZE - val + 2 + dist
        for c in range(m, SIZE + 1):
            cell.remove(c)

    for i in range(SIZE * SIZE):
        val = constraints[i][0]
        if val == 1:
            grid[i].clear()
            grid[i].add(SIZE)
        elif val == SIZE:
            for v, j in enumerate(units[i][constraints[i][1]]):
                grid[v].clear()
                grid[v].add(j + 1)
        else:
            for v, j in enumerate(units[i][constraints[i][1]]):
                constrain_cell(grid[v], val, j)



def assign(arr, s, v):
    """
    :param arr: 후보군을 표시하고 있는 Grid
    :param s: 해당하는 칸의 번호 2차원배열을 1차원으로 표현
    :param v: 할당하고자 하는 값
    해당하는 칸에 값을 할당한다
    """
    return 1


def eliminate(arr, s, v):
    """
    :param arr: 후보군을 표시하고 있는 Grid
    :param s: 해당하는 칸의 번호 2차원배열을 1차원으로 표현
    :param v: 제거하고자 하는 값
    주어진 값을 해당하는 칸의 후보에서 제외시키고 새로 바뀐 제약조건을 전파 시킨다
    """
    return 1
                                                         tower-sudoku/test_case_result                                                                       000644  000765  000024  00000000040 14132763741 020675  0                                                                                                    ustar 00leesoungmook                    staff                           000000  000000                                                                                                                                                                         3 4 1 2
2 3 4 1
4 1 2 3
1 2 3 4
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tower-sudoku/tower.py                                                                               000644  000765  000024  00000000000 14132763741 017110  0                                                                                                    ustar 00leesoungmook                    staff                           000000  000000                                                                                                                                                                         tower-sudoku/rush01_tester.py                                                                       000644  000765  000024  00000007333 14132763741 020500  0                                                                                                    ustar 00leesoungmook                    staff                           000000  000000                                                                                                                                                                         import argparse
import random
import subprocess
import time

SIZE: int


def is_full(arr):
    for a in arr:
        for i in a:
            if i == 0:
                return 0
    return 1


def find_unfilled_rand(arr):
    r = []
    for i in range(SIZE):
        for j in range(SIZE):
            if arr[i][j] == 0:
                r.append(i * SIZE + j)
    return r[random.randint(0, len(r) - 1)]


def generate_sudoku(arr):
    if is_full(arr):
        return 1
    s = find_unfilled_rand(arr)
    x = s // SIZE
    y = s % SIZE
    ret = set([i for i in range(1, SIZE + 1)])
    rows = set(arr[x][:])
    cols = set([arr[i][y] for i in range(SIZE)])
    cand = ret - rows - cols
    while cand:
        cur = random.choice(list(cand))
        arr[x][y] = cur
        if generate_sudoku(arr):
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


def get_constraints(size=4):
    A = [[0 for _ in range(size)] for _ in range(size)]
    generate_sudoku(A)
    return generate_constraints(A)


def evaluate(constraints, arr):
    comp = generate_constraints(arr)
    for x, y in zip(comp, constraints):
        if x != y:
            return comp


# if generate_sudoku(A, 0):
#
#     file = open("./test_case_result", 'w')
#     for a in A:
#         file.write(' '.join(map(str, a)) + '\n')
#         # print(*a)
#     file.close()
#     # print("===================")
#     constraints = generate_constraints(A)
#     con = open("./test_case_constraints", 'w')
#     con.write(' '.join(map(str, constraints)))
#     print(' '.join(map(str, constraints)), end='')
# else:
#     raise RuntimeError('Generate Failed!!')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Skyscraper Puzzle Random Generator and Evaluate for Rush01')
    parser.add_argument('-e', '--eval', required=False, action='store_true',
                        help='For evaluation')
    parser.add_argument('-s', '--size', metavar='grid size',
                        required=False, default=4, type=int, help='For adjust size default=4')
    parser.add_argument('-r', '--run', required=False, action='store_true',
                        help='find *.c to compile and run evaluate performance')

    args = parser.parse_args()
    SIZE = args.size
    A = [[0 for _ in range(SIZE)] for _ in range(SIZE)]
    generate_sudoku(A)
    constraints = generate_constraints(A)
    if args.run:
        st = time.time()
        cmd = 'find . -name *.c | xargs gcc -o doku -Wall -Werror -Wextra && ./doku ' + ' '.join(map(str, constraints))
        end = time.time() - st
        proc = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        out = proc.communicate()[0]
        result = list(map(lambda x: list(map(int, x.split())), out.decode('ascii').strip().split('\n')));
        # print(result)
        e = evaluate(constraints, result)
        if e is None:
            print("compare success")
        else:
            print("compare failed")
            print("your result\n" + ' '.join(map(str, e)))
        print(f'complete in {end:.5f} sec')
    elif args.eval:
        pass
    else:
        print(' '.join(map(str, constraints)), end='')
                                                                                                                                                                                                                                                                                                     tower-sudoku/main.py                                                                                000644  000765  000024  00000004144 14132763741 016711  0                                                                                                    ustar 00leesoungmook                    staff                           000000  000000                                                                                                                                                                         def find_unfilled(board):
    for i in range(4):
        for j in range(4):
            if board[i][j] != 0:
                continue
            return i, j
    return None


def is_full(board):
    for row in board:
        for e in row:
            if e == 0:
                return 0
    return 1


def find_candidates(board, size, x, y):
    ret = set([i for i in range(1, size + 1)])
    rows = set(board[x][:])
    cols = set([board[i][y] for i in range(size)])
    return ret - rows - cols


def check_height(line):
    if not line:
        return 0
    line = [x for x in line if x != 0]
    st = [line[0]]
    for l in line[1:]:
        if st[-1] < l:
            st.append(l)
    return len(st)


def check_row(board, size, x, y, val, rowCondition):
    if y < size - 1:
        return 1
    row = board[x][:]
    row[y] = val
    return check_height(row) == rowCondition[x][0] and check_height(row[::-1]) == rowCondition[x][1]


def check_col(board, size, x, y, val, colCondition):
    if x < size - 1:
        return 1
    col = [board[i][y] for i in range(size)]
    col[x] = val
    return check_height(col) == colCondition[y][0] and check_height(col[::-1]) == colCondition[y][1]


def is_move_valid(board, n, x, y, val, rowCondition, colCondition):
    return check_row(board, n, x, y, val, rowCondition) and check_col(board, n, x, y, val, colCondition)


def solution():
    colCondition = [
        (4, 1), (3, 2), (2, 2), (1, 2)
    ]
    rowCondition = [
        (4, 1), (3, 2), (2, 2), (1, 2)
    ]

    board = [[0 for _ in range(4)] for _ in range(4)]

    def solve(board):
        if is_full(board):
            return 1
        x, y = find_unfilled(board)
        cand = find_candidates(board, 4, x, y)
        for b in board:
            print(*b)
        print()
        for c in cand:
            if is_move_valid(board, 4, x, y, c, rowCondition, colCondition):
                board[x][y] = c
                if solve(board):
                    return 1
                board[x][y] = 0
        return 0

    if solve(board):
        for b in board:
            print(*b)
    else:
        print("Error")


solution()
                                                                                                                                                                                                                                                                                                                                                                                                                            tower-sudoku/test.sh                                                                                000644  000765  000024  00000000306 14132763741 016722  0                                                                                                    ustar 00leesoungmook                    staff                           000000  000000                                                                                                                                                                         DIR=$SHELL_SOURCE
norminette -R CheckForbiddenHeader *
find ../ -name "*.c" gcc -Wall -Werror -Wextra -o sudoku
for file in $(DIR/constraints)
do
  cat $file | sudoku > test_$file
  python3 evaluate                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          