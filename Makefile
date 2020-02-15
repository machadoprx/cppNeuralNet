all:
	g++ -std=c++17 -lopenblas -fopenmp -liomp5 -lpthread -Ofast main.cpp Matrix.cpp NeuralNet.cpp Layer.cpp png2array/png2array.cpp png2array/lodepng.cpp -Wall
run:
	./a.out