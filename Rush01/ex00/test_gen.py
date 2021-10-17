import argparse
import random
import subprocess
import time
from datetime import timedelta

SIZE = 4


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
    print(SIZE)
    A = [[0 for _ in range(SIZE)] for _ in range(SIZE)]
    generate_sudoku(A)
    constraints = generate_constraints(A)
    if args.run:
        try:
            st = time.time()
            cmd = 'find . -name \"*.c\" | xargs gcc -o doku -Wall -Werror -Wextra && ./doku ' + ' '.join(map(str, constraints))
            print("running...")
            proc = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
            out = proc.communicate()[0]
            r = out.decode('ascii')
            print(r)
            result = list(map(lambda x: list(map(int, x.split())), out.decode('ascii').strip().split('\n')));
            # print(result)
            e = evaluate(constraints, result)
            if e is None:
                print("compare success")
            else:
                print("compare failed")
                print("your result\n" + ' '.join(map(str, e)))
            print(f'complete in {time.time() - st:.5f} sec')
        except:
            print("error")
            exit(1)
    elif args.eval:
        pass
    else:
        print(' '.join(map(str, constraints)), end='')
