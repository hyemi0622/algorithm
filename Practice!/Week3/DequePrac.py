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




# Practice2
# Palindrome 찾기
# Palindrome 이면 true, 아니면 false 를 반환하세요.
# Palindrome: 앞으로 읽어도 거꾸로 읽어도 같은 문자열

# 입출력 예시)
# 입력: a
# 결과: true

# 입력: madam
# 결과: true

# 입력: abab
# 결과: false
from collections import deque

def check_palindrome(s):
    # Add code here
    return False  # Placeholder

# Test code
print(check_palindrome("a"))       # True
print(check_palindrome("aba"))     # True
print(check_palindrome("abba"))    # True
print(check_palindrome("abab"))    # False
print(check_palindrome("abcba"))   # True
print(check_palindrome("abccba"))  # True
print(check_palindrome("madam"))   # True



// Practice3
// 데크 변형
// 기본 데크 구조에서 중간에 데이터를 추가하는 기능을 구현하세요.
// 단, 추가적인 자료구조 생성하지 말고 구현

// 입력 예시)
// 초기 데크 상태 (size: 5)
// -> 1, 2, 3, 4
// 중간 입력: 10
// 결과 데크
// -> 1, 2, 10, 3, 4
