#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../1_1/Permutations.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

TEST_CASE("Test when no way between vertices")
{
	vector<size_t> vertices = { 1, 2 };
	sort(vertices.begin(), vertices.end());

	vector<vector<int>> graph =
	{
		{0, 0},
		{0, 0},
	};

	CHECK(FindMinWeight(vertices, graph) == 0);
}

TEST_CASE("Test when one way between vertices")
{
	vector<size_t> vertices = { 1, 2 };
	sort(vertices.begin(), vertices.end());

	vector<vector<int>> graph =
	{
		{0, 1},
		{1, 0},
	};

	CHECK(FindMinWeight(vertices, graph) == 1);
}

TEST_CASE("Test when multiple ways between vertices")
{
	vector<size_t> vertices = { 1, 2, 3 };
	sort(vertices.begin(), vertices.end());

	vector<vector<int>> graph =
	{
		{0, 1, 2},
		{1, 0, 3},
		{2, 3, 0},
	};

	CHECK(FindMinWeight(vertices, graph) == 3);
}

TEST_CASE("when one vertex is isolated, gamylton cycle won't work")
{
	vector<size_t> vertices = { 1, 2, 3 };
	sort(vertices.begin(), vertices.end());

	vector<vector<int>> graph =
	{
		{0, 0, 2},
		{0, 0, 0},
		{2, 0, 0},
	};

	CHECK(FindMinWeight(vertices, graph) == 0);
}
