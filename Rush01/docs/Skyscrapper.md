# Sudoku Solve

## Backtracking `퇴각검색` 이란

제약 만족 문제 `Constraints Satisfaction Problem` 에서 해를 찾기 위한 전략으로 사용할수 있다.

해가 될수 있는 가능한 모든 조합을 탐색하되 해당 후보군이 제약 조건을 만족할수 없다고 판단하면 현재 상태를 배제 시키고 이전의 상태로 돌아가서 `BackTrack` 다른 가능성을 탐색한다.

- 임의의 노드에 대해 제약조건을 만족하는 값을 점검한다
- 제약 조건을 만족하는 값이 없다면 배제한다.
- 현재 노드의 부모노드로 돌아가서 다른 자손 노드를 탐색한다.

#### 용어

- 유망성 `Promising` : 가능성이 있는지 확인 하는 기준 (제약조건)
- 가지치기 `Pruning` : 유망성을 따져보고 유망하지 않는 경우의 수는 배제한다

## 제약 조건

1. N x N 격자에 1 ... N 높이의 건물이 각 열과 각 행에 중복없이 모두 존재해야 한다.

2. 방향에 따라 보이는 건물의 개수가 주어진 제약조건과 일치해야한다.

## 풀이

다항시간 내에 풀수 있는 알고리즘이 존재하지 않는 문제이다.

풀이가 가능한 여러가지 알고리즘이 존재하지만 BackTracking 을 사용하여 풀수있다.

일종의 무식하게 풀기 전략이다.

- 후보군의 가능성을 탐색한다.

    해당 건물이 각 열과 행에 사용 되었는지 체크

- 만약 현재 칸이 열 또는 행을 꽉 채웠을때 제약조건에 맞춰 높이를 체크한다

    만약 높이 체크에 실패한다면 다시 뒤로 돌아가서 위 과정을 반복한다

- 격자가 가득 찼으면 true 를 리턴한다.
  
  true 가 리턴되면 스택에 쌓여있던 모든 과정이 연쇄적으로 true 가 리턴되고 풀이가 끝나게 된다

### 구현

현재 격자의 상태와 모든 제약조건, 후보군에대해 기록하는데 사용되는 구조체이다.

한번에 많은 데이터를 다루어야 하기때문에 구조체를 사용한 포인터로 접근하는 방식을 사용

```c
typedef struct s_status
{
 int row_constraints[__MAX_SIZE__][2]; 
 int col_constraints[__MAX_SIZE__][2];
    // 행과 열의 제약조건 arr[좌표][left | right] 0 left 1 right
 int row_candidates[__MAX_SIZE__];
 int col_candidates[__MAX_SIZE__];
    // 열과 행의 가능한 후보군을 기록하는 배열
 int grid[__MAX_SIZE__][__MAX_SIZE__];
 int size; // 현재 격자의 크기
} t_status;
```

탐색을 하는 과정은 다음과 같다.

```c
int solve(t_status *status)
{
 int x;
 int y;
 int c; // 후보

 c = 0;
    // 상자가 배치되지 않은 비어있는 칸의 좌표를 찾는다
 find_free_cell(&x, &y, status->grid, status->size);
    if (x == -1 || y == -1) //격자가 꽉차있으면 true 를 리턴하고 과정이 끝난다
  return (1);
 while (++c <= status->size) // 후보군을 1...N 까지 탐색한다
 {
        // 제약조건에 따른 유망성을 점검한다
        // 1. 현재 좌표가 속해있는 열과 행에 값이 중복되지 않았는지
        // 2. 열 또는 행이 가득 찼을 때 
        //    열 또는 행에서 보이는 상자의 수를 세어 제약조건에 맞는지 확인
        
        // 만약 제약 조건에 대해 하나라도 만족하지 않는다면
        // 유망하지 않은 노드이기때문에 탐색을 진행하지 않는다
  if (is_used_box(x, y, c, status) || !is_valid_move(status, c, x, y))
   continue ;
        // 제약조건을 만족했다면 현재 값의 상태를 격자에 기록하고
        // 각 열과 행에 현재값이 사용되었다는 것을 표시한다.
  place_box(x, y, c, status);
        
        // 현재상태가 기록된 상태로 모든 가능성에 대해서 탐색한다
  if (solve(status)) 
        // 만약 현재기록된 값에서 모든 조건을 만족하는 조합이있다면 
        // true 를 리턴하고 모든 과정이 끝나게 된다.
   return (1);
        // 위의 조건문을 통과 하지 못한 경우
        // 현재 상자를 선택했을때 모든 조건을 만족하는 풀이가 없다는 의미이기 때문에
        // 현재 기록 상태를 이전 상태로 되돌리고 후보탐색을 계속한다.
  delete_box(x, y, c, status);
 }
    // 반복문을 빠져나온 경우
    // 현재 칸에서 선택할수 있는 후보군의 후보들을 각각 선택했을때 
    // 가능한 풀이가 없다는 의미이기 때문에 false 를 리턴한다.
 return (0);
}
```

현재 상태를 기록하는 구현

```c
void place_box(int x, int y, int value, t_status *status)
{
 status->grid[x][y] = value; // 격자에 현재 상자를 기록
 status->col_candidates[x] |= 1 << value;
 status->row_candidates[y] |= 1 << value;
    // x 열과 y 행의 상태에 합집합 연산을 통해서 
    // value 번째 원소가 사용되었음을 기록
}

void delete_box(int x, int y, int value, t_status *status)
{
 status->grid[x][y] = 0; // 격자를 초기상태로 갱신
 status->col_candidates[x] &= MASK ^ (1 << value);
 status->row_candidates[y] &= MASK ^ (1 << value);
    // MASK = 최대 원소의 개수 를 모두 가지고 있는 집합
    // Xor 연산을 통해 Value 번째 원소빼고 0으로 만든다
    // ex 1111 ^ 0100 = 1011
    // x 열과 y 행의 상태에 교집합 연산을 통해서
    // value 번째 원소를 삭제 
}
```

제약 조건 을 확인하는 방식은 다음과 같다.

열과 행에서 이미 사용된 상자를 검사한다.

```c
int is_used_box(int x, int y, int value, t_status *status)
{
 return ((status->col_candidates[x]
   | status->row_candidates[y])
  & (1 << value));
}
```

열과 행의 Or 연산을 통해서 합집합을 구한다

`S = col_candidates[x] | row_candidates[y] x열과 (세로) y 행의 (가로) 가 가지고 있는 모든 원소들`

`S & (1 << value) if value 번째 원소가 포함되어있다면 1 << value else 0`

```c
int is_valid_move(t_status *status, int val, int x, int y)
{
 int col[__MAX_SIZE__];
 int row[__MAX_SIZE__];
 int col_pass;
 int row_pass;

 copy_col(status->grid, col, y, status->size);
 copy_row(status->grid, row, x, status->size);
 col[x] = val;
 row[y] = val;

    // 열과 행을 각각 복사한뒤 x, y 좌표를 value 로 기록한다
 col_pass = 1; // 기본값은 true 이다
 row_pass = 1;
 if (x == status->size - 1) // 열이 꽉찼을 때
  col_pass = check_line_constraints(col, status->col_constraints[y][LEFT],
    status->col_constraints[y][RIGHT], status->size);
    // 갱신된 열에 대해서 검사한다.
    // col_constraints[y] ==> x, y 위치에서 y 번째 위치하는 열의 제약조건
 if (y == status->size - 1)
  row_pass = check_line_constraints(row, status->row_constraints[x][LEFT],
    status->row_constraints[x][RIGHT], status->size);
    // 갱신된 행에 대해서 검사한다.
    // row_constraints[x] ==> x, y 위치에서 x 번째 위치하는 행의 제약조건
 return (col_pass && row_pass);
     // 열과 행이 모두 조건에 통과해야 true
}
```

|  yx  |  0   |  1   |  2   |  3   |
| :--: | :--: | :--: | :--: | :--: |
|  0   |      |      |      |      |
|  1   |      |      |      |  A   |
|  2   |      |      |      |      |
|  3   |  B   |      |      |      |

A 위치

X = 1, Y = 3 일때 해당하는 행의 제약조건은 col_condition[x] 에 해당한다.

B 위치

X = 3, Y = 0 일때 해당하는 열의 제약 조건은 row_condition[y] 에 해당한다.

행또는 열을 체크하는 방식

```c
int check_line_constraints(int arr[], int left, int right, int size)
{
 int ret;

 ret = count_boxes(arr, size) == left; // 정방향으로 상자를 세고 확인한다
 reverse_arr(arr, size); // 배열을 뒤집는다
    // 뒤집은 배열의 정방향 (역방향) 으로 상자를 세고 확인한다.
 return (ret && count_boxes(arr, size) == right);
    // 정방향과 역방향 모두 통과해야 true
}
```

상자를 세는 방식

```c
int count_boxes(int tab[], int size)
{
 i = -1;
 max = 0; // 최대값
 cnt = 0; // 보이는 상자의 개수
 while (++i < size) // 0..SIZE-1
 {
  if (tab[i] && tab[i] > max)
        // 현재값이 0이 아니고 현재값이 이전의 최대값보다 크다면
        // 현재 위치한 상자는 보이므로 개수를 증가, 최대값 갱신
  {
   cnt++; 
   max = tab[i];
  }
 }
 return (cnt);
}
```

입력값 처리

유효성 검사

공백문자 제외 숫자만 처리

```c
int setup_input(t_status *status, char *arr)
{
 int i;
 int j;
 int x;
 int v;

 i = 0;
 j = 0;
 while (arr[j])
 {
  if ('0' <= arr[j] && arr[j] <= '9')
  {
   x = i % status->size; 
            // 현재 좌표계산 4 * size 형태로 입력이 들어오기때문에 나머지연산을 
            // 해주면 각자리가 나온다
   v = arr[j] - '0'; // 숫자변환
   if (i < (status->size * 2)) // 앞쪽 절반은 열정보가 들어온다
    status->col_constraints[x][i / status->size] = v;
                // size 만큼은 앞쪽 정방향 size 보다 클때 역방향
   else
            // 행 정보에 대해서 처리
    status->row_constraints[x][i / (status->size * 3)] = v;
   i++;
  }
  j++;
 }
 return (i);
}
```

메인 함수에서 처리하는부분

```c
int main(int argc, char **argv)
{
 t_status *status;
 int   lenght;

    // 유효성 검사 잘못된 입력이 들어올때 처리
 if (argc != 2) 
    // 인자가 두개가 아닐때 0번인자는 무조건 파일이름이기 떄문에 실제로 1개
 {
  print_str("Error\n");
  return (1);
 }
 lenght = get_intput_length(argv[1]);
 if (lenght <= 4 || lenght % 4 != 0) // 정보가 제대로 들어오지 않았을때
 {
  print_str("Error\n");
  return (1);
 }

    // 구조체에 대해서 메모리 동적할당
 status = malloc(sizeof(t_status));
 status->size = lenght / 4;
    // 모든 데이터를 초기화 => 처음 할당했을때 쓰레기값이 들어있다
 initialize_status(status);
    // 조건들입력처리
 setup_input(status, argv[1]); 
 if (solve(status)) // 풀이가 성공했을때
  print_board(status->grid, status->size);
 else // 풀이가 없을때
  print_str("Error\n");
 free(status); // 동적할당한 메모리는 해제해줘야함
 return (0);
}
```

## C 언어에 관한 자료

메모리 구조

스택과 힙

[메모리](https://jinshine.github.io/2018/05/17/%EC%BB%B4%ED%93%A8%ED%84%B0%20%EA%B8%B0%EC%B4%88/%EB%A9%94%EB%AA%A8%EB%A6%AC%EA%B5%AC%EC%A1%B0/)

malloc

[정적할당과 동적할당](https://dojang.io/mod/page/view.php?id=285)

헤더파일

[헤더파일 wiki](https://ko.wikipedia.org/wiki/%ED%97%A4%EB%8D%94_%ED%8C%8C%EC%9D%BC)
[헤더파일](https://boycoding.tistory.com/144)

헤더의 중복 인클루드 방지를 위해사용

[헤더가드](https://boycoding.tistory.com/146)

define ==> 매크로

[매크로](https://dojang.io/mod/page/view.php?id=651)

구조체

[구조체](https://dojang.io/mod/page/view.php?id=408)

[구조체 포인터](https://dojang.io/mod/page/view.php?id=418)

메인함수에 들어오는 인자(파라미터) 값 argc, argv

[메인함수 인자](https://m.blog.naver.com/sharonichoya/220501242693)
