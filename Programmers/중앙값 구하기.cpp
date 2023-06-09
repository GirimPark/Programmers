#include <string>
#include <vector>
//#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int min = 1000; // INT_MAX
    int idx = 0;
    int cnt = 0;

    while (cnt <= array.size() / 2)
    {
        min = 1000; // INT_MAX

        for (size_t i = 0; i < array.size(); i++)
        {
            if (array[i] < min)
            {
                min = array[i];
                idx = i;
            }
        }

        answer = min;
        array[idx] = 1000; // INT_MAX
        cnt++;
    }
    
    return answer;
}

int main()
{
    vector<int> array = { 9, -1, 0 };
    cout << solution(array) << endl;
}