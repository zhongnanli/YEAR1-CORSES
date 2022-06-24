%Problem 5
clear all;
close all;
clc;

%Define parameter lamda
lamda=1;
%Define h for mesh size
h=input('Please specify the mesh size: ');
%Define parameters for computational domain 
a=input('Please specify the boundary for x- dimension: ');
b=input('Please specify the boundary for y- dimension: ');
%Define parameter omega
omega=2/(1+sqrt(1-((cos(pi/(a/h))+cos(pi/(b/h)))/2)^2));
%Define numbers of divided length in x & y directions
m1=a/h;
m2=b/h;
%Nodes in x & y directions
hx=m1+1;
hy=m2+1;
%Define and initialize a matrix for voltage u
u=ones(hy,hx);
%Define boundary conditions
u(1,:)=input('Please specify boundary condition for y= 0: '); 
u(hy,:)=input('Please specify boundary condition for y = b: ');
u(:,1)=input('Please specify boundary condition for x= 0: '); 
u(:,hx)=input('Please specify boundary condition for x = a: ');
%Define domain of the figure
x=0:h:a;
y=0:h:b;
%Call Voltage function to calculate and return the result matrix
u2 = Voltage (hx,hy, omega, u);
%Draw the coordinates and the graph
[X1,Y1]=meshgrid(x,y); 
subplot(1,2,1)
mesh(X1,Y1,u2)
axis([0 a 0 b])
%Define show the coordinates labels
xlabel('Dimension x(cm)') 
ylabel('Dimension y(cm)') 
zlabel('Voltage Phi(V)')

%Draw the colored Top view figure
subplot(1,2,2)
contour(u2,32)
[C,h]=contour(X1,Y1,u2 );
clabel(C, h)
%Define show the coordinates labels
xlabel('Dimension x(cm)') 
ylabel('Dimension y(cm)') 

%Finite Difference Method
function u2 = Voltage(hx,hy,omega,u) 
m=1;%error value
k=0;%count for the times in loops
u2=u;%copy the matrix to the result matrix
while(m>10e-5)
 k=k+1;
 m=0;
 for j=2:hx-1
  for i=2:hy-1
   %apply iterative equation
   u2(i,j)=u(i,j)+omega*0.25*(u2(i-1,j)+u(i+1,j)+u2(i,j-1)+u(i,j+1)-4*u(i,j));
   t=(abs(u2(i,j)-u(i,j)));%calculate error
   if(t>m)%compare to last error
    m=t;%pass error value
   end
  end
 end
u=u2;%pass the calculated values to the last matrix
end
display(k)%show loop times
end
