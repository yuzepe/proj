#!/bin/bash

touch links.txt
touch names.txt
site="http://www.mineralienatlas.de/lexikon/index.php/"
abc="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for i in `seq 1 26`;
do
	letter=$(echo $abc | head -c $i | tail -c 1)
	wget -q -O letter.html ${site}Mineralien-$letter
	grep -Eo '(MineralData\?mineral=)[^<]+' letter.html > linksnames.tmp
	grep -Eo '^[^"]+' linksnames.tmp >> links.txt
	grep -Eo '[^>]+$' linksnames.tmp >> names.txt
done

rm -f linksnames.tmp letter.html
