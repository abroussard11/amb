#!/usr/bin/python
#digraph G {
#	main -> parse -> execute;
#	main -> init;
#	main -> cleanup;
#	execute -> make_string;
#	execute -> printf
#	init -> make_string;
#	main -> printf;
#	execute -> compare;
#}

#dot -Tpng genDAG.dot -o DAG.png

import os

os.system("make --print-data-base > data/MakeDag/database")

f = open("data/MakeDag/database", 'r')
g = open("data/MakeDag/makeDag.dot", 'w')
lines = f.readlines()

g.write("digraph G {\n")
g.write("   graph[rankdir=LR, center=true, margin=0.2, nodesep=0.1, ranksep=0.3]\n")
g.write("   node [shape=record]\n")

for line in lines:
	if (": " in line) and ("#" not in line) and ("%" not in line) and (".SUFFIXES" not in line) and ("make:" not in line) and (".PHONY" not in line):
		line = line.replace("src/","").replace("build/","")
		tup = line.split(':')
		targets = tup[0].split()
		deps = tup[1].split()
		for tgt in targets:
			for dep in deps:
				g.write("   \"" + tgt + "\" -> \"" + dep + "\";\n")
g.write("}")

g.close()
f.close()

os.system("dot -Tpng data/MakeDag/makeDag.dot -o data/MakeDag/makeDag.png")
