//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int solution(vector<int> nums)
//{
//	int answer = 0;
//	int select = nums.size() / 2;
//	sort(nums.begin(), nums.end());
//	nums.erase(unique(nums.begin(), nums.end()), nums.end());
//
//	if (nums.size() >= select)
//		answer = select;
//	else
//		answer = nums.size();
//
//	return answer;
//}
//
//// �ð� �ʰ�
////int solution(vector<int> nums) 
////{
////	int answer = 0;
////	sort(nums.begin(), nums.end());
////	
////	vector<int> temp(0);
////	do
////	{
////		//	next_permutation���� ���� ������ temp�� push
////		for (int i = 0; i < nums.size() / 2; i++)
////			temp.push_back(nums[i]);	// 3 1
////		
////		// temp ���� �� unique+erase�� �ߺ� ����
////		sort(temp.begin(), temp.end());
////		temp.erase(unique(temp.begin(), temp.end()), temp.end());
////
////		// temp�� ����� �ִ밪���� Ȯ��
////		if (temp.size() > answer)	answer = temp.size();
////		temp.clear();
////	} while (next_permutation(nums.begin(), nums.end()));
////
////	return answer;
////}
//
//int main() 
//{
//	vector<int> nums = { 3,3,3,2,2,4 };
//	cout << solution(nums) << endl;
//	return 0;
//}