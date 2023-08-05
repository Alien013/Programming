use student

switched to db student

db.test.insertMany([{rollno:"S101",name:"Rahul",grade:"A+",hobbies:"dancing",doj:"m"}, {rollno:"S102",name:"abd",grade:"A+",hobbies:"chess",doj:"m"}, {rollno:"S105",name:"xyz",grade:"C",hobbies:"skating",doj:"ja"}, {rollno:"S103",name:"abc",grade:"A+",hobbies:"singing",doj:"m"}, {rollno:"S104",name:"Mnc",grade:"B",hobbies:"cricket",doj:"m"}, {rollno:"S106",name:"mpo",grade:"A+",hobbies:"surfing",doj:"un"}, {rollno:"S107",name:"Ytu",grade:"D",hobbies:"voleyball",doj:"ion"}, {rollno:"S108",name:"ppl",grade:"A+",hobbies:"reading",doj:"m"}, {rollno:"S109",name:"Rem",grade:"B+",hobbies:"carrom",doj:"m"}, {rollno:"S110",nname:"Ram",grade:"A+",hobbies:"riding",doj:"mil"} ])

db.test.updateOne({rollno:"S101"},{$set:{hobbies:"Ice Hockey"}})

db.test.updateOne({name:"Aryan Davi"},{$set:{rollno:"S111",name:"Aryan Davi",grade:"D",hobbies:"ludo",doj:"nil"}},{upsert:true})

db.test.find({$or:[{hobbies:"chess"},{hobbies:"skating"}]})

db.test.find().skip(10)

db.test.find().sort({grade:1},{hobbies:-1})

db.test.deleteOne({rollno:"S101",name:"Rahul"})
