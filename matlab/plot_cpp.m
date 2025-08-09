clear;
clc;

sFile_cyrcle = "../output_data/cyrcle.txt";
pFile_cyrcle = load (sFile_cyrcle, "r");
sFile_shots = "../output_data/shots.txt";
pFile_shots = load (sFile_shots, "r");
clear sFile_cyrcle sFile_shots;

x_cyrcle = pFile_cyrcle (:, 1);
y_cyrcle = pFile_cyrcle (:, 2);
shots = size(pFile_shots);
shots = shots(1);

F1 = figure();
plot (x_cyrcle, y_cyrcle, '.b');
grid on;
axis equal;
hold on

for i = 1:shots
    plot (pFile_shots(i, 1), pFile_shots(i, 2), '*r');
end



