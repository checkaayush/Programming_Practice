def gcd(a, b):
    if not b:
        return a
    else:
        return gcd(b, a % b)


def gcd_n(numbers):
    return reduce(lambda x, y: gcd(x, y), numbers)


user_input = raw_input("Insert space separated numbers: ")
numbers = [int(n) for n in user_input.split()]
print "GCD of given numbers is %g" % (gcd_n(numbers))
