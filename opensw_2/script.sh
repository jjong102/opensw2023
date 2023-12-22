#! /bin/bash

test_func() {
echo -n -e "Enter your name:\t"
read name
echo "Hello $name"
}

test_func2() {
 echo $1
 echo $2
 echo $*
 echo $#
}

test_for() {
 for x in 10 20 30; do
  echo $x
 done
}

test_for2() {
 for x in $*; do
  echo $x
 done
}

test_seq() {
 for i in $(seq 10); do
  echo $i
 done
}

test_arithmetic() {
 num1=10
 num2=20
 echo $((num1+num2))
}

test_arithmetic_seq() {
 s_num=0
 for i in $(seq 100); do
  s_num=$((s_num + i))
 done
 echo $s_num
}

test_txt_wordconut() {
 txt_files=$(ls *.txt)
 for file in $txt_files; do
  word_count=$(cat $file | wc -w)
  echo $file $word_count
 done 
}

test_if() {
 str1='hellow'
 str2='hellow'
 if [ $str1 = $str2 ]; then
   echo "$str1 and $str2 are same"
 else
   echo "$str1 and $str2 are different"
 fi
 if [ -x a.out ]; then
    echo "a.out is executable"
 fi 
}

test_txt_wordcount_2() {
 files=$(ls)
 for file in $files; do
   if [ ! -x $file ]; then 
     word_count=$(cat $file | wc -w)
     echo $file $word_count
   fi 	
 done
}
#test_func2 hellow world 10 20 30
#test_func
#test_for
#test_for2 hellow world good bye good evening
#test_seq
#test_arithmetic
#test_arithmetic_seq
#test_txt_wordconut
#test_if

test_txt_wordcount_2
#echo $0
#echo $1
#echo $2
#echo $*
#echo $#
