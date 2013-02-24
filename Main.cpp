#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "Features.h"

#pragma warning(disable:4244)

const int MAX_ITERATIONS = 100000;

using namespace std;

function<int(vector<int>&)> Sum = [&](vector<int>& ints) -> int {
	auto sum = 0;
	for_each(ints.begin(), ints.end(), [&](int n) {
		sum += n;
	});
	return sum;
};

function<double(int)> Average = [&](int sum) -> double {
	auto avg = 0.00;
	avg = (sum / MAX_ITERATIONS) / 100;
	return avg;
};

int main() {
	LoadLogfile();

	vector<int> win;
	win.reserve(100000);

	// Puffer fish features
	for (auto i = 0; i < MAX_ITERATIONS; i++) {
		win.push_back(ExecutePufferFeature(3));
	}
	auto a = Sum(win);
	auto b = Average(a);
	WriteLogFile(a, MAX_ITERATIONS, b, std::string("puffer 3"));

	win.clear();
	for (auto i = 0; i < MAX_ITERATIONS; i++) {
		win.push_back(ExecutePufferFeature(4));
	}

	a = Sum(win);
	b = Average(a);
	WriteLogFile(a, MAX_ITERATIONS, b, std::string("puffer 4"));
	win.clear();
	
	for (auto i = 0; i < MAX_ITERATIONS; i++) {
		win.push_back(ExecutePufferFeature(5));
	}

	a = Sum(win);
	b = Average(a);
	WriteLogFile(a, MAX_ITERATIONS, b, std::string("puffer 5"));
	win.clear();

	// Starfish feature
	for (auto i = 0; i < MAX_ITERATIONS; i++) {
		win.push_back(ExecuteStarfishFeature(3));
	}

	a = Sum(win);
	b = Average(a);
	WriteLogFile(a, MAX_ITERATIONS, b, std::string("Starfish 3"));
	win.clear();

	for (auto i = 0; i < MAX_ITERATIONS; i++) {
		win.push_back(ExecuteStarfishFeature(4));
	}

	a = Sum(win);
	b = Average(a);
	WriteLogFile(a, MAX_ITERATIONS, b, std::string("Starfish 4"));
	win.clear();

	for (auto i = 0; i < MAX_ITERATIONS; i++) {
		win.push_back(ExecuteStarfishFeature(5));
	}

	a = Sum(win);
	b = Average(a);
	WriteLogFile(a, MAX_ITERATIONS, b, std::string("Starfish 5"));
	win.clear();

	// Wonga feature
	for (auto i = 0; i < MAX_ITERATIONS; i++) {
		win.push_back(ExecuteWongaFeature(3));
	}

	a = Sum(win);
	b = Average(a);
	WriteLogFile(a, MAX_ITERATIONS, b, std::string("Wonga 3"));
	win.clear();

	for (auto i = 0; i < MAX_ITERATIONS; i++) {
		win.push_back(ExecuteWongaFeature(4));
	}

	a = Sum(win);
	b = Average(a);
	WriteLogFile(a, MAX_ITERATIONS, b, std::string("Wonga 4"));
	win.clear();

	for (auto i = 0; i < MAX_ITERATIONS; i++) {
		win.push_back(ExecuteWongaFeature(5));
	}

	a = Sum(win);
	b = Average(a);
	WriteLogFile(a, MAX_ITERATIONS, b, std::string("Wonga 5"));
	win.clear();
	
	// Shell fish feature
	for (auto i = 0; i < MAX_ITERATIONS; i++) {
		win.push_back(ExecuteShellFeature(3));
	}

	a = Sum(win);
	b = Average(a);
	WriteLogFile(a, MAX_ITERATIONS, b, std::string("Shell 3"));
	win.clear();

	for (auto i = 0; i < MAX_ITERATIONS; i++) {
		win.push_back(ExecuteShellFeature(4));
	}

	a = Sum(win);
	b = Average(a);
	WriteLogFile(a, MAX_ITERATIONS, b, std::string("Shell 4"));
	win.clear();

	for (auto i = 0; i < MAX_ITERATIONS; i++) {
		win.push_back(ExecuteShellFeature(5));
	}

	a = Sum(win);
	b = Average(a);
	WriteLogFile(a, MAX_ITERATIONS, b, std::string("Shell 5"));
	win.clear();

	CloseLogfile();
	
	return 0;
}

