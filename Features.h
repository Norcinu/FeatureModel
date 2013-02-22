#ifndef FEATURES_H
#define FEATURES_H

#include <iostream>
#include <fstream>



void LoadLogfile();
void CloseLogfile();
void WriteLogFile(const int win);

int ExecuteCrabFeature(const int count, int position);
int ExecutePufferFeature(const int count);
int ExecuteShellFeature(const int count);
int ExecuteStarfishFeature(const int count);
int ExecuteWongaFeature(const int count);

#endif