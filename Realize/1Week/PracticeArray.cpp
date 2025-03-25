#include <iostream>
#include <vector>
#include <algorithm>

class MyArray {
public:
    std::vector<int> arr;

    // 배열의 초기 사이즈 설정
    MyArray(int size) {
        arr.resize(size);
    }

    // 배열에 데이터 삽입
    void insertData(int index, int data) {
        if (index < 0 || index > arr.size()) {
            std::cout << "Index Error" << std::endl;
            return;
        }
        arr.insert(arr.begin() + index, data);
    }

    // 배열에서 특정 데이터 삭제
    void removeData(int data) {
        auto it = std::find(arr.begin(), arr.end(), data);
        if (it != arr.end()) {
            arr.erase(it);
        }
        else {
            std::cout << "해당 데이터가 없습니다." << std::endl;
        }
    }

    // 배열 출력
    void printArray() {
        for (int i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Test code
    int size = 5;
    MyArray myArray(size);

    // 배열에 데이터 삽입
    for (int i = 0; i < size; ++i) {
        myArray.arr[i] = i + 1;
    }
    myArray.printArray();  // [1, 2, 3, 4, 5]

    // 배열 값 변경
    myArray.arr[0] = 10;
    myArray.printArray();  // [10, 2, 3, 4, 5]

    // 데이터 삽입
    myArray.insertData(2, 20);
    myArray.printArray();  // [10, 2, 20, 3, 4, 5]

    myArray.insertData(6, 60);
    myArray.printArray();  // [10, 2, 20, 3, 4, 5, 60]

    myArray.insertData(-1, 0);  // Index Error

    // 데이터 삭제
    myArray.removeData(4);
    myArray.printArray();  // [10, 2, 20, 3, 5, 60]

    myArray.removeData(5);
    myArray.printArray();  // [10, 2, 20, 3, 60]

    myArray.removeData(99); // 해당 데이터가 없습니다.

    return 0;
}
