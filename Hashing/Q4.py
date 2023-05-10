import random
import time

class QuadraticProbingHashTable:
    def __init__(self, size):
        self.size = size
        self.keys = [None] * self.size
        self.values = [None] * self.size
        self.count = 0

    def hash_function(self, key):
        return key % self.size

    def insert(self, key, value):
        if self.count == self.size:
            print("Hash table is full.")
            return False

        index = self.hash_function(key)

        if self.keys[index] is None:
            self.keys[index] = key
            self.values[index] = value
            self.count += 1
            return True

        i = 1
        while i < self.size:
            new_index = (index + i ** 2) % self.size
            if self.keys[new_index] is None:
                self.keys[new_index] = key
                self.values[new_index] = value
                self.count += 1
                return True
            i += 1

        print("Could not insert key-value pair.")
        return False

    def search(self, key):
        index = self.hash_function(key)

        if self.keys[index] == key:
            return self.values[index]

        i = 1
        while self.keys[(index + i ** 2) % self.size] != key:
            i += 1

        return self.values[(index + i ** 2) % self.size]

def test_quadratic_probing():
    table = QuadraticProbingHashTable(10000)
    nums = random.sample(range(1000000), 2000)

    # Insert 2000 random numbers
    start_time = time.time()
    for num in nums:
        table.insert(num, num)
    end_time = time.time()
    print("Time taken to insert 2000 numbers:", end_time - start_time)

    # Print table contents
    print("Table contents:")
    for i in range(len(table.keys)):
        if table.keys[i] is not None:
            print(table.keys[i], table.values[i])

    # Calculate load factor
    load_factor = table.count / table.size
    print("Load factor:", load_factor)

    # Search for a random number
    start_time = time.time()
    random_num = random.choice(nums)
    result = table.search(random_num)
    end_time = time.time()
    print("Time taken to search for a random number:", end_time - start_time)

    # Insert a random number
    start_time = time.time()
    new_num = random.randint(1000000, 2000000)
    table.insert(new_num, new_num)
    end_time = time.time()
    print("Time taken to insert a new number:", end_time - start_time)

test_quadratic_probing()

