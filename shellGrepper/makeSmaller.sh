#!/bin/bash

filename="names.txt"
while read -r line
do
	name=$line
	tr -d "\n" < sites/${name}.html > sites/${name}.tmp
	mv sites/${name}.tmp sites/${name}.html
done < "$filename"

sed -i 's/<script.*script>//' sites/*.html
sed -i 's/<script.*script>//' sites/*.html
sed -i 's/<script.*script>//' sites/*.html