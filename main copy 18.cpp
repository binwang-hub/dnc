//
//  main.cpp
//  mt03
//
//  Created by Wang Bin on 2021/8/22.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution{
public:
    int solve(string str){
        stack<int> s;
        s.push(1);
        for(auto &c : str){
            if(c == '('){
                s.push(1);
            }
            else{
                int temp1 = s.top();
                s.pop();
                int temp2 = s.top();
                s.pop();
                if(temp2 == 1){
                    s.push((temp1+1) * temp2);
                }
                else{
                    s.pop();
                    s.push(temp1 * temp2 + 1);
                }
                    
            }
        }
        return s.top();
    }
};

int main(int argc, const char * argv[]) {
    string ss;
    cin >> ss;
    Solution s;
    cout << s.solve(ss) << endl;
    return 0;
}
