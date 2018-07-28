example: example.o
	g++ example.o -o example

example.o: example.cpp
	g++ -std=c++11 example.cpp -o example.o -c -g

example_weak_children: example_weak_children.o
	g++ example_weak_children.o -o example_weak_children

example_weak_children.o: example.cpp
	g++ -std=c++11 example.cpp -o example_weak_children.o -c -g -DWEAK_CHILDREN

