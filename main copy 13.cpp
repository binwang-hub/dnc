//
//  main.cpp
//  jbt001
//
//  Created by Wang Bin on 2021/8/24.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, k;
    cin >> n >> k;
    if(n % (k + 1) == 0 ){
        cout << "T win" << endl;
    }
    else cout << "G win" << endl;
    return 0;
}
