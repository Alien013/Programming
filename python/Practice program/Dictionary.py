# Creating a dictionary
dict1={'Name':'Manoj','Age':'20','Phone':'79055636946'}
print(dict1)

print(dict1['Name']) # to print a particular key element
print(dict1['Age']) # to print a particular key element
print(dict1['Phone']) # to print a particular key element

print(dict1.get('Name')) #to print the key element

print(dict1.get('Address', 'NOT PRESENT')) # to print message instead of error message

dict1['Address']= 'Gulamaiipura' # To insert any key in the given dictionary
print(dict1)

# To update any dictionary
dict1.update({'Name':'Chandrashekhar','Age':'21','Phone':'1234567890','Address':'oddisha','Subject':'CP'}) 
print(dict1)

# For size of dictionary
print(len(dict1))

# For printing all keys present
print(dict1.keys())

# For printing values of keys
print(dict1.values())

# For printing key+values
print(dict1.items())

# delete any key and value
del dict1['Age']
print(dict1)

# Delete given key and value and print value 
Name=dict1.pop('Name')
print(dict1)
print(Name)
print(len(dict1))

# Loop in dictionary
for keys,value in dict1.items():
    print(keys,value)
    
# Sorting of dictionary
dict1={'Name':'Manoj','class':'Graduation','state':'UP'}
sorted_dict=sorted(dict1)
print(sorted_dict)