//
//  main.cpp
//  tx003
//
//  Created by Wang Bin on 2021/8/22.
//

#include <iostream>
#include <set>
#include <string>
using namespace std;

class Solution{
private:
    set<string> strSet;
    string str;
public:
    void backTracking(string &s, int n, int start, string str){
        if(str.size() == n){
            strSet.insert(str);
            return;
        }
        for(int i = start; i < n; i++){
            str.push_back(s[i]);
            backTracking(s, n, i + 1, str);
            str.pop_back();
        }
    }
    
    string solve(string &s, int n){
        backTracking(s, n, 0, str);
        auto it = strSet.begin();
        return *it;
    }
};

int main(int argc, const char * argv[]) {
    int M, N;
    cin >> M >> N;
    string str;
    cin >> str;
    Solution s;
    cout << s.solve(str, N) << endl;
    return 0;
}
