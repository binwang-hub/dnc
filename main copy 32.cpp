//
//  main.cpp
//  tx9503
//
//  Created by Wang Bin on 2021/9/5.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    int n, l, r;
    cin >> n >> l >> r;
    queue<int> que;
    que.push(n);
    bool flag = false;
    while(!flag){
        flag = true;
        int cap = que.size();
        for(int i = 0; i < cap; i++){
            int temp  = que.front();
            que.pop();
            if(temp > 1){
                flag = false;
                que.push(temp / 2);
                que.push(temp % 2);
                que.push(temp / 2);
            }
            else{
                que.push(temp);
            }
            
        }
    }
    
    int num = 0;
    for(int i = 1; i <= r; i++){
        if(i >= l && que.front() == 1){
            num++;
        }
        que.pop();
    }
    cout << num << endl;
    return 0;
}
