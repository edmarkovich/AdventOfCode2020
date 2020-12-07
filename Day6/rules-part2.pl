

everyone_has(_, [], 1).

everyone_has(What, [Person|_], 0) :-
                   string_codes(Person, Person1),
                   not(member(What, Person1)).

everyone_has(What, [Person|Rest], 1) :-
                   string_codes(Person, Person1),
                   member(What, Person1),
                   everyone_has(What, Rest, 1).
                   
everyone_has(What, [Person|Rest], 0) :-
                   string_codes(Person, Person1),
                   member(What, Person1),
                   everyone_has(What, Rest, 0).

shared_count([], _, 0).
shared_count([Answer|Rest], Group, Score) :-
                            everyone_has(Answer, Group, Out1),
                            shared_count(Rest, Group, Out2),
                            Score is Out1 + Out2.


group_score([Person|Rest], Score) :-
                           string_codes(Person, Person1),
                           shared_count(Person1, Rest, Score).



all_groups_score(X) :-
              input(Input),
              member(Q, Input),
              group_score(Q, X).

all_groups(X) :-
               bagof(Q, all_groups_score(Q), T),
               sum_list(T, X).

