#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr, const string& name) {
    cout << name << ": ";
    for (int n : arr) {
        cout << n << " ";
    }
    cout << endl;
}

// 버블 정렬
void bubbleSort(vector<int>& arr) {
     // 1.
    for (int i = 1; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    // 2. (1과 2 같은 방식인데 i 인덱스 사용 다르게 참고)
    for (int i = arr.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 삽입 정렬
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            } else {
                break;
            }
        }
    }
}

// 선택 정렬
void selectionSort(vector<int>& arr) {
     // 1. 최소 값을 찾아 앞 쪽부터 교환하는 방식
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
     // 2. 최대 값을 찾아 뒤 쪽부터 교환하는 방식
    for (int i = arr.size() - 1; i > 0; i--) {
        int maxIdx = i;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        swap(arr[i], arr[maxIdx]);
    }
}

int main() {
    vector<int> arr = {3, 5, 2, 7, 1, 4};

    vector<int> temp = arr;
    bubbleSort(temp);
    printArray(temp, "버블 정렬");

    temp = arr;
    insertionSort(temp);
    printArray(temp, "삽입 정렬");

    temp = arr;
    selectionSort(temp);
    printArray(temp, "선택 정렬");

    return 0;
}
