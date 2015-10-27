def gcd(a, b):
    if b == 0:
        return a
    else:
        a = a % b
        return gcd(b, a)


def lcm(a, b):
    g = gcd(a, b)
    return ((a * b) / g)

t = input()
while t:
    a, b = raw_input().split()
    a, b = int(a), int(b)
    print "%d %d" % (gcd(a, b), lcm(a, b))
    t -= 1
