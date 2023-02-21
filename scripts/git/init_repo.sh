#!/bin/bash

_folder_init() {
	if [ -d ".git" ]; then
		echo "This folder is already a github repository !"
		exit 84
	fi

	echo "Please paste git repository link:"
	read link
	git init
	git add .
	git commit -m "Hello, world !"
	git branch -M main
	git remote add origin $link
	git push -u origin main
	exit 0
}

echo "Make the current folder a github repository ? (y/a)"
read status
if [ $status == 'y' ]; then
	_folder_init
else
	echo "aborted"
fi
