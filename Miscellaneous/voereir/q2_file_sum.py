"""Write implementation for class X, create a file and write N numbers in it,
one per line. Calculate the sum of all the numbers and output the value.
Delete the file afterwards.

class X(object):
    def __init__():
        self.numbers = []

    def sum():
        return sum(self.numbers)

    # Your code goes here.

# This should do all that what is asked in the question.
x_obj = X()
with x_obj:
    X.sum()
"""

import os
from random import randrange


class X(object):
    def __init__(self):
        self.numbers = []
        self.filepath = None

    def sum(self):
        return sum(self.numbers)

    def _prepare_input_file(self, filename, numlines, maxvalue):
        """Creates file with numlines random numbers, one per line."""
        with open(filename, 'a') as f:
            for _ in range(numlines):
                f.write(str(randrange(maxvalue)) + '\n')
        self.filepath = f.name

    def __enter__(self):
        numlines = 10
        maxvalue = 100
        self._prepare_input_file('q2_nums.txt', numlines, maxvalue)
        with open(self.filepath, 'r') as f:
            for i, line in enumerate(f):
                try:
                    num = int(line.strip())
                    self.numbers.append(num)
                except ValueError:
                    print('Invalid number on line {}'.format(i+1))
        print(self.numbers)

    def __exit__(self, exc_type, exc_value, exc_traceback):
        try:
            os.remove(self.filepath)
        except FileNotFoundError:
            print('File {} does not exist.'.format(self.filepath))


if __name__ == '__main__':
    x_obj = X()
    with x_obj:
        print(x_obj.sum())
