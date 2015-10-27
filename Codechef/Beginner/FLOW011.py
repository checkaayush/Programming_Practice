t = input()
while t:
    sal = input()
    (hra, da) = (((0.1 * sal), (0.9 * sal)) if (sal < 1500)
                 else ((500), (0.98 * sal)))
    gr_sal = sal + hra + da
    print gr_sal
    t -= 1
