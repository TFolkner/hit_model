#include "../heads/dispatcher.h"





int main_dispatcher() {
    // init data
    ConfigData cfg = read_init();


    // make cyrcle
    cfg.alpha = cfg.alpha * const_pi / const_cyrcle_grad/2;
    const int arr_size = int(2 * const_pi / cfg.alpha);
    std::vector<double> circle_x(arr_size);
    std::vector<double> circle_y(arr_size);
    std::vector<double> alphas(arr_size);

    for (int count = 0; count < arr_size; count++) {
        alphas[count] = cfg.alpha * count;
        circle_x[count] = cfg.radius * cos(alphas[count]);
        circle_y[count] = cfg.radius * sin(alphas[count]);
    }

    // shots
    std::vector<double> shot_line_x(cfg.shots);
    std::vector<double> shot_line_y(cfg.shots);
    std::vector<double> shot_alphas(cfg.shots);

    std::random_device rd{};
    std::mt19937 gen{ rd() };

    for (int shot_count = 0; shot_count < cfg.shots; shot_count++) {
        // make distr
        std::uniform_int_distribution<int> RND_uniform{ 0, static_cast<int>(circle_x.size()) };
        shot_alphas[shot_count] = alphas[RND_uniform(gen)];

        // remake distr
        std::normal_distribution<double> RND_normal{ 0.0, 1.0 };
        shot_line_x[shot_count] = cos (shot_alphas[shot_count]) * cfg.radius * RND_normal(gen);
        shot_line_y[shot_count] = sin (shot_alphas[shot_count]) * cfg.radius * RND_normal(gen);
    }
    






    // print result to file
    FILE* pFile_cyrcle = fopen(cfg.sFile_cyrcle, "w");
    if (pFile_cyrcle == NULL) {
        printf("file %s not found", cfg.sFile_cyrcle);
        assert(0);
    }
    for (int print_count = 0; print_count < arr_size; print_count++) {
        fprintf(pFile_cyrcle, " %10.5f %10.5f \n", circle_x[print_count], circle_y[print_count]);
    }

    FILE* pFile_shots = fopen(cfg.sFile_shots, "w");
    if (pFile_shots == NULL) {
        printf("file %s not found", cfg.sFile_shots);
        assert(0);
    }
    for (int print_count = 0; print_count < cfg.shots; print_count++) {
        fprintf(pFile_shots, " %10.5f %10.5f \n", shot_line_x[print_count],
                                                  shot_line_y[print_count]);
    }

    return 0;
}






// funcs =============================================
ConfigData read_init() {
    FILE* pFile_init;
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
    fscanf_val = fscanf(pFile_init, "%lf", &config.alpha);               fgets(tmp_Buff, 120, pFile_init);
    fscanf_val = fscanf(pFile_init, "%s", config.sFile_cyrcle);        fgets(tmp_Buff, 120, pFile_init);
    fscanf_val = fscanf(pFile_init, "%s", config.sFile_shots);         fgets(tmp_Buff, 120, pFile_init);


    printf("!!!!!!!!!!PLEASE CHEACK YOUR INIT DATA!!!!!!!!!!!:\n");
    printf(" - distribution_arc- %d\n", config.distribution_arc);
    printf(" - distribution_radius- %d\n", config.distribution_radius);
    printf(" - radius- %f\n", config.radius);
    printf(" - shots- %d\n", config.shots);
    printf(" - alpha- %f\n", config.alpha);
    printf(" - sFile_output- %s\n", config.sFile_cyrcle);
    printf(" - sFile_output- %s\n", config.sFile_shots);

    printf("------------------------------------------------------------------\n");

    printf("\n");

    fclose(pFile_init);
    return config;
}



