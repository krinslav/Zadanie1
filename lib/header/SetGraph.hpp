#pragma once

#include <IGraph.hpp>

#include <vector>
#include <unordered_set>

struct SetGraph : public IGraph{
public:
    SetGraph(int size) : arrayOfHashTable(size){};

    SetGraph(const IGraph& graph) : arrayOfHashTable(graph.VerticesCount()) {
        for (int i = 0; i < graph.VerticesCount(); i++){
            std::unordered_set<int> s;
            for(int j : graph.GetNextVertices(i))
                s.insert(j);
            arrayOfHashTable[i] = s;
        }
    };
    
    ~SetGraph(){};
    
    void AddEdge(int from, int to) override;
    
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::unordered_set<int>> arrayOfHashTable;
};