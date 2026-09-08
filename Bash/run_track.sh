#!/bin/bash

if [[ $# -lt 1 ]]
then	echo "Usage: run_track.sh <command>"
	exit 2
fi

com=""

for i in "$@"
do com+=" \"$i\""
done

echo $(($# - 1)) "Argument(s) passed"

stat=0

for i in {1..3}
do	echo "Attempt $i:" "$@"
	"$@" || stat=$?

	if [[ $stat -eq 0 ]]
	then	echo "Succeedded at attempt $i"
		break
	fi
	sleep $(($RANDOM % 3))
done

echo "PID: $$"
echo "PPID: $PPID"
if [[ stat -ne 0 ]]
then echo "Command failed with exit code $stat"
fi
