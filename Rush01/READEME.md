# Tower Sudoku

주어진 조건이 다른 스도쿠의 변형

## 제약조건

1. 각 Row 와 Col 에 하나의 숫자만 존재해야 한다
2. Rowcondition 과 ColCondition 이 지정하는 보이는 상자의 개수를 맞추어야한다.

### 제약조건 전파 방식

Bitmask 를 사용한 조건 체크

각 Row , Col 에 대해 board 에 Fix 된 원소들을 체크

EX)

```pseudo
row_condtion[0] == 0b1111 
index 0의 행에서 고정되지 않은 (선택 가능한 원소) == 1, 2, 3, 4
```

후보군을 포함한 Grid체크

```pseudo
grid[SIZE*SIZE] = {0b1111, 0b1111, ....., 0b1111}
```

Grid 는 1차원 배열로 사용

## Algorithm

1. 제약 조건에 따라 Grid의 후보군을 줄인다

    - 조건 C == SIZE
    - 조건 C == 1
    - 조건 1 < C < SIZE

2. 가장 후보군을 적게 가진 그리드의 자리를 찾는다

3. 해당 그리드의 후보군을 순회하면서 모든 가능성을 탐색한다

    - 선택된 후보를 자리에 쓰고 제약조건을 peer에게 전파한다
    - 재귀적으로 위의 과정을 수행한다
    - 만약 모순이 발생 한다면 return false
