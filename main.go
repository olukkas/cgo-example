package main

// #cgo CFLAGS: -I./lib
// #cgo LDFLAGS: -L./lib -ltree
// #include "lib/tree.h"
import "C"
import "fmt"

type MyTree struct {
	root *C.Tree
}

func NewMyTree(initialVal int) *MyTree {
	return &MyTree{
		root: C.leaf(C.size_t(initialVal)),
	}
}

func (m *MyTree) AddNode(value int) {
	C.add_node(m.root, C.size_t(value))
}

func (m *MyTree) IsValuePresent(value int) bool {
	return bool(C.value_present(m.root, C.size_t(value)))
}

func (m *MyTree) Clear() {
	C.clear_tree(m.root)
}

func PrintTree(tree *MyTree) {
	printTreeValues(tree.root, 0)
}

func printTreeValues(tree *C.Tree, level int) {
	if tree == nil {
		return
	}

	for i := 0; i < level; i++ {
		fmt.Print("  ")
	}

	fmt.Printf("node(%d)\n", int(tree.value))

	printTreeValues(tree.left, level+1)
	printTreeValues(tree.right, level+1)
}

func main() {
	tree := NewMyTree(6)
	defer tree.Clear()

	// will be at left of the tree
	tree.AddNode(4)
	tree.AddNode(5)
	tree.AddNode(3)

	// will be at right of tree
	tree.AddNode(9)
	tree.AddNode(7)
	tree.AddNode(10)

	fmt.Printf("is value 6 present?: %v\n", tree.IsValuePresent(6))
	fmt.Printf("is value 33 present?: %v\n", tree.IsValuePresent(33))

	PrintTree(tree)
}
