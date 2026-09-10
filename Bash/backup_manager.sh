#!/bin/bash

LOGFILE="$HOME/.backup_log"
BACKUPDIR="$HOME/.backups"

write_log() {
	printf "$1 " >> "$LOGFILE"
	echo $2 | tee -a "$LOGFILE"
}

show_log() {
	if [[ ! -f "$LOGFILE" ]]
	then echo "No Log yet."; return 1
	fi
	cat "$LOGFILE"
}

create_backup() {
	printf "Enter Source Path: "
	read src
	dt=$(date "+%Y-%m-%d-%H:%M:%S")
	if [[ ! -e "$BACKUPDIR" ]]
	then	mkdir "$BACKUPDIR" > /dev/null
		if [[ ! $? -eq 0 ]]
		then write_log $dt "ERROR: Could not create Backup Directory"; return 1
		fi
	elif [[ ! -e "$src" ]]
	then write_log $dt "ERROR: $(realpath $src) does not exist"; return 1
	fi
	tar -cf "$BACKUPDIR/$(basename $src)-$dt" "$src" > /dev/null
	if [[ ! $? -eq 0 ]]
	then write_log $dt "ERROR: Failed to create Backup"; return 1
	fi
	write_log $dt "Successfully Backed up $(realpath $src)"
}

echo "===== BACKUP Manager ====="

select i in "Create Backup" "Show Backup History" "Check Backup" "Exit"
do	case $REPLY in
	1)	create_backup;;
	2)	show_log;;
	4)	echo "Goodbye!"
		exit;;
	*)	echo "Invalid Option."
		continue;;
	esac
done
