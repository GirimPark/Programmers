
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <sstream>
//#include <map>
//#include <iostream>
//
//using namespace std;
//
//vector<int> solution(vector<string> id_list, vector<string> report, int k) {
//    vector<int> answer;
//    for (int i = 0; i < id_list.size(); i++) {
//        answer.push_back(0);
//    }
//
//    // 1. report���� �ߺ� ���ֱ�
//    sort(report.begin(), report.end());
//    report.erase(unique(report.begin(), report.end()), report.end());
//
//    // 2. �Ű���, �ǽŰ��� ����
//    vector<string> reporter;
//    vector<string> receiver;
//    string temp1, temp2;
//    for (int i = 0; i < report.size(); i++) {
//        istringstream ss(report[i]);
//        ss >> temp1 >> temp2;
//        reporter.push_back(temp1);
//        receiver.push_back(temp2);
//    }
//   
//    // 3. �ǽŰ��� �Ű� Ƚ�� ����
//    map<string, int> reporterMap;
//    map<string, int> receiverMap;
//    for (int i = 0; i < id_list.size(); i++) {
//        reporterMap.insert({ id_list[i], 0 });
//    }
//    for (int i = 0; i < id_list.size(); i++) {
//        receiverMap.insert({ id_list[i], 0 });
//    }
//
//    for (int i = 0; i < receiver.size(); i++) {
//        receiverMap[receiver[i]]++;
//    }
//
//    // 4. 
//    
//    // 3. ���� ó���� ���� Ȯ��, report ���Ϳ��� �����Ͽ� �Ű����� result++
//    string restriction;
//    
//    for (int i = 0; i < receiverMap.size(); i++) {
//        if (receiverMap[receiver[i]] >= k) {
//            restriction = receiver[i];  //  �������� Ȯ�� frodo
//            for (int j = 0; j < id_list.size(); j++) {
//                if (restriction.compare(receiver[j])) { 
//                    reporterMap[reporter[j]]++;
//                    //for (int k = 0; k < answer.size(); k++) {
//                    //    if (id_list[k] == reporter[j]) {    //reporter[j] == apeach
//                    //        answer[k]++;
//                    //        break;
//                    //    }
//                    //}
//                }
//            }
//        }
//    }
//
//    for (int i = 0; i < answer.size(); i++) {
//        cout << reporterMap[id_list[i]] << endl;
//    }
//
//    return answer;
//}
//
//int main() {
//    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
//    vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
//    int k = 2;
//
//    /*vector<string> id_list = { "con", "ryan" };
//    vector<string> report = { "ryan con", "ryan con", "ryan con", "ryan con" };
//    int k = 3;*/
//
//    solution(id_list, report, k);
//}
