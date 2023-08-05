n = int(input("Enter the number of times you want to perform operation: "))


def Occurrances(list1):
    return list1.count(19) == 2 and list1.count(5) >= 3


list1 = []
for i in range(n):

    m = int(input("Enter the number of elements in list: "))
    for j in range(m):
        xx = int(input("enter the element :"))
        list1.append(xx)
    print("Original List: ", list1)
    print("Check the occurrances of two 19 and more than three 5: \n",
          Occurrances(list1))
    list1 = []

    # //At 5 % alpha level, check whether the complaint is true or not .
