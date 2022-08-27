//
//  main.cpp
//  huawei11
//
//  Created by Wang Bin on 2021/9/13.
//
//借助strtok实现split
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
    string s = "how are you ";
    int len = (int)s.size();
    string str;
    string temp;
    for(int i = 0; i < len; i++){
        if(s[i] != ' '){
            temp.push_back(s[i]);
        }
        else{
            reverse(temp.begin(), temp.end());
            str += temp;
            temp.clear();
            str += ' ';
        }
    }
    cout << str << endl;
    return 0;
}

