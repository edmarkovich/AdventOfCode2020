

getData(X,Y) :- mydata(A), member(X, A), member(Y,A), 2020 is X + Y.
getData(X,Y,Z) :- mydata(A), member(X, A), member(Y,A), member(Z,A), 2020 is X + Y + Z.
