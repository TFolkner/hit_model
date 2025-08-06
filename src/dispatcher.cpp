#include "../heads/dispatcher.h"





int main_dispatcher() {
    // init data
    ConfigData cfg = read_init();

    


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



