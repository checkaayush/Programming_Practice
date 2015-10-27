t = input()
while t:
    ch = raw_input().lower()
    if ch == "b":
        print "BattleShip"
    elif ch == "c":
        print "Cruiser"
    elif ch == "d":
        print "Destroyer"
    else:
        print "Frigate"
    t -= 1
