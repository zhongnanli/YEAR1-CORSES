%Problem 1 Matrix Operation
%P1-2
clear all
close all
clc

A=[1 4 2;2 4 100;7 9 7;3 pi 42];
B=log(A);
%(a)
disp('a) The second row of B is: ')
a=B(2,:);
disp(a);
%(b)
disp('b) The sum of the second row of B is: ');
disp(sum(a));
%(c)
disp('c) The product of the second column of B multiply the first column of A element by element is: ');
disp(B(:,2).*A(:,1));
%(d)
disp('d) The maximum value in the vector resulting from question c) is: ');
disp(max(B(:,2).*A(:,1)));
%(e)
disp('e) the sum of the elements of the resulting vector is:');
disp(sum(sum(A(1,:)./B(1:3,3))));