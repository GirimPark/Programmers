#include <iostream>
#include<vector>
#include<queue>
using namespace std;

struct Vec2
{
    int x;
    int y;
};

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n = maps.size() - 1;
    int m = maps[0].size() - 1;
    Vec2 startPos = { n, m };
    Vec2 endPos = { 0, 0 };
    if (maps[n][m] == 0) return -1;

    vector<vector<int>> bfsMap(n + 1, vector<int>(m + 1, 0));


    queue<Vec2> bfs;
    bfs.push(startPos);

    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

    Vec2 curPos = startPos;
    bfsMap[curPos.x][curPos.y] = 1;

    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    while (!bfs.empty())
    {
        curPos = bfs.front();
        int x = curPos.x, y = curPos.y;
        visited[x][y] = true;

        if (curPos.x == endPos.x && curPos.y == endPos.y)
            break;

        bfs.pop();

        for (int i = 0; i < 4; i++) // ╩С ©Л го аб
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx<0 || nx > n || ny<0 || ny>m)  continue;
            if (maps[nx][ny] == 0)   continue;
            if (visited[nx][ny]) continue;

            bfs.push({ nx, ny });
            visited[nx][ny] = true;
            bfsMap[nx][ny] = bfsMap[x][y] + 1;
        }
    }
    if (curPos.x == endPos.x && curPos.y == endPos.y)
        answer = bfsMap[curPos.x][curPos.y];
    else
        answer = -1;

    return answer;
}

int main()
{
    vector<vector<int>> maps
        = { {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} };

    cout <<solution(maps) <<endl;
}