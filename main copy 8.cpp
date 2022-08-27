//
//  main.cpp
//  findNum
//
//  Created by Wang Bin on 2021/8/3.
//

#include <iostream>
using namespace std;


int measure(int x, int y){//求取最大公约数
    int temp;
    while(x % y != 0){
        temp = x % y;
        x = y;
        y = temp;
    }
    return temp;
}

int main(int argc, const char * argv[]) {
    int A, B, a, b;
    cin >> A >> B >> a >> b;
    
    int maxY = measure(a, b);
    a /= maxY;
    b /= maxY;
    
    long x, y;//why
    if(A >= a && B >= b){
        x = a, y = b;
        while(x + a <= A && y + b <= B){
        x += a;
        y += b;
        }
    }
    else{
        x = 0;
        y = 0;
    }
    cout << x << ' ' << y << endl;;
    return 0;
}
