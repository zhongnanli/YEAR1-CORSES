%Problem 1 Matrix Operation
%P1-3
clear all
close all
clc

A=[1/sqrt(35) -3/sqrt(34) 1/sqrt(42);3/sqrt(35) 0 -4/sqrt(42);5/sqrt(35) 5/sqrt(34) 5/sqrt(42)];
B=[0;0;1];
T=A\B;
T1=T(1);
T2=T(2);
T3=T(3);
fprintf("T1,T2,T3 in terms of an unspecified value of the weight mg is: %dmg, %dmg, %dmg",T1,T2,T3);