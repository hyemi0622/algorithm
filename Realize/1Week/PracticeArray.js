class MyArray {
    constructor(size) {
        this.arr = new Array(size);
    }

    // 배열에 데이터 삽입
    insertData(index, data) {
        if (index < 0 || index > this.arr.length) {
            console.log("Index Error");
            return;
        }

        const arrDup = [...this.arr];  // 기존 배열을 복사
        this.arr = new Array(this.arr.length + 1);  // 새로운 배열 크기 생성

        // 기존 데이터 복사
        for (let i = 0; i < index; i++) {
            this.arr[i] = arrDup[i];
        }

        // 새 데이터 삽입
        this.arr[index] = data;

        // 나머지 데이터 복사
        for (let i = index + 1; i < this.arr.length; i++) {
            this.arr[i] = arrDup[i - 1];
        }
    }

    // 배열에서 특정 데이터 삭제
    removeData(data) {
        let targetIndex = -1;

        // 해당 데이터의 인덱스를 찾기
        for (let i = 0; i < this.arr.length; i++) {
            if (this.arr[i] === data) {
                targetIndex = i;
                break;
            }
        }

        if (targetIndex === -1) {
            console.log("해당 데이터가 없습니다.");
        } else {
            const arrDup = [...this.arr];
            this.arr = new Array(this.arr.length - 1);  // 새로운 배열 크기 생성

            // 데이터 삭제 후 배열 재구성
            for (let i = 0; i < targetIndex; i++) {
                this.arr[i] = arrDup[i];
            }

            for (let i = targetIndex; i < this.arr.length; i++) {
                this.arr[i] = arrDup[i + 1];
            }
        }
    }
}

// 테스트 코드
const size = 5;
const myArray = new MyArray(size);

// 초기 배열에 데이터 할당
for (let i = 0; i < size; i++) {
    myArray.arr[i] = i + 1;
}
console.log(myArray.arr);  // [1, 2, 3, 4, 5]

myArray.arr[0] = 10;
console.log(myArray.arr);  // [10, 2, 3, 4, 5]

myArray.insertData(2, 20);
console.log(myArray.arr);  // [10, 2, 20, 3, 4, 5]

myArray.insertData(6, 60);
console.log(myArray.arr);  // [10, 2, 20, 3, 4, 5, 60]

myArray.insertData(-1, 0);  // Index Error

myArray.removeData(4);
console.log(myArray.arr);  // [10, 2, 20, 3, 5, 60]

myArray.removeData(5);
console.log(myArray.arr);  // [10, 2, 20, 3, 60]

myArray.removeData(99); // 해당 데이터가 없습니다.
