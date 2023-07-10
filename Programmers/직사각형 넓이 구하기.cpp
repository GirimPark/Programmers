#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;

    int width = 0, height = 0;

    int pointX = dots[0][0];
    int pointY = dots[0][1];
    for (size_t i = 1; i < dots.size(); i++)
    {
        if (pointX == dots[i][0])  height = abs(pointY - dots[i][1]);
        if (pointY == dots[i][1])  width = abs(pointX - dots[i][0]);
    }
    answer = width * height;

    return answer;
}

int main()
{
    vector<vector<int>> dots(4);
    dots[0].push_back(1);
    dots[0].push_back(1);
    dots[1].push_back(2);
    dots[1].push_back(1);
    dots[2].push_back(2);
    dots[2].push_back(2);
    dots[3].push_back(1);
    dots[3].push_back(2);

    cout << solution(dots) << endl;
}