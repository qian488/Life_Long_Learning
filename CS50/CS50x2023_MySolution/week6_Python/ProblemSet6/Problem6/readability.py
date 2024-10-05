# TODO
import re

def solve():
    # 获取用户输入
    text = input("Text: ")
    
    sent = word = letter = 0

    for c in text:
        if c == " ":  
            word += 1
        elif c == "." or c == "?" or c == "!":  
            sent += 1
        elif c.lower() >= "a" and c.lower() <= "z":  
            letter += 1

    word += 1  
    print(word)
    print(sent)
    print(letter)

    L = (letter * 100) / word  
    S = (sent * 100) / word  
    grade = round((0.0588 * L) - (0.296 * S) - 15.8) 


    if grade >= 1 and grade < 16:
        print(f"Grade {grade}")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print("Before Grade 1")

def main():
    # 获取用户输入
    text = input("Text: ")
    
    # 计算单词数、字母数和句子数
    words = len(re.findall(r'\s+', text))
    words += 1
    letters = len(re.findall(r'[A-Za-z]', text))
    sentences = len(re.findall(r'[.!?]', text))

    print(words)
    print(letters)
    print(sentences)
    
    if words == 0:
        print("Before Grade 1")
        return
    
    # 计算L和S的值
    L = (letters * 100) // words
    S = (sentences * 100) // words
    
    # 应用科尔曼-廖公式
    index = 0.0588 * L - 0.296 * S - 15.8
    
    # 确定年级水平
    if index < 1:
        grade = "Before Grade 1"
    elif index >= 16:
        grade = "Grade 16+"
    else:
        grade = f"Grade {round(index)}"
    
    # 打印结果
    print(grade)

if __name__ == "__main__":
    main()