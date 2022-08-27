//
//  main.cpp
//  tx9502
//
//  Created by Wang Bin on 2021/9/5.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int yueshuSize(int &num){
    int ans = 0;
    for(int i = 1; i <= num; i++){
        if(num % i == 0){
            ans++;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = yueshuSize(a[i]);
    }
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
        b[i] = yueshuSize(b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int ans = 0;
    bool flag = false;
    while(!flag){
        flag = true;
        for(int i = a.size() - 1; i >= 0; i--){
            for(int j = a.size() - 1; j >= 0; j--){
                if(a[i] > b[j]){
                    flag = false;
                    ans++;
                    a.erase(a.begin() + i);
                    b.erase(b.begin() + j);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
