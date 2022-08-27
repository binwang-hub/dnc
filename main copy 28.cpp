//
//  main.cpp
//  tx02
//
//  Created by wangbin on 2021/8/21.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
private:
    string s;
    int n;
    string str;
    vector<string> result;

    void getData(){
        cin >> s >> n;
    }
    
    void backTracking(string str, int start){
        if(start == s.size()){
            //result.push_back(str);
            return;
        }
        
        if(start < s.size()){
            result.push_back(str);
            return;
        }
        
        for(int i = start; i < s.size(); i++){
            str.push_back(s[i]);
            backTracking(str, i + 1);
            str.pop_back();
        }
    }
public:
    string solve(){
        getData();
        backTracking(str, 0);
        return result[n];
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << "look :" << s.solve() << endl;
    return 0;
}
