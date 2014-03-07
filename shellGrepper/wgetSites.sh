#!/bin/bash

mkdir sites
site="http://www.mineralienatlas.de/lexikon/index.php/"
filename1="links.txt"
filename2="names.txt"

while read -r a && read -r b <&3; do
	link=$a
	name=$b
	wget -q -O "sites/${name}.html" $site$link
done < "$filename1" 3<"$filename2"