#include <IGraph.hpp>
#include <SetGraph.hpp>

#include <cassert>
#include <vector>
#include <unordered_set>

void SetGraph::AddEdge(int from, int to) {
        assert(0 <= from && from < arrayOfHashTable.size());
        assert(0 <= to && to < arrayOfHashTable.size());
        arrayOfHashTable[from].insert(to);
};

int SetGraph::VerticesCount() const {
        return static_cast<int>(arrayOfHashTable.size());
};

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
        assert(0 <= vertex && vertex < arrayOfHashTable.size());
        std::vector<int> nextVertex;
        for(auto& i : arrayOfHashTable[vertex])
            nextVertex.push_back(i);
        return nextVertex;
};

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
        std::vector<int> prevVertices;
        for(int i = 0; i < arrayOfHashTable.size(); ++i){
            if(i == vertex)
                continue;
            for(auto& j : arrayOfHashTable[i])
                if(j == vertex)
                    prevVertices.push_back(i);
        }
        return prevVertices;
};