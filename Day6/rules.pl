


group_answers([], []).
group_answers([H|T], Out) :-
                     %H/T are current and next person in the group
                     group_answers(T, Out1),
                     string_chars(H, H1),
                     append(H1, Out1, Out2),
                     sort(Out2, Out).
                     
all_groups(X) :-
              input(Input),
              member(Q, Input),
              group_answers(Q, Y),
              length(Y, X).
              
all_lengths(X) :-
               bagof(Q, all_groups(Q), T),
               sum_list(T, X).
