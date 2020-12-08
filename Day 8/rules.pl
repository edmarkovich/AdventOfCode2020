
special_line(Number, Cmd, Inc, Number) :-
   line(Number, "jmp", Inc),
   Cmd = "nop".
   
special_line(Number, Cmd, Inc, Number) :-
   line(Number, "nop", Inc),
   Cmd = "jmp".
   
special_line(Number, Cmd, Inc, _) :-
   line(Number, Cmd, Inc).

state(Line_Num, Seen_Lines, _, "XXX",_) :-
  member(Line_Num, Seen_Lines),
  !.

state(639, _, Acc, Acc,_).

state(Line_Num, Seen_Lines, Acc, Result, Magic) :-

  special_line(Line_Num, "nop", _, Magic),

  New_Line is Line_Num + 1,
  New_Seen = [Line_Num|Seen_Lines],

  state(New_Line, New_Seen, Acc, Result, Magic).


state(Line_Num, Seen_Lines, Acc, Result, Magic) :-

  special_line(Line_Num, "jmp", Increment, Magic),

  New_Line is Line_Num + Increment,
  New_Seen = [Line_Num|Seen_Lines],

  state(New_Line, New_Seen, Acc, Result, Magic).

state(Line_Num, Seen_Lines, Acc, Result, Magic) :-

  special_line(Line_Num, "acc", Increment, Magic),
  New_Acc is Acc + Increment,
  
  New_Line is Line_Num + 1,
  New_Seen = [Line_Num|Seen_Lines],
  
  
  state(New_Line, New_Seen, New_Acc, Result, Magic).
  
answer(X) :-
          state(1,[],0,X,_),
          X \= "XXX".

