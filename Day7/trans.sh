cat data.txt |
     sed "s/bag[s]*[ ]*//g"                            | # get rid of word bag/bags
     sed -E "s/^([a-z]*) ([a-z]*)/\1_\2/g"             | # put underscore in tgt col name
     sed "s/no other//g"                               | # special case - empty
     sed -E "s/([0-9]+) ([a-z]+) ([a-z]+)/\1 \2_\3/g"  | # put underscore in tgt col name
     sed "s/contain/,\t[/g"                             | # write as rule
     sed "s/^/has\(/g" |
     sed "s/.$/]\)./g"      |
     tr -d "0123456789" |  # get rid of bad color counts. will prolly need for part 2
     cat > trans.pl
