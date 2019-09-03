#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'gameWinner' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING colors as parameter.
#

def is_move_possible(colors, player):
    search = 'www'
    if player == 'bob':
        search = 'bbb'
    
    index = colors.find(search)
    if index == -1:
        return colors, False
    else:
        return colors[:index+1] + colors[index+2:], True


def gameWinner(colors):
    winner = 'bob'
    turn = 0
    players = ['wendy', 'bob']

    while True:
        player = players[turn]
        turn = (turn + 1) % 2

        colors, is_possible = is_move_possible(colors, player)
        if not is_possible:
            winner = players[turn]
            break
    
    return winner


if __name__ == '__main__':