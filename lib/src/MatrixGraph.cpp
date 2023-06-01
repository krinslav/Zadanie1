#include <IGraph.hpp>
#include <MatrixGraph.hpp>

#include <cassert>
#include <vector>

void MatrixGraph::AddEdge(int from, int to) override{
    assert(0 <= from && from < adjacencyMatrix.size());
    assert(0 <= to && to < adjacencyMatrix.size());
    adjacencyMatrix[from][to] = 1;
    
};
    
int MatrixGraph::VerticesCount() const override{
    return static_cast<int>(adjacencyMatrix.size());
};
    
std::vector<int> MatrixGraph::GetNextVertices(int vertex) const override{
    assert(0 <= vertex && vertex < adjacencyMatrix.size());
    std::vector<int> nextVertex;
    for(int i = 0; i < adjacencyMatrix.size(); ++i)
        if(adjacencyMatrix[vertex][i] == 1)
            nextVertex.push_back(i);
    return nextVertex;
};
    
std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const override{
    assert(0 <= vertex && vertex < adjacencyMatrix.size());
    std::vector<int> prevVertices;
    for(int i = 0; i < adjacencyMatrix.size(); ++i){
        if(i == vertex)
            continue;
        if(adjacencyMatrix[i][vertex] == 1)
            prevVertices.push_back(i);
    }
    return prevVertices;
};