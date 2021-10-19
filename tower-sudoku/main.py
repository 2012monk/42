def find_unfilled(board):
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
