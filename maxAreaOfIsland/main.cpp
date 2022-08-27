//
//  main.cpp
//  maxAreaOfIsland
//
//  Created by Wang Bin on 8/5/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> result;
    int dfs(vector<vector<int>>& grid, int cur_i, int cur_j) {
        if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
            return 0;
        }
        grid[cur_i][cur_j] = 0;
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        int ans = 1;
        for (int index = 0; index != 4; ++index) {
            int next_i = cur_i + di[index], next_j = cur_j + dj[index];
            ans += dfs(grid, next_i, next_j);
        }
        return ans;
    }
public:
    void maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        result.push_back(ans);
    }
    
    void shuChu(){
        for(auto &i : result){
            cout << i << endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    int N, m, n;
    cin >> N >> m >> n;
    vector<vector<int>> nums(m, vector<int>(n));
    Solution s;
    while(N--){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> nums[i][j];
            }
        }
        s.maxAreaOfIsland(nums);
    }
    s.shuChu();
    return 0;
}




