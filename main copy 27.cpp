struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param m int整型
     * @param a ListNode类 指向彩带的起点，val表示当前节点的val，next指向下一个节点
     * @return ListNode类vector
     */
    vector<ListNode*> solve(int m, ListNode* a) {
        vector<ListNode*> hashVec;
        for(int i = 0; i < m; i++){
            hashVec[i] = new ListNode(-1);
        }
        hashVec.resize(m);
        while(a != nullptr){
            int indice = a->val % m;
            ListNode *temp = a;
            a = a->next;
            
            
            temp->next = hashVec[indice];
            hashVec[indice] = temp;
            return hashVec;
        }
    }
};
