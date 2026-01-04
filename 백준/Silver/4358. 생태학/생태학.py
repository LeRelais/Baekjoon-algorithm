import sys
from collections import Counter 

lines = sys.stdin.read().splitlines()

total_count = 0
tree_dict = {}
for name in lines:
    if not name:
        continue
    
    if name in tree_dict:
        tree_dict[name] += 1
    else:
        tree_dict[name] = 1
    total_count += 1
sorted_keys = sorted(tree_dict.keys())

output = []
for key in sorted_keys:
    ratio = (tree_dict[key] / total_count) * 100
    print(f"{key} {ratio:.4f}")