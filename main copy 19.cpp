//
//  main.cpp
//  mt04
//
//  Created by Wang Bin on 2021/8/22.
//

#include <iostream>
#include <vector>
using namespace std;

void mode1(vector<int> &nums, int L, int R){
    long result = 0;
    for(int i = L; i <= R; i++){
        result += nums[i];
    }
    cout << result << endl;
}

void mode2(vector<int> &nums, int L, int R){
    long sum = 0;
    for(int i = L; i <= R; i++){
        sum += nums[i];
    }
    long result = 0;
    for(int i = L; i <= R; i++){
        result += (sum - nums[i]) * (sum - nums[i]);
    }
    cout << result << endl;
}

void mode3(vector<int> &nums, int L, int R){
    long result = -2000;
    for(int i = L; i <= R; i++){
        result = max(result, nums[i]);
    }
    cout << result << endl;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int> nums;
    nums.resize(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int T;
    cin >> T;
    while(T--){
        int indice;
        cin >> indice;
        int L, R;
        cin >> L >> R;
        L--;R--;
        if(indice == 1){
            mode1(nums, L, R);
        }
        else if(indice == 2){
            mode2(nums, L, R);
        }
        else if(indice == 3){
            mode3(nums, L, R);
        }
    }
    return 0;
}
