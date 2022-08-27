//
//  main.cpp
//  ali0803
//
//  Created by Wang Bin on 2021/8/3.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution{
private:
    vector<int> getErJinZhi(int num){
        vector<int> result;
        while(num > 0){
            result.push_back(num % 2);
            num /= 2;
        }
        //reverse(result.begin(), result.end());
        return result;
    }
public:
    int solveDiff(int num1, int num2){
        vector<int> num1V = getErJinZhi(num1);
        vector<int> num2V = getErJinZhi(num2);
        
        int len1 = num1V.size();
        int len2 = num2V.size();
        while(len1 != len2){
            if(len1 > len2){
                num2V.push_back(0);
                len2++;
            }
            else if(len1 < len2){
                num1V.push_back(0);
                len1++;
            }
        }
        int diff = 0;
        for(int i = 0; i < len1; i++){
            if(num1V[i] != num2V[i]){
                diff += pow(2, i);
            }
        }
        return diff;
    }
    
    
};

int main(int argc, const char * argv[]) {
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        Solution s;
        cout << s.solveDiff(a, b) << endl;
    }
    return 0;
}
