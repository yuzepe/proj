#!/bin/bash

rm -f namelinks.txt
site="http://www.mineralienatlas.de/lexikon/index.php/"
abc="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for i in `seq 1 26`;
do
	letter=$(echo $abc | head -c $i | tail -c 1)
	wget -q -O letter.html ${site}Mineralien-$letter
	grep -Eo '(MineralData\?mineral=)[^<]+' letter.html >> namelinks.txt
done

rm -f letter.html

touch materials.dat
filename="namelinks.txt"
while read -r line
do
	link=$(echo $line | grep -Eo '^[^"]+')
	name=$(echo $line | grep -Eo '[^>]+$')
	wget -q -O site.html $site$link
	density=$(grep -E '(Dichte)' -A 1 site.html | grep -Eo '[0-9]+\.[0-9]+' | grep -m 1 ".*")
	echo "$name $density" >> materials.dat
done < "$filename"

rm -f site.html
