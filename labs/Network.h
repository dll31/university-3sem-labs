#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>

#include "Pipe.h"
#include "Compressor_station.h"


class Network
{
private:
    std::string pipeSepInFile = "Pipe";
    std::string compStationSepInFile = "CS";

public:

    std::unordered_map<int, Pipe> Pipeline;
    std::unordered_map<int, Compressor_station> CSArray;

    void loadElementsFromFile(std::string file);
    void saveInFile(std::string file);

    template <typename T>
    int getId(std::unordered_map<int, T>& umap);

    void pipeInputConsole();
    void csInputConsole();

    template <typename T>
    void deleteEnement(std::unordered_map<int, T>& umap, int id);

    template <typename T>
    void edit(std::unordered_map<int, T>& umap, int id);

    void display();
};


template <typename T>
int Network::getId(std::unordered_map<int, T>& umap)
{
    int id = 0;

    while (true)
    {
        //from example: https://www.geeksforgeeks.org/unordered_map-at-cpp/
        try
        {
            umap.at(id);
        }

        catch (const std::out_of_range& e)
        {
            return id;
        }

        id++;
    }

    return id;
}


template <typename T>
void Network::deleteEnement(std::unordered_map<int, T>& umap, int id)
{
    if (umap.count(id))
        umap.erase(id);
    else
        std::cout << "No element with id " << id << "\n";
}


template <typename T>
void Network::edit(std::unordered_map<int, T>& umap, int id)
{
    if (umap.count(id))
        umap[id].edit();
    else 
        std::cout << "No element with id " << id << "\n";
}