//
//  main.cpp
//  jbt01
//
//  Created by Wang Bin on 2021/8/24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    int n, m;
    vector<vector<int>> nums;
    int result = 0;
    void getData(){
        cin >> n >> m;
        nums.clear();
        vector<vector<int>> nums(n, vector<int>(m));
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                cin >> nums[i][j];
            }
        }
    }
    bool check(vector<vector<bool>> &seted, int i, int j){
        bool ans = false;
        if(i - 1 >= 0 && nums[i- 1][j] == 1){
            if(seted[i- 1][j] == true) ans = true;
        }
        if(i + 1 < n && nums[i + 1][j] == 1){
            if(seted[i + 1][j] == true) ans = true;
        }
        if(j - 1 >= 0 && nums[i][j - 1] == 1){
            if(seted[i][j - 1] == true) ans = true;
        }
        if(j + 1 < m && nums[i][j + 1] == 1){
            if(seted[i][j + 1] == true) ans = true;
        }
        return ans;
    }
    void backTracking(vector<vector<bool>> seted, int start, int end){
        if(check(seted, start, end) == false){
            result++;
        }
        if(start == n && end == m) return;
        for(int i = start; i < n; i++){
            for(int j = end; j < m; j++){
                if(nums[i][j] == 1){
                    seted[i][j] = true;
                    backTracking(seted, 0, 0);
                    seted[i][j] = false;
                }
            }
        }
    }
public:
    int solve(){
        getData();
        vector<vector<bool>> seted(n, vector<bool>(m, false));
        backTracking(seted, 0, 0);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.solve() << endl;
    return 0;
}
