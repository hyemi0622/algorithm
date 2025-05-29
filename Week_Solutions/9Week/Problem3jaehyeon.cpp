//송재현

#include <string>
#include <vector>
using namespace std;
void bubbleSort(vector<string>& arr, int n) {
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = 0; j < arr.size() - i - 1; j++) {
			if (arr[j][n] > arr[j + 1][n] ||
				(arr[j][n] == arr[j + 1][n] && arr[j] > arr[j + 1])) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
vector<string> solution(vector<string> strings, int n) {
	bubbleSort(strings,n);
    return strings;
}
