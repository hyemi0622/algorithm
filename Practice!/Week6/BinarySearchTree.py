# Practice1
# 주어진 이진 탐색 트리에서 N 번째로 작은 수 구하기

# 입력 트리: 3, 1, 4, null, 2
# N: 1
# 결과: 1

# 입력 트리: 5, 3, 6, 2, 4, null, null, 1
# N: 3
# 결과: 3

from typing import Optional, List
from collections import deque

class Node:
    def __init__(self, key: int):
        self.key = key
        self.left: Optional[Node] = None
        self.right: Optional[Node] = None

class BinarySearchTree:
    def __init__(self):
        self.head: Optional[Node] = None

    def add_node(self, key: int):
        self.head = self._add_node(self.head, key)

    def _add_node(self, cur: Optional[Node], key: int) -> Node:
        if not cur:
            return Node(key)
        if key < cur.key:
            cur.left = self._add_node(cur.left, key)
        else:
            cur.right = self._add_node(cur.right, key)
        return cur

def solution(data: List[Optional[int]], n: int):
    # 여기에 코드 작성. 필요시 다른 함수 추가 가능

# 테스트
solution([3, 1, 4, None, 2], 1)  # 출력: 1
solution([5, 3, 6, 2, 4, None, None, 1], 3)  # 출력: 3
