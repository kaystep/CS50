import cs50

while True:
    print("Please enter a number that is greater than 0 but less than 24, this will be how high Mario climbes")
    height = cs50.get_int()
    if  (height > 0 and height < 24):
        break

for i in range(height):
    print(" " * (height - i - 1), end="")
    print("#" * (2 + i))
    # print spaces
    # print hashes
    # print newline
