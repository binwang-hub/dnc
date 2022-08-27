//
//  main.cpp
//  maxDiff
//
//  Created by Wang Bin on 2021/8/3.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, const char * argv[]) {
    long long n;
    cin >> n;
    vector<long long> nums(n);
    for(long long i = 0; i < n; ++i){
        cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
    
    vector<long long> num1;
    vector<long long> num2;
    num1.insert(num1.end(), nums.begin(), nums.begin() + n / 2);
    num2.insert(num2.end(), nums.begin() + n / 2, nums.end());
    reverse(num2.begin(), num2.end());
    
    vector<long long> numDiffMax;
    auto it1 = num1.begin();
    auto it2 = num2.begin();
    while(it1 != num1.end() || it2 != num2.end()){
        if(it1 != num1.end()){
            numDiffMax.push_back(*it1);
            it1++;
        }
        if(it2 != num2.end()){
            numDiffMax.push_back(*it2);
            it2++;
        }
    }
    
    long long sum = 0;
    for(long long i = 1; i < n; i++){
        sum += abs(numDiffMax[i] - numDiffMax[i - 1]);
    }
    cout << sum + abs(numDiffMax[0] - numDiffMax[n - 1]) <<  endl;
    
    for(long long i = 0; i < n; i++){
        cout << numDiffMax[i] << ' ';
    }
    cout << endl;
    return 0;
}
