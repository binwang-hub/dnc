//
//  main.cpp
//  wangyi01
//
//  Created by Wang Bin on 2021/8/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int temp;
    vector<int> nums;
    while(cin >> temp){
        nums.push_back(temp);
        if(cin.get() == '\n')
           break;
        
    }
    int M;
    cin >> M;
    
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int count = 0;
    for(int i = 0; i < len; ++i){
        for(int j = i + 1; j < len; ++j){
            if(nums[i] + nums[j] <= M){
                count++;
            }
        }
    }
    cout << count << endl;
    
    return 0;
}
