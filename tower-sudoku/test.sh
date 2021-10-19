DIR=$SHELL_SOURCE
norminette -R CheckForbiddenHeader *
find ../ -name "*.c" gcc -Wall -Werror -Wextra -o sudoku
for file in $(DIR/constraints)
do
  cat $file | sudoku > test_$file
  python3 evaluate