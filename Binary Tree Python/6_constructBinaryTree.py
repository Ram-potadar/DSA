

class BinaryTree:
    def __init__(self, val, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def constructTree(self, preorder, inorder):

        inMpp = {}

        for i, x in enumerate(inorder):
            inMpp[x] = i
        
        root = self.buildTree(preorder, 0, len(preorder) - 1, 
                        inorder, 0, len(inorder) - 1, inMpp)
        
        return root
    
    def buildTree(self, preorder, preStart, preEnd, inorder, inStart, inEnd, inMpp):

        if preStart > preEnd or inStart > inEnd:
            return None
        
        root = BinaryTree(preorder[preStart])

        inRoot = inMpp[root.val]
        numsLeft = inRoot - inStart

        root.left = self.buildTree(preorder, preStart + 1, preStart + numsLeft,inorder, inStart, inRoot-1, inMpp)

        root.right = self.buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMpp)

        return root

if __name__  == "__main__":
    preorder = [3, 9, 20, 15, 7]
    inorder = [9, 3, 15, 20, 7]

    sol = Solution()
    tree = sol.constructTree(preorder, inorder)

    print(tree.val)
