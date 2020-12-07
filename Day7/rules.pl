%consult("trans.rl").

bags(X) :- findall(A, has(A,_), X).

contains(Bag, -, 0) :- has(Bag,  []).

contains(Bag, Target, 1) :-
              has(Bag, InnerBags),
              member(Target, InnerBags).
              
contains(Bag, Target, 1) :-
              has(Bag, InnerBags),
              member(X, InnerBags),
              contains(X, Target, 1).


contains(Bag, Target, 0) :-
              has(Bag, InnerBags),
              not(member(X, InnerBags)),
              contains(X, Target, 0).

count(Out) :-
         findall(X, contains(X, shiny_gold, 1), Out1),
         sort(Out1, Out2),
         length(Out2, Out).
         
