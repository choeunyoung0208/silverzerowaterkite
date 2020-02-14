%2)System Solution and Simulation

close all 
%close : ������ Figure ����
%close all�� �ڵ��� �������� ���� ��� Figure�� �����մϴ�. �ڵ��� �����ϱ�..? �˾ƺ��ô�
clear all
%�۾� �������� �׸��� �����Ͽ� �ý��� �޸� �ø���
%clear�� ���� �۾� �������� ��� ������ �����Ͽ� �ý��� �޸𸮿��� �����մϴ�.
clc

%Initilization
th_int=[-pi/2 pi/2]; %initial positions
ths=[pi/2 -pi/2]; %set-points => final positions

x0=[0 0 th_int 0 0 0 0]; %states initial values(�ʱⰪ) 
%�ʱⰪ�� �̿��ؼ� ODE�� �����(���л�� �����͵�)�� Ư�������� ��������
Ts=[0 20]; %time span

%Robot Specifications
L1=1; %link 1
L2=1; %link 2
M1=1; %mass 1
M2=1; %mass 2
spec=[L1 L2 M1 M2];

%PID Parameters
%PID parameters for theta 1
Kp1=15;
Kd1=7;
Ki1=10;
%PID parameters for theta 2
Kp2=15;
Kd2=10;
Ki2=10;

Kpid=[Kp1 Kd1 Ki1 Kp2 Kd2 Ki2];

%ODE solving
%ode45 �� ����� ODE Ǯ��
%[t,y] = ode45(odefun,tspan,y0)
%odefun : Ǯ����� ode�Լ�
%tspan = [t0 tf] &  y0 : t0���� tf������ �������� �ʱ� ���� y0�� ����Ͽ� �����̺й����� y��=f(t,y)�� ������
%�� �迭 y�� �� ���� �� ���� t�� ��ȯ�� ���� ������

[T, X]=ode45(@(t, x) r2dof(t, x, ths, spec, Kpid), Ts, x0); 
%���������� 2���� r2dof(t, x, ths, spec, Kpid)�Լ��� ���Ͽ� Ts�������� �ʱ� ���� x0�� ����Ͽ� ode Ǯ��

%Output (���ϰ� ���� ��!)
th1=X(:, 3); %theta1 waveform. �ð� T�� ���� ����1
th2=X(:, 4); %theta2 waveform. �ð� T�� ���� ����2

%torque inputs computation from the 7th, 8th states inside ODE
%�� F1�� F2�� r2dof.m���� x'7�� x'8�� �̺а����� ���������Ƿ�, diff(����) �Լ��� ����Ͽ� ���ϱ�

%���� ��� ���� ����
%Y=diff(X) : X�� ���� ������ �����. Y�� ��Ҵ� X�� ���� ��� ���� ���а���� X���� ��Ұ� �ϳ� �� ���� ��µ�
%ex) X=[1 1 2 3 5 8 13 21]���� Y = diff(X)�� �ϸ� 
%��� : Y=[0  1  1  2  3  5  8]

F1=diff(X(:, 7))./diff(T); %�и�� ���� ��� ��Į�� �ƴ� �����̹Ƿ� ���к� ������(./) ���. F1=xdot(7)=X(:, 7)./diff(T)
F2=diff(X(:, 8))./diff(T); %F2=xdot(8)=X(:, 8)./diff(T)
tt=0:(T(end)/(length(F1)-1)):T(end);

%xy
x1=L1*sin(th1); %X1
y1=L1*cos(th1); %Y1
x2=L1*sin(th1)+L2*sin(th1+th2); %X2
y2=L1*cos(th1)+L2*cos(th1+th2); %Y2

%theta1 error plot
plot(T, ths(1)-th1) %x�� : T, y�� : ths(1)-th1
grid;
title('Theta-1 error');
xlabel('time (sec)');
ylabel('theta1 error (rad)');

%theta2 error plot
figure;
plot(T, ths(2)-th2);
grid;
title('Theta-2 error');
xlabel('time (sec)');
ylabel('theta2 error (rad)');

%torque1 plot
figure;
plot(tt, F1);
grid;
title('Torque of theta 1');
xlabel('time (sec)');
ylabel('theta1 torque');

%torque2 plot
figure;
plot(tt, F2);
grid;
title('Torque of theta 2');
xlabel('time (sec)');
ylabel('theta2 torque');