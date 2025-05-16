#include <iostream>
#include <queue>
#include <vector>
#include <string>
// 나이 순으로 오름차순 또는 내림차순 출력
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string name, int age) : name(name), age(age) {}
};

// 나이 기준 내림차순 (크면 먼저)
struct Compare {
    bool operator()(const Person& a, const Person& b) {
        return a.age < b.age;  // 내림차순 (큰 나이가 우선)
        // return a.age > b.age;  // 오름차순 (작은 나이가 우선)
    }
};

void solution(vector<string>& names, vector<int>& ages) {
    priority_queue<Person, vector<Person>, Compare> pq;

    for (size_t i = 0; i < names.size(); ++i) {
        pq.push(Person(names[i], ages[i]));
    }

    cout << "== 실제 출력 순서 ==" << endl;
    while (!pq.empty()) {
        Person p = pq.top(); pq.pop();
        cout << p.name << p.age << endl;
    }
}

int main() {
    vector<string> names = { "A", "B", "C", "D", "E" };
    vector<int> ages = { 30, 20, 45, 62, 35 };

    solution(names, ages);
    return 0;
}
