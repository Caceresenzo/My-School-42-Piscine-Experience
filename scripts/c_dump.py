import os
import re

def read_file(path):
	return open(path).read()

def print_array(prefix, array, sort=True):
	string = ""
	item_count = len(array)

	if sort:
		array.sort()

	for index in range(0, item_count):
		is_last = index == item_count - 1

		string += array[index]
		
		if not is_last:
			string += ", "

	print("{}: {}".format(prefix, string))

def dump_includes(file_path):
	content = read_file(file_path)
	includes = []
	
	regexes = [
		r"^[\s]*#[\s]*include[\s]*([<].*?[>])[\s]*$",
		r"^[\s]*#[\s]*include[\s]*([\"].*?[\"])[\s]*$"
	]
	
	for regex in regexes:
		matches = re.finditer(regex, content, re.MULTILINE)
		for match in matches:
			includes.append(match.group(1))
	
	print_array("includes ", includes)

def dump_calls(file_path):
	content = read_file(file_path)
	calls = set([])

	matches = re.finditer(r"([\w]+)\(", content, re.MULTILINE)
	for match in matches:
		call = match.group(1)
		if call != "":
			calls.add(call)
	print_array("calls    ", list(calls))

for file in os.listdir():
	if (os.path.isdir(file)):
		for subfile in os.listdir(file):
			full_path = file + "/" + subfile
			if (subfile.endswith(".c")):
				print(">>> " + full_path)
				dump_includes(full_path)
				dump_calls(full_path)
				print("<<<")
