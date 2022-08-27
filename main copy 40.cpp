//
//  main.cpp
//  xhs
//
//  Created by Wang Bin on 2021/9/4.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
/*
map<char, int> myMap = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}};

long long change(string &str){
    long long ans = 0;
    int len = str.size();
    for(int i = 0; i < len; i++){
        ans += myMap[str[i]] * pow(16, len - 1 - i);
    }
    return ans;
}
*/
int main(int argc, const char * argv[]) {
    string s;
    cin >> s;
    int len = s.size();
    long long ans = 0;
    for(int i = 0; i < len; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            ans += (s[i] - '0') * pow(16, len - 1 - i);
        }
        else{
            ans += (s[i] - 'A' + 10) * pow(16, len - 1 - i);
        }
    }
    cout << ans << endl;
    return 0;
}
