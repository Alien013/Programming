import random
def coin_trials():
    head=0
    for i in range(1000):
        if random.random() <= 0.5:
            head+=1
        return head
# n = input('Number of times coin tossed')
def dimulate(n):
    trials=[]
    for i in range(10):
        trials.append(coin_trials())
        return (sum(trials)/n)