//
//  main.cpp
//  shoopee
//
//  Created by Wang Bin on 2021/9/6.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     *
     *
     * @param s string字符串
     * @return string字符串vector
     */
    vector<string> permutation(string s) {
        // write code here
        if(s.empty()) return {};
        sort(s.begin(), s.end());
        vector<string> str;
        str.push_back(s);
        while(next_permutation(s.begin(), s.end())){
            str.push_back(s);
        }
        sort(str.begin(), str.end());
        str.erase(unique(str.begin(), str.end()), str.end());
        for(auto &it : str){
            cout << it << endl;
        }
        cout << str.size() << endl;
        return str;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.permutation("aabac");
    return 0;
}
