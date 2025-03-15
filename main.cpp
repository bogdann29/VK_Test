#include <iostream>
#include <fstream>
#include "src/helper.h"


int main(){
    std::string graph_fname = "gr.txt", output_fname = "result.txt";

    std::ifstream file(graph_fname);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл" + graph_fname);
    }

    std::vector<std::vector<size_t>> graph;

    size_t vertices, edges, source;

    try{
        source = read_file(file, graph, vertices, edges); 
    }
    catch(std::exception& ex){
        std::cout << ex.what() << std::endl;
        return -1;
    }

    std::ofstream out(output_fname);
    if (!out.is_open()) {
        std::cout << "Не удалось открыть файл " << output_fname << std::endl;
        return -1;
    }
    auto distances = dijkstra(graph, vertices, source);

    for(const auto& el: distances)
        out << el << "\n";
    return 0;
}