#include <iostream>
#include <fstream>
#include "helper.h"

int main(){
    std::string graph_fname = "gr.txt", output_fname = "result.txt";
    std::vector<std::vector<size_t>> graph;

    size_t vertices, edges, source;

    try{
        source = read_file(graph_fname, graph, vertices, edges); 
    }
    catch(std::exception& ex){
        std::cout << ex.what() << std::endl;
        return -1;
    }

    if (vertices == 0) {
        std::cout << "В графе нет вершин" << std::endl;
        return 0;
    }

    std::ofstream out(output_fname);
    if (!out.is_open()) {
        std::cout << "Не удалось открыть файл" << output_fname << std::endl;
        return -1;
    }
    auto distances = dijkstra(graph, vertices, source);

    for(const auto& el: distances)
        out << el << "\n";
    return 0;
}