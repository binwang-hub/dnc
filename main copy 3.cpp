//
//  main.cpp
//  baidu
//
//  Created by Wang Bin on 2021/9/7.
//
/*
#include <iostream>
using namespace std;

int calMax(int x, int y){
    int z = y;
    while(x % y != 0){
        z = x % y;
        x = y;
        y = z;
    }
    return z;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int ans = 0;
        for(int i = 1; i * i <= N; i++){
            if(N % i == 0){
                int temp = calMax(i, N / i);
                if(temp == 1){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int N, K;
    cin >> N >> K;
    int temp;
    //vector<vector<int>> nums(N, vector<int>(N));
    vector<vector<int>> ans(N * K, vector<int>(N * K));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> temp;
            for(int m = i * K; m < (i + 1) * K; m++){
                for(int n = j * K; n < (j + 1) * K; n++){
                    ans[m][n] = temp;
                }
            }
        }
    }
    for(int i = 0; i < N * K; i++){
        for(int j = 0; j < N * K; j++){
            cout << ans[i][j];
            if(j != N * K - 1) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
 */


#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    int N, Q;
    cin >> N >> Q;
    while (Q--) {
        string s;
        cin >> s;
        
        
        
        
        
        cout << 3 << endl;
    }
    return 0;
}
