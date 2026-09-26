import math

def count_letters(text):
    count = 0
    for char in text:
        if char.isalpha():
            count += 1
    return count

def count_words(text):
    count = 1
    for char in text:
        if char.isspace():
            count += 1
    return count

def count_sentences(text):
    count = 0
    for char in text:
        if char == '.' or char == '!' or char == '?':
            count += 1
    return count

def main():
    text = input("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = 0.0588 * L - 0.296 * S - 15.8

    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(index)}")

main()
