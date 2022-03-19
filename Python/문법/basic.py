#자료형
#숫자, 문자열, bool
#변수, 리스트, 튜플, 딕셔너리, 집합

#변수
a = 3
b = 4
print(type(a))
print(a + b)
print(a/b)
print(a//b) #몫
print(a%2) #나머지

c = 'python'
d = 'python\'s favorite food is perl'
print(type(c))
print(c)
print(d)

e = "Python"
print(e*100)
print(e[0])
print(e[-1])

#문자열 자료형
#a[(이상):(미만):(간격)]
print(e[:5])
print(e[::-1])#부호가 들어가면 반대로 읽는거임

h = "hey, hey you, {name} you".format(name = 'yeah')
print(h)

#말도 안돼...이게 바로...신세계인가...*/