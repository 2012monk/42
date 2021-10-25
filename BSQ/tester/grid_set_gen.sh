#!/bin/bash

rm -rf set
mkdir set

for i in `seq 1 10`;
do
        ./grid_generator.perl 10 20 10 > set/grid_$i
done
