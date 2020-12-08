
state(Line_Num, Seen_Lines, Acc, Acc) :-
  member(Line_Num, Seen_Lines),
  !.



state(Line_Num, Seen_Lines, Acc, Result) :-

  line(Line_Num, "nop", _),
  write("NOP"),

  New_Line is Line_Num + 1,
  New_Seen = [Line_Num|Seen_Lines],

  state(New_Line, New_Seen, Acc, Result).


state(Line_Num, Seen_Lines, Acc, Result) :-

  line(Line_Num, "jmp", Increment),
  write("JMP"),

  New_Line is Line_Num + Increment,
  New_Seen = [Line_Num|Seen_Lines],

  state(New_Line, New_Seen, Acc, Result).

state(Line_Num, Seen_Lines, Acc, Result) :-

  line(Line_Num, "acc", Increment),
  New_Acc is Acc + Increment,
  write("ACC"),
  
  New_Line is Line_Num + 1,
  New_Seen = [Line_Num|Seen_Lines],
  
  
  state(New_Line, New_Seen, New_Acc, Result).

