//
//  main.cpp
//  kuohao
//
//  Created by Wang Bin on 2021/8/26.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
 (A) A + 1
 AB  A * B
 */
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        for(char c:S){
            if(c == '('){     //遇到左括号入栈，用0模拟
                s.push(1);
            }
            else{       //遇到右括号进行判断
                if(s.top() == 1){     //栈顶为0即栈顶为左括号，此时为()的情况，得1分
                    s.pop();
                    s.push(2);
                }
                else{       //栈顶不为左括号即为(ABC)的情况，得分为(A+B+C)*2
                    int inScore = 1;
                    while(s.top() != 1){
                        inScore *= s.top();
                        s.pop();
                    }
                    
                    if(s.top() == 1) {
                        s.pop();
                        s.push(inScore + 1);
                    }
                }
            }
        }
        int ans = 1;
        while(!s.empty()){      //最后栈内都是分数，没有括号了，求和即可
            ans *= s.top();
            s.pop();
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    Solution s;
    cout << s.scoreOfParentheses(str) << endl;
    return 0;
}
