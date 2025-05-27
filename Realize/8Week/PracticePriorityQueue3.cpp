#include <iostream>
#include <queue>
#include <vector>
#include <string>
// 문자열 사전식 오름차순
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string name, int age) : name(name), age(age) {}
};

// 사전식 오름차순 정렬 (name 기준)
struct Compare {
    bool operator()(const Person& a, const Person& b) {
        return a.name > b.name;  // greater: 사전식 오름차순
    }
};

void solution(vector<string>& names, vector<int>& ages) {
    priority_queue<Person, vector<Person>, Compare> pq;

    for (size_t i = 0; i < names.size(); ++i) {
        pq.push(Person(names[i], ages[i]));
    }

    while (!pq.empty()) {
        Person p = pq.top(); pq.pop();
        cout << p.name << " " << p.age << endl;
    }
}

int main() {
    vector<string> names = {"A", "B", "C", "D", "E"};
    vector<int> ages = {30, 20, 45, 62, 35};

    solution(names, ages);
    return 0;
}
