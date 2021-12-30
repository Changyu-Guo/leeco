# -*- coding: utf - 8 -*-

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def is_valid_bst(root):
    def check(node, low, up):
        if not node:
            return True

        if node.val <= low or node.val >= up:
            return False

        if not check(node.left, low, node.val):
            return False
        if not check(node.right, node.val, up):
            return False

        return True

    return check(root, float('-inf'), float('inf'))


if __name__ == '__main__':
    pass
