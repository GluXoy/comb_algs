#include <algorithm>
#include <iostream>
#include<limits>
#include <vector>

using namespace std;

int GetWeight(vector<size_t> v, vector<vector<int>> graph)
{
	int weightTotal = 0;
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		size_t firstVertex = v[i];
		size_t secondVertex = v[i + 1];
		int edge = graph[firstVertex - 1][secondVertex - 1];
		if (!edge)
		{
			return 0;
		}
		weightTotal += edge;
	}
	return weightTotal;
}

int FindMinWeight(vector<size_t> v, vector<vector<int>> graph)
{
	int minWeight = numeric_limits<int>::max();
	do
	{
		//copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " "));
		//cout << endl;
		/*cout << "weight: " << GetWeight(v, graph) << endl;*/
		int weight = GetWeight(v, graph);
		if (weight == 0)
		{
			continue;
		}
		minWeight = weight < minWeight ? weight : minWeight;
	} while (std::next_permutation(v.begin(), v.end()));
	return minWeight == numeric_limits<int>::max() ? 0 : minWeight;
}