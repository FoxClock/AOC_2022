CC=CC
Day=1
challenge1=Day$(Day)
challenge2=Day$(Day)
commonPath=../Common
common=common.c
all: AOC-challenge1

AOC-challenge1:
-e 	$(CC) -o AOC$(Day) $(challenge1).c $(commonPath)/$(common)

AOC-challenge2:
-e 	$(CC) -o AOC$(Day) $(challenge2).c $(commonPath)/$(common)

clean:
-e 	rm *.o
