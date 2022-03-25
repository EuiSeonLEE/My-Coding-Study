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
print(e[::-2])#부호가 들어가면 반대로 읽는거임

h = "hey, hey you, {name} you".format(name = 'yeah')
print(h)

h = """hey,
hey you, 
{name} you""".format(name = 'yeah')
print(h)

h = "%0.4f"%3.1421354
print(h)

h = "hobbbby"
print(h.count('b'))
print(h.find('b'))

h = ",".join("abcd")
print(h)
h = ",".join(["a","b","c","b","e","f"])
print(h)
h = "hi"
print(h.upper())
h = "    hi my name is SEX     "
print(h.strip())
print(h.split())
print(h.replace("my","your"))

#리스트
a = "ABC"
b = "DEF"
c = [1,2,"int",["APPLE", "BANANA"]]
print(c[3])
print(c[0:2])
print(c)
del c[0] #리스트 요소삭세
print(c)
c.append("sex") #리스트 요소 추가
print(c)
d = [1,6,9,2,10,6,3,5,6,7]
d.sort() #숫자는 크기순, 알파벳은 a부터 z, 한글은 ㄱ부터 ㅎ
print(d)
d.reverse() #순서 뒤집기
print(d)
d.insert(0, 11) #리스트 0번째에 숫자 11추가
print(d)
d.remove(6) #리스트의 숫자6을 삭제(여러개면 가장 앞에 번째 1개 지움)
print(d)
print(d.pop()) #스택의 pop이라고 생각하면 됨(꺼낸 요소 보여줌)
print(d.count(6)) #리스트에 숫자 6이 몇개있는지 세준다
d.extend([12,13]) #리스트에 리스트를 뒤로 추가
print(d)