#!/bin/bash

touch materials.dat
filename="names.txt"
while read -r line
do
	name=$line
	density=$(grep -E '(Dichte)' -A 1 sites/${name}.html | grep -Eo '[0-9]+\.[0-9]+' | grep -m 1 ".*")
	echo "$name $density" >> materials.dat
done < "$filename"