// libres =============================================
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <assert.h>
#include <vector>
#include <math.h>
#include <random>



// data struct =======================================
struct ConfigData {
    int distribution_arc;
    int distribution_radius;
    double radius;
    int shots;
    double step;
    char sFile_cyrcle[128];
    char sFile_shots[128];
};


// macroses ==========================================
#define sFile_init "init.ini"






// protos ============================================
int main_dispatcher ();
ConfigData read_init();






// funcs =============================================
ConfigData read_init () {
    FILE *pFile_init;
    ConfigData config;
    int fscanf_val;
    const int tmp_Buff_len = 256;
	char tmp_Buff[tmp_Buff_len];

    pFile_init = fopen(sFile_init, "r");
	if (pFile_init == NULL) {
		printf("file %s not found", sFile_init);
		assert(0);
	}

    fseek(pFile_init, 0L, SEEK_SET);

    fscanf_val = fscanf(pFile_init, "%d", &config.distribution_arc);    fgets(tmp_Buff, 120, pFile_init);
    fscanf_val = fscanf(pFile_init, "%d", &config.distribution_radius); fgets(tmp_Buff, 120, pFile_init);
    fscanf_val = fscanf(pFile_init, "%lf", &config.radius);             fgets(tmp_Buff, 120, pFile_init);
    fscanf_val = fscanf(pFile_init, "%d", &config.shots);               fgets(tmp_Buff, 120, pFile_init);
    fscanf_val = fscanf(pFile_init, "%lf", &config.step);               fgets(tmp_Buff, 120, pFile_init);
    fscanf_val = fscanf(pFile_init, "%s", config.sFile_cyrcle);        fgets(tmp_Buff, 120, pFile_init);
    fscanf_val = fscanf(pFile_init, "%s", config.sFile_shots);         fgets(tmp_Buff, 120, pFile_init);


    printf("!!!!!!!!!!PLEASE CHEACK YOUR INIT DATA!!!!!!!!!!!:\n");
    printf(" - distribution_arc- %d\n", config.distribution_arc);
    printf(" - distribution_radius- %d\n", config.distribution_radius);
    printf(" - radius- %f\n", config.radius);
    printf(" - shots- %d\n", config.shots);
    printf(" - step- %f\n", config.step);
    printf(" - sFile_output- %s\n", config.sFile_cyrcle);
    printf(" - sFile_output- %s\n", config.sFile_shots);

    printf("------------------------------------------------------------------\n");

    printf("\n");

    fclose(pFile_init);
    return config;
}

int main_dispatcher () {
    // init data
    ConfigData cfg = read_init();

    // make cyrcle
    const int arr_size = (cfg.radius - (-cfg.radius)) / cfg.step;
    std::vector<double> circle_x (arr_size);
    std::vector<double> circle_y (arr_size);

    for (size_t i = 0; i < arr_size; i++) {
        circle_x[i] = -cfg.radius + cfg.step * i;
    }
    for (size_t i = 0; i < arr_size; i += 2) {
        circle_y[i] = sqrt(cfg.radius * cfg.radius - circle_x[i] * circle_x[i]);
        circle_y[i+1] = -sqrt(cfg.radius * cfg.radius - circle_x[i+1] * circle_x[i+1]);
    }

    // make shots
    std::vector<double> shot_line_x (cfg.shots);
    std::vector<double> shot_line_y (cfg.shots);
    std::vector<double> shot_r (cfg.shots);
    std::vector<double> shot_x (cfg.shots);
    std::vector<double> shot_y (cfg.shots);

    std::random_device rd{};
    std::mt19937 gen{ rd() };

    for (int shot_count = 0; shot_count < cfg.shots; shot_count++) {
        // make distr
        std::uniform_int_distribution<int> RND_uniform{ 0, static_cast<int>(circle_x.size()) };
        shot_line_x[shot_count] = circle_x[RND_uniform(gen)];

        // remake distr
        RND_uniform.param(std::uniform_int_distribution<int>::param_type{ -1, 1 });
        shot_line_y[shot_count] = sqrt(cfg.radius * cfg.radius - shot_line_x[shot_count] * shot_line_x[shot_count]) * RND_uniform(gen);

        std::normal_distribution<double> RND_normal{ 0.0, 1.0 };
        shot_r[shot_count] = abs(cfg.radius * RND_normal(gen));
        shot_x[shot_count] = shot_r[shot_count] * shot_line_x[shot_count] / cfg.radius;

        if (shot_line_y[shot_count] > 0)
            shot_y[shot_count] = sqrt(shot_r[shot_count] * shot_r[shot_count] - shot_x[shot_count] * shot_x[shot_count]);
        else 
            shot_y[shot_count] = -sqrt(shot_r[shot_count] * shot_r[shot_count] - shot_x[shot_count] * shot_x[shot_count]);
    }
    

    // print result to file
    FILE* pFile_cyrcle = fopen(cfg.sFile_cyrcle, "w");
    if (pFile_cyrcle == NULL) {
        printf("file %s not found", cfg.sFile_cyrcle);
        assert(0);
    }
    for (int print_count = 0; print_count < arr_size; print_count++) {
        fprintf(pFile_cyrcle, " %f %f \n", circle_x[print_count],
                                           circle_y[print_count]);
    }





    FILE* pFile_shots = fopen(cfg.sFile_shots, "w");
    if (pFile_shots == NULL) {
        printf("file %s not found", cfg.sFile_shots);
        assert(0);
    }
    for (int print_count = 0; print_count < cfg.shots; print_count++) {
        fprintf(pFile_shots, " %f %f %f \n", shot_r[print_count],
                                              shot_x[print_count],
                                              shot_y[print_count]);
    }


    return 0;
}




// main ==============================================
int main () {
    printf("\n");
    printf("I.M.Markov \n");
    printf("Hit model v0.1 \n");
    printf("------------------------------------------------------------------\n");
    printf("\n");

    switch (main_dispatcher()) {
        // init error
        case -1:
            break;

        // succes launch
        case 0:
            printf("secces launch\n");
            break;
        
        // .......
        case 1:
            break;

    }
    printf("bye bye :)\n");
    return 0;
}