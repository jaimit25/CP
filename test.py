import sys

sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

age = input()
print("Hello, World! " + str(age))

list = []
list.append(12)
list.append(13)
list.append(14)


# list with multiple repetetions of and element
list2 =  [19] * 3
print(list2)

last_element = list2[-1]
print(last_element)

last_element = list2.pop()


element = 19
# del list[index]
# or
list2.remove(element)

list2.clear()
print(len(list2))









