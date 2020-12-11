cat data.txt | tr "\- " "," | tr -d ':' | sed "s/^/pw(/g" | sed "s/$/)./g" > trans.txt
