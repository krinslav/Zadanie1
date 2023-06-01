#pragma once

#include <IGraph.hpp>
#include <vector>

struct MatrixGraph : public IGraph{
public:
    
    MatrixGraph(int size) : adjacencyMatrix(size, std::vector<int>(size, 0)) {};
    
    MatrixGraph(const IGraph& graph) : adjacencyMatrix(graph.VerticesCount(), std::vector<int>(graph.VerticesCount(), 0)){
        for(int i = 0; i < graph.VerticesCount(); ++i)
            for(int j : graph.GetNextVertices(i))
                adjacencyMatrix[i][j] = 1;
    };
    
    ~MatrixGraph(){};
    
    void AddEdge(int from, int to) override;
    
    int VerticesCount() const override;
    
    std::vector<int> GetNextVertices(int vertex) const override;
    
    std::vector<int> GetPrevVertices(int vertex) const override;
    
private:
    std::vector<std::vector<int>> adjacencyMatrix;
};