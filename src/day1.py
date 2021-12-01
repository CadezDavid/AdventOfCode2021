data = open("in/day1.in", "r").readlines()

prev = None
count = 0
for line in data:
    line = int(line)
    if prev and prev < line:
        count += 1
    prev = line

out = open("out/day1.out", "w").write(str(count))
