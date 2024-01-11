#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> g_sum;

int getMaximumSum(int x, int y, vector<vector<int>>& triangle)
{
	if(g_sum[x][y])
	{
		return g_sum[x][y];
	}

	int left = getMaximumSum(x + 1, y, triangle);
	int right = getMaximumSum(x + 1, y + 1, triangle);
	left > right ? g_sum[x][y] += left : g_sum[x][y] += right;

	return g_sum[x][y];
}

int solution(vector<vector<int>> triangle)
{
	g_sum.resize(triangle.size());
	for(auto& inner : g_sum)
	{
		inner.resize(triangle.size(), 0);
	}

	for(int i=0; i< triangle.size(); ++i)
	{
		g_sum[triangle.size() - 1][i] = triangle[triangle.size() - 1][i];
	}

    int answer = getMaximumSum(0, 0, triangle);

    return answer;
}

int main()
{
    vector<vector<int>> triangle =
    { {7} ,{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} };

	cout << solution(triangle) << endl;
}