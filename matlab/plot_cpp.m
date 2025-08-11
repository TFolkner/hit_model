clear;
clc;

sFile_cyrcle = "../output_data/cyrcle.txt";
pFile_cyrcle = load (sFile_cyrcle, "r");
sFile_shots = "../output_data/shots.txt";
pFile_shots = load (sFile_shots, "r");
clear sFile_cyrcle sFile_shots;

shot_line_x = pFile_shots(:, 1);
shot_line_y = pFile_shots(:, 2);
shot_alphas = pFile_shots (:, 3);

x_cyrcle = pFile_cyrcle (:, 1);
y_cyrcle = pFile_cyrcle (:, 2);
shots = size(pFile_shots);
shots = shots(1);

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
plot (x_cyrcle, y_cyrcle, '.b');
grid on;
axis equal;
hold on
title ('shots');
for i = 1:shots
    plot (shot_line_x(i), shot_line_y(i), '*r');
end

sgtitle ('FINAL RESULT')



