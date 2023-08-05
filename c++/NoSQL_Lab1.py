import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  password="",
  database="sem4"
)


mycursor= mydb.cursor()
# print(mydb)

mycursor.execute("CREATE TABLE student( roll varchar(15)")
# Create Database
mycursor.execute("CREATE DATABASE nosql_lab")
for x in mycursor:
      print(x)

# # Create Table
# mycursor.execute("CREATE TABLE customer(cid varchar (15), cname varcha(50) NOT NULL,    PRIMARY KEY(cid))")

# # Insert Values
# mycursor.execute("INSERT INTO customer VALUES('1', 'A'),('2', 'B'),('3', 'C'),('4', 'D')")

# # Update Values
# sql = "UPDATE customer SET cname = 'Z' WHERE cid = '2'"

# mycursor.execute(sql)

# mydb.commit()

# print(mycursor.rowcount, "record(s) affected")

# sql = "DELETE FROM customer WHERE cid = '2'"

# mycursor.execute(sql)

# mydb.commit()

# print(mycursor.rowcount, "record(s) deleted")

# # Q.1
# mycursor.execute("SELECT DISTINCT customer.cname, customer.cid FROM Customer WHERE customer.cid IN (SELECT cid FROM account WHERE atype='S') AND customer.cid IN (SELECT cid FROM account WHERE atype='C')")

# # Q.2
# mycursor.execute(" SELECT b.bcode, b.bname, COUNT(a.ano) AS number_of_accounts FROM branch b, account a WHERE a.bcode= b.bcode GROUP BY a.bcode")

# # Q.3
# mycursor.execute("SELECT branch.bcode, branch.bname FROM branch,account WHERE branch.bcode=account.bcode GROUP BY branch.bcode HAVING COUNT(account.ano)<(SELECT AVG(totalNumb) FROM (SELECT branch.bcode, branch.bname, COUNT(account.ano) AS totalNumb FROM branch,account WHERE branch.bcode=account.bcode GROUP BY branch.bcode) AS temp)")

# # Q.4
# mycursor.execute("SELECT customer.cname, customer.cid, tdate FROM customer JOIN account ON customer.cid = account.cid JOIN Transaction ON account.ano = Transaction.ano GROUP BY cname, customer.cid, tdate HAVING COUNT(Transaction.tid) >= 3 ORDER BY tdate")

# myresult = mycursor.fetchall()

# for x in myresult:
#   print(x)