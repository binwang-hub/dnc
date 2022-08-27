//
//  main.cpp
//  tx002
//
//  Created by Wang Bin on 2021/8/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        vector<long> nums(N);
        for(int i = 0; i < N; i++){
            cin >> nums[i];
        }
        
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        long long result = 0;
        for(int i = 0; i < N; i++){
            result += pow(2, N - 1 - i) * nums[i];
        }
        cout << result % 1000000007 << endl;
    }
    return 0;
}
