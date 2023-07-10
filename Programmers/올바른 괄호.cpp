#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
	bool answer = true;

	stack<char> open;
	for (const char& i : s)
	{
		if (i == '(')
		{
			open.push(i);
		}
		else
		{
			if (!open.empty())	open.pop();
			else				return false;
		}
	}

	if (!open.empty())	answer = false;

	return answer;
}

int main()
{
	cout << solution("()()") << endl;
	cout << solution("(()(") << endl;
}