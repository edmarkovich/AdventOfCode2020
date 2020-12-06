
count(_, [], 0).

count(Letter, [Letter|T], Out) :-
	count(Letter, T, Out1),
	Out is 1 + Out1.

count(Letter, [L|T], Out) :-
	L \= Letter,
	count(Letter, T, Out).
	

count_str(Letter, String, Out) :-
	string_codes(String, Codes),
	char_code(Letter, Code),
	count(Code,Codes, Out).


validPw(Min, Max, Letter, Pass) :-
	count_str(Letter, Pass, Count),
	Count =< Max,
	Count >= Min.

vpw(A,B,C,D) :-
	pw(A,B,C,D),
	validPw(A,B,C,D).

answer(Count) :- aggregate_all(count, vpw(A,B,C,D), Count).

% Part 2

is_nth(_     , []        , _, 0).
is_nth(Letter, [Letter|T], 1, 1).
is_nth(Letter, [H|T],      1, 0) :- H \= Letter.
is_nth(Letter, [H|T],      N, Out) :-
	N > 1,
	N1 is N - 1,
	is_nth(Letter, T, N1, Out).


validPw2(A,B,Letter,Pass) :-
        string_codes(Pass, Codes),
        char_code(Letter, Code),
	is_nth(Code, Codes, A, Q1),
	is_nth(Code, Codes, B, Q2),
	Q is Q1 + Q2,
	Q=1.

vpw2(A,B,C,D) :-
        pw(A,B,C,D),
        validPw2(A,B,C,D).


answer2(Count) :- aggregate_all(count, vpw2(A,B,C,D), Count).




