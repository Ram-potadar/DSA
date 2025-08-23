

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorderTraversal(self, root):
        result = []
        self._inorder(root, result)
        return result
    
    def _inorder(self, node, result):
        if not node:
            return
    
        self._inorder(node.left, result)
        result.append(node.val)
        self._inorder(node.right, result)


if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(23)
    root.right = TreeNode(4)
    root.left.left = TreeNode(5)
    root.left.right = TreeNode(6)

    sol = Solution()

    print("Inorder Traversal: ", sol.inorderTraversal(root))

