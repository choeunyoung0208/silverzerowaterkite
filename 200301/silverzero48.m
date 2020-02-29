%2)System Solution and Simulation

close all 
%close : ������ Figure ����
%close all�� �ڵ��� �������� ���� ��� Figure�� �����մϴ�.
clear all
%�۾� �������� �׸��� �����Ͽ� �ý��� �޸� �ø���
%clear�� ���� �۾� �������� ��� ������ �����Ͽ� �ý��� �޸𸮿��� �����մϴ�.
clc

%Initilization
th_int=[pi/6 pi/3 pi/2]; %initial positions
ths=[0 pi/2 pi/4]; %set-points => final positions

x0=[0 0 0 th_int 0 0 0 0 0 0]; %states initial values(�ʱⰪ) 
%�ʱⰪ�� �̿��ؼ� ODE�� �����(���л�� �����͵�)�� Ư�������� ��������
Ts=[0 20]; %time span

%Robot Specifications
L1=1; %link 1
L2=1; %link 2
L3=1; %link 3
M1=1; %mass 1
M2=1; %mass 2
M3=1; %mass 3
spec=[L1 L2 L3 M1 M2 M3];

%PID Parameters
%PID parameters for theta 1
Kp1=0;
Kd1=0;
Ki1=0;
%PID parameters for theta 2
Kp2=0;
Kd2=0;
Ki2=0;
%PID parameters for theta 3
Kp3=0;
Kd3=0;
Ki3=0;

Kpid=[Kp1 Kd1 Ki1 Kp2 Kd2 Ki2 Kp3 Kd3 Ki3];

%ODE solving
%ode45 �� ����� ODE Ǯ��
%[t,y] = ode45(odefun,tspan,y0)
%odefun : Ǯ����� ode�Լ�
%tspan = [t0 tf] &  y0 : t0���� tf������ �������� �ʱ� ���� y0�� ����Ͽ� �����̺й����� y��=f(t,y)�� ������
%�� �迭 y�� �� ���� �� ���� t�� ��ȯ�� ���� ������

[T, X]=ode45(@(t, x) r3dof(t, x, ths, spec, Kpid), Ts, x0); 
%���������� 2���� r3dof(t, x, ths, spec, Kpid)�Լ��� ���Ͽ� Ts�������� �ʱ� ���� x0�� ����Ͽ� ode Ǯ��

%Output (���ϰ� ���� ��!)
th1=X(:, 4); %theta1 waveform. �ð� T�� ���� ����1
th2=X(:, 5); %theta2 waveform. �ð� T�� ���� ����2
th3=X(:, 6); %theta3 waveform. �ð� T�� ���� ����3

%torque inputs computation from the 10th, 11th, 12th states inside ODE
%�� F1, F2, F3�� r3dof.m���� x'10, x'11, x'12��� �̺а����� ���������Ƿ�, diff(����) �Լ��� ����Ͽ� ���ϱ�

%���� ��� ���� ����
%Y=diff(X) : X�� ���� ������ �����. Y�� ��Ҵ� X�� ���� ��� ���� ���а���� X���� ��Ұ� �ϳ� �� ���� ��µ�
%ex) X=[1 1 2 3 5 8 13 21]���� Y = diff(X)�� �ϸ� 
%��� : Y=[0  1  1  2  3  5  8]

F1=diff(X(:, 10))./diff(T); %�и�� ���� ��� ��Į�� �ƴ� �����̹Ƿ� ���к� ������(./) ���. F1=xdot(10)=X(:, 10)./diff(T)
F2=diff(X(:, 11))./diff(T); %F2=xdot(11)=X(:, 11)./diff(T)
F3=diff(X(:, 12))./diff(T); %F3=xdot(12)=X(:, 12)./diff(T)
tt=0:(T(end)/(length(F1)-1)):T(end);

%xy
x1=L1*cos(th1); %X1
y1=L1*sin(th1); %Y1
x2=L1*cos(th1)+L2*cos(th1+th2); %X2
y2=L1*sin(th1)+L2*sin(th1+th2); %Y2
x3=L1*cos(th1)+L2*cos(th1+th2)+L3*cos(th3-(th1+th2)); %X3
y3=L1*sin(th1)+L2*sin(th1+th2)-L3*sin(th3-(th1+th2)); %Y3

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

%theta3 error plot
figure;
plot(T, ths(3)-th3);
grid;
title('Theta-3 error');
xlabel('time (sec)');
ylabel('theta3 error (rad)');

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

%torque3 plot
figure;
plot(tt, F3);
grid;
title('Torque of theta 3');
xlabel('time (sec)');
ylabel('theta3 torque');