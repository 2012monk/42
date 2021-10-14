#!/bin/sh
export PRJ=$1
complie() {
  files=$(find . -name "*.c" -not -name 'main.c' -exec basename {} \; | xargs echo "main.c ")
  gcc -o m $files 
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
# gcc -o m main.c rush04.c ft_putchar.c && ./m  && rm m
# compare

test_(){
  if [[ $PRJ == "C02" ]]
  then
    echo "Hello"
  fi
}

test_