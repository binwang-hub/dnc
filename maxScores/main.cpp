//
//  main.cpp
//  maxScores
//
//  Created by Wang Bin on 2021/8/1.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    int N, M;
    while(cin >> N >> M){
        vector<int> scores(N);
        for(int i = 0; i < N; i++){
            cin >> scores[i];
        }
        string s;
        int A, B;
        char inChar;
        for(int i = 0; i < M; i++){
            //getline(cin, s);
            cin >> inChar >> A >> B;
        
            if(inChar == 'Q'){
                if(B >= A)
                    cout << *max_element(scores.begin() + A - 1, scores.begin() + B) << endl;
                else
                    cout << *max_element(scores.begin() + B - 1, scores.begin() + A) << endl;
            }
            else if(inChar == 'U'){
                scores[A - 1] = B;
            }
        }
    }
    
    return 0;
}

/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class GradeQuery{
    public:
    vector<int> stuGrade;
    void query(int stu1, int stu2){
        auto it = max_element(stuGrade.begin()+stu1-1, stuGrade.begin()+stu2);
        cout << *it << endl;
    }
    void update(int stu, int grade){
        stuGrade[stu-1] = grade;
    }
};

int main(){
    int num, oper_num;
    while(cin >> num >> oper_num){
    GradeQuery gradeQuery;
    int tmp, arg1, arg2;
    char inChar;
    for(int i=0; i<num; i++){
        cin >> tmp;
        gradeQuery.stuGrade.push_back(tmp);
    }
    for(int i=0; i<oper_num; i++){
        cin >> inChar >> arg1 >> arg2;
        if(inChar == 'Q') {
            if(arg2>=arg1) gradeQuery.query(arg1, arg2);
            else gradeQuery.query(arg2,arg1);
        }
        else gradeQuery.update(arg1, arg2);
    }
    }

    return 0;
}
*/
