is_tree(35, 1).
is_tree(X,  0) :- X \= 35.

is_tree(Row, Col, Out) :-
	input(Input),
	nth0(Row, Input, LineA),
	string_codes(LineA, LineB),
	length(LineB, Length),
	ColB is mod(Col, Length),
	nth0(ColB, LineB,  Character),
	is_tree(Character, Out).
	

count_trees(Row,_,0,_,_) :-
	input(Input),
	length(Input, L),
	Row >= L.

count_trees(Row, Col, Out, Run, Rise) :-
	input(Input),
	length(Input, L),
	Row < L,
	is_tree(Row, Col, Out1),
	NextRow is Row + Rise,
	NextCol is Col + Run,
	count_trees(NextRow, NextCol, Out2, Run, Rise),
	Out is Out1 + Out2.
	
	
