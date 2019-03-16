#!/bin/bash
LOGIN="brvalcas"
echo "\033[31mNORME\033[0m"
read $VAR

norminette ../roliveir
echo "\033[31mNORME SUITE\033[0m"
read $VAR

find ../roliveir -name '*.c' -exec cat {} \; | grep "\+\n"
find ../roliveir -name '*.c' -exec cat {} \; | grep "\*\n"
find ../roliveir -name '*.c' -exec cat {} \; | grep "\-\n"
find ../roliveir -name '*.c' -exec cat {} \; | grep "\ \/\n"
find ../roliveir -name '*.c' -exec cat {} \; | grep "\&\n"
find ../roliveir -name '*.c' -exec cat {} \; | grep "\|\n"
find ../roliveir -name '*.c' -exec cat {} \; | grep "\%\n"
echo "\033[31mAUTEUR\033[0m"
read $VAR

cat -e ../roliveir/auteur
echo "\033[31mMAKE\033[0m"
read $VAR

make re -C ../roliveir
make clean -C ../roliveir
echo "\033[31mFONCTIONS\033[0m"
read $VAR

nm -u ../roliveir/$LOGIN.filler
echo "\033[31mMALLOC\033[0m"
read $VAR

find ../roliveir -name '*.c' -exec cat {} \; | grep "join"
find ../roliveir -name '*.c' -exec cat {} \; | grep "strnew"
find ../roliveir -name '*.c' -exec cat {} \; | grep "strdup"
find ../roliveir -name '*.c' -exec cat {} \; | grep "malloc"
find ../roliveir -name '*.c' -exec cat {} \; | grep "lstnew"
find ../roliveir -name '*.c' -exec cat {} \; | grep "strsub"
echo "\033[31mINCLUDES\033[0m"
read $VAR

find ../roliveir -name '*.*' -exec cat {} \; | grep "include"
echo "\033[31mLOGIN\033[0m"
read $VAR

find ../roliveir -name '*.*' -exec cat {} \; | grep "by"
echo "\033[31mTEST ERREUR FACILE\033[0m"
read $VAR

./../roliveir/$LOGIN.filler
./../roliveir/$LOGIN.filler < file/error1
./../roliveir/$LOGIN.filler < file/error2
./../roliveir/$LOGIN.filler < /dev/null

echo "\033[31mTEST ERREUR MOYEN\033[0m"
read $VAR

./../roliveir/$LOGIN.filler < file/error3
./../roliveir/$LOGIN.filler < file/error4
./../roliveir/$LOGIN.filler < file/error5
./../roliveir/$LOGIN.filler < file/error6

echo "\033[31mTEST ERREUR DIFFICILE\033[0m"
read $VAR

./../roliveir/$LOGIN.filler < file/error7
./../roliveir/$LOGIN.filler < file/error8
./../roliveir/$LOGIN.filler < file
./../roliveir/$LOGIN.filler < /dev/random

echo "\033[31mTEST LEAKS FACILE\033[0m"
read $VAR

valgrind ./../roliveir/$LOGIN.filler
valgrind ./../roliveir/$LOGIN.filler < file/error1
valgrind ./../roliveir/$LOGIN.filler < file/error2
valgrind ./../roliveir/$LOGIN.filler < /dev/null

echo "\033[31mTEST LEAKS MOYEN\033[0m"
read $VAR

valgrind ./../roliveir/$LOGIN.filler < file/error3
valgrind ./../roliveir/$LOGIN.filler < file/error4
valgrind ./../roliveir/$LOGIN.filler < file/error5
valgrind ./../roliveir/$LOGIN.filler < file/error6

echo "\033[31mTEST LEAKS DIFFICILE\033[0m"
read $VAR

valgrind ./../roliveir/$LOGIN.filler < file/error7
valgrind ./../roliveir/$LOGIN.filler < file/error8
valgrind ./../roliveir/$LOGIN.filler < file
valgrind ./../roliveir/$LOGIN.filler < /dev/random
