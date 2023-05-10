import random
import time

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash_function(self, key):
        return key % self.size

    def insert(self, key):
        hash_value = self._hash_function(key)
        bucket = self.table[hash_value]
        for i, k in enumerate(bucket):
            if k == key:
                return
        bucket.append(key)

    def search(self, key):
        hash_value = self._hash_function(key)
        bucket = self.table[hash_value]
        for k in bucket:
            if k == key:
                return True
        return False

    def delete(self, key):
        hash_value = self._hash_function(key)
        bucket = self.table[hash_value]
        for i, k in enumerate(bucket):
            if k == key:
                del bucket[i]
                return True
        return False

# Create a hash table with separate chaining that can hold up to 10,000 integers.
hash_table = HashTable(10000)

# Generate 10,000 random integers and insert them into the hash table.
for i in range(10000):
    hash_table.insert(random.randint(1, 100000))

# Print out the contents of the hash table.
print(hash_table.table)

# Calculate the load factor of the hash table.
load_factor = sum(len(bucket) for bucket in hash_table.table) / len(hash_table.table)
print(f"Load factor: {load_factor}")

# Measure the time it takes to search for a random integer in the hash table.
start_time = time.time()
hash_table.search(random.randint(1, 100000))
end_time = time.time()
print(f"Search time: {end_time - start_time} seconds")

# Measure the time it takes to remove a random integer from the hash table.
start_time = time.time()
hash_table.delete(random.randint(1, 100000))
end_time = time.time()
print(f"Delete time: {end_time - start_time} seconds")

# Repeat steps 5 and 6 for different load factors (e.g. 0.5, 0.75, 0.9) and record the results.
load_factors = [0.5, 0.75, 0.9]
for lf in load_factors:
    # Create a new hash table with the desired load factor.
    hash_table = HashTable(int(10000 * lf))

    # Insert random integers into the hash table until the desired load factor is reached.
    while sum(len(bucket) for bucket in hash_table.table) / len(hash_table.table) < lf:
        hash_table.insert(random.randint(1, 100000))

    # Measure the time it takes to search for a random integer in the hash table.
    start_time = time.time()
    hash_table.search(random.randint(1, 100000))
    end_time = time.time()
    print(f"Load factor {lf}: Search time: {end_time - start_time} seconds")

    # Measure the time it takes to remove a random integer from the hash table.
    start_time = time.time()
    hash_table.delete(random.randint(1, 100000))
    end_time = time.time()
    print(f"Load factor {lf}: Delete time: {end_time - start_time} seconds")
