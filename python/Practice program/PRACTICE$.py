# Creating a dictionary

d1 = {}
print(type(d1))  # dictionary
d2 = ()
print(type(d2))  # tuple
d3 = []
print(type(d3))  # list

# Print any dictionary
d4 = {"Manoj": "Spicy", "Aryan": "Sweets",
      "Adil": "Salty", "Chandrashekhsr": "Medium-Spicy"}
print(d4)

# Print any particuollar element
print(d4["Adil"])

# Inserting new element in a dictionary
d4["Hussain"] = "Junk food"
print(d4)

# deleting an element from dictionary
del d4["Adil"]
print(d4)


d5 = d4.copy()
del d5["Manoj"]
print(d5)

print(d4.get("Aryan"))

# d4.update({"Shraddha":"Manoj"})

print(d4)
print(d4.keys())
print(d4.items())
