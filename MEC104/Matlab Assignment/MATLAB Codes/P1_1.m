%Problem 1 Matrix Operation
%P1-1
clear all
close all
clc

A=[3 7 -4 12;-5 9 10 2;6 13 8 11;15 5 4 1];
%(a)
disp('a) The vector v consisting of the elements in the second column of A is:');
v=A(:,2);
disp(v);
%(b)
disp('b) The vector w consisting of the elements in the second row of A is:');
w=A(2,:);
disp(w);
%(c)
disp('c) The array B consisting of all elements in the second through fourth columns of A is:');
B=A(:,2:4);
disp(B);
%(d)
disp('d) The array C consisting of all elements in the second through fourth rows of A is:');
C=A(2:4,:);
disp(C);
%(e)
disp('e) The array D consisting of all elements in the first two rows and the last three columns of A is:');
D=A(1:2,2:4);
disp(D);