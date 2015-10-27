t = input()
while t:
    a, b, c = raw_input().split()
    a, b, c = int(a), int(b), int(c)
    if a > b:
        if b > c:
            print b
        elif a > c:
            print c
        else:
            print a

    else:
        if a > c:
            print a
        elif b > c:
            print c
        else:
            print b

    t -= 1
