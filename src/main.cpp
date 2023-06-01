#include <IGraph.hpp>
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
    
    BFS(listGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    DFS(listGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    for (int vertex: topologicalSort(listGraph)){
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
    
    //Проверим конструкторы от класса listGraph
    MatrixGraph matrixGraph1(listGraph);
    SetGraph setGraph1(listGraph);
    ArcGraph arcGraph1(listGraph);

    //Проверим конструкторы от класса MatrixGraph
    SetGraph setGraph2(matrixGraph1);
    ArcGraph arcGraph2(matrixGraph1);
    
    //Проверим конструкторы от класса setGraph2
    ArcGraph arcGraph3(setGraph2);

    std::cout << std::endl;
    BFS(matrixGraph1, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    DFS(matrixGraph1, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    for (int vertex: topologicalSort(matrixGraph1)){
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