//
//  main.cpp
//  pdd
//
//  Created by Wang Bin on 2021/8/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        map<int, int, std::greater<int>> ST;
        while(N--){
            int si, ti;
            cin >> si >> ti;
            ST[si] = ti;
        }
        int i = 0;
        int count = 0;
        for(auto it = ST.begin(); it != ST.end(); it++){
            auto ittemp = it;
            
            if(ittemp->second == i){
                count += ittemp->first;
                i++;
            }
            if(it->second > i){
                count += it->first;
                i++;
            }
            
        }
        cout << count << endl;
    }
    return 0;
}
