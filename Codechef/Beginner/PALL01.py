t = input()
while t:
    n = raw_input()
    if (n == n[::-1]):
        print "wins"
    else:
        print "losses"
    t -= 1
