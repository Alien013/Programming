import random
import  itertools

N=int(input("the value of N\n"))

dice1 = random.randint(1,4)
for i in range(int(N)):
    dice1 = random.randint(1,4)
    print("Sample Space:",dice1)
   
    outcomes=[list(itertools.product('1234' ,repeat =N))]
    sample = 2**N
    print(outcomes)
    
    
    
    
    
    
    
    
    
    