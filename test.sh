#!/bin/bash                                                                    #
# test.sh                                                                      #
# mpuig-ma <mpuig-ma@student.42barcelona.com>                                  #
# Tue Nov 21 15:13:11 2023                                                     #

function quit_tester
{
	kill -s KILL "$pid"
	printf "Ciao\n"
	exit 1
}

function execute
{
	./cub3D "$1" 1>/dev/null 2>/dev/null &
	pid=$!
	wait $pid
	if [ $? -eq 0 ]
	then
		return 0
	else
		return 1
	fi
}

stty -echoctl
trap 'quit_tester' SIGINT

for FILE in maps/invalid_*
do
	if execute "$FILE" -eq 0
	then
		printf "\033[0;31mKO: %s\033[0m\n" "$FILE"
	else
		printf "\033[0;32mOK: %s\033[0m\n" "$FILE"
	fi
done

for FILE in maps/valid_*
do
	if ! execute "$FILE" -eq 0
	then
		printf "\033[0;31mKO: %s\033[0m\n" "$FILE"
	else
		printf "\033[0;32mOK: %s\033[0m\n" "$FILE"
	fi
done
