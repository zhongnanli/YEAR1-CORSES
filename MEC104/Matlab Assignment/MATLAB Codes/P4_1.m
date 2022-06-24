%Problem 4
clear all;
close all;
clc;

A1 = 3;%A2 Bottom Area of Tank 1 
A2 = 5;%A2 Bottom Area ot Tank 1
R_L1= 1E6;%No flow through the left-hand inlet 
R_R1 = 30;% ftA(-1)*sA(-1)
R_L2=30;%0ne resistance between tanks: R_R1= RL2=R1 
R_R2 = 40;% ftA(-1)*sA(-1)
rho = 1.94;% kg/m3
g= 32.2;% m/s2
h01 = 2;%Initial height in Tank 1 
h02 = 5;%Initial height in Tank 1 
qmi1 = 0.5;%Input flow into Tank 1
timestep1 = 0;%Time when Input flow into Tank 1 is turned on
