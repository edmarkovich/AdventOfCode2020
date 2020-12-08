cat -n data.txt | 
sed "s/^ */line(/g" | 
sed "s/\s/,/g" | 
sed "s/$/)./g" |
sed -E "s/,(.+),/,\"\1\",/g" > trans.pl