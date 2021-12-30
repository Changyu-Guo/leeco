# -*- coding: utf - 8 -*-

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def generate_trees(n):
    def generate(start, end):
        if start > end:
            return [None, ]

        all_trees = []
        for i in range(start, end + 1):
            left_trees = generate(start, i - 1)
            right_trees = generate(i + 1, end)

            for l in left_trees:
                for r in right_trees:
                    cur = TreeNode(i)
                    cur.left = l
                    cur.right = r
                    all_trees.append(cur)

        return all_trees

    return generate(1, n) if n else []


if __name__ == '__main__':
    generate_trees(3)
