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
//    // 1�ܰ� : new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
//    for (int i = 0; i < suggest.size(); i++)
//        if (suggest[i] > 64 && suggest[i] < 91)
//            suggest[i] += 32;
//    // 2�ܰ� : ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
//    for (int i = 0; i < suggest.size(); i++)
//        if (!((suggest[i] > 96 && suggest[i] < 123) || (suggest[i] > 47 && suggest[i] < 58)
//            || suggest[i] == '-' || suggest[i] == '_' || suggest[i] == '.')) 
//        {
//            suggest.erase(suggest.begin() + i);
//            i--;
//        }
//    // 3�ܰ� : ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
//    for(int i=0; i<suggest.size(); i++)
//        if (i > 0 && suggest[i] == '.' && suggest[i - 1] == '.')
//        {
//            suggest.erase(suggest.begin() + i);
//            i--;
//        }
//     // 4�ܰ� : new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
//    if (suggest[0] == '.') suggest.erase(suggest.begin());
//    if (suggest[suggest.size() - 1] == '.') suggest.erase(suggest.end() - 1);
//    // 5�ܰ� : new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
//    if (suggest.size() == 0)  suggest.push_back('a');
//    // 6�ܰ� : new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
//    // ���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
//    if (suggest.size() > 15) 
//    {
//        suggest.erase(suggest.begin() + 15, suggest.end());
//        if (suggest[suggest.size() - 1] == '.') suggest.erase(suggest.end() - 1);
//    }
//    // 7�ܰ� : new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
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