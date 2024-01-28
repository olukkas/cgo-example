.PHONY: lib
lib:
	cd ./lib && gcc -c tree.c && ar -rcs libtree.a tree.o

.PHONY: clean-lib
clean-lib:
	cd ./lib && rm libtree.a && rm tree.o

.PHONY: run
run:
	go run main.go
