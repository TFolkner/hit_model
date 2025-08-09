clear;
clc;

% НУ
alpha = 5 * pi/180; % град
r = 1;
steps = 2*pi / alpha;
x = zeros (steps, 1);
y = zeros (steps, 1);
alphas = zeros (steps, 1);
shots = 100;

% cyrcle
for i = 1:steps
    alphas(i) = alpha*i;
    x(i) = r * cos(alphas(i));
    y(i) = r * sin(alphas(i));
end

% shot
shot_line_x = zeros (shots, 1);
shot_line_y = zeros (shots, 1);
shot_alphas = zeros (shots, 1);


for i = 1:shots
    shot_alphas(i) = alphas(randi(length(alphas)));
    shot_line_x(i) = cos(shot_alphas(i)) * randn*r;
    shot_line_y(i) = sin(shot_alphas(i)) * randn*r;
end

% plot
F1 = figure();

subplot (3, 3, 1)
histogram (rad2deg(shot_alphas), 20);
grid on;
title ('shot alphas');
xlabel ('deg')
subplot (3, 3, 2)
histogram (shot_line_x);
grid on;
title ('shot line x');
xlabel ('m')
subplot (3, 3, 3)
histogram (shot_line_y);
grid on;
title ('shot line y');
xlabel ('m')

subplot (3, 3, [4,5,6,7,8,9])
plot (x, y, '.b');
grid on;
axis equal;
hold on
title ('shots');
for i = 1:shots
    plot (shot_line_x(i), shot_line_y(i), '*r');
end

sgtitle ('FINAL RESULT')