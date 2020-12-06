
year_in([58,A,B,C,D], Min, Max, 1) :-
	Year is (A-48)*1000 + (B-48)*100 + (C-48)*10 + (D-48),
	Year >= Min,
	Year =< Max,
	!.
	
year_in(_,_,_,0).

hgt_ok([58,X,Y,Z,C,M], 1) :-
	char_code('c', C), char_code('m',M),
	Hgt is (X-48)*100 + (Y-48)*10 + (Z-48),
	Hgt >= 150, Hgt =< 193,
	!.

hgt_ok([58,Y,Z,C,M], 1) :-
	char_code('i', C), char_code('n',M),
	Hgt is (Y-48)*10 + (Z-48),
	Hgt >= 59, Hgt =< 76,
	!.
	
hgt_ok(_,0).


valid_hex("1234567890abcdef").

hcl_ok([58, Hash, A1, A2, A3, A4, A5, A6], 1) :-
	char_code('#',Hash),
	valid_hex(ValidHex),
	string_codes(ValidHex, ValidHexCode),
	member(A1, ValidHexCode),
	member(A2, ValidHexCode),
	member(A3, ValidHexCode),
	member(A4, ValidHexCode),
	member(A5, ValidHexCode),
	member(A6, ValidHexCode),
	!.
	
hcl_ok(_,0).

ecl_ok([58|T], 1) :-
	string_codes(String, T),
	member(String, ["amb", "blu", "brn", "gry","grn","hzl","oth"]),
	!.
ecl_ok(_,0).

digit(X) :-
	member(X, [48,49,50,51,52,53,54,55,56,57]).

id_ok([58,A1,A2,A3,A4,A5,A6,A7,A8,A9], 1) :-
	digit(A1),
	digit(A2),
	digit(A3),
	digit(A4),
	digit(A5),
	digit(A6),
	digit(A7),
	digit(A8),
	digit(A9),
	!.
id_ok(_,0).



% cid
count_field([99,105,100|_], 0) :- !.

%byr
count_field([98,121,114|T], Out) :-
	year_in(T, 1920, 2002, Out),
	!.
	
%iyr
count_field([105,121,114|T], Out) :-
	year_in(T, 2010, 2020, Out),
	!.

%eyr
count_field([101,121,114|T], Out) :-
	year_in(T, 2020, 2030, Out),
	!.	

%hgt	
count_field([104,103,116|T], Out) :-
	hgt_ok(T, Out),
	!.	

%hcl	
count_field([104,99,108|T], Out) :-
	hcl_ok(T, Out),
	!.	

%ecl
count_field([101,99,108|T], Out) :-
	ecl_ok(T, Out),
	!.	
	
%pid
count_field([112,105,100|T], Out) :-
	id_ok(T, Out),
	!.	
	

count_field([A,B,C|_], 0). % :-
	%A\=99 ; B\=105 ; C \= 100.

count_field_string(String, Out) :-
	string_codes(String, Codes),
	count_field(Codes, Out).


count_fields([], 0).

count_fields([H|T], Out) :-
	count_field_string(H, Out1),
	count_fields(T, Out2),
	Out is Out1 + Out2.
	
	
valid_line(Line, 1) :-
	count_fields(Line, 7).
	
valid_line(Line, 0) :-
	count_fields(Line, X),
	X < 7.
	
valid_lines([], 0).

valid_lines([H|T], Out) :-
	valid_line(H, Out1),
	valid_lines(T, Out2),
	Out is Out1 + Out2.
	
valid_input(Out) :-
	input(Input),
	valid_lines(Input, Out).



	
	