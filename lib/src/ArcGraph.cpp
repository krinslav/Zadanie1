#include <IGraph.hpp>
#include <ArcGraph.hpp>

#include <vector>
#include <set>

void ArcGraph::AddEdge(int from, int to){
    std::pair<int, int> p(from,to);
    arrayOfPairs.push_back(p);
};

int ArcGraph::VerticesCount() const{
    std::set<int> s;
    for(auto& i : arrayOfPairs){
        s.insert(i.first);
        s.insert(i.second);
    }
    return static_cast<int>(s.size());
};

std::vector<int> ArcGraph::GetNextVertices(int vertex) const{
    std::vector<int> nextVertex;
    for(auto& i : arrayOfPairs)
        if(i.first == vertex)
            nextVertex.push_back(i.second);
    return nextVertex;
};
    
std::vector<int> ArcGraph::GetPrevVertices(int vertex) const{
    std::vector<int> prevVertices;
    for(auto& i : arrayOfPairs)
        if(i.second == vertex)
            prevVertices.push_back(i.first);
    return prevVertices;
};