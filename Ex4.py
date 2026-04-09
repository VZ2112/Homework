import math

fcs = {
    "square": (lambda x: x * x),
    "sin": math.sin,
    "exp": math.exp,
    "log": math.log
}

ders = {
    "square": (lambda x: 2 * x),
    "sin": math.cos,
    "exp": math.exp,
    "log": (lambda x: 1 / x)
}

def val(func, x):
    if not len(func): return x
    try:
        return fcs[func[0]](val(func[1:], x))
    except:
        return None

def chain_rule(func, x):
    if not len(func): return 1
    try:
        return ders[func[0]](val(func[1:], x)) * chain_rule(func[1:], x)
    except:
        return None

func = ["log", "log"]
x = 1

print(chain_rule(func, x))
