clear;
clc;

% HY
step = 0.001;
R = 1;
shots = 1;
variable = [-1, 1];

% формируем окружность
x = -R:step:R;
y = sqrt(R^2 - x.^2);

% формируем рандомный выстрел
shot_line_x = x(randi(length(x)));
shot_line_y = sqrt(R^2 - shot_line_x.^2) * variable(randi(length(variable)));

shot_r = abs(randn)*R;
shot_x = shot_r * shot_line_x / R;
if (shot_line_y > 0)
    shot_y = sqrt(shot_r^2 - shot_x^2);
else
    shot_y = -1 * sqrt(shot_r^2 - shot_x^2);
end

plot(x, +y, '-b', ...
     x, -y, '-b');
hold on
% plot([0,shot_line_x], [0,shot_line_y], '-g')
plot(shot_x, shot_y, '*r')
grid on;
axis equal;

% shots_distr = zeros(1, shots);
% for i = 1:shots
%     shoot = randi(length(rnd));
%     plot(rnd(2, shoot), rnd(3, shoot), '*r');
%     shots_distr(i) = rnd(1, shoot);
% end

