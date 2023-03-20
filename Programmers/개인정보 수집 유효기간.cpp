#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    // terms 벡터 수정
    map<string, int> new_terms;   // type term
    for (string s : terms)
        new_terms.insert({ s.substr(0, 1), stoi(s.substr(2)) });
    // privacies 벡터 순서 바꿔서 수정
    vector<vector<string>> new_privacies;  // type day
    for (string s : privacies)
        new_privacies.push_back({s.substr(11, 1), s.substr(0, 10)});
    
    // 현재 날짜 int형 변수로 받기
    int curYear = stoi(today.substr(0, 4));
    int curMonth = stoi(today.substr(5, 2));
    int curDay = stoi(today.substr(8, 2));

    string type;
    int term, year, month, day;
    string expiration;
    int exYear=0, exMonth=0, exDay=0;
    for (int i = 0; i < new_privacies.size(); i++)
    {
        type = new_privacies[i][0];
        term = new_terms.find(type)->second;
        if (new_privacies[i][0] == type)
        {
            year = stoi(new_privacies[i][1].substr(0, 4));
            month = stoi(new_privacies[i][1].substr(5, 2));
            day = stoi(new_privacies[i][1].substr(8, 2));

            if ((month + term) < 13 && day > 1)   // year, month 넘어가지 않음
            {
                exYear = year; 
                exMonth = month + term; 
                exDay = day - 1;
            }
            else if ((month + term) < 13 && day == 1) // month 넘어감
            {
                exYear = year; 
                exMonth = month + term - 1; 
                exDay = 28;
            }
            else if ((month + term) > 12 && day > 1)  // year 넘어감
            {
                exYear = year + (month + term) / 12; 
                exMonth = month + term - 12 * ((month + term) / 12); 
                exDay = day - 1;
            }
            else if ((month + term) > 12 && day == 1) // year, day 넘어감
            {
                exYear = year + (month + term) / 12; 
                exMonth = month + term - 12 * ((month + term) / 12) - 1; 
                exDay = 28;
            }

            if (exYear < curYear)
                answer.push_back(i + 1);
            else if (exYear == curYear && exMonth < curMonth)
                answer.push_back(i + 1);
            else if (exYear == curYear && exMonth == curMonth && exDay < curDay)
                answer.push_back(i + 1);
        }
    }
    
    return answer;
}

int main()
{
    string today = "2021.12.08";
    vector<string> terms = { "A 18" };
    vector<string> privacies = { "2020.06.08 A" };
    // 만료일 : 2020.24.08 2021.12.08

    for (int a : solution(today, terms, privacies))
    {
        cout << a << " ";
    }
    
    return 0;
}