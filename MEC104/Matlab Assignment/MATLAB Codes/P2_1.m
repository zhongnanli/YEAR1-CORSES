%Problem 2
%P5-1
clear all
close all
clc

%(a)
[t,x]=ode45(@Motion1,[0 10],[0.5 0]);
subplot(3,1,1);
plot(t,x(:,1),'r-');
xlabel('time(t)')
ylabel('angle')
title('Plot of Problem 2 P5-1')

%(b)
[t,x]=ode45(@Motion2,[0 10],[3 0]);
subplot(3,1,2);
plot(t,x(:,1),'b-');
xlabel('time(t)')
ylabel('angle')

%(c)
[t,x]=ode45(@Motion3,[0 10],[3 0]);
subplot(3,1,3);
plot(t,x(:,1),'k-');
xlabel('time(t)')
ylabel('angle')

function [xdot]= Motion1(t,x)
g=9.81;
L=1;
a=5;
xdot=zeros(2,1);
xdot(1)=x(2);
xdot(2)=a*cos(x(1))/L-g*sin(x(1))/L;
end

function [xdot]= Motion2(t,x)
g=9.81;
L=1;
a=5;
xdot=zeros(2,1);
xdot(1)=x(2);
xdot(2)=a*cos(x(1))/L-g*sin(x(1))/L;
end

function [xdot]= Motion3(t,x)
g=9.81;
L=1;
a=0.5*t;
xdot=zeros(2,1);
xdot(1)=x(2);
xdot(2)=a*cos(x(1))/L-g*sin(x(1))/L;
end