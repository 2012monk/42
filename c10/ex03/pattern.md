#Hexdump Error pattern

☁  ex03 [master] ⚡  hexdump 1 2 3 4          
hexdump: 1: No such file or directory
hexdump: 2: No such file or directory
hexdump: 3: No such file or directory
hexdump: 4: No such file or directory
hexdump: 4: Bad file descriptor

모두 없는 파일만 인자로 줄때는 마지막에 read 를 시도한다

☁  ex03 [master] ⚡  hexdump 1 2 3 srcs  
hexdump: 1: No such file or directory
hexdump: 2: No such file or directory
hexdump: 3: No such file or directory
hexdump: srcs: Is a directory

디렉터레라 끼어있을경우 read를 시도하지 않음

☁  ex03 [master] ⚡  hexdump test/1 1    
0000000 31 0a 32 0a 33 0a 34 0a 35 0a 36 0a 37 0a 38 0a
hexdump: 1: No such file or directory
0000010 39 0a 30 0a 31 0a 32 0a 33 0a 34 0a 35 0a      
000001e

☁  ex03 [master] ⚡  hexdump test/1 1 2 3 4
0000000 31 0a 32 0a 33 0a 34 0a 35 0a 36 0a 37 0a 38 0a
hexdump: 1: No such file or directory
hexdump: 2: No such file or directory
hexdump: 3: No such file or directory
hexdump: 4: No such file or directory
0000010 39 0a 30 0a 31 0a 32 0a 33 0a 34 0a 35 0a      
000001e

존재하는 파일과 없는 파일을 넣을때는 첫줄이 출력되고 에러메세지가 중간에 모두 나타남

☁  ex03 [master] ⚡  hexdump test/1 srcs   
0000000 31 0a 32 0a 33 0a 34 0a 35 0a 36 0a 37 0a 38 0a
hexdump: srcs: Is a directory
0000010 39 0a 30 0a 31 0a 32 0a 33 0a 34 0a 35 0a      
000001e