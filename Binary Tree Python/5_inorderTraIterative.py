class TreeNode:
    def __init__(self, val = 0, left = None, right= None):
        self.val = val
        self.left = left
        self.right = right
        self.data = 0


class Solution:
    def find(self, root, target):
        if not root:
            return None
        return self._find(root, target)
    

    def _find(self, node, target):
        if not node:
            return
        if node.val == target:
            return node
        
        leftnode = self._find(node.left, target)
        if leftnode:
            return leftnode
        return self._find(node.right, target)
    

if __name__ == "__main__":
    root = TreeNode(2, TreeNode(3, TreeNode(6), TreeNode(7)), TreeNode(5))
    sol = Solution()
    targetnode = sol.find(root, 7)
    print("target is at: ", targetnode)
    



