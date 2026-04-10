def exp_val(boxes, wgts):
    res = 0
    for i in range(len(boxes)):
        res += boxes[i] * wgts[i]
    res /= sum(wgts)
    return res

boxes = []
wgts = []
n = int(input("Size:"))
print("Elements:")
for i in range(n):
    tmp = int(input())
    boxes.append(tmp if tmp > 0 else 0)
print("Weights:")
for i in boxes:
    tmp = int(input())
    wgts.append(tmp if tmp > 0 else 0)
print(exp_val(boxes, wgts))
