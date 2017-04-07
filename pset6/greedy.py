import cs50

while True:
    print("How much change is owed")
    change = cs50.get_float()
    if (change > 0.00):
        break

quarter = 25
dime = 10
nickel = 5



while True:
    coins = change / 25
    change = change % 25
    coins = coins + change / 10
    change = change % 10
    coins = coins + change / 5
    change = change % 5
    coins = coins + (change / 1)
    if (change == 0):
        break


print(coins)