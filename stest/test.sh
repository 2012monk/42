#!/bin/sh
export PRJ=$1
complie() {
  norminette -R CheckForbiddenSourceHeader *
  files=$(find . -name "*.c" -not -name 'main.c' -exec basename {} \; | xargs echo "main.c ")
  gcc -o m -Wall -Wextra -Werror $0
}

compare() {
  cp main.c main.c.bak
  DIR=$(dirname "$BASH_SOURCE")
  for i in $(seq 1 $(wc -l $DIR/value | awk '{print $1}'))
  do
    t=$(sed -n $i\p $DIR/value)
    sed "s/rush([0-9], [0-9])/rush($t)/" main.c > tmp
    mv tmp main.c
    complie
    ./m > ures
    
    echo "test_$i" >> $DIR/result
    echo "input $(sed -n $i\p $DIR/value)\n" >> $DIR/result
    diff -u $DIR/comp/test_$i ures
    rm ures
    rm m
  done
  mv main.c.bak main.c
}

test() {
  DIR=$(dirname "$BASH_SOURCE")
  PJ=$1
  complie $PJ/
}
>>>>>>> 428a3f68aa7e4b20eb51fe41fae0a04ed0d46c9b
