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
#define sFile_init "initial_data/init.ini"





// func protos
int main_dispatcher();
ConfigData read_init();








