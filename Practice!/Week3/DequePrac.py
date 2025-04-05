# Practice1
# 데이터 재정렬
# D_0 -> D_1 -> ... -> D_n-1 -> D_n 순으로 되어 있는 데이터를
# D_0 -> D_n -> D_1 -> D_n-1 -> ... 순이 되도록 재정렬 하시오.

# 입력 예시)
# 입력 데이터: 1 -> 2 -> 3 -> 4 -> 5
# 출력 데이터: 1 -> 5 -> 2 -> 4 -> 3
from collections import deque

def reorderData(arr):
    dq = deque(arr) # 배열의 모든 요소를 덱에 추가
    //여기에 코드 작성
   

# Test code
reorderData([1, 2, 3, 4, 5]) # 출력: "1 -> 5 -> 2 -> 4 -> 3"
reorderData([1, 2, 3, 4, 5, 6, 7]) # 출력: "1 -> 7 -> 2 -> 6 -> 3 -> 5 -> 4"
