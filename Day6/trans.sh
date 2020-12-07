echo "input([["
cat data.txt       |
  #sed "s/^$/],[/g" |
  sed "s/^/\"/g"    |
  sed "s/$/\",/g"   |
  tr -d '\n'  |
  sed "s/,\"\",/], [/g" |
  sed "s/.$//g"
echo "]])."
