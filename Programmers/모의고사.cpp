//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> answers) {
//    vector<int> answer;
//    vector<int> arr2 = { 1,3,4,5 };
//    vector<int> arr3 = { 3,1,2,4,5 };
//    int c1 = 0, c2 = 0, c3 = 0;
//
//    for (int i = 0; i < answers.size(); i++) {
//        //  1번: (i=1)i++
//        if (answers[i] == i % 5 + 1) c1++;
//
//        //  2번: 배열[1,3,4,5] 짝수번째=2, 홀수번째=1,3,4,5
//        if (i % 2 == 0) {
//            if (answers[i] == 2) c2++;
//        }
//        else {
//            if (answers[i] == arr2[(i / 2) % arr2.size()]) c2++;
//        }
//
//        //  3번: 배열[3,1,2,4,5] (i/2) % arr3.size()
//        if (answers[i] == arr3[(i / 2) % arr3.size()]) c3++;
//    }
//
//    vector<int> scores = { c1,c2,c3 };
//    sort(scores.begin(), scores.end());
//
//    if (scores[2] == scores[1] && scores[2] != scores[0])
//        scores.erase(scores.begin() + 0);
//    else if (scores[2] != scores[1]) {
//        scores.erase(scores.begin() + 1);
//        scores.erase(scores.begin() + 0);
//    }
//
//    for (int i = 0; i < scores.size(); i++) {
//        if (scores[i] == c1) answer.push_back(1);
//        if (scores[i] == c2) answer.push_back(2);
//        if (scores[i] == c3) answer.push_back(3);
//        if (answer.size() == scores.size()) break;
//    }
//
//    return answer;
//}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3);

    vector<int> player1(answers.size()),
                player2(answers.size()),
                player3(answers.size());
    vector<int> player2Sub = { 1, 3, 4, 5 };
    vector<int> player3Sub = { 3,3,1,1,2,2,4,4,5,5 };

    // 정답 벡터 만들기
    for (size_t i = 0; i < answers.size(); i++)
    {
        player1[i] = i % 5 + 1;
        
        if (i % 2 == 0)
            player2[i] = 2;
        else
            player2[i] = player2Sub[(i / 2) % player2Sub.size()];
        
        player3[i] = player3Sub[i % player3Sub.size()];
    }
    
    // 채점
    for (size_t i = 0; i < answers.size(); i++)
    {
        if (answers[i] == player1[i])
            score[0]++;
        if (answers[i] == player2[i])
            score[1]++;
        if (answers[i] == player3[i])
            score[2]++;
    }

    int max = 0;
    for (const auto& iter : score)
    {
        if (iter > max)
            max = iter;
    }
    for (size_t i = 0; i < score.size(); i++)
    {
        if (score[i] == max)
            answer.push_back(i + 1);
    }
    
    return answer;
}

int main()
{
    vector<int> answer = { 1,3,2,4,2 };
    vector<int> output = solution(answer);
    for (size_t i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}