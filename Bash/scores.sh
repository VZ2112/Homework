#!/bin/bash

validate_score() {
	if [[ "$1" -eq -1 ]]
	then	echo "Goodbye."
		exit
	elif [[ "$1" -gt -1 && "$1" -lt 101 ]]
	then return 0
	else return 1
	fi
}

get_grade() {
	if [[ "$1" -lt 60 ]]
	then echo F
	elif [[ "$1" -lt 70 ]]
	then echo D
	elif [[ "$1" -lt 80 ]]
	then echo C
	elif [[ "$1" -lt 90 ]]
	then echo B
	else echo A
	fi
}

is_passed() {
	if [[ "$1" -lt 60 ]]
	then return 1
	else return 0
	fi
}

print_result() {
	echo $'\nStudent:' " $1"
	echo "Score: $2"
	echo "Grade: $3"
	printf "Status: "
	if is_passed $2
	then echo "Passed"
	else echo "Failed"
	fi
}

while true
do	printf "\nEnter Name: "
	read name
	printf "Enter Score: "
	read score
	until validate_score $score
	do	echo $'\nInvalid Score.'
		printf "Enter a valid Score: "
		read score
	done
	grade=$(get_grade "$score")
	print_result "$name" "$score" "$grade"
done
