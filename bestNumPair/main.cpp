//
//  main.cpp
//  bestNumPair
//
//  Created by Wang Bin on 2021/8/3.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
private:
    int n, k;
    int allSameNum = 0;
    unordered_map<string, int> memo;
    
    string getAntiCode(const string &s) {
        string r;
        for (char c : s) {
            if (c == '+')
                r += '-';
            else if (c == '-')
                r += '+';
            else
                r += c;
        }
        return r;
    }
public:
    Solution() {
        cin >> n >> k;
        int temp, last;
        for (int i = 0; i < n; i++)
        {
            string code;//<code：形如+1-2+3，code对应的物品个数>
            bool allSame = true;
            for (int j = 0; j < k; j++)
            {
                cin >> temp;
                if (j == 0)
                    last = temp;
                else {
                    if (temp != last)
                        allSame = false;
                    if (temp - last > 0)
                        code += '+';
                    code += to_string(temp - last);
                    last = temp;
                }
            }
            if (allSame)
                allSameNum += 1;
            else if (memo.count(code))
                ++memo[code];
            else
                memo[code] = 1;
        }
    }
    void solve() {
        int r = 0;
        for (const auto &m : memo) {
            string antiCode = getAntiCode(m.first);
            if (memo.count(antiCode))
                r += m.second * memo[antiCode];
        }
        r /= 2;
        r += allSameNum * (allSameNum - 1) / 2;
        cout << r << endl;
    }
};


int main()
{
    Solution s;
    s.solve();
    return 0;
}
