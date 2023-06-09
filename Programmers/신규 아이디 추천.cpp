//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//string solution(string new_id) {
//    string answer = "";
//    vector<char> suggest;
//
//    for (int i = 0; i < new_id.size(); i++)
//        suggest.push_back(new_id[i]);
//
//    // 1단계 : new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
//    for (int i = 0; i < suggest.size(); i++)
//        if (suggest[i] > 64 && suggest[i] < 91)
//            suggest[i] += 32;
//    // 2단계 : 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
//    for (int i = 0; i < suggest.size(); i++)
//        if (!((suggest[i] > 96 && suggest[i] < 123) || (suggest[i] > 47 && suggest[i] < 58)
//            || suggest[i] == '-' || suggest[i] == '_' || suggest[i] == '.')) 
//        {
//            suggest.erase(suggest.begin() + i);
//            i--;
//        }
//    // 3단계 : 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
//    for(int i=0; i<suggest.size(); i++)
//        if (i > 0 && suggest[i] == '.' && suggest[i - 1] == '.')
//        {
//            suggest.erase(suggest.begin() + i);
//            i--;
//        }
//     // 4단계 : new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
//    if (suggest[0] == '.') suggest.erase(suggest.begin());
//    if (suggest[suggest.size() - 1] == '.') suggest.erase(suggest.end() - 1);
//    // 5단계 : new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
//    if (suggest.size() == 0)  suggest.push_back('a');
//    // 6단계 : new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
//    // 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
//    if (suggest.size() > 15) 
//    {
//        suggest.erase(suggest.begin() + 15, suggest.end());
//        if (suggest[suggest.size() - 1] == '.') suggest.erase(suggest.end() - 1);
//    }
//    // 7단계 : new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
//    while (suggest.size() < 3) 
//    {
//        char temp = suggest[suggest.size() - 1];
//        suggest.push_back(temp);
//    }
//            
//    for (int i = 0; i < suggest.size(); i++)
//        answer += suggest[i];
//    return answer;
//}
//
//int main()
//{
//    string new_id = "...!@BaT#*..y.abcdefghijklm";
//    cout << solution(new_id) << endl;
//
//    return 0;
//}