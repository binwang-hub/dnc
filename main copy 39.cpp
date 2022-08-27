//
//  main.cpp
//  wb
//
//  Created by Wang Bin on 2021/8/28.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <queue>

using namespace std;

queue<vector<int>> nums;

void chuliData(vector<int> numV, int indice, int k, int x){
    int start = 0;
    int end = numV.size();
    if(indice - k > 0) start = indice - k;
    if(indice + k < end) end = indice + k;
    for(int i = start; i <= end; i++){
        numV[i] += x;
    }
    nums.push(numV);
}

int main(int argc, const char * argv[]) {
    int n, m, x, k;
    cin >> n >> m >> x >> k;
    vector<int> num(n);
    for(int i = 0; i < n; i ++){
        cin >> num[i];
    }
    
    nums.push(num);
    while(m--){
        int size = nums.size();
        while(size--){
            vector<int> temp = nums.front();
            nums.pop();
            int minNum = *min_element(temp.begin(), temp.end());
            for(int i = 0; i < temp.size(); i++){
                if(temp[i] == minNum){
                    chuliData(temp, i, k, x);
                }
            }
        }
        
        
    }
    return 0;
}
