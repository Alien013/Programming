
# if-elseif-else
city='Bahraich' #input('Name of the city:')
if city == 'Jabalpur':
    print('City is Jabalpur')
elif city == 'Delhi':
    print('City is not Jabalpur')
else:
    print('City not matched')

# Operators: and                       
user='Admin'
login=True
if user == 'Admin' and login:
    print('Admin page')
else:
    print('Please log in')

login = False
if user == 'Admin' and login:
    print('Pease log in')
else:
    print('Pease log in')

# Or operator
login = False
if user == 'Admin' and login:
    print('Pease log in')
else:
    print('Pease log in')

# not operator
if not login:
    print('Welcome')
else:
    print('PLease log in')
    
# is - used for object comparison or object are same or not
list1=[2,3,4]
list2=[2,3,4]
print(list1 == list2)
print(list1 is list2) # False because ids are different
print(id(list1))
print(id(list2))

list1=[2,3,4]
list2=list1
print(list1 == list2)
print(list1 is list2)
print(id(list1))
print(id(list2))