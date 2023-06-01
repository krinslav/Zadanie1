#pragma once

#include <IGraph.hpp>
#include <vector>

struct ArcGraph : public IGraph{
public:
    ArcGraph(int size) : arrayOfPairs(size){};
    
    ArcGraph(const IGraph& graph){
        for(int i = 0; i < graph.VerticesCount(); ++i)
            for(int j : graph.GetNextVertices(i)){
                std::pair<int, int> p(i,j);
                arrayOfPairs.push_back(p);
            }
    };
    
    ~ArcGraph(){};
    
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::pair<int, int>> arrayOfPairs;
};