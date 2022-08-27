//
//  main.cpp
//  ali0803_2
//
//  Created by Wang Bin on 2021/8/3.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    int Q;
    cin >> Q;
    vector<int> nums(Q);
    for(int i = 0; i < Q; i++){
        cin >> nums[i];
    }
    
    vector<int> results(Q);
    for(int i = 0; i < Q; i++){
        
        int sum= 0;//2进制转化10进制
        for(int j = 0; j <= i; j++){
            if(nums[j] == 1)
                sum += pow(2, i - j);
        }
        
    
        int zhishu = 0;//10进制转化8进制
        int result = 0;
        while(sum > 0){
            result += pow(10, zhishu) * (sum % 8);
            zhishu++;
            sum /= 8;
        }
        results[i] = result;
    }
    
    for(auto &i : results){
        cout << i << endl;
    }
    return 0;
}
