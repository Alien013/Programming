CREATE
(john:EMPLOYEE{name:'John', age:34 , salary:12000 , address:'USA', numberOfDependent:5, gender:'M'}),
(mark:EMPLOYEE{name:'Mark', age:25 , salary:17000 , address:'London', numberOfDependent:2, gender:'M'}),
(joe:EMPLOYEE{name:'Joe', age:23 , salary:25000 , address:'Russia', numberOfDependent:3, gender:'M'}),
(diana:EMPLOYEE{name:'Diana', age:31 , salary:36000 , address:'Switzerland', numberOfDependent:8, gender:'F'}),
(sally:EMPLOYEE{name:'Sally', age:34 , salary:120000 , address:'Brazil', numberOfDependent:4, gender:'F'}),
(jennifer:EMPLOYEE{name:'Jennifer', age:27 , salary:34000 , address:'UK', numberOfDependent:15, gender:'F'}),
(melissa:EMPLOYEE{name:'Melissa', age:34 , salary:27000 , address:'Europe', numberOfDependent:6, gender:'F'}),
(dan:EMPLOYEE{name:'Dan', age:64 , salary:1200000 , address:'South Africa', numberOfDependent:7, gender:'M'}),
(ann:EMPLOYEE{name:'Ann', age:54 , salary:7800000 , address:'USA', numberOfDependent:16, gender:'M'}),

(company1:Company{name:'Company1', networth:1.5, year:2023}),
(company2:Company{name:'Company2', networth:175, year:2023}),
(neo4j:Company{name:'Neo4j', networth:9.5, year:2023}),
(xyz:Company{name:'XYZ', networth:11.5, year:2023}),
(abc:Company{name:'ABC', networth:3.5, year:2023}),

(java:Language{name:'Java', developedby:'Me', year:'1992'}),
(dataetl:Language{name:'Data ETL', developedby:'You', year:'2002'}),
(graphs:Language{name:'Graphs', developedby:'xyz', year:'2001'}),
(integration:Language{name:'Integration', developedby:'Yam', year:'2002'}),
(querylanguage:Language{name:'Query Language', developedby:'abc', year:'2005'}),
(application:Language{name:'Application', developedby:'mno', year:'2004'}),

(melissa)-[:WORKS_FOR]->(company1),
(melissa)-[:LIKES]->(dataetl),
(melissa)-[:LIKES]->(querylanguage),
(melissa)-[:LIKES]->(graphs),

(diana)-[:LIKES]->(graphs),
(diana)-[:LIKES]->(querylanguage),
(diana)-[:WORKS_FOR]->(company2),

(joe)-[:LIKES]->(querylanguage),
(joe)-[:IS_FRIENDS_WITH]->(diana),
(joe)-[:IS_FRIENDS_WITH]->(mark),

(mark)-[:LIKES]->(graphs),

(jennifer)-[:LIKES]->(graphs),
(jennifer)-[:IS_FRIENDS_WITH]->(mark),
(jennifer)-[:LIKES]->(java),
(jennifer)-[:IS_FRIENDS_WITH]->(john),
(jennifer)-[:WORKS_FOR]->(neo4j),
(jennifer)-[:IS_FRIENDS_WITH]->(ann),
(jennifer)-[:IS_FRIENDS_WITH]->(sally),
(jennifer)-[:IS_FRIENDS_WITH]->(melissa),

(ann)-[:WORKS_FOR]->(abc),
(ann)-[:IS_FRIENDS_WITH]->(dan),
(ann)-[:LIKES]->(application),

(dan)-[:WORKS_FOR]->(abc),
(dan)-[:LIKES]->(dataetl),
(dan)-[:LIKES]->(integration),

(sally)-[:WORKS_FOR]->(xyz),
(sally)-[:LIKES]->(integration),

(john)-[:LIKES]->(java),
(john)-[:IS_FRIENDS_WITH]->(sally),
(john)-[:WORKS_FOR]->(xyz),
(john)-[:LIKES]->(application)