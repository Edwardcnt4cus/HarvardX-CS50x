def luhn_algorithm(number):
    sum = 0
    alternate = False

    while number > 0:
        digit = number % 10
        if alternate:
            digit *= 2
            if digit > 9:
                digit -= 9
        sum += digit
        alternate = not alternate
        number //= 10

    return (sum % 10) == 0

def get_card_type(number):
    length = 0
    start = number

    while start > 0:
        start //= 10
        length += 1

    first_two_digits = number
    while first_two_digits >= 100:
        first_two_digits //= 10

    if ((first_two_digits == 34 or first_two_digits == 37) and length == 15):
        return "AMEX"
    elif (51 <= first_two_digits <= 55 and length == 16):
        return "MASTERCARD"
    elif ((first_two_digits // 10 == 4) and (length == 13 or length == 16)):
        return "VISA"
    else:
        return "INVALID"

def main():
    while True:
        try:
            number = int(input("Number: "))
            if number > 0:
                break
        except ValueError:
            pass

    if luhn_algorithm(number):
        print(get_card_type(number))
    else:
        print("INVALID")

main()
