#define BOOST_TIMER_ENABLE_DEPRECATED
#include <algorithm>
#include <iostream>
#include<limits>
#include <vector>
#include "Permutations.h"
#include <boost/timer.hpp>

using namespace std;

int main()
{
	//vector<size_t> vertices = { 1, 2, 3, 4 };
	//sort(vertices.begin(), vertices.end());
	//vector<vector<int>> graph =
	//{
	//	{0, 1, 0, 2},
	//	{1, 0, 3, 0},
	//	{0, 3, 0, 1},
	//	{2, 0, 1, 0}
	//};

	vector<size_t> vertices = { 1, 2, 3, 4, 6, 5, 8, 9, 7, 10 };
	vector<vector<int>> graph =
	{
		{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
		{1, 0, 2, 3, 4, 5, 6, 7, 8, 9},
		{2, 2, 0, 3, 4, 5, 6, 7, 8, 9},
		{3, 3, 3, 0, 4, 5, 6, 7, 8, 9},
		{4, 4, 4, 4, 0, 5, 6, 7, 8, 9},
		{5, 5, 5, 5, 5, 0, 6, 7, 8, 9},
		{6, 6, 6, 6, 6, 6, 0, 7, 8, 9},
		{7, 7, 7, 7, 7, 7, 7, 0, 8, 9},
		{8, 8, 8, 8, 8, 8, 8, 8, 0, 9},
		{9, 9, 9, 9, 9, 9, 9, 9, 9, 0}
	};

	boost::timer t;
	t.restart();
	cout << "Min weight: " << FindMinWeight(vertices, graph) << endl;
	double duration = t.elapsed();
	cout << duration << endl;
}
