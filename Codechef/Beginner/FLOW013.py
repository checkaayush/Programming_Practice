t = input()
while t:
    a, b, c = raw_input().split()
    a, b, c = int(a), int(b), int(c)
    sum_ = a + b + c
    if (a and b and c and (sum_ == 180)):
        print "YES"
    else:
        print "NO"
    t -= 1
