#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int x = (brown + yellow) / 3; x >= 3; x--) {
        if ((brown + yellow) % x != 0)   continue;
        for (int y = 3; y <= (brown + yellow) / 3; y++) {
            if ((brown + yellow) % y != 0) continue;
            if ((x * y == (brown + yellow)) &&
                (x + y) == (brown + 4) / 2)
            {
                answer.push_back(x);
                answer.push_back(y);
                return answer;
            }
        }
    }
}

int main()
{
    int brown = 24;
    int yellow =24;
    for (const auto& answer : solution(brown, yellow))
        cout << answer << " ";
    cout << "\n";
    return 0;
}