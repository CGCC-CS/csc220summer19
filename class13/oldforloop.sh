#!/bin/bash

# Example of different shell script syntax

#For loop
STOP=5
for ((i=1;i<=STOP;i++))
do
    echo $i
done

# Files in the current directory
allfiles=(*)
cfiles=(*.c)

echo $allfiles[0]
echo ${allfiles[0]}
echo ${allfiles[1]}
echo


echo "List of C files"
for filename in $cfiles;
do
    echo $filename
done

echo
echo "Results of find command"
cppfiles=($(find . -name "*.cpp"))
echo "List of C++ files"
for filename in ${cppfiles[*]};
do
    echo $filename
done

