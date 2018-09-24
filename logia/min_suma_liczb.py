def suma(numbers):
    result = 0
    for i in range(len(numbers)):
        result += numbers[i]
        if i == len(numbers) - 1:
            return result + 1
        elif result + 1 < numbers[i + 1]:
            return result + 1


print(suma([1, 2, 3, 4, 100]))
print(suma([1, 1, 2, 3, 5, 18, 21]))
print(suma([1,1,1,1,1]))

a = [object()]
a.append(a[0])
a.append(object())
print(a)
print(a[0] == a[1])
print(a[1] == a[2])
