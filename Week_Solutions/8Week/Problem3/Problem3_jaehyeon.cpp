//송재현
#include <string>
#include <vector>

using namespace std;

const int MX = 105;
int sz = 0;

pair<int, int> heap[MX];
void push(pair<int, int>x){
    heap[++sz] = x;
    int idx = sz;
    while(idx != 1){
        int par = idx/2;
        if(heap[par].first >= heap[idx].first)break;
        swap(heap[par],heap[idx]);
        idx=par;
    }
}

pair<int, int>top(){
    return heap[1];
}
void pop(){
    heap[1]=heap[sz--];
    int idx=1;
    while(2*idx <=sz){
        int lc = 2*idx,rc=2*idx+1;
        int max_child = lc;
        if(rc <= sz && heap[rc].first > heap[lc].first)
            max_child=rc;
        if(heap[idx].first >= heap[max_child].first)break;
        swap(heap[idx],heap[max_child]);
        idx = max_child;
    }
}
vector<int> solution(vector<int> emergency) {
    vector<int> answer(emergency.size());
    for(int i=0;i<emergency.size();i++){
        push({emergency[i],i});
    }
    int rank = 1;
    while(sz>0){
        pair<int,int> now = top();
        pop();
        answer[now.second]=rank++;
        
    }
    
    return answer;
}
