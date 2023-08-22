def check(el, q_el):
    if el == ')' and q_el == '(':
        return True
    elif el == ']' and q_el == '[':
        return True
    elif el == '}' and q_el == '{':
        return True
    else:
        return False

s = input()
queue = []
open_brackets = {'(', '[', '{'}
can = True
counter = 0
for el in s:
    if el in open_brackets:
        queue.append(el)
        counter += 1
    else:
        if counter > 0:
            if check(el, queue[-1]):
                queue.pop()
            else:
                can = False
                break
            counter -= 1
        else:
            can = False
            break
if counter != 0:
    can = False
if can:
    print('yes')
else:
    print('no')