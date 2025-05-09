def solution(num_list):
    return max(sum([num_list[i] for i in range(len(num_list)) if i%2==0]), 
               sum([num_list[i] for i in range(len(num_list)) if i%2==1]))

###############################################################################################
class Binomial:
    def __init__(self, value=0):
        self.value = value
        self.parent = None
        self.left = None
        self.right = None

    def insert(self, value, index):
        new_node = Binomial()
        new_node.value = self.value + value
        new_node.parent = self

        if index % 2 == 1:
            if self.left:
                self.left.insert(value, 1)
            else:
                self.left = new_node
        else:
            if self.right:
                self.right.insert(value, 0)
            else:
                self.right = new_node

    def find_max(self):
        # 리프 노드면 자기 값 반환
        if self.left is None and self.right is None:
            return self.value

        left_max = self.left.find_max() if self.left else float('-inf')
        right_max = self.right.find_max() if self.right else float('-inf')

        return max(left_max, right_max)
