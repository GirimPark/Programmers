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

    map<string, vector<int>> reportMap;   // id, {유효신고한 횟수, 신고당한 횟수}
    for (const auto& id : id_list)
        reportMap.insert({ id, { 0, 0 } });

    // reports에서 신고 내역을 map으로 정리
    string reporter, receiver;
    for (const auto& report : reports)
    {
        stringstream ss(report);
        ss.str(report);
        ss >> reporter >> receiver;
        reportMap.find(receiver)->second[1]++;
    }

    // 신고당한 유저의 reportMap 확인, 정지라면 신고한 유저의 reportMap 유효신고한 횟수 증가
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