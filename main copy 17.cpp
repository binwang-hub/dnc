//
//  main.cpp
//  mt02
//
//  Created by Wang Bin on 2021/8/22.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findMinCharacter(string &s, int pos){
    int len = s.size();
    int result = INT_MAX;
    pos--;
    for(int i = 0; i < len; i++){
        if(s[i] == s[pos] && pos != i){
            result = min(result, abs(pos - i));
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    string s;
    cin >> s;
    int N;
    cin >> N;
    while(N--){
        int indice;
        cin >> indice;
        if(indice == 1){
            char c;
            cin >> c;
            s.push_back(c);
        }
        else if(indice == 2){
            int pos;
            cin >> pos;
            int ans = findMinCharacter(s, pos);
            if(ans == INT_MAX) cout << -1 << endl;
            else cout << ans << endl;
        }
    }
    return 0;
}

