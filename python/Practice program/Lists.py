# Creating a list

course=['1','2','2','4','Manoj','Aryan',['DBMS','COA']]
print(course)
print(course[0:4])

print(course[6][0])

# To get length of the list
print(len(course))

# Insert element at end of lists

course.append('SHRADDHA')
print(course)

# Insert element at any position of lists
course.insert(2,['Adil','Hussain','Chandrashekhar'])
print(course)

# To extend the given list
course1=['butter','sweets']
course.append(course1)
print(course)
print(len(course))

# Delete last element
course.remove('1')
popped= course.pop()  # for deleting last element only and return deleted element
print(course)
print(popped)

# to check presence of any element in list
print('DBMS' in course)

# sorting a list or array
arr=[1,6,5,4,2]
sorted_arr = sorted(arr)
print(arr)
print(sorted_arr)

arr.sort(reverse=True)
print(arr)

# Separate elements of list with any symbol

course2=['coa','dsa','cmd','cpp','python']
str3= ' - '.join(course2)
new_arr=str3.split(' - ') # reset separated elements in a list
print(str3)
print(new_arr)

str3= ' , '.join(course2)
print(str3)

new_arr=str3.split(' , ') # reset separated elements in the list
print(new_arr)