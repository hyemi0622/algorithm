#include <iostream>

class MyArray {
public:
    int* arr;
    int size;

    // 배열의 초기 사이즈 설정
    MyArray(int initialSize) {
        size = initialSize;
        arr = new int[size];
    }

    // 배열에 데이터 삽입
    void insertData(int index, int data) {
        if (index < 0 || index > size) {
            std::cout << "Index Error\n";
            return;
        }

        int* newArr = new int[size + 1];  // 배열 크기를 하나 증가시킴

        // 기존 배열을 새로운 배열로 복사
        for (int i = 0; i < index; i++) {
            newArr[i] = arr[i];
        }

        // 새로운 데이터를 삽입
        newArr[index] = data;

        // 기존 배열의 나머지 데이터를 새로운 배열로 복사
        for (int i = index; i < size; i++) {
            newArr[i + 1] = arr[i];
        }

        // 기존 배열 메모리 해제 후 새로운 배열로 교체
        delete[] arr;
        arr = newArr;
        size++;
    }

    // 배열에서 특정 데이터 삭제
    void removeData(int data) {
        int targetIndex = -1;

        // 데이터가 배열에 있는지 확인
        for (int i = 0; i < size; i++) {
            if (arr[i] == data) {
                targetIndex = i;
                break;
            }
        }

        if (targetIndex == -1) {
            std::cout << "해당 데이터가 없습니다.\n";
            return;
        }

        int* newArr = new int[size - 1];  // 배열 크기를 하나 줄임

        // 삭제할 데이터 앞의 데이터를 복사
        for (int i = 0; i < targetIndex; i++) {
            newArr[i] = arr[i];
        }

        // 삭제할 데이터 뒤의 데이터를 복사
        for (int i = targetIndex + 1; i < size; i++) {
            newArr[i - 1] = arr[i];
        }

        // 기존 배열 메모리 해제 후 새로운 배열로 교체
        delete[] arr;
        arr = newArr;
        size--;
    }

    // 배열 출력
    void printArray() {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }

    // 소멸자: 동적 배열 메모리 해제
    ~MyArray() {
        delete[] arr;
    }
};

int main() {
    // Test code
    int size = 5;
    MyArray myArray(size);

    // 초기 배열 설정
    for (int i = 0; i < size; i++) {
        myArray.arr[i] = i + 1;
    }

    myArray.printArray();   // [1, 2, 3, 4, 5]

    myArray.arr[0] = 10;
    myArray.printArray();   // [10, 2, 3, 4, 5]

    myArray.insertData(2, 20);
    myArray.printArray();   // [10, 2, 20, 3, 4, 5]

    myArray.insertData(6, 60);
    myArray.printArray();   // [10, 2, 20, 3, 4, 5, 60]

    myArray.insertData(-1, 0);  // Index Error

    myArray.removeData(4);
    myArray.printArray();   // [10, 2, 20, 3, 5, 60]

    myArray.removeData(5);
    myArray.printArray();   // [10, 2, 20, 3, 60]

    myArray.removeData(99); // 해당 데이터가 없습니다.

    return 0;

}
