//
//  main.cpp
//  huawei
//
//  Created by Wang Bin on 2021/9/13.
//

#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &Nums, int N){
    int start = 0;
    while (++start <= Nums[N - 1]) {
        for(int i = 0; i < N; i++){
            if(Nums[i] >= start){
                int size = N - i;
                if(size == start){
                    return start;
                }
                else{
                    break;
                }
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    cout << solve(nums, n) << endl;
    return 0;
}
