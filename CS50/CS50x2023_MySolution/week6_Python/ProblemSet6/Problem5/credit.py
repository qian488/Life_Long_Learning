# TODO
# ai 太强啦
import re

def luhn_algorithm(card_number):
    def digits_of(n):
        return [int(d) for d in str(n)]
    digits = digits_of(card_number)
    odd_digits = digits[-1::-2]
    even_digits = digits[-2::-2]
    card_check = [sum(divmod(2 * d, 10)) if d * 2 > 9 else d * 2 for d in even_digits]
    return sum(odd_digits + card_check) % 10 == 0

def determine_card_type(card_number):
    if len(card_number) < 13 or len(card_number) > 19:
        return None, False
    if re.match(r'^3[47][0-9]{13}$', str(card_number)):
        return 'AMEX', luhn_algorithm(card_number)
    elif re.match(r'^5[1-5][0-9]{14}$', str(card_number)):
        return 'MASTERCARD', luhn_algorithm(card_number)
    elif re.match(r'^4[0-9]{12}(?:[0-9]{3})?$', str(card_number)):
        return 'VISA', luhn_algorithm(card_number)
    else:
        return None, False

def main():
    card_number = input("Number: ")
    card_type, is_valid = determine_card_type(card_number)
    
    if card_type and is_valid:
        print(card_type)
    else:
        print("INVALID")

if __name__ == "__main__":
    main()