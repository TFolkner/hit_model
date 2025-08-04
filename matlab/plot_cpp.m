clear;
clc;

sFile_cyrcle = "cyrcle.txt";
pFile_cyrcle = load (sFile_cyrcle, "r");
sFile_shots = "shots.txt";
pFile_shots = load (sFile_shots, "r");
clear sFile_cyrcle sFile_shots;

x_cyrcle = pFile_cyrcle (:, 1);
y_cyrcle = pFile_cyrcle (:, 2);
shots = size(pFile_shots);
shots = shots(1);

figure;
title ('Радиус обстрела и попадания');
plot (x_cyrcle, y_cyrcle, '.');
grid on;
hold on;
for i = 1:shots
    % plot ([0, pFile_shots(i, 2)], [0, pFile_shots(i, 3)], '-g');
    plot (pFile_shots(i, 2), pFile_shots(i, 3), '*r');
end
legend ('Радиус поражения', 'Обстрелы');
axis equal;


figure;
bars = 5;
subplot (3, 1, 1)
sgtitle ('Частотные гистограммы распределения СВ');
histogram (pFile_shots(:, 1), bars);
title ('Распределение по радиусу');
grid on;
subplot (3, 1, 2)
histogram (pFile_shots(:, 2), bars);
title ('Распределение по дуге оси X');
grid on;
subplot (3, 1, 3)
histogram (pFile_shots(:, 3), bars);
title ('Распределение по оси Y');
grid on;

