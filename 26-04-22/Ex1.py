base = []

def borrow(title, author):
    lst = []
    for i in range(len(base)):
        f = 1
        if title and base[i][0] != title: f = 0
        if author and base[i][1] != author: f = 0
        if base[i][2]: f = 0
        if f:
            lst.append(i)
            print("\t %s - %s" % (base[i][0], base[i][1]))
    if lst:
        n = 0
        while True:
            try:
                n = int(input("Choose one (0 to cancel):"))
                break
            except:
                continue
        if n:
            base[n][2] = True
            print("Borrowed %s by %s" % (base[n][0], base[n][1]))
    else:
        print("No such Book found.")

def ret(title, author):
    lst = []
    for i in range(len(base())):
        f = 1
        if title and base[i][0] != title: f = 0
        if author and base[i][1] != author: f = 0
        if not base[i][2]: f = 0
        if f:
            lst.append(i)
            print("\t %s - %s" % (base[i][0], base[i][1]))
    if lst:
        n = 0
        while True:
            try:
                n = int(input("Choose one (0 to cancel):"))
                break
            except:
                continue
        if n:
            base[n][2] = False
            print("Return %s by %s" % (base[n][0], base[n][1]))
    else:
        print("No such Book found.")

def srt():
    for i in range(len(base) - 1):
        for j in range(i, len(base)):
            if base[i][0] > base[j][0]:
                tmp = base[i]
                base[i] = base[j]
                base[j] = tmp
            elif base[i][0] == base[j][0] and base[i][1] > base[j][1]:
                tmp = base[i]
                base[i] = base[j]
                base[j] = tmp

def data(taken=False):
    srt()
    for i in base:
        if i[2] == taken: print("\t %s - %s" % (base[i][0], base[i][1]))

with open("Books.txt") as b:
    for i in b.readlines():
        base.append(["", "", False])
        base[-1] = [j.strip() for j in i.split(" - ")]
        base[-1].append(False)

for i in base:
    print(i)

while True:
    cmd, args = ent.split(' ', 1)
    if cmd in ("borrow", "return"):
        arg1, arg2 = "", ""
        args = args.lstrip()
        if args[0] == '"':
            arg1, args = args[1:].split('"', 1)
        else:
            arg1, args = args.split(' ', 1)
        args = args.lstrip()
        if args and args[0] == '"':
            arg2, args = args[1:].split('"', 1)
        elif args:
            arg2, args = args.split(' ', 1)
        print((arg1, arg2))
        if cmd == "borrow": borrow(arg1, arg2)
        else: ret(arg1, arg2)
    elif cmd == "sort":
        srt()
    elif cmd in ("free", "borrowed"):
        data(cmd == "borrowed")
    else:
        print("Bad Command.")