#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <exception>
#include <vector>
#include <queue>
#include "output.h"

size_t read_file(std::string& filename, std::vector<std::vector<size_t>>& graph, size_t& vertices, size_t& edges);

std::vector<size_t> dijkstra(const std::vector<std::vector<size_t>>& graph, size_t vertices, size_t source);
