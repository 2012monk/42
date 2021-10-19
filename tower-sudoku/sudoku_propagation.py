import test_gen
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
