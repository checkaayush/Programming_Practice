"""
Given a function with a unknown positive hard-coded value,
write a function to find the hard-coded value. Return "Not possible" otherwise.
"""


def fun(n):
    """Given function with hard coded value"""
    hard_coded = 42
    if n > hard_coded:
        return 1
    elif n < hard_coded:
        return -1
    else:
        return 0


def guess():
    """Returns hard coded value for fun"""
    i = 0
    while fun(2 ** i) <= 0:
        i += 1

    left = 2 ** (i - 1)
    right = 2 * left

    while left <= right:
        mid = left + ((right - left) // 2)
        if fun(mid) == 0:
            return mid
        elif fun(mid) == -1:
            left = mid + 1
        else:
            right = mid - 1

    return 'Not possible'


if __name__ == '__main__':
    print(guess())