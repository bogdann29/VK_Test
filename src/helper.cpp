#include "helper.h"

size_t read_file(std::istream& stream, std::vector<std::vector<size_t>>& graph,
                    size_t& vertices, size_t& edges){

    if(!(stream >> vertices >> edges)){
        throw std::runtime_error("Неверный формат файла");
    }
    graph.resize(vertices);

    size_t v1, v2;
    for(int i = 0; i < edges; ++i){
        if(!(stream >> v1 >> v2) || v1 >= vertices || v2 >= vertices){
            throw std::runtime_error("Неверный формат файла");
        }
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    size_t source;
    if(!(stream >> source) || source >= vertices){
        throw std::runtime_error("Неверный формат файла");
    }

    return source;
}

std::vector<size_t> dijkstra(const std::vector<std::vector<size_t>>& graph, size_t vertices, size_t source){
    if(vertices == 0)
        return {};
    std::vector<size_t> distance(vertices, -1);
    distance[source] = 0;

    using Pair = std::pair<size_t, size_t>;
    auto comp = [](const Pair& p1, const Pair& p2){ return p1.first > p2.first; };

    std::priority_queue<Pair, std::vector<Pair>, decltype(comp)> pq(comp);
    pq.push({0, source});

    while(!pq.empty()){
        auto [cur_d, v] = pq.top();
        pq.pop();
        if(cur_d > distance[v])
            continue;
        for(const auto& adj: graph[v])
            if(distance[adj] > distance[v] + 1){
                distance[adj] = distance[v] + 1;    
                pq.push({distance[adj], adj});
            }
    }

    return distance;
}
