import random
import os

levels = [3, 5, 100, 500]

for level in levels:
    nums = " ".join([str(i) for i in random.sample(range(level), level)])
    print("Level: " + str(level), end=', ', flush=True)
    os.system("./push_swap " + nums + " | ./checker " + nums)

# 3   : 2 or 3
# 5   : < 12
# 100 : 700, 900, 1100, 1300, 1500
# 500 : 5500, 7000, 8500, 10000, 11500
