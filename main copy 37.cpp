//
//  main.cpp
//  wangyi0807
//
//  Created by Wang Bin on 8/7/21.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution{
private:
    vector<int> xiShu = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    map<char, int> idLastNum = {{'1', 0}, {'0', 1}, {'X', 2}, {'9', 3}, {'8', 4}, {'7', 5}, {'6', 6}, {'5', 7}, {'4', 8}, {'3', 9}, {'2', 10}};
public:
    
    
    void solve(string &str){
        int sum = 0;
        for(int i = 0; i < 17; ++i){
            char temp = str[i];
            if(temp != '*'){
                sum += xiShu[i] * (str[i] - '0');
            }
        }
        
        queue<int> que;
        que.push(sum);
        for(int i = 14; i < 17; ++i){
            if(str[i] == '*'){
                int size = que.size();
                for(int j = 0; j < size; ++j){
                    int tempSum = que.front();
                    que.pop();
                    for(int k = 0; k <= 9; ++k){
                        tempSum += k * xiShu[i];
                        que.push(tempSum);
                        tempSum -= k * xiShu[i];
                    }
                }
            }
        }
        
        int result = 0;
        char lastChar = str[17];
        int yuShu = idLastNum[lastChar];
        while(que.empty() != true){
            int temp = que.front();
            que.pop();
            if(temp % 11 == yuShu) result++;
        }
        
        cout << result << endl;
    }
};

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    while(T--){
        string isNumber;
        cin >> isNumber;
        
        Solution s;
        s.solve(isNumber);
    }
    
    return 0;
}
