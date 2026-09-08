#!/bin/bash

LOG=$HOME/track_log

if [[ $# -lt 1 ]]
then	echo "Usage: run_track.sh <command>"
	exit 2
fi

com=""

for i in "$@"
do com+=" \"$i\""
done

echo $(($# - 1)) "Argument(s) passed"
echo "$0:" "$@" >> $LOG

stat=0

for i in {1..3}
do	printf "Attempt $i: " | tee -a $LOG
	echo "$@"
	"$@" || stat=$?

	if [[ $stat -eq 0 ]]
	then	echo "Succeedded at attempt $i"
		echo "Success." >> $LOG
		break
	fi
	echo "Failed." >> $LOG
	sleep $(($RANDOM % 3))
done

echo "PID: $$"
echo "PPID: $PPID"
if [[ stat -ne 0 ]]
then echo "Command failed with exit code $stat" | tee -a $LOG
fi
