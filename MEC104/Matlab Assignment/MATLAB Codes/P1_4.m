%Problem 1 Matrix Operation
%P1-4
clear all
close all
clc

R1=0.036;
R2=4.01;
R3=0.408;
R4=0.038;
Ti=20;
T0=-10;

A=[R1 1 0 0;R2 -1 1 0;R3 0 -1 1;R4 0 0 -1];
B=[Ti;0;0;-T0];
X=A\B;
q1=X(1);
q2=X(1)*10;
T1=X(2);
T2=X(3);
T3=X(4);
disp("The other three temperatures T1, T2, T3 and heat loss rate q is:");
disp("T1=");disp(T1);
disp("T2=");disp(T2);
disp("T3=");disp(T3);
disp("q=");disp(q1);
disp("If the wall's area is 10 m2, q=");disp(q2);