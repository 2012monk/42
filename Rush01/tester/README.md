# Rush01 Tester

## 사용방법

프로젝트가 있는 디렉토리에 파일을 배치하시고 아래 명령어를 실행하시면 됩니다

```
python3 ./test_gen.py
```

alias 명령어로 별칭을 지정하시면 사용하기 편리합니다

```bash
alias doku="python3 $(pwd)/test_gen.py"
```

zshrc 에 쓰시면 쉘을 다시 켜도 적용이 됩니다

```bash
echo "doku=\"python3 $(pwd)/test_gen.py\" >> ~/.zhrc
source ~/.zshrc
```

## 옵션

기본적으로 실행하시면 입력값만 만들어서 stdout 으로 프린트합니다

-r *.c 파일을 모두 찾아서 컴파일 후 채점합니다

-s SIZE 사이즈를 입력하시면 조절 가능합니다 default=4

-c NUM 실행 횟수를 지정하실수 있습니다 default=1
예시

```bash
doku -r -s 6 -c 2
running...
6 1 3 2 5 4
4 6 1 3 2 5
2 4 6 5 1 3
3 5 2 6 4 1
5 2 4 1 3 6
1 3 5 4 6 2

compare success
complete in 0.14714 sec
running...
6 1 3 2 5 4
4 6 1 3 2 5
2 4 6 5 1 3
3 5 2 6 4 1
5 2 4 1 3 6
1 3 5 4 6 2

compare success
complete in 0.14747 sec
```
