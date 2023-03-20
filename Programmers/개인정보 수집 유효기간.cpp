#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    // terms º¤ÅÍ ¼öÁ¤
    map<string, int> new_terms;   // type term
    for (string s : terms)
        new_terms.insert({ s.substr(0, 1), stoi(s.substr(2)) });
    // privacies º¤ÅÍ ¼ø¼­ ¹Ù²ã¼­ ¼öÁ¤
    vector<vector<string>> new_privacies;  // type day
    for (string s : privacies)
        new_privacies.push_back({s.substr(11, 1), s.substr(0, 10)});
    
    string type;
    int term, year, month, day;
    string expiration;

    for (int i = 0; i < new_privacies.size(); i++)
    {
        type = new_privacies[i][0];
        term = new_terms.find(type)->second;
        if (new_privacies[i][0] == type)
        {
            year = stoi(new_privacies[i][1].substr(0, 4));
            month = stoi(new_privacies[i][1].substr(5, 2));
            day = stoi(new_privacies[i][1].substr(8, 2));

            if (month + term < 12 && day > 1)    expiration = to_string(year) + "." + to_string(month + term) + "." + to_string(day - 1);
            else if (month + term < 13 && day == 1) expiration = to_string(year) + "." + to_string(month + term - 1) + ".28";
            else if (month)
            
        }
    }
    
    return answer;
}

int main()
{
    string today = "2022.05.19";
    vector<string> terms = { "A 6", "B 12", "C 3" };
    vector<string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };

    for (int a : solution(today, terms, privacies))
    {
        //cout << a << " ";
    }
    
    return 0;
}