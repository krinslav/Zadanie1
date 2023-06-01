#include <IGraph.hpp>
#include <ListGraph.hpp>

#include <cassert>
#include <vector>

void ListGraph::AddEdge(int from, int to) override{
    assert(0 <= from && from < adjacencyLists.size());
    assert(0 <= to && to < adjacencyLists.size());
    adjacencyLists[from].push_back(to);
}

int ListGraph::VerticesCount() const override{
    return static_cast<int>(adjacencyLists.size());
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const override{
    assert(0 <= vertex && vertex < adjacencyLists.size());
    return adjacencyLists[vertex];
}
    
std::vector<int> ListGraph::GetPrevVertices(int vertex) const override{
    assert(0 <= vertex && vertex < adjacencyLists.size());
    std::vector<int> prevVertices;
    
    for (int from = 0; from < adjacencyLists.size(); from++)
    {
        for (int to: adjacencyLists[from])
        {
            if (to == vertex)
            {
                prevVertices.push_back(from);
            }
        }
    }
    return prevVertices;
}