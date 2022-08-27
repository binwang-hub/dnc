//
//  main.cpp
//  wangyi0807_02
//
//  Created by Wang Bin on 8/7/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

class Solution{
private:
    vector<vector<int>> edges;
    vector<int> indegrees;
    vector<int> ans;
    
    vector<int> topSort(int n){
        queue<int> que;
        for(int i = 1; i <= n; ++i){
            if(indegrees[i] == 0) que.push(i);
        }
        
        while(que.empty() != true){
            if(que.size() > 1) break;
//有序就是[入度为零]的点一个接一个出现，所以que中元素个数应一直保持一个，直至图空。凡是出现大于1的情况，均是出现了无法判断大小元素的出现
            int cur = que.front();
            que.pop();
            ans.push_back(cur);
            for(int nex: edges[cur]){
                if(--indegrees[nex] == 0) que.push(nex);
            }
        }
        
        if(ans.size() < n) return {};
        return ans;
    }
public:
    vector<int> order(int numPeople, vector<vector<int>> &orders){
        edges.resize(numPeople + 1);
        indegrees.resize(numPeople + 1);
        ans.reserve(numPeople);
        for(auto &nodes : orders){
            int pre = nodes[0], cur = nodes[1];
            edges[pre].push_back(cur);
            indegrees[cur]++;
        }
        return topSort(numPeople);
    }
    
};

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;//确定运动员人数，接下来输入的行数
        set<vector<int>> numsChange;
        
        for(int i = 0; i < M; ++i){
            int temp;
            cin >> temp;//确定该行输入元素个数
            
            vector<int> tempV(temp);//输入该行元素
            for(int j = 0; j < temp; ++j){
                cin >> tempV[j];
            }
            
            for(int i = 0; i < temp - 1; ++i){
                for(int j = i + 1; j < temp; ++j){
                    vector<int> tempV2;
                    tempV2.push_back(tempV[i]);
                    tempV2.push_back(tempV[j]);
                    numsChange.insert(tempV2);
                }
            }
        }
        
        vector<vector<int>> preOrder;
        for(auto &i : numsChange){
            preOrder.push_back(i);
        }
        
        Solution s;
        vector<int> result = s.order(N, preOrder);
        
        if(result.empty() == true){
            string str = "NO";
            cout << str << endl;
        }
        else{
            for(auto &i : result){
                cout << i << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}

/*
4
3 2
2 1 3
2 1 2
4 3
3 1 2 3
2 1 3
2 1 4
4 1
4 1 2 3 4
4 3
3 1 2 4
3 1 3 4
2 3 2
 
*/
