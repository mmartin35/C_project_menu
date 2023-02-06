#!/bin/bash
today=$(date +%d/%m/%Y)
time=$(date +"%T")
div=/*
div2=*/
email=matthieu1.martin@epitech.eu

/usr/bin/clear
_select_title(){

    # User input.
    printf "Write down the title of your project: " ; read -r title

    # Remove spaces.
    title=${title// /_}

    # Convert upper to lower.
    title=${title,,}

    # Add .c to the end.
    [ "${title: -3}" != '.c' ] && title=${title}.c

    # Check if file exists.
    if [ -e $title ] ; then 
        printf "\n%s\n%s\n\n" "The script \"$title\" already exists." \
        "Choose another name."
        _select_title
    fi
}

_select_title

# Format the output.
printf "%-2s\n\
%-0s%-0s\n\
%-0s%-0s\n\
%-19s%-0s\n\
%-19s%-0s\n\
%-19s%-0s\n\
%-19s%-0s\n\
%s\n" \
"${div}" "** EPITECH PROJECT, 2022" '' '** Title' ": $title" '** File description:' \
"" "** <------------------------------------------->" '' '** Made by' ": $email" '** Creation date' ": $today at $time" \
"${div2}" > $title

/usr/bin/clear
