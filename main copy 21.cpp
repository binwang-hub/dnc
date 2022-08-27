//
//  main.cpp
//  pdd03
//
//  Created by Wang Bin on 2021/8/22.
//

#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        int pos = 0;
        int test = 0;
        for(int i = 1; pos != 0; i++){
            test = i * M;
            pos = test / pow(10, N);
        }
        cout << test << endl;
    }
    return 0;
}
