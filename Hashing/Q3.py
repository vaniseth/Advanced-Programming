import random
import time

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def _hash_function1(self, key):
        return key % self.size

    def _hash_function2(self, key):
        return 7 - (key % 7)

    def insert(self, key):
        index = self._hash_function1(key)
        offset = self._hash_function2(key)
        for i in range(self.size):
            if self.table[index] is None:
                self.table[index] = key
                return
            if self.table[index] == key:
                return
            index = (index + offset) % self.size

    def search(self, key):
        index = self._hash_function1(key)
        offset = self._hash_function2(key)
        for i in range(self.size):
            if self.table[index] == key:
                return True
            if self.table[index] is None:
                return False
            index = (index + offset) % self.size
        return False

    def remove(self, key):
        index = self._hash_function1(key)
        offset = self._hash_function2(key)
        for i in range(self.size):
            if self.table[index] == key:
                self.table[index] = None
                return
            if self.table[index] is None:
                return
            index = (index + offset) % self.size

# Create a hash table with double hashing that can hold up to 10,000 integers.
hash_table = HashTable(10000)

# Generate 7,000 random integers and insert them into the hash table.
for i in range(7000):
    hash_table.insert(random.randint(1, 100000))

# Print out the contents of the hash table.
print(hash_table.table)

# Calculate the load factor of the hash table.
load_factor = sum(1 for x in hash_table.table if x is not None) / len(hash_table.table)
print(f"Load factor: {load_factor}")

# Measure the time it takes to search for a random integer in the hash table.
start_time = time.time()
hash_table.search(random.randint(1, 100000))
end_time = time.time()
print(f"Search time: {end_time - start_time} seconds")

# Measure the time it takes to remove a random integer from the hash table.
start_time = time.time()
hash_table.remove(random.randint(1, 100000))
end_time = time.time()
print(f"Remove time: {end_time - start_time} seconds")

# Repeat steps 5 and 6 for different load factors (e.g. 0.5, 0.75, 0.9) and record the results.
load_factors = [0.5, 0.75, 0.9]
for lf in load_factors:
    # Create a new hash table with the desired load factor.
    hash_table = HashTable(int(10000 * lf))

    # Insert random integers into the hash table until the desired load factor is reached.
    while sum(1 for x in hash_table.table if x is not None) / len(hash_table.table) < lf:
        hash_table.insert(random.randint(1, 100000))

    # Measure the time it takes to search for a random integer in the hash table.
    start_time = time.time()
    hash_table.search(random.randint(1, 100000))
    end_time = time.time()
    print(f"Load factor {lf}: Search time: {end_time - start_time} seconds")
