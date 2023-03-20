//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//vector<vector<int>> score(4, vector<int>(2, 0));   //RT CF JM AN
//
//void setScore(char character, int num) {
//    if (character == 'R')
//        score[0][0] += num;
//    else if (character == 'T')
//        score[0][1] += num;
//    else if (character == 'C')
//        score[1][0] += num;
//    else if (character == 'F')
//        score[1][1] += num;
//    else if (character == 'J')
//        score[2][0] += num;
//    else if (character == 'M')
//        score[2][1] += num;
//    else if (character == 'A')
//        score[3][0] += num;
//    else if (character == 'N')
//        score[3][1] += num;
//}
//
//string solution(vector<string> survey, vector<int> choices) {
//    string answer = "";
//
//    //  설문 확인, score 벡터에 점수 조정
//    for (int i = 0; i < survey.size(); i++) {
//        if (choices[i] < 4) {
//            setScore(survey[i][0], 4-choices[i]);
//        }
//        else if (choices[i] > 4) {
//            setScore(survey[i][1], choices[i]-4);
//        }
//    }
//
//    //  점수 확인, 결과 도출
//    if (score[0][1] > score[0][0])
//        answer += "T";
//    else
//        answer += "R";
//    if (score[1][1] > score[1][0])
//        answer += "F";
//    else
//        answer += "C";
//    if (score[2][1] > score[2][0])
//        answer += "M";
//    else
//        answer += "J";
//    if (score[3][1] > score[3][0])
//        answer += "N";
//    else
//        answer += "A";
//
//    return answer;
//}
//
//int main() {
//    vector<string> survey = { "AN", "CF", "MJ", "RT", "NA" };
//    vector<int> choices = { 5,3,2,7,5 };
//
//    solution(survey, choices);
//}