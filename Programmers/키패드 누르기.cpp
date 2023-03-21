#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    // 1 2 3
    // 4 5 6
    // 7 8 9
    // * 0 #
    // 
    // 거리 계산
    // 좌우 : 0 or 1
    // (next-cur)%3==0 > 0
    // (next-cur)%3!=0 > 1
    // 
    // 상하 : 0 or 1 or 2 or 3(cur또는next == 0일 경우)
    // (0포함x) (cur-1)/3 - (next-1)/3 == 0 or 1 or 2
    // if(next==0) cur>4, cur>7, cur>10
    // 
    // 첫 거리계산 케이스
    // if(next==0, 8, 5, 2)

    //error : test 14~20

    int left = -1, right = -1;
    int disL = 0, disR = 0;
    for (int num : numbers)
    {
        if (num == 1 || num == 4 || num == 7)
        {
            answer += "L";
            left = num;
        }
        else if (num == 3 || num == 6 || num == 9)
        {
            answer += "R";
            right = num;
        }
        else if (num == 2 || num == 5 || num == 8 || num == 0)  // 거리 계산이 필요한 경우
        {
            if (left > -1)  // 왼손 거리 계산 : 처음이 아닌 경우
            {
                if (left!=0 && num == 0) // 1~9 > 0 거리 계산
                {
                    if (left % 3 != 2) disL += 1;  // 왼손 좌우 거리
                    if (left < 4)   disL += 3; // 왼손 상하 거리
                    else if (left > 7) disL += 2;
                    else disL += 1;
                }
                else if(left!=0 && num!=0)   // 1~9 > !0 거리 계산
                {
                    if (abs(num - left) % 3 != 0)  disL += 1;   // 왼손 좌우 거리
                    disL += abs((num - 1) / 3 - (left - 1) / 3);    // 왼손 상하 거리
                }
                else if (left == 0 && num != 0) // 0 > 2,5,8,0 거리 계산
                {
                    disL = (11 - num) / 3;
                }
            }
            else    // 왼손 거리 계산 :*에서 시작
            {
                switch (num)
                {
                case 0:
                    disL = 1;
                    break;
                case 8:
                    disL = 2;
                    break;
                case 5:
                    disL = 3;
                    break;
                case 2:
                    disL = 4;
                    break;
                }
            }

            if (right > -1) // 오른손 거리 계산 : 처음이 아닌 경우
            {
                if (right != 0 && num == 0) // 1~9 > 0 거리 계산
                {
                    if (right % 3 != 2) disR += 1;  // 왼손 좌우 거리
                    if (right < 4)   disR += 3; // 왼손 상하 거리
                    else if (right > 7) disR += 2;
                    else disR += 1;
                }
                else if (right != 0 && num != 0)   // 1~9 > !0 거리계산
                {
                    if (abs(num - right) % 3 != 0)  disR += 1;   // 오른손 좌우 거리
                    disR += abs((num - 1) / 3 - (right - 1) / 3);    // 오른손 상하 거리
                }
                else if (right == 0 && num != 0) // 0 > 2,5,8,0 거리 계산
                {
                    disR = (11 - num) / 3;
                }
            }
            else    // 오른손 거리 계산 :*에서 시작
            {
                switch (num)
                {
                case 0:
                    disR = 1;
                    break;
                case 8:
                    disR = 2;
                    break;
                case 5:
                    disR = 3;
                    break;
                case 2:
                    disR = 4;
                    break;
                }
            }

            // 거리 계산 끝, 결정
            if (disL < disR)
            {
                answer += "L";
                left = num;
            }
            else if (disL > disR) 
            {
                answer += "R";
                right = num;
            }
            else 
            {
                if (hand == "right") 
                {
                    answer += "R";
                    right = num;
                }
                else
                {
                    answer += "L";
                    left = num;
                }
            }
                
            disL = 0; disR = 0;
            
        }
    }

    return answer;
}

int main()
{
    vector<int> numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
    string hand = "left";

    cout << solution(numbers, hand) << endl;

    return 0;
}