"""Print matrix in spiral fashion"""


def top_right(matrix):
    """Returns top and right matrix traversal"""
    top = matrix.pop(0)

    right = []
    for i in range(len(matrix)):
        right.append(matrix[i].pop())

    return top + right


def bottom_left(matrix):
    """Returns bottom and left matrix traversal"""
    bottom = matrix.pop()

    left = []
    for i in range(len(matrix)):
        left.append(matrix[i].pop(0))
    
    return list(reversed(bottom)) + list(reversed(left))


def spiral(matrix):
    """Returns spiral matrix traversal"""
    spir = []

    while len(matrix) > 0:
        if len(matrix) == 1:
            spir += matrix[0]
            break
        
        tr = top_right(matrix)
        spir += tr

        bl = bottom_left(matrix)
        spir += bl

    return spir


if __name__ == '__main__':
    M = [[1, 2, 3],
         [4, 5, 6],
         [7, 8, 9]]
    print(spiral(M))
