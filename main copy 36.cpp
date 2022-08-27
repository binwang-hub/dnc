//
//  main.cpp
//  wangyi03
//
//  Created by Wang Bin on 2021/8/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算最小航行费用
     * @param input int整型vector<vector<>> 二维网格
     * @return int整型
     */
    int minSailCost(vector<vector<int> >& input) {
        int row = input.size();
        int col = input[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1));
        for(int i = 0; i <= col; i++){
            dp[0][i] = INT_MAX;
        }
        for(int i = 1; i <= row; i++){
            dp[i][0] = INT_MAX;
        }
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i == 0 &&  j == 0)
                    dp[i + 1][j + 1] = 0;
                else{
                    if(input[i][j] == 2){
                        dp[i + 1][j + 1] = INT_MAX;
                    }
                    else if(input[i][j] == 1){
                        if(dp[i + 1][j] == INT_MAX && dp[i][j + 1] != INT_MAX){
                            dp[i + 1][j + 1] = dp[i][j + 1] + 1;
                        }
                        else if (dp[i + 1][j] != INT_MAX && dp[i][j + 1] == INT_MAX){
                            dp[i + 1][j + 1] = dp[i + 1][j] + 1;
                        }
                        else if (dp[i + 1][j] == INT_MAX && dp[i][j + 1] == INT_MAX){
                            dp[i + 1][j + 1] = INT_MAX;
                        }
                        else{
                            dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i][j + 1]) + 1;
                        }
                    }
                    else{
                        if(dp[i + 1][j] == INT_MAX && dp[i][j + 1] != INT_MAX){
                            dp[i + 1][j + 1] = dp[i][j + 1] + 2;
                        }
                        else if (dp[i + 1][j] != INT_MAX && dp[i][j + 1] == INT_MAX){
                            dp[i + 1][j + 1] = dp[i + 1][j] + 2;
                        }
                        else if (dp[i + 1][j] == INT_MAX && dp[i][j + 1] == INT_MAX){
                            dp[i + 1][j + 1] = INT_MAX;
                        }
                        else{
                            dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i][j + 1]) + 2;
                        }
                    }
                }
            }
        }
        cout << dp[row][col] << endl;
        return dp[row][col];
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> nums = {{1,1,1,1,0}, {0,1,0,1,0}, {1,1,2,1,1}, {0,2,0,0,1}};
    Solution s;
    s.minSailCost(nums);
    return 0;
}
