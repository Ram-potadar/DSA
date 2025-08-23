

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        

class Solution:
    def preorderTraversal(self, root):
        result = []
        self._preorder(root, result)
        return result
    
    def _preorder(self, node, result):
        if not node:
            return
        result.append(node.val)
        self._preorder(node.left, result)
        self._preorder(node.right, result)


if __name__ == "__main__":
    root = TreeNode(2)
    root.left = TreeNode(23)
    root.right = TreeNode(21)
    root.left.left = TreeNode(1)

    sol = Solution()
    print("Preorder Traversal: ", sol.preorderTraversal(root))


