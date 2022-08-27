//
//  main.cpp
//  tx01
//
//  Created by wangbin on 2021/8/21.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> num2vec;
        vector<vector<int>> numVec;
        int i = 0;
        while (n--) {
            int num1, num2;
            cin >> num1 >> num2;
            auto it1 = num2vec.find(num1);
            auto it2 = num2vec.find(num2);
            if(it1 == num2vec.end() && it2 == num2vec.end()){
                num2vec[num1] = i;
                num2vec[num2] = i;
                i++;
            }
            else if (it1 != num2vec.end() && it2 == num2vec.end()){
                int indice = it1->second;
                numVec[indice].push_back(num2);
                num2vec[num2] = indice;
            }
            else if (it1 == num2vec.end() && it2 != num2vec.end()){
                int indice = it2->second;
                numVec[indice].push_back(num1);
                num2vec[num1] = indice;
            }
            else{
                int indice1 = it1->second;
                int indice2 = it2->second;
                for(int i = 0; i < num2vec[indice2].size(); i++){
                    num2vec[indice1].push
                }
            }
            
        }
    }
    return 0;
}
