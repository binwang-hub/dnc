//
//  main.cpp
//  tx9505
//
//  Created by Wang Bin on 2021/9/5.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
    vector<vector<long>> result;
    int res = 0;
    bool check(vector<long> &nums){
        int ans = 0;
        int len = nums.size();
        for(int i = 1; i <= len - 2; i++){
            if(nums[i] >= nums[0] && nums[i] >= nums[len - 1]){
                ans++;
            }
        }
        if(ans == len - 2){
            return true;
        }
        return false;
    }
public:
    int solve(vector<long> &nums){
        vector<long> path;
        for(int i = 0; i < nums.size() - 1; i++){
            path.clear();
            for(int j = i; j < nums.size(); j++){
                path.push_back(nums[j]);
                if(path.size() > 1){
                    result.push_back(path);
                    if(path.size() == 2){
                        res++;
                    }
                    else{
                        if(check(path) == true){
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    vector<long> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution s;
    cout << s.solve(nums) << endl;
    return 0;
}
