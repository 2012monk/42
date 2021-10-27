#!/bin/bash

rm -rf set5
mkdir set5

for i in `seq 20 30`;
do
        ./grid_generator.perl 5 7 2 > set/grid_$i
done
