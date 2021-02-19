from string import punctuation

if __name__ == '__main__':
    s = input()
    s = s.translate(str.maketrans('', '', punctuation + ' '))

    contains_letters_or_numbers = s.isalnum()
    contains_letters = contains_letters_or_numbers and not s.isdigit()
    contains_numbers = contains_letters_or_numbers and not s.isalpha()
    contains_lowercase = contains_letters and s.upper() != s
    contains_uppercase = contains_letters and s.lower() != s

    print(contains_letters_or_numbers)
    print(contains_letters)
    print(contains_numbers)
    print(contains_lowercase)
    print(contains_uppercase)
