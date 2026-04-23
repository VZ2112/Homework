alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def decode(arg):
    if not arg: return [""]
    if len(arg) == 1:
        if '1' <= arg <= '9': return alphabet[int(arg) - 1]
        else: return []
    res = []
    if '1' <= arg[0] <= '9':
        res += [alphabet[int(arg[0]) - 1] + i for i in decode(arg[1:])]
        if arg[0] == '1':
            res += [alphabet[int(arg[:2]) - 1] + ' ' + i for i in decode(arg[2:])]
        if arg[0] == '2':
            if '0' <= arg[1] <= '6':
                res += [alphabet[int(arg[:2]) - 1] + ' ' + i for i in decode(arg[2:])]
        return res
    else:
        return []

text = input("$")
for i in decode(text): print(repr(i))
