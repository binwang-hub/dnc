//
//  main.cpp
//  test
//
//  Created by Wang Bin on 2021/8/17.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution{
private:
    int n;
    int root;
    vector<vector<int>> nums;
    vector<int> result;
    
    void printResult(vector<int> &ans){
        for(int i = 0; i < n; ++i){
            if(i != n - 1) cout << ans[i] << ' ';
            else cout << ans[i] << endl;
        }
    }
    
    int findRow(int &root){
        for(int i = 0; i < n; i++){
            if(nums[i][0] == root) return i;
        }
        return 0;
    }
    
    void traversalPre(int &root){
        if(root == 0) return;
        result.push_back(root);
        int temp = findRow(root);
        traversalPre(nums[temp][1]);
        traversalPre(nums[temp][2]);
    }
    
    void traversalMid(int &root){
        if(root == 0) return;
        int temp = findRow(root);
        traversalMid(nums[temp][1]);
        result.push_back(root);
        traversalMid(nums[temp][2]);
    }

    void traversalPost(int &root){
        if(root == 0) return;
        int temp = findRow(root);
        traversalPost(nums[temp][1]);
        traversalPost(nums[temp][2]);
        result.push_back(root);
    }
public:
    void getData(){
        cin >> n >> root;
        nums.resize(n, vector<int>(3));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < 3; ++j){
                cin >> nums[i][j];
            }
        }
    }
    
    void Order(){
        
        result.clear();
        traversalPre(root);
        printResult(result);
        
        result.clear();
        traversalMid(root);
        printResult(result);
        
        result.clear();
        traversalPost(root);
        printResult(result);
        
    }
};



int main() {
    Solution s;
    s.getData();
    s.Order();
    
    return 0;
}


