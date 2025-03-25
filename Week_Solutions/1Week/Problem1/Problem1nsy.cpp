#include <vector>
using namespace std;
vector<int> solution(vector<int> arr, int n) {
	int len = arr.size();
	bool is Odd = len%2 == 1;

	for (int i = 0; i < len; ++i){
		if ((isOdd && i%2 == 0) || (! is Odd && i%2 == 1)){
			arr[i] ++ n;
		}
	}
	return 0;
}
