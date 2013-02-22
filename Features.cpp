#include <iostream>
#include <fstream>
#include "Features.h"


unsigned int featureLogCode = 0;
std::fstream logfile;

void LoadLogfile() {
	logfile.open("logfile.txt");
}

void CloseLogfile() {
	logfile.close();
}

void WriteLogFile(const int win) {
	logfile << "Feature: " << featureLogCode << " : Win £" << win << "\n";
}

int ExecuteCrabFeature(const int count, int position) {	
	int win = 0;
	if (count == 3) {
		featureLogCode = 13;
		win = 3000;
	}
	else if (count == 4) {
		featureLogCode = 14;
		win = 4000;
	}
	else if (count == 5) {
		featureLogCode = 15;
		win = 5000;
	}

	return win;
}

int ExecuteWongaFeature(const int count) {
	if (count == 3)
		featureLogCode = 73;
	else if (count == 4)
		featureLogCode = 74;
	else
		featureLogCode = 75;
	
	int WinTable3s[32] = {3000, 2900, 2800, 2700, 2600, 2500, 2400, 2300, 2200, 2100, 2000, 1900, 1800, 1700, 1600, 1500, 1400, 1300, 1200, 1100, 1000,
		900, 800, 700, 600, 500, 600, 700, 800, 500, 600, 900};
	int WinTable4s[32] = {5000, 4900, 4800, 4700, 4600, 4500, 4400, 4300, 4200, 4100, 4000, 3900, 3800, 3700, 3600, 3500, 3400, 2800, 2600, 2200, 2100,
		2000, 1900, 1800, 1700, 1600, 1500, 1400, 1300, 1200, 1100, 1000};
	int WinTable5s[32] = {50000, 35000, 25000, 17500, 15000, 12500, 10000, 7500, 6000, 5000, 4500, 4000, 3900, 3800, 3700, 3600, 3500, 3400, 3300, 3200, 
		4500, 3200, 3300, 6600, 5700, 5500, 4800, 4600, 3500, 3200, 3100, 3000};
	
	int WinAmount = 0;
	if (count == 3)
		WinAmount = WinTable3s[rand() % 31 + 0];//;GetLocalIntRandomNumber(32)];
	if (count == 4) 
		WinAmount = WinTable4s[rand() % 31 + 0];//GetLocalIntRandomNumber(32)];
	if (count == 5)
		WinAmount = WinTable5s[rand() % 31 + 0];//GetLocalIntRandomNumber(32)];

	return WinAmount;
}

int ExecutePufferFeature(const int count) {
	if (count == 3)		 featureLogCode = 43;
	else if (count == 4) featureLogCode = 44;
	else if (count == 5) featureLogCode = 45;
	
	int PresentWinValues[5] = {0};
	int i = 0;
	
	memset(PresentWinValues, 0, 5);
	const int PufferWinValues[32] = {10000, 9000, 8000, 5000, 3000, 2500, 2000, 1500, 1200, 1100, 1000, 1000, 1000,
		900, 800, 700, 600, 500, 500, 500, 400, 400, 400, 300, 300, 300, 200, 300, 500, 200, 200, 100};
	
	int SelectedWinAmount = 0;
	
	for(; i < count; i++) {
		PresentWinValues[i] = PufferWinValues[rand()%31+0];//GetLocalIntRandomNumber(32)];
	}

	for (i = 0; i < count; i++) {
		SelectedWinAmount += PresentWinValues[i];
	}

	return SelectedWinAmount;
}

int ExecuteStarfishFeature(const int count) {
	if (count == 3) featureLogCode = 63;
	else if (count == 4) featureLogCode = 64;
	else if (count == 5) featureLogCode = 65;
	
	int FreeSpinsTotalWin = 0;

	if (count == 3) {
		int PossibleWinAmounts[32] = {10000, 8900, 6000, 5000, 3000, 2500, 2000, 1500, 1200, 1100, 1000, 2200,
			2600, 2400, 2300, 2200, 2100, 2000, 1900, 1800, 1700, 1600, 1500, 1400, 1200, 1000, 700, 700, 600, 600, 500, 400};
		
		FreeSpinsTotalWin = PossibleWinAmounts[rand()%31+0];//GetLocalIntRandomNumber(32)];
	}
	else if (count == 4) {
		int PossibleWinAmounts[32] = {12000, 9500, 8000, 6000, 5500, 5000, 4700, 4500, 4000, 3700, 3500, 3200, 3000, 2800, 
			2600, 2400, 2200, 2000, 1900, 1800, 1700, 2100, 3000, 1500, 1400, 1200, 1000, 1800, 1600, 1400, 1200, 1000 };
		FreeSpinsTotalWin = PossibleWinAmounts[rand()%31+0];//GetLocalIntRandomNumber(32)];
	}
	else if (count == 5) {
		int PossibleWinAmounts[32] = {25000, 15500, 9700, 8500, 8000, 7700, 7000, 6600, 6000, 3700, 3500, 3200, 3000, 2800, 
			2600, 2700, 6500, 5500, 5000, 1800, 4500, 1600, 3300, 1500, 1400, 2400, 2200, 2000, 3500, 3100, 1800, 1600};
		FreeSpinsTotalWin = PossibleWinAmounts[rand()%31+0];//GetLocalIntRandomNumber(32)];
	}

	return FreeSpinsTotalWin;
}

int ExecuteShellFeature(const int count) {
	if (count == 3) {
		DbFeatureLogging = 53;
	}
	else if (count == 4) {
		DbFeatureLogging = 54;
	}
	else
		DbFeatureLogging = 55;
	
	
	int	PresentWinValues[5] = {0};
	int ShellWinValues[] = {10000, 10000, 9000, 8500, 8000, 7000, 6500, 6000, 5500, 5000, 4000, 4000, 3800, 
3600, 3400, 3200, 3000, 2800, 2600, 2400, 2200, 2000, 1800, 1600, 1500, 1200, 1000, 800, 600, 500, 400};
	for (int i = 0; i < 5; i++) {
		PresentWinValues[i] = ShellWinValues[GetLocalIntRandomNumber(29)]; 
	}
}
