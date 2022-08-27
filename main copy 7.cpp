//
//  main.cpp
//  d y
//
//  Created by Wang Bin on 2021/8/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solusion{
private:
    vector<vector<int>> result;
    vector<int> path;
public:
    void backTracking(int N, int startIndex){
        result.push_back(path);
        if(path.size() > N){
            return;
        }
        for(int i = startIndex; i <= N; i++){
            path.push_back(i);
            backTracking(N, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> solve(int N){
        backTracking(N, 1);
        return result;
    }
    
};

int main(int argc, const char * argv[]) {
    Solusion s;
    vector<vector<int>> ans = s.solve(3);
    return 0;
}
