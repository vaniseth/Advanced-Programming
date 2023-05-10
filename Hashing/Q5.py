import random
import time

# Hash table with separate chaining
class HashTableSeparateChaining:
    def __init__(self, capacity):
        self.capacity = capacity
        self.size = 0
        self.table = [[] for _ in range(capacity)]

    def __len__(self):
        return self.size

    def _hash(self, key):
        return key % self.capacity

    def insert(self, key):
        hash_val = self._hash(key)
        bucket = self.table[hash_val]
        for i, (k, v) in enumerate(bucket):
            if k == key:
                bucket[i] = (k, v+1)
                break
        else:
            bucket.append((key, 1))
            self.size += 1

    def search(self, key):
        hash_val = self._hash(key)
        bucket = self.table[hash_val]
        for k, v in bucket:
            if k == key:
                return v
        return None

    def delete(self, key):
        hash_val = self._hash(key)
        bucket = self.table[hash_val]
        for i, (k, v) in enumerate(bucket):
            if k == key:
                del bucket[i]
                self.size -= 1
                return
        raise KeyError(f"Key {key} not found in table")

# Hash table with linear probing
class HashTableLinearProbing:
    def __init__(self, capacity):
        self.capacity = capacity
        self.size = 0
        self.keys = [None] * capacity
        self.values = [None] * capacity

    def __len__(self):
        return self.size

    def _hash(self, key):
        return key % self.capacity

    def _probe(self, hash_val):
        i = 0
        while self.keys[(hash_val + i) % self.capacity] is not None:
            i += 1
        return (hash_val + i) % self.capacity

    def insert(self, key, value):
        hash_val = self._hash(key)
        if self.keys[hash_val] is None:
            self.keys[hash_val] = key
            self.values[hash_val] = value
            self.size += 1
        else:
            i = self._probe(hash_val)
            self.keys[i] = key
            self.values[i] = value
            self.size += 1

    def search(self, key):
        hash_val = self._hash(key)
        i = 0
        while self.keys[(hash_val + i) % self.capacity] is not None:
            if self.keys[(hash_val + i) % self.capacity] == key:
                return self.values[(hash_val + i) % self.capacity]
            i += 1
        return None

    def delete(self, key):
        hash_val = self._hash(key)
        i = 0
        while self.keys[(hash_val + i) % self.capacity] is not None:
            if self.keys[(hash_val + i) % self.capacity] == key:
                self.keys[(hash_val + i) % self.capacity] = None
                self.values[(hash_val + i) % self.capacity] = None
                self.size -= 1
                return
            i += 1
        raise KeyError(f"Key {key} not found in table")

# Hash table with double hashing
class HashTableDoubleHashing:
    def __init__(self, capacity):
        self.capacity = capacity
        self.size = 0
        self.keys = [None] * capacity
        self.values = [None] * capacity
        
