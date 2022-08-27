//
//  main.cpp
//  calMath
//
//  Created by Wang Bin on 8/5/21.
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long LL;

class Solution{
public:
    static const int mod = 1e9 + 7;
    vector<LL>res;
    LL a, b, n;
    LL ans0, ans1, ans;
    vector<LL> calculate(vector<vector<LL>>& nums, int len) {
        for (int i = 0; i < len; i++) {
            a = nums[i][0];
            b = nums[i][1];
            n = nums[i][2];
            vector<LL>temp;
            ans0 = a % mod;
            ans1 = (a * a % mod - 2 * b % mod + mod) % mod;
            if (n == 1) {
                res.push_back(ans0);
            }
            if (n == 2) {
                res.push_back(ans1);
            }
            else {
                temp.push_back(ans0);
                temp.push_back(ans1);
                ///ans = a * ans1 - b * ans0;
                ///temp.push_back(ans);
                for (int j = 2; j < n; j++) {
                    LL now = (a * temp[j - 1] % mod - b * temp[j - 2] % mod + mod) % mod;
                    temp.push_back(now);
                }
                LL size = temp.size();
                ans = temp[size - 1];
                res.push_back(ans);
            }
        }
        return res;
    }
     
    //int backtracking(int a, int b, int n, int ans, int ans0, int ans1, int startIndex) {
    //  if (startIndex == n) { return ans; }
    //  else {
    //      ans0 = ans1;
    //      ans1 = ans;
    //      ans = ans = a * ans1 - b * ans0;
    //      backtracking(a, b, n, ans, ans0, ans1, startIndex + 1);
    //  }
    //}
};
 
 
 
int main() {
    LL n;
    cin >> n;
    
    LL b;
    vector<vector<LL>>input;
    while (--n >= 0) {
        vector<LL>temp;
        for (int i = 0; i < 3; i++) {
            cin >> b;
            temp.push_back(b);
        }
        input.push_back(temp);
    }
    Solution result;
    
    LL t;
    t = n;
    vector<LL>output;
    output = result.calculate(input, t);
    for (int j = 0; j < t; j++) {
        cout << output[j] << endl;
    }
}
