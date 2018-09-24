def roman2arabic(roman):
    digits = {"I": 1,
              "V": 5,
              "X": 10,
              "L": 50,
              "C": 100,
              "D": 500,
              "M": 1000}
    arabic = 0
    previous = float("inf")
    for x in roman:
        current = digits[x]
        if current > previous:
            arabic -= 2 * previous
        arabic += current
        previous = current
    return arabic


def arabic2roman(arabic):
    digits = {1: 'I', 4: 'IV', 5: 'V', 9: 'IX', 10: 'X', 40: 'XL', 50: 'L',
              90: 'XL', 100: 'C', 400: 'CD', 500: 'D', 900: 'CM', 1000: 'M', 5000: 'MMMMM'}
    arabic = str(arabic)
    roman = []
    for i, x in enumerate(arabic, -len(arabic) + 1):
        i *= -1
        x = int(x)
        if x == 4 or x == 9:
            roman.append(digits[x * 10**i])
            continue
        else:
            fives = x // 5
            ones = x - 5 * fives
            roman.append(digits[5*10**i] * fives + digits[10**i]*ones)
    return "".join(roman)


def dodajr(romans):
    result = 0
    for roman in romans:
        result += roman2arabic(roman)
    return arabic2roman(result)


if __name__ == '__main__':
    print(dodajr(['MCMXCIX', 'I', 'VII']))
