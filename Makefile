all:
	g++ -shared -o sum.dll src/cpp/sum.cpp
	g++ -shared -o libsum.so src/cpp/sum.cpp