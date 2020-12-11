
echo "input(["
cat data.txt | 
	sed "s/^/\"/g" | 
	sed "s/$/\",/g" |
	sed '$ s/.$//'
echo "])."

