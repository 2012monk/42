#!/bin/sh
for f in $(ls BSQ_TC/*)
do
  ./bsq < $f
done
