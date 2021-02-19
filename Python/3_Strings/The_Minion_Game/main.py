def minion_game(s):
    length = len(s)
    vowels = 'AEIOU'

    stuart_score = 0
    kevin_score = 0

    for i in range(len(s)):
        if s[i] in vowels:
            kevin_score += length - i
        else:
            stuart_score += length - i

    if stuart_score > kevin_score:
        print('Stuart {}'.format(stuart_score))
    elif stuart_score < kevin_score:
        print('Kevin {}'.format(kevin_score))
    else:
        print('Draw')


if __name__ == '__main__':
    s = input()
    minion_game(s)
