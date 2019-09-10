"""Write a python program to reverse a string word by word. The full stop,
question mark, exclamation mark, comma, semicolon should stay where they were.

Input - ‘This is a sample String. However, it can hold integers.’
Output - ‘integers hold can it However. String, sample a is This.’
"""

SPECIAL_CHARS = ['.', '?', '!', ',', ';']


def reverse_string(s):
    """Reverses given string keeping special characters intact."""
    words = s.split()

    l, r = 0, len(words) - 1
    while l < r:
        l_last_char = words[l][-1]
        r_last_char = words[r][-1]

        if l_last_char in SPECIAL_CHARS and r_last_char in SPECIAL_CHARS:
            words[l] = words[l].rstrip(l_last_char) + r_last_char
            words[r] = words[r].rstrip(r_last_char) + l_last_char
        elif l_last_char in SPECIAL_CHARS:
            words[l] = words[l].rstrip(l_last_char)
            words[r] = words[r] + l_last_char
        elif r_last_char in SPECIAL_CHARS:
            words[r] = words[r].rstrip(r_last_char)
            words[l] = words[l] + r_last_char

        l += 1
        r -= 1

    return ' '.join(reversed(words))


def main():
    inp = input('Enter string to be reversed: ')
    print(reverse_string(inp))


if __name__ == '__main__':
    main()