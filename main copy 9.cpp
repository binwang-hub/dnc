//
//  main.cpp
//  tx
//
//  Created by Wang Bin on 2021/8/27.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    vector<long> result;
    while (T--) {
        long coins;
        cin >> coins;
        long times = 0;
        
        while (coins != 0) {
            if(coins % 3 == 0){
                coins = coins / 3;
            }
            else if (coins % 2 == 0){
                coins = coins /2;
            }
            else{
                coins--;
            }
            times++;
        }
        result.push_back(times);
    }
    for(auto &i : result){
        cout << i << endl;
    }
    return 0;
}
/*
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void getData(vector<float> &nums){
    
    string s;
    int temp;
    
    cin >> s;
    replace(s.begin(), s.end(), ',', ' ');
    
    stringstream ss;
    ss << s;
    while (ss >> temp) {
        nums.push_back(temp);
    }
    ss.clear();
    return;
}

int main(int argc, const char * argv[]) {
    vector<float> numsSize;
    getData(numsSize);
    vector<float> nums;
    for(int i = 0; i < numsSize.size(); i++){
        getData(nums);
    }
    sort(nums.begin(), nums.end());
    int len = nums.size();
    if(len % 2 == 0){
        double result = (nums[len / 2 - 1] + nums[len / 2]) / 2;
        cout << result << endl;
    }
    else{
        cout << nums[len / 2] << endl;
    }
    return 0;
}
*/
