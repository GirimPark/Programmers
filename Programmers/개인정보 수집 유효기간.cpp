//#include <string>
//#include <vector>
//#include <map>
//#include <iostream>
//
//#define YEAR_TO_DAY 336
//#define MONTH_TO_DAY 28
//
//using namespace std;
//
//vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
//    vector<int> answer;
//
//    // terms 벡터 수정
//    map<string, int> new_terms;   // type term
//    for (string s : terms)
//        new_terms.insert({ s.substr(0, 1), stoi(s.substr(2)) });
//    // privacies 벡터 순서 바꿔서 수정
//    vector<vector<string>> new_privacies;  // type day
//    for (string s : privacies)
//        new_privacies.push_back({s.substr(11, 1), s.substr(0, 10)});
//    
//    // 현재 날짜 int형 변수로 받기
//    int curYear = stoi(today.substr(0, 4));
//    int curMonth = stoi(today.substr(5, 2));
//    int curDay = stoi(today.substr(8, 2));
//    // 0000.00.00 ~ today의 일수 합계
//    int o_today = (curYear - 1) * YEAR_TO_DAY + (curMonth - 1) * MONTH_TO_DAY + curDay;
//
//    string type;
//    int term, year, month, day;
//    int o_expiration;   
//    for (int i = 0; i < new_privacies.size(); i++)
//    {
//        type = new_privacies[i][0];
//        term = new_terms.find(type)->second;
//
//        year = stoi(new_privacies[i][1].substr(0, 4));
//        month = stoi(new_privacies[i][1].substr(5, 2));
//        day = stoi(new_privacies[i][1].substr(8, 2));
//
//        // 0000.00.00 ~ 만료일의 일수 합계
//        o_expiration = (year - 1) * YEAR_TO_DAY + (month - 1) * MONTH_TO_DAY + day + term * MONTH_TO_DAY - 1;
//
//        if (o_today > o_expiration)
//            answer.push_back(i + 1);
//        
//    }
//    
//    return answer;
//}
//
//int main()
//{
//    string today = "2022.05.19";
//    vector<string> terms = { "A 6", "B 12", "C 3" };
//    vector<string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };
//    // 만료일 : 2020.24.08 > 2021.12.07
//    // 2020.06.01 > 2020.24.01-1 > 2021.12.01-1
//
//    for (int a : solution(today, terms, privacies))
//    {
//        cout << a << " ";
//    }
//    
//    return 0;
//}