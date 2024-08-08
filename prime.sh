

#!/bin/bash

echo "Enter the upper bound"
read n1
echo "Enter the lower bound"
read n2

echo "the prime numbers between $n1 and $n2 are"
for (( i=n1;i<n2;i++ ))
do
  for (( j=2;j<=$i/2;j++ ))
  do
   if [[ $((i%j)) == 0 ]]
   then
   flag=1
   fi
  done
  
  if [[ $flag == 0 ]]
  then
  echo -ne " $i "
  fi
  flag=0
done
  
