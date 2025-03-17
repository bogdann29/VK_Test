#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>
#include "src/helper.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]){
    std::string graph_fname, output_fname;

    po::options_description desc("Allowed options");

    desc.add_options()("help,h", "produce help message")
                    ("graph,g", po::value<std::string>(&graph_fname)->default_value("gr.txt"), "file with graph description")
                    ("output,o", po::value<std::string>(&output_fname)->default_value("result.txt"), "output file name");

    po::variables_map varMap;
    po::store(po::parse_command_line(argc, argv, desc), varMap);

    try{
        po::notify(varMap);
    }
    catch(std::exception& ex){
        std::cout << ex.what() << std::endl;
        return -1;
    }

    if (varMap.count("help") || varMap.count("h"))
    {
        std::cout << desc << "\n";
        return 1;
    }

    std::ifstream file(graph_fname);
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл " << graph_fname << std::endl;
        return -1;
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