//
//  main.cpp
//  beibao
//
//  Created by Wang Bin on 2021/8/18.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
    int money, N;
    vector<int> weight;
    vector<int> value;
    void getData(){
        cin >> money >> N;
        int price, number, likeLevel;
        while(N--){
            cin >> price >> number >> likeLevel;
            while(number--){
                value.push_back(likeLevel);
                weight.push_back(price);
            }
        }
    }
public:
    void pack(){
        getData();
        vector<int> dp(money + 1, 0);
        for(int i = 0; i < weight.size(); i++){
            for(int j = money; j >= weight[i]; j--){
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        cout << dp[money] << endl;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.pack();    
    return 0;
}

