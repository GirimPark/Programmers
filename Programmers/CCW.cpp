#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct POINT
{
	int x, y;
};

int solution(const vector<POINT>& points)
{
	int answer = -2;

	POINT vec1 = { points[1].x - points[0].x, points[1].y - points[0].y };
	POINT vec2 = { points[2].x - points[1].x, points[2].y - points[1].y };
	int outer = vec1.x * vec2.y - vec1.y * vec2.x;
	if (outer > 0)		return 1;
	else if (outer < 0)	return -1;
	else				return 0;

	return answer;
}

int main()
{
	vector<POINT> points(3);
	for (size_t i = 0; i < points.size(); i++)
	{
		cin >> points[i].x >> points[i].y;
	}

	cout << solution(points) << '\n';
}