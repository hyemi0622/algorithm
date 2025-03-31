class MyArray:
    def __init__(self, size):
        self.arr = [i + 1 for i in range(size)]

    def insert_data(self, index, data):
        if index < 0 or index > len(self.arr):
            print("Index Error")
            return
        
        self.arr = self.arr[:index] + [data] + self.arr[index:]

    def remove_data(self, data):
        if data not in self.arr:
            print("해당 데이터가 없습니다.")
            return
        
        self.arr.remove(data)

if __name__ == "__main__":
    size = 5
    my_array = MyArray(size)
    print(my_array.arr)  # [1, 2, 3, 4, 5]

    my_array.arr[0] = 10
    print(my_array.arr)  # [10, 2, 3, 4, 5]

    my_array.insert_data(2, 20)
    print(my_array.arr)  # [10, 2, 20, 3, 4, 5]

    my_array.insert_data(6, 60)
    print(my_array.arr)  # [10, 2, 20, 3, 4, 5, 60]

    my_array.insert_data(-1, 0)  # Index Error

    my_array.remove_data(4)
    print(my_array.arr)  # [10, 2, 20, 3, 5, 60]

    my_array.remove_data(5)
    print(my_array.arr)  # [10, 2, 20, 3, 60]

    my_array.remove_data(99)  # 해당 데이터가 없습니다.
