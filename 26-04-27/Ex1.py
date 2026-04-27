data = """
[
  {
    "fullName": "John Smith",
    "points": 20,
    "child": {
      "fullName": "Michael Brown",
      "points": 25,
      "child": {
        "fullName": "David Wilson",
        "points": 14
      }
    }
  },
  {
    "fullName": "Emma Johnson",
    "points": 30
  },
  {
    "fullName": "Olivia Davis",
    "points": 22,
    "child": {
      "fullName": "James Miller",
      "points": 18
    }
  }
]
"""

def parse_char(i, data, char):
    if i == len(data) or data[i] != char:
        raise Exception("Expected %s." % (repr(char)))
    i += 1
    while i < len(data) and data[i] in " \t\n": i += 1
    return i

def parse_int(i, data):
    if i == len(data) or data[i] not in "0123456789":
        raise Exception("Expected Integer.")
    res = 0
    while i < len(data) and data[i] in "0123456789":
        res = 10 * res + int(data[i])
        i += 1
    while i < len(data) and data[i] in " \t\n": i += 1
    return i, res

def parse_str(i, data):
    if i == len(data) or data[i] != '"':
        raise Exception("Expected String.")
    res = ""
    i += 1
    while i < len(data) and data[i] != '"':
        res += data[i]
        i += 1
    if i == len(data) or data[i] != '"':
        raise Exception("Expected closing Quote.")
    i += 1
    while i < len(data) and data[i] in " \t\n": i += 1
    return i, res

def parse_object(arr, i, data):
    name = ""
    pts = 0
    if i == len(data) or data[i] != '{':
        raise Exception("Expected Object.")
    i += 1
    while i < len(data) and data[i] in " \t\n": i += 1
    while i < len(data) and data[i] != '}':
        i, tmp = parse_str(i, data)
        i = parse_char(i, data, ':')
        if tmp == "fullName":
            i, name = parse_str(i, data)
        elif tmp == "points":
            i, pts = parse_int(i, data)
        elif tmp == "child":
            i = parse_object(arr, i, data)
        else: raise Exception("Unknown Identifier.")
        if i == len(data) or data[i] != ',': break
        i += 1
        while i < len(data) and data[i] in " \t\n": i += 1
    arr.append([name, pts])
    return parse_char(i, data, '}')

def parse_array(arr, i, data):
    i = parse_char(i, data, '[')
    while i < len(data) and data[i] != '}':
        if data[i] == '[': i = parse_array(arr, i, data)
        elif data[i] == '{': i = parse_object(arr, i, data)
        else: break
        if i == len(data) or data[i] != ',': break
        i += 1
        while i < len(data) and data[i] in " \t\n": i += 1
    return parse_char(i, data, ']')

def parse_json(arr, i, data):
    while i < len(data) and data[i] in " \t\n": i += 1
    if i == len(data): return i
    if data[i] == '[': return parse_array(arr, i, data)
    if data[i] == '{': return parse_object(arr, i, data)
    raise Exception("Expected Array or Object.")

arr = []
try: parse_json(arr, 0, data)
except Exception as e: print(e)
avg = cnt = 0
for i in arr:
    print(i[0])
    cnt += 1
    avg += i[1]
print("Average Points:", avg / cnt if cnt else avg)