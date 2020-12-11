
seat_row([F|_], RangeA, _, 10, Out) :-
	char_code('F', F),
	Out is (RangeA).

seat_row([B|_], _, RangeB, 10, Out) :-
	char_code('B', B),
	Out is (RangeB).


seat_row([F|T], RangeA, _, 7, Out) :-
	char_code('F', F),
	seat_row(T, 0, 7, 8, Out1),
	Out is (RangeA * 8) + Out1.

seat_row([B|T], _, RangeB, 7, Out) :-
	char_code('B', B),
	seat_row(T, 0, 7, 8, Out1),
	Out is (RangeB * 8) + Out1.

seat_row([F|T], RangeA, RangeB, Position, Out) :-
	Position \= 7,
	Position \= 10,
	char_code('F', F),
	NewEnd is floor( (RangeA + RangeB) / 2),
	NewPosition is Position+1,
	seat_row(T, RangeA, NewEnd, NewPosition, Out).

seat_row([B|T], RangeA, RangeB, Position, Out) :-
	Position \= 7,
	Position \= 10,
	char_code('B', B),
	NewStart is ceiling( (RangeA + RangeB) / 2),
	NewPosition is Position+1,
	seat_row(T, NewStart, RangeB, NewPosition, Out).




seat(Out) :-
	input(Input),
	member(I, Input),
	string_codes(I, I2),
	seat_row(I2, 0, 127, 1, Out).




maxseat(Out) :-
	bagof(X, seat(X),  Out1),
	max_list(Out1, Out).

missingid([H|_], Index, Index) :-
	Index \= H.

missingid([H|T], H, Out) :-
	NextIndex is H+1,
	missingid(T, NextIndex, Out).


missingid(Out) :-
	bagof(X, seat(X),  Out1),
	sort(Out1, Out2),
	missingid(Out2, 91, Out).
