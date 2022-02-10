#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    report.erase(unique(report.begin(), report.end()), report.end());
    
    unordered_map<string, int> idx_map;
    unordered_map<string, set<string>> report_map;
    
    for (int i=0, size=id_list.size(); i<size; i++) {
        idx_map[id_list[i]] = i;
    }
    
    stringstream ss;
    for (string s: report) {
        ss.str(s);
        string reporter, target;
        
        ss >> reporter >> target; 
        report_map[target].insert(reporter);
        
        ss.clear();
    }
    
    for(auto it: report_map) { 
        if(it.second.size() >= k) {
            for (auto set_it: it.second) {
                answer[idx_map[set_it]]++;
            }
        }
    }
    
    return answer;
}
