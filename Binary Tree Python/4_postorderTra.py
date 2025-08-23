class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def postorderTravesal(self, root):
        result = []
        self._postorder(root, result)
        return result
    
    def _postorder(self, node, result):
        if not node:
            return
        
        self._postorder(node.left, result)
        self._postorder(node.right, result)
        result.append(node.val)




if __name__ == "__main__":
    root = TreeNode(23)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(6)

    sol = Solution()

    print("Postnorder Traversal: ", sol.postorderTravesal(root))

