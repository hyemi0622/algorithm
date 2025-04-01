#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x):data(x),next(nullptr){}
};

vector<int> solution(long long n) {
    vector<int> answer;
    int a;
    Node* head=nullptr;
    Node* tail=nullptr;
    while(n>0){
        a=n%10;
        Node* newNode=new Node(a);
        if(tail==nullptr){
            head=newNode;
            tail=newNode;
            }
        else{   
            tail->next=newNode;
            tail=newNode;
        }
        n/=10;
    }
   
     Node* temp = head;
    while (temp != nullptr) {
        answer.push_back(temp->data);
        temp = temp->next;
    }

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return answer;
}
