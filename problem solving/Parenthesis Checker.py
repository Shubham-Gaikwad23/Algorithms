# https://practice.geeksforgeeks.org/problems/parenthesis-checker/0
def check_Paranthesis(exp:str):
    stk = []
    for tkn in exp:
        if tkn in ['(', '{', '[']:
            stk.append(tkn)
        else:
            if len(stk)==0:
                return False
                
            match = stk.pop()
            if tkn == ')' and match=='(':
                continue
            elif tkn == ']' and match=='[':
                continue
            elif tkn == '}' and match=='{':
                continue
            else:
                return False
    
    if len(stk)==0:
        return True
    else:
        return False

t = int(input())
while t:
    exp = input()
    if check_Paranthesis(exp):
        print("balanced")
    else:
        print("not balanced")
    t=t-1
