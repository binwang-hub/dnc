//
//  main.cpp
//  testWhile
//
//  Created by Wang Bin on 2021/7/29.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    cout << "--------- for i++ ----------" << endl;
    int a = 0;
    for(a; a <= 10; a++){
        cout << a;
    }
    cout << endl;
    cout << a << endl;
    
    cout << "--------- for ++i ----------" << endl;
    int b = 0;
    for(b; b <= 10; ++b){
        cout << b;
    }
    cout << endl;
    cout << b << endl;
    
    cout << "--------- for --i ----------" << endl;
    int c = 10;
    for(c; c >= 0; --c){
        cout << c;
    }
    cout << endl;
    cout << c << endl;
    
    cout << "--------- for i-- ----------" << endl;
    int d = 10;
    for(d; d >= 0; d--){
        cout << d;
    }
    cout << endl;
    cout << d << endl;
    
    cout << "--------- while i++ ----------" << endl;
    int i = 0;
    while(i++ <= 10){
        cout << i;
    }
    cout << endl;
    cout << i << endl;
    
    cout << "--------- while ++i ----------" << endl;
    int j = 0;
    while(++j <= 10){
        cout << j;
    }
    cout << endl;
    cout << j << endl;
    
    cout << "--------- while i-- ----------" << endl;
    int m = 10;
    while(m--){
        cout << m;
    }
    cout << endl;
    cout << m << endl;
    
    cout << "--------- while --i ----------" << endl;
    int n = 10;
    while(--n){
        cout << n;
    }
    cout << endl;
    cout << n << endl;
    
    return 0;
}
