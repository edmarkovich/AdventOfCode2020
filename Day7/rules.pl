

bags(X) :- findall(A, has(A,_), X).

contains(Bag, -, 0) :- has(Bag,  []).

contains(Bag, Target, 1) :-
              has(Bag, InnerBags),
              member([_,Target], InnerBags).
              
contains(Bag, Target, 1) :-
              has(Bag, InnerBags),
              member([_,X], InnerBags),
              contains(X, Target, 1).


contains(Bag, Target, 0) :-
              has(Bag, InnerBags),
              not(member([_,X], InnerBags)),
              contains(X, Target, 0).

count(Out) :-
         findall(X, contains(X, shiny_gold, 1), Out1),
         sort(Out1, Out2),
         length(Out2, Out).
         
/* Part Two */

contents([], 0).
contents([[Count, Bag]|T], Out) :-
              bag_plus_contents(Bag, Out1),
              Out2 is Out1 * Count,
              contents(T, Out3),
              Out is Out2 + Out3.

              
bag_plus_contents(B, Out) :-
     has(B, Contents),
     contents(Contents, Out1),
     Out is Out1 +1 .
     % Don't forget to subtract one from final answer since we don't count top-level bag"



