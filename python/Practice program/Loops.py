# For loop in python
num =[1,2,3,4,5]
for i in num:
    print(i)
    
num =[1,2,3,4,5]
for i in num:
    if i==3:
        print('Found!')
        break
    print(i)

# range function
for i in range(10):
    print(i)
for i in range(1,11):
    print(i)
    
# nested for loop   
num =[1,2,3,4]
for i in num:
    for j in 'abc':
        print(i,j)
        
# while loop
x=0
while x<10:
    x+=1
    print(x)
    