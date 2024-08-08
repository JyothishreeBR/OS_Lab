#!/bin/bash

echo "Enter the number of rows of a matrix"
read row
echo "Enter the number of columns of a matrix"
read col

declare -A a
declare -A b

echo "enter the elements of the 1st matrix"
for (( i=0;i<row;i++ ))
do
 for (( j=0;j<col;j++ ))
do
 echo "Enter Element [$i,$j]:"
  read a[$i,$j]
done
done

echo "enter the elements of the 2nd matrix"
for (( i=0;i<row;i++ ))
do
 for (( j=0;j<col;j++ ))
do
 echo "Enter Element [$i,$j]:"
  read b[$i,$j]
done
done

echo "sum of the 2 matrices"
for (( i=0;i<row;i++ ))
do
 for (( j=0;j<col;j++ ))
do
  sum=$((a[$i,$j]+b[$i,$j]))
  echo -n " $sum "
  
done
echo ""
done
