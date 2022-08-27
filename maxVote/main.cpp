//
//  main.cpp
//  maxVote
//
//  Created by Wang Bin on 8/5/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> A(n + 1);
    for(int i = 1;i <= n; i++){
        cin >> A[i];
    }
    
    vector<int> num(n + 1, 1);
    for(int i = n; i >= 1; i--){
       num[A[i]] += num[i];
    }
    
    for(int i = 1;i <= n; i++){
        cout << num[i] << endl;
    }
    return 0;
}
