//
//  main.cpp
//  maxSubString
//
//  Created by Wang Bin on 8/13/21.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int len = s.size();
        //map<string, int> strMap;
        for(int i = 0; i < len; ++i){
            string temp;
            temp.clear();
            int j = i;
            while(j != len){
                temp += s[j];
                for(int k = )
                    strMap[temp] = 1;
                }
                else{
                    strMap[temp]++;
                }
                j++;
            }
        }

        int ans = 0;
        for(auto it = strMap.begin(); it != strMap.end(); it++){
            if(it->second > 1){
                string str = it->first;
                int size = str.size();
                ans = max(ans, size);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    Solution s;
    cout << s.longestRepeatingSubstring(str) << endl;
    return 0;
}
