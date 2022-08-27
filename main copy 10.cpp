//
//  main.cpp
//  huawei
//
//  Created by Wang Bin on 2021/8/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
private:
    int result = 0;
    int target, M;
    vector<int> nums;
    
    void getData(){
        cin >> target >> M;
        nums.resize(M);
        for(int i = 0; i < M; ++i){
            cin >> nums[i];
        }
    }
    
    void backTracking(int sum, int startIndex){
        if(sum > target) return;
        if(sum == target){
            result++;
            return;
        }
        
        for(int i = startIndex; i < nums.size() && sum + nums[i] <= target; i++){
            sum += nums[i];
            backTracking(sum, i + 1);
            sum -= nums[i];
        }
    }
public:
    void findCombination(){
        getData();
        //sort(nums.begin(), nums.end());
        backTracking(0, 0);
        if(result != 0) cout << result << endl;
        else cout << -1 << endl;
    }
};
int main(int argc, const char * argv[]) {
    
    Solution s;
    s.findCombination();
}
