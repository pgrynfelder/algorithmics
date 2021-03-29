
def zadanie4():
    n = 20;
    with open("plansza.txt", "r") as f:
        table = f.read().split("\n")
        f.close()
    for i in range(0, len(table)):
        table[i] = [int(x) for x in table[i].split(" ")]
    with open("robot.txt", "r") as f:
        moves = f.read().split("\n")
        f.close()
    result1 = 0
    hiscore = 0
    result2 = 0
    result31 = 0
    result32 = []
    for i in range(0, len(moves)):
        player = moves[i]
        x = 0
        y = 0
        score = 0
        score += table[0][0]
        for move in player:
            if move == "N":
                y -= 1
            elif move == "S":
                y += 1
            elif move == "W":
                x -= 1
            elif move == "E":
                x += 1
            score += table[y][x]

            if x < 0 or x >= n or y < 0 or y >= n:
                result1 += 1
                score = -1
                break
        if score > hiscore:
            hiscore = score
            result2 = i + 1
        sublen = 0
        for move in player:
            if move == "N" or move == "S":
                sublen  = 0
            else:
                sublen += 1;
            if sublen == result31:
                result32.append(i+1)
            elif sublen > result31:
                result31 = sublen
                result32 = []
                result32.append(str(i+1))

    with open("zadanie4.txt", "w") as f:
        f.write(f"4.1 {result1}\n")
        f.write(f"4.2 {result2} {hiscore}\n")
        f.write("4.3 {} {}\n".format(" ".join(result32), result31))
        f.close()


if __name__ == "__main__":
    zadanie4();

