//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//string solution(vector<string> participant, vector<string> completion) 
//{
//    string answer = "";
//
//    if (participant.size() == 1)
//        return participant[0];
//
//    sort(participant.begin(), participant.end());
//    sort(completion.begin(), completion.end());
//    for (int i = 0; i < completion.size(); i++)
//    {
//        if (participant[i] != completion[i])
//        {
//            answer = participant[i];
//            break;
//        }
//        else
//            answer = participant[participant.size() - 1];
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<string> participant = { "mislav", "stanko", "mislav", "ana" };   // ana mislav mislav stanko
//    vector<string> completion = { "stanko", "ana", "mislav" };              // ana mislav stanko
//    cout << solution(participant, completion)<<endl;
//
//    return 0;
//}