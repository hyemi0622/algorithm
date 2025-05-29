//송재현
#include<vector>
#include<algorithm>
using namespace std;
void insertionSort(vector<int>& a) {
	for (int i = 1; i < a.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (a[j] > a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}
}
long long solution(long long n)
{
	vector<int> v;
	while (n > 0) {
		v.push_back(n % 10);
		n /= 10;
	}

	insertionSort(v);

	long long answer = 0;
	for (int i = 0; i < v.size(); i++) {
		answer = answer * 10 + v[i];
	}
	return answer;
}
