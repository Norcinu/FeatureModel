#ifndef FEATURES_H
#define FEATURES_H

#include <iostream>
#include <fstream>

enum WriteTypes {WRITE_NORMAL=1, WRITE_STATS, WRITE_NEWLINE};

void LoadLogfile();
void CloseLogfile();
void WriteLogFile(const int total, const int runs, const int average, const std::string feature);

int ExecuteCrabFeature(const int count);
int ExecutePufferFeature(const int count);
int ExecuteShellFeature(const int count);
int ExecuteStarfishFeature(const int count);
int ExecuteWongaFeature(const int count);

#endif