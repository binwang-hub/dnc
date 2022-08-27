//
//  main.cpp
//  crossRiver
//
//  Created by Wang Bin on 2021/8/3.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        
        sort(nums.begin(), nums.end());
        
        int time = 0;
        while(n >= 4){
            time += min(2 * nums[0] + nums[n - 2] + nums[n - 1], nums[0] + 2 * nums[1] + nums[n - 1]);
            n -= 2;
        }
        if(n == 3){
            time += (nums[0] + nums[1] + nums[2]);
        }
        else if(n == 2){
            time += nums[1];
        }
        else{
            time += nums[0];
        }
        cout << time << endl;
    }
    return 0;
}
