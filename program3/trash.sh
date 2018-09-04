#!/bin/bash
FILE=$1
mkdir -p $PWD/TRASH
if [ -f $FILE ]
then
	mv $FILE $PWD/TRASH
else
	echo "No file found with $FILE"
fi
