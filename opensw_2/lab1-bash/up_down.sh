x#! /bin/bash

up_down_func(){
 echo "UP & dowm game!"
 echo "Random number range(max : 32768) :100"
 echo "Number Range : 1 - 100"

 num=$((($RANDOM % 100) + 1))
 count=1
 
 while [ 1 ] 
 do
  echo -n "Enter the number : "
  read a
  if [ $num -lt $a ]; then
   echo "answer is less than $a!"
   ((count++))
  elif [ $num -gt  $a ]; then
   echo "answer is greater than $a!"
   ((count++))
  else
   break
  fi
 done
 echo "Congratulation! Answer is $a."
 echo "Count : $count"
}

up_down_func


