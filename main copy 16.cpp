//
//  main.cpp
//  mt01
//
//  Created by Wang Bin on 2021/8/22.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
    int n;
    vector<int> nums;
    
    vector<vector<int>> result;
    vector<int> path;
    
    void getData(){
        cin >> n;
        nums.clear();
        int temp;
        while(n--){
            cin >> temp;
            nums.push_back(temp);
            //if(cin.get() == '\n') break;
        }
    }
    
    
    void backTracking(vector<int> path, vector<bool> used){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false){
                continue;;
            }
            if(used[i] == false){
                used[i] = true;
                path.push_back(nums[i]);
                backTracking(path, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> solve(){
        getData();
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backTracking(path, used);
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> ans = s.solve();
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            if(j != ans[0].size() - 1){
                cout << ans[i][j] << ' ';
            }
            if(j == ans[0].size() - 1){
                cout << ans[i][j] << endl;
            }
        }
    }
    return 0;
}
