#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 250 + 5;
bool chk[MX];
int nxt[MX][10];

int c2i(char c){
    return c - '0';
}
void trie_C(){
    unused = 2;
    for(int i=0;i<MX;i++){
        chk[i] = false;
        fill(nxt[i],nxt[i] + 10 , -1);
    }
}
bool insert_and_check(string &s){
    int cur = ROOT;
    for(char c:s){
        if(nxt[cur][c2i(c)]==-1)
            nxt[cur][c2i(c)]=unused++;
        cur=nxt[cur][c2i(c)];
        if(chk[cur]) return false;
    }
    chk[cur]=true;
    return true;
}
bool solution(vector<string> phone_book) {
    trie_C();
    sort(phone_book.begin(),phone_book.end());
    for(auto& number : phone_book){
        if(!insert_and_check(number))
            return false;
    }

    return true;
}
