def main(sequence):
    a_count = 0
    result = 0
    for char in sequence:
        if char == "a":
            a_count += 1
        elif char == "b":
            result += a_count
    return result


print(main("abaaaba"))
