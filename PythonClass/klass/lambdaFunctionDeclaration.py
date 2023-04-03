#lambda function declaration
import lambdaFunctionDeclaration

def add_1(a,b):
    return (a+b)

add_2 = lambda a,b: a+b

d = add_2(10,20)
print(d)
