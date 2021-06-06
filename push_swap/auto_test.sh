#!/bin/bash

if [[ $# -ne 2 ]]; then
	echo "auto_test.sh <max> <time>"
	exit 0
fi

count=$2
biggest=0
if [[ $1 -le 3 ]]; then
	limit=2
elif [[ $1 -le 6 ]]; then
	limit=12
elif [[ $1 -le 100 ]]; then
	limit=700
elif [[ $1 -le 500 ]]; then
	limit=5300
fi
while [[ count -gt 0 ]]; do
	ARG=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")
	./push_swap_debug.out $ARG > .tmp
	line=$(wc -l < .tmp)
	echo $line
	if [[ $line -gt $limit ]]; then
		echo $ARG
	fi
	if [[ $(./checker_Mac $ARG < .tmp) == KO ]]; then
		echo [KO]
		echo input: $ARG
	fi
	if [[ $line -gt $biggest ]]; then
		biggest=$line
		biggest_input=$ARG
	fi
	count=$((count - 1))
done

echo biggest line count is $biggest
echo input: $biggest_input
