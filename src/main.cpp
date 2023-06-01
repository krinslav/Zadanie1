#include <ArcGraph.hpp>
#include <ListGraph.hpp>
#include <MatrixGraph.hpp>
#include <SetGraph.hpp>
#include <otherFunc.hpp>

#include <iostream>

int main(int argc, const char * argv[]) {
    ListGraph listGraph(9);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);
    listGraph.AddEdge(7, 8);
    
    MatrixGraph matrixGraph(listGraph);
    SetGraph setGraph(matrixGraph);
    ArcGraph arcGraph(matrixGraph);
    
    BFS(setGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    DFS(setGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    for (int vertex: topologicalSort(setGraph)){
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
    // Нужно продемонстрировать работу конструктора копирования, проинициализировав
    // графы разных классов друг от друга. Далее, показать, что вершины и ребра
    // успешно скопированы: число вершин осталось прежним, произвести BFS и DFS.
    // ArcGraph arcGraph(listGraph);
    // MatrixGraph matrixGraph(arcGraph);
    // SetGraph setGraph(matrixGraph);
    
    return 0;
}