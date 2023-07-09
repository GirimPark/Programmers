#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct POINT
{
	int x, y;

	bool operator== (POINT o)
	{
		return (this->x == o.x) && (this->y == o.y);
	}
};

vector<bool> solution(vector<POINT>& polygon, int& N, vector<POINT>& friends)
{
	vector<bool> answer(3, false);

	for (size_t i = 0; i < friends.size(); i++)
	{
		vector<float> cross;
		for (size_t j = 0; j < polygon.size(); j++)
		{
			// 꼭짓점의 위치와 일치하다면 continue
			if (friends[i] == polygon[j] || friends[i] == polygon[(j + 1) % polygon.size()])
			{
				answer[i] = true;
				continue;
			}
			// Y값 범위에 들지 않아 검사할 필요가 없다면 continue
			int biggerY = max(polygon[j].y, polygon[(j + 1) % polygon.size()].y);
			int smallerY = polygon[j].y + polygon[(j + 1) % polygon.size()].y - biggerY;
			if (friends[i].y < smallerY || friends[i].y > biggerY)
				continue;
			
			// 1. y = friends[i].y와 선분의 교점 구하기
			// 기울기 구하기
			int deltaX = polygon[(j + 1) % polygon.size()].x - polygon[j].x;
			int deltaY = polygon[(j + 1) % polygon.size()].y - polygon[j].y;
			// 교점의 x좌표 구하기
			if (deltaY == 0)	continue;

			float crossX;
			if (deltaX == 0)	crossX = polygon[j].x;
			else				crossX = (friends[i].y - polygon[j].y + (float)deltaY / deltaX * polygon[j].x) * (float)deltaX / deltaY;

			// 2. 해당 교점이 유효한지 확인한다 - 두 지점의 사이에 있는지
			//	  유효하다면 교점 벡터에 추가한다.
			int biggerX = max(polygon[j].x, polygon[(j + 1) % polygon.size()].x);
			int smallerX = polygon[j].x + polygon[(j + 1) % polygon.size()].x - biggerX;
			if (crossX >= smallerX && crossX <= biggerX)
				cross.push_back(crossX);

		}

		// 3. friends[i].x가 교점 벡터 중 짝수-홀수 인덱스 사이의 값이라면 내부로 판별한다
		if (cross.empty())	continue;
		sort(cross.begin(), cross.end());
		unique(cross.begin(), cross.end());
		for (size_t k = 0; k < cross.size() - 1; k+=2)
		{
			if (friends[i].x >= cross[k] && friends[i].x <= cross[k + 1])
				answer[i] = true;
		}
	}

	return answer;
}

int main()
{
	int N;
	cin >> N;

	vector<POINT> polygon(N);
	for (size_t i = 0; i < N; i++)
	{
		cin >> polygon[i].x >> polygon[i].y;
	}

	vector<POINT> friends(3);
	for (size_t i = 0; i < 3; i++)
	{
		cin >> friends[i].x >> friends[i].y;
	}

	const vector<bool> res = solution(polygon, N, friends);
	for (size_t i = 0; i < 3; i++)
	{
		cout << res[i] << '\n';
	}

	return 0;
}