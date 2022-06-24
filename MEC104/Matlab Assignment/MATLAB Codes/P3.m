%Problem 3
clear all
close all
clc

%(a) Motor current
[ta,xa]=ode45(@Current1,[0 0.16],[0,0]);
subplot(4,1,1) 
plot(ta,xa(:,1))
xlabel('Time (sec)')
ylabel('Motor current(A)')
title('Plots of Problem 3')

% Rotational velocity
[ta,xa]=ode45(@Current1,[0 0.16],[0,0]);
subplot(4,1,2) 
plot(ta,xa(:,2))
xlabel('Time (sec)')
ylabel('Rotational velocity (rad/sec)')

%(b) Rotational velocity
[tb,xb]=ode45(@Current2,[0 0.3],[0,0]);
subplot(4,1,3)
plot(tb,xb(:,2))
xlabel('Time (sec)')
ylabel('Rotational velocity (rad/sec)')

% Applied Motor voltage
t=linspace(0,0.3,1000);
for k= 1:1000
if t(k)<0.05
v(k)=400*t(k);
elseif t(k)>0.05 && t(k)<=0.2
v(k)=20;
elseif t(k)>0.2 && t(k)<=0.25
v(k)=-400*(t(k)-0.2)+ 20; 
else
v(k)= 0; 
end 
end

subplot(4,1,4)
plot(t,v)
xlabel('Time (sec)')
ylabel('Applied Motor voltage(v)') 
axis([0 0.3 0 25])

function xdot = Current1(t,x)
R=0.8;
L=0.003;
Kt=0.05;
Ke=0.05;
c=0;
J=8*10^-5;
v=20;
A=[-R/L -Ke/L;Kt/J -c/J]; 
B=[1/L;0];
xdot=A*x+B*v;
end


function xdot = Current2(t,x)
R=0.8;
L=0.003;
Kt=0.05;
Ke=0.05;
c=0;
J=8*10^-5;
A = [-R/L -Ke/L;Kt/J -c/J];
for k= 1:1000
if t<0.05
v=400*t;
elseif t>0.05 && t<=0.2
v=20;
elseif t>0.2 && t<=0.25
v=-400*(t-0.2)+20;
else
v=0;
end 
B=[1/L; 0];
xdot=A*x+B*v;
end
end