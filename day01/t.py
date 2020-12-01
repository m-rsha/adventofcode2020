#!/usr/bin/env python3

from sys import exit
from sys import stdin

def main():
	leest = []
#	with open("input", 'r') as f:
#		for line in f:
#			leest.append(int(line.zfill(5)))

	for line in stdin:
		leest.append(int(line.zfill(5)))
	leest.sort()

	for i in leest:
		for j in leest:
			for k in leest:
				if i + j + k == 2020:
					return i * j * k
		
if __name__ == "__main__":
	exit(print(main()))
