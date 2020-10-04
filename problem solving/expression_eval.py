# import jenkins
# from xml.etree import ElementTree
#
# HOST = "http://desktop-l5t987d.local:8080/"
# username = "shubham"
# password = "0202@btii"
# server = jenkins.Jenkins(HOST, username=username, password=password)
#
# config = server.get_job_config("UoM--Boost/hfr--IB--sn--api_test--ddos_7.1--HPUX_IA64")
# root = ElementTree.fromstring(config)
# new_config = ElementTree.tostring(root, encoding="utf8", method="xml").decode()
# print(type(new_config))
# print(new_config)
# server.create_job("My_new_TEST", new_config)

def tokenize(s: str) -> list:
    tokens = []
    digits = ("0", "1", "2", "3", "4", "5", "6", "7", "8", "9")
    i = 0
    operand = ""
    while i < len(s):
        c = s[i]
        if c in ("*", "/", "%", "+", "-", "(", ")"):
            tokens.append(c)
        elif c == " ":
            pass
        elif c in digits:
            operand = c
            while i + 1 < len(s) and s[i + 1] in digits:
                i = i + 1
                operand = operand + s[i]
            tokens.append(int(operand))
        i = i + 1
    return tokens


def infix_to_postfix(infix: list) -> list:
    postfix = []
    stk = ["$"]
    for t in infix:
        if type(t) is int:
            postfix.append(t)
        elif t == "(":
            stk.append(t)
        elif t == ")":
            while stk[-1] != "(":
                postfix.append(stk.pop())
            stk.pop()
        elif t in ("+", "-", "*", "/", "%"):
            if t in ("*", "/", "%"):
                if stk[-1] not in ("*", "/", "%"):
                    stk.append(t)
                else:
                    postfix.append(stk.pop())
                    stk.append(t)
            else:
                if stk[-1] in ("$", "("):
                    stk.append(t)
                else:
                    postfix.append(stk.pop())
                    stk.append(t)
        else:
            raise Exception("Unrecognized character %s" % t)
    while stk[-1] != "$":
        postfix.append(stk.pop())
    return postfix


def eval_postfix(postfix: str) -> int:
    stk = ["$"]
    for t in postfix:
        if type(t) is int:
            stk.append(t)
        else:
            y = stk.pop()
            x = stk.pop()
            if t == "+":
                stk.append(x + y)
            elif t == "-":
                stk.append(x - y)
            elif t == "*":
                stk.append(x * y)
            elif t == "/":
                stk.append(x / y)
            else:
                stk.append(x % y)
    return stk[-1]


def main():
    s = input()
    print(eval_postfix(infix_to_postfix(tokenize(s))))


if __name__ == "__main__":
    main()
