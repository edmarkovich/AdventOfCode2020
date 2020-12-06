echo "input(["
cat data.txt | 
	sed "s/^/\"/g" |
	sed "s/$/\",/g" |
	sed "$ s/.$//g" |
	tr 'L' 'F' |
	tr 'R' 'B'
echo "])."
