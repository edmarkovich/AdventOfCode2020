cat data.txt |
     sed "s/bag[s]*[ ]*//g"                            | # get rid of word bag/bags
     sed -E "s/^([a-z]*) ([a-z]*)/\1_\2/g"             | # put underscore in tgt col name
     sed "s/no other//g"                               | # special case - empty
     sed -E "s/([0-9]+) ([a-z]+) ([a-z]+)/\1 \2_\3/g"  | # put underscore in tgt col name
     sed "s/contain/,\t[/g"                            | # write as rule
     sed "s/^/has\(/g"                                 |
     sed -E "s/ , ([0-9])/\],\[\1/g"                   | # put braces around pairs
     sed -E "s/([a-z]) .$/\1\] ./"       |
     sed -E "s/\[ ([0-9])/\[\[\1/g"                    |
     sed "s/.$/]\)./g"                                 | # end of line cleanup
     sed -E "s/([0-9]+)/\1,/g"                         | # commans inside pairs
     cat  > trans.pl
