#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> mergeQ(scoville.begin(), scoville.end());
    while (mergeQ.top() < K)
    {
        if (mergeQ.size() < 2)  return -1;

        int newScoville = mergeQ.top();
        mergeQ.pop();
        newScoville += (mergeQ.top() * 2);
        mergeQ.pop();

        mergeQ.push(newScoville);
        answer++;
    }

    return answer;
}

int main()
{
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
    cout << solution(scoville, 7) << endl;
}