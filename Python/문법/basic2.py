#[튜플] : 리스트와 비슷함
a = [1,2,3] #리스트
b = (1,2,3) #튜플 : 배열의 크기와 길이 변화, 요소 추가, 삭제 등을 못함

t1 = (1,2,'a','b')
print(t1[0])
t2 = (3,4)
print(t1+t2) #t1,t2는 변하지 않고 새로운 튜플을 생성해서 출력했다고 보는게 맞다
print(t1 * 3) 

#[디럭셔리] : "사전"이라는 뜻을 갖는다, JSON객체 같이 '이름'을 검색하면 '이름'이 무엇인지 알려주는 개념이다
#[Key : Value]로 이루어져 있다.
dic = {'name': 'Euiseon', 'age': 26}
print(dic['name'], dic['age'])
a = {1: 'a'}
a['name'] = "익명" #a딕셔너리에 'name'을 이용해서 Value 넣기
print(a)
del a['name']
print(a)
# B = {1: 'a',1:'b'}을 선언하면 뒤에있는 것만 남음
# print(B)하면 '1: b'만 출력됨
c = {1: '파랑구름', 2: '이의선', 3: 'MinsicKoon'}
print(c.keys()) #key들만 출력
print(c.values()) #Value들만 출력
print(c.items()) #새로운 배열안에 튜플 형태로 뽑아낼 수 있음
for k in c.keys():
    print(k)
for v in c.values():
    print(v)    
for i in c.items():
    print(i)        
#c.clear()을 쓰면 c가 비워짐
#print(c[4])라고쓰면 컴파일 오류가 됨
print(c.get(4)) #4라는 key가 없어 'None'이라고 반환함
print(c.get(4, '없음')) #4라는 key가 없으면 '없음'이라고 반환하라는 명령임
print(4 in c) #c안에 4라는 key가 있냐고 물어보고 Ture, False로 대답함(bool형태)

#[집합] : 교집합, 차집합, 여집합 등에 많이 쓰임
#특징 
#(1) 집합에 관련된 것들을 쉽게 처리하기 위해 만들어진 자료형
#(2) 중복을 허용하지 않는다(중복제거할 떄 많이 쓰임)
#(3) 순서가 없다(Unordered)
s1 = set([1,2,3]) #리스트에 set으로 감싸서 선언가능
print(s1)
s2 = {4,5,6} #중괄호로 선언가능
print(s2)
l = [1,2,2,3,3]
newlist = list(set(l))
print(newlist)

s1 = set("Hello")
print(s1) #문자열도 알파벳 나눠서 나눈 다음에 중복을 없애줌

s1 = set([1,2,3,4,5,6])
s2 = set([4,5,6,7,8,9])
print(s1 & s2) #여집합 되는 부분을 출력
print(s1 | s2) #합집합 되는 부분을 출력
print((s1 | s2) - (s1 & s2)) #여집합 나머지 되는 부분 출력
s1.add(7) #추가
print(s1)
s1.update([7,8,9]) #여러개 추가
print(s1)

#[bool(true, false)]
a = True
print(a)
print(type(a))

a = "안녕"
if a:
    print(a)

a = [1,2,3,4]
if a:
    a.pop()
    print(a)

while a: #a리스트가 빌워질 떄까지 출력한다는 의미
    a.pop()
    print(a)

print(id(a)) #a의 주소값
b = a #값이 복사가 된 것이 아닌 a의 주소값을 넘긴거임(메모리 추가 X)
print(id(b)) #b의 주소값
print(a is b) #a가 b와 같은 주소값을 갖느냐고 bool형태로 물어보는거임
b = a[:] #이렇게 해야 복사가 됨(메모리 추가 O)
print(id(a))
print(id(b))
print(a is b)
from copy import copy #copy라는 라이브러리에서 copy라는 함수를 갖고 온다는 뜻
b = copy(a) #copy함수로도 복사 가능(메모리 추가 O)

#[변수]
(a, b) = ('python', 'life') #튜플을 아용해서 각각 변수 선언 가능
print(a)
print(b)

[a, b] = ['python', 'life'] #리스트을 아용해서 각각 변수 선언 가능
print(a)
print(b)
 
a = b ='hello'
print(a)
print(b)

a = 3
b = 5
a,b = b,a #a와 b를 스왑
print(a)
print(b)

