echo -n "input([[\""
cat data.txt | sed "s/^$/END/g" | 
	sed "s/ /\n/g" | 
	tr '\n' ' ' | 
	sed "s/ END /\"],\n[\"/g" | 
	sed "s/ /\",\"/g" |
	sed '$ s/.\"$//'
echo "]])."
