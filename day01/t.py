#!/usr/bin/env python3

import sys

def part_one(nums):
	for i in nums:
		for j in nums:
			if i + j == 2020:
				return i * j

def part_two(nums):
	for i in nums:
		for j in nums:
			for k in nums:
				if i + j + k == 2020:
					return i * j * k

def main():
	input = []
	for line in sys.stdin:
		input.append(int(line.zfill(5)))

	input.sort()
	
	print(part_one(input))
	print(part_two(input))

if __name__ == "__main__":
	sys.exit(main())
