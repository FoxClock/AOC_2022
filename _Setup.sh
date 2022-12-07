#!/bin/sh

makefile="Makefile"
date=`date +"%d-%m-%Y"`

# Sets up a day for AOC
# Steps
# - Prompts user for the day they want to create -> $(Day)
# - Creates folder for that day
# - CD into folder
# - Create first and second C file 
# -- called $(Day).c and $(Day)-2.c
# - Create makefile
# - Create input.txt & testInput.txt

# Reads the Day number
echo "enter Day number to setup:\t"
read Day

# makes the directory
mkdir -p 'Day'$Day

# Move to folder
cd 'Day'$Day

# Create c files
touch 'Day'$Day'.c'
touch 'Day'$Day'-2.c'

# Get puzzle input
touch 'input.txt'
curl --cookie "~/Downloads/cookies.txt"  "https://adventofcode.com/2022/day/"$Day"/input" >> input.txt

# Put comments into file
echo -e "// AUTHOR:\tHayden Foxwell" >> 'Day'$Day'.c'
echo -e "// DATE:\t$date" >> 'Day'$Day'.c'
echo -e "// PURPOSE:\tDay $Day -" >> 'Day'$Day'.c'
echo -e "// AUTHOR:\tHayden Foxwell" >> 'Day'$Day'-2.c'
echo -e "// DATE:\t$date" >> 'Day'$Day'-2.c'
echo -e "// PURPOSE:\tDay $Day -" >> 'Day'$Day'-2.c'


# Setup makefile
touch $makefile
echo "CC=CC" >> $makefile
echo "Day="$Day >> $makefile
echo 'challenge1=Day$(Day)' >> $makefile
echo 'challenge2=Day$(Day)' >> $makefile

echo 'commonPath=../Common' >> $makefile
echo 'common=common.c' >> $makefile

echo "" $makefile
echo "all: AOC-challenge1" >> $makefile
echo "" >> $makefile

echo "AOC-challenge1:" >> $makefile 
echo -e "\t"'$(CC) -o AOC$(Day) $(challenge1).c $(commonPath)/$(common)' >> $makefile
echo "" >> $makefile

echo "AOC-challenge2:" >> $makefile
echo -e "\t"'$(CC) -o AOC$(Day) $(challenge2).c $(commonPath)/$(common)' >> $makefile
echo "" >> $makefile

echo "clean:" >> $makefile
echo -e "\t""rm *.o" >> $makefile

# Create text files
touch testInput.txt
