#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    stack<int> pick;

    for (auto& move : moves)
    {
        move--;
        for (auto& i : board)
        {
            if (i[move] != 0)
            {
                if (pick.size() > 0 && pick.top() == i[move])
                {
                    pick.pop();
                    answer += 2;
                }
                else
                    pick.push(i[move]);
                i[move] = 0;
                break;
            }
        }
    }
    
    return answer;
}

int main()
{
    vector<vector<int>> board = { {0, 0, 0, 0, 0}, 
                                  {0, 0, 1, 0, 3},
                                  {0, 2, 5, 0, 1},
                                  {4, 2, 4, 4, 2},
                                  {3, 5, 1, 3, 1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };
    cout << solution(board, moves) << endl;

    return 0;
}