clear all;
clc;

output = importfile('output.csv', 2, 183);

%Figure 1: Processes over Time
fa = plot(output(1,:),output(6,:),output(1,:),output(7,:));