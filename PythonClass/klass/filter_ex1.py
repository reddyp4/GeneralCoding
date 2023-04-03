#filter_ex1.py
scores = [66, 90, 68, 59, 76, 60, 88, 74]

def is_A_student(score):
    return score>75

over_75 = list(filter(is_A_student(scores)))

def less_zero(x):
    return x<0

numbers_list = list(range(-5,5))
less_than_zero = list(filter(lambda x: x<0, numbers_list))
print(less_than_zero)
