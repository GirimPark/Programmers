#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <iostream>

using namespace std;
string solution(vector<int> numbers, string hand) {
    string answer = "";
    map<int, vector<int>> keypad = { {1, {0,0}}, {2, {0,1}}, {3, {0,2}}
                                    ,{4, {1,0}}, {5, {1,1}}, {6, {1,2}}
                                    ,{7, {2,0}}, {8, {2,1}}, {9, {2,2}}
                                    ,{10, {3,0}}, {0, {3,1}}, {11, {3,2}} }; // *==10, #==11

    int left = 10, right = 11;
    int disL = 0, disR = 0;
    for (const auto& num : numbers)
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
        else 
        {
            // �޼� �Ÿ� ���ϱ�
            disL = abs(keypad.find(left)->second[0] - keypad.find(num)->second[0])
                + abs(keypad.find(left)->second[1] - keypad.find(num)->second[1]);
            // ������ �Ÿ� ���ϱ�
            disR = abs(keypad.find(right)->second[0] - keypad.find(num)->second[0])
                + abs(keypad.find(right)->second[1] - keypad.find(num)->second[1]);

            if(disL > disR)
            {
                answer += "R";
                right = num;
            }
            else if (disL < disR)
            {
                answer += "L";
                left = num;
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
        }
    }

    return answer;
}

//string solution(vector<int> numbers, string hand) {
//    string answer = "";
//    
//    // 1 2 3
//    // 4 5 6
//    // 7 8 9
//    // * 0 #
//    // 
//    // �Ÿ� ���
//    // �¿� : 0 or 1
//    // (next-cur)%3==0 > 0
//    // (next-cur)%3!=0 > 1
//    // 
//    // ���� : 0 or 1 or 2 or 3(cur�Ǵ�next == 0�� ���)
//    // (0����x) (cur-1)/3 - (next-1)/3 == 0 or 1 or 2
//    // if(next==0) cur>4, cur>7, cur>10
//    // 
//    // ù �Ÿ���� ���̽�
//    // if(next==0, 8, 5, 2)
//
//    //error : test 14~20
//
//    int left = -1, right = -1;
//    int disL = 0, disR = 0;
//    for (int num : numbers)
//    {
//        if (num == 1 || num == 4 || num == 7)
//        {
//            answer += "L";
//            left = num;
//        }
//        else if (num == 3 || num == 6 || num == 9)
//        {
//            answer += "R";
//            right = num;
//        }
//        else if (num == 2 || num == 5 || num == 8 || num == 0)  // �Ÿ� ����� �ʿ��� ���
//        {
//            if (left > -1)  // �޼� �Ÿ� ��� : ó���� �ƴ� ���
//            {
//                if (left!=0 && num == 0) // 1~9 > 0 �Ÿ� ���
//                {
//                    if (left % 3 != 2) disL += 1;  // �޼� �¿� �Ÿ�
//                    if (left < 4)   disL += 3; // �޼� ���� �Ÿ�
//                    else if (left > 7) disL += 2;
//                    else disL += 1;
//                }
//                else if(left!=0 && num!=0)   // 1~9 > !0 �Ÿ� ���
//                {
//                    if (abs(num - left) % 3 != 0)  disL += 1;   // �޼� �¿� �Ÿ�
//                    disL += abs((num - 1) / 3 - (left - 1) / 3);    // �޼� ���� �Ÿ�
//                }
//                else if (left == 0 && num != 0) // 0 > 2,5,8,0 �Ÿ� ���
//                {
//                    disL = (11 - num) / 3;
//                }
//            }
//            else    // �޼� �Ÿ� ��� :*���� ����
//            {
//                switch (num)
//                {
//                case 0:
//                    disL = 1;
//                    break;
//                case 8:
//                    disL = 2;
//                    break;
//                case 5:
//                    disL = 3;
//                    break;
//                case 2:
//                    disL = 4;
//                    break;
//                }
//            }
//
//            if (right > -1) // ������ �Ÿ� ��� : ó���� �ƴ� ���
//            {
//                if (right != 0 && num == 0) // 1~9 > 0 �Ÿ� ���
//                {
//                    if (right % 3 != 2) disR += 1;  // �޼� �¿� �Ÿ�
//                    if (right < 4)   disR += 3; // �޼� ���� �Ÿ�
//                    else if (right > 7) disR += 2;
//                    else disR += 1;
//                }
//                else if (right != 0 && num != 0)   // 1~9 > !0 �Ÿ����
//                {
//                    if (abs(num - right) % 3 != 0)  disR += 1;   // ������ �¿� �Ÿ�
//                    disR += abs((num - 1) / 3 - (right - 1) / 3);    // ������ ���� �Ÿ�
//                }
//                else if (right == 0 && num != 0) // 0 > 2,5,8,0 �Ÿ� ���
//                {
//                    disR = (11 - num) / 3;
//                }
//            }
//            else    // ������ �Ÿ� ��� :*���� ����
//            {
//                switch (num)
//                {
//                case 0:
//                    disR = 1;
//                    break;
//                case 8:
//                    disR = 2;
//                    break;
//                case 5:
//                    disR = 3;
//                    break;
//                case 2:
//                    disR = 4;
//                    break;
//                }
//            }
//
//            // �Ÿ� ��� ��, ����
//            if (disL < disR)
//            {
//                answer += "L";
//                left = num;
//            }
//            else if (disL > disR) 
//            {
//                answer += "R";
//                right = num;
//            }
//            else 
//            {
//                if (hand == "right") 
//                {
//                    answer += "R";
//                    right = num;
//                }
//                else
//                {
//                    answer += "L";
//                    left = num;
//                }
//            }
//                
//            disL = 0; disR = 0;
//            
//        }
//    }
//
//    return answer;
//}

int main()
{
    vector<int> numbers = { 0, 0, 6, 5, 5, 8 };
    string hand = "left";

    cout << solution(numbers, hand) << endl;

    return 0;
}