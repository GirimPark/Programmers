#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> reports, int k) {
    vector<int> answer(id_list.size());

    sort(reports.begin(), reports.end());
    reports.erase(unique(reports.begin(), reports.end()), reports.end());

    map<string, vector<int>> reportMap;   // id, {��ȿ�Ű��� Ƚ��, �Ű���� Ƚ��}
    for (const auto& id : id_list)
        reportMap.insert({ id, { 0, 0 } });

    // reports���� �Ű� ������ map���� ����
    string reporter, receiver;
    for (const auto& report : reports)
    {
        stringstream ss(report);
        ss.str(report);
        ss >> reporter >> receiver;
        reportMap.find(receiver)->second[1]++;
    }

    // �Ű���� ������ reportMap Ȯ��, ������� �Ű��� ������ reportMap ��ȿ�Ű��� Ƚ�� ����
    for (auto& report : reports)
    {
        stringstream ss(report);
        ss.str(report);
        ss >> reporter >> receiver;
        
        if (reportMap.find(receiver)->second[1] >= k)
            reportMap.find(reporter)->second[0]++;
    }

    for (int i=0; i<id_list.size(); i++)
    {
        answer[i] = reportMap.find(id_list[i])->second[0];
    }

    return answer;
}

int main()
{
    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
    int k = 2;
    vector<int> answer = solution(id_list, report, k);
    for (const auto& i : answer)
        cout << i << " ";
    cout << "\n";
    return 0;
}