%Problem 2
%P5-2
clear all
close all
clc

%(a)
[ta,xa]= ode45(@Spring1,[0 20],[0,0]);
subplot(3,1,1)
plot(ta, xa(:,1),'r-')
ylabel('Position (m)')
title('Plot of Problem 2 P5-2')
text(0.3,-0.15,'\omega = 1.0 rad/s')

%(b)
[tb,xb]= ode45(@Spring2,[0 20],[0,0]);
subplot(3,1,2) 
plot(tb,xb(:,1),'b-') 
ylabel('Position (m)')
text(0.3,-5,'\omega = 5.0 rad/s')

%(c)
[tc,xc]= ode45(@Spring3,[0 20],[0,0]);
subplot(3,1,3) 
plot(tc,xc(:,1),'k-')
xlabel('Time t(sec)'),ylabel('Position (m)') 
text(0.3,-0.1,'\omega = 10.0 rad/s')

function [xdot]=Spring1(t,x)
omega=1; 
u=10*sin(omega*t);
xdot(1)=x(2);
xdot(2)=-75*x(1)/3-0*x(2)/3+1*u/3;
A=[0 1;-75/3 -0/3]; 
B=[0;1/3];
xdot=A*x+B*u;
end

function [xdot]=Spring2(t,x)
omega=5; 
u=10*sin(omega*t);
xdot(1)=x(2);
xdot(2)=-75*x(1)/3-0*x(2)/3+1*u/3;
A=[0 1;-75/3 -0/3]; 
B=[0;1/3];
xdot=A*x+B*u;
end

function [xdot]=Spring3(t,x)
omega=10; 
u=10*sin(omega*t);
xdot(1)=x(2);
xdot(2)=-75*x(1)/3-0*x(2)/3+1*u/3;
A=[0 1;-75/3 -0/3]; 
B=[0;1/3];
xdot=A*x+B*u;
end