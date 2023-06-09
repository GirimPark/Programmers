#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for (int i = 0; i<citations[citations.size() - 1]; i++)
    {
        for (int j = 0; j < citations.size(); j++)
        {
            if (citations[j] >= i && 
                i <= (citations.size() - j) &&
                i >= j)
                answer = i;
        }
    }

    return answer;
}

int main()
{
    vector<int> citations = { 0, 1, 2, 5, 5, 6 }; // 3
    cout << solution(citations) << endl;
}