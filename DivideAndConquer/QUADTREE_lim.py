# Time Complexity: O(n) - str scan once
# Elapsed time: 36ms
#
# To store large data, Use QuadTree
# Using for represent compressed black and white picture
# 
# When swap occurs, (0, 1, 2, 3) -> (2, 3, 0, 1) so 0 <-> 2, and 1 <-> 3

import sys

def parse_tree(t_str, idx):
	if t_str[idx] == 'b' or t_str[idx] == 'w':
		return t_str[idx], idx+1
	else:
		# case of 'x'
		sub_tree = [None for _ in range(4)]
		idx += 1
		for i in range(4):
			sub_tree[i], idx = parse_tree(t_str, idx)
		
		return sub_tree, idx

# Solution 1
def work():
	"""
	1) With string - build tree
	2) swap tree's node
	3) Compress tree again and print it.
	"""
	tree_str = sys.stdin.readline().rstrip()
	tree, _ = parse_tree(tree_str, 0)
	
	def swap(t):
		if type(t) is not list:
			return

		for b in t:
			if type(b) is list:
				swap(b)

		# swap(0, 2), swap(1, 3)
		tmp = t[0]
		t[0] = t[2]
		t[2] = tmp
		tmp = t[1]
		t[1] = t[3]
		t[3] = tmp
	
	swap(tree)

	def compress_tree(t):
		if type(t) is not list:
			return t
		
		compressed = 'x'
		for b in t:
			compressed += compress_tree(b)

		return compressed
	
	return compress_tree(tree)


# Solution 2
def work_well():
	"""
	build tree is not needed, because string already represent quad_tree
	just swap 0-2 1-3 nodes.
	"""
	tree_str = list(sys.stdin.readline().rstrip())
	
	def reverse(start):
		"""
		@param start: currently referenced index at string.
		@return: (swapped_string, end_of_current_string_index+1)
		"""
		if tree_str[start] == 'b' or tree_str[start] == 'w':
			return tree_str[start], start+1
		else:
			start += 1
			up_left, start = reverse(start)
			up_right, start = reverse(start)
			lower_left, start = reverse(start)
			lower_right, start = reverse(start)

			return 'x' + lower_left + lower_right + up_left + up_right, start

	# reverse function returns tuple that (swapped string, next start index)
	# we need only 0 index - swapped string so get 0 index element.
	return reverse(0)[0]

test_case = int(sys.stdin.readline())

for _ in range(test_case):
	print(work_well())
