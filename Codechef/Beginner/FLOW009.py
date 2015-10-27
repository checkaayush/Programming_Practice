t = input()
while t:
    q, p = raw_input().split()
    q, p = int(q), int(p)

    dis = 0.0
    if q > 1000:
        dis = 0.1

    amt = (1 - dis) * (q * p)
    print "%0.6f" % amt
    t -= 1
