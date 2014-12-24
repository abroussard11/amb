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

#dot -Tpng genDAG.output -o DAG.png

import os

os.system("make --print-data-base > makeDB.out")

f = open("makeDB.out", 'r')
g = open("genDag.out", 'w')
lines = f.readlines()

g.write("digraph G {\n")

for line in lines:
	if ": " in line and "#" not in line and "%" not in line and ".SUFFIXES" not in line:
		line = line.replace("build/obj/","").replace("build/dep/","").replace("build/lib/","").replace("src/","")
		tup = line.split(':')
		targets = tup[0].split()
		deps = tup[1].split()
		for target in targets:
			tgt = "   " + target.replace(".", "_").replace("/", "_").replace("-", "_")
			for dep in deps:
				g.write("   " + tgt + " -> " + dep.replace(".", "_").replace("/", "_").replace("-", "_"))
g.write("}")

g.close()
f.close()

os.system("dot -Tpng genDag.out -o DAG.png")
