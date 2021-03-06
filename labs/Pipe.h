#pragma once

#include <iostream>
#include <fstream>
#include <cmath>

class Pipe
{
private:
    int id = 0;

public:

    int diameter;
    double length;
    int throughput = 0;
    bool inRepair = false;

    Pipe();
    Pipe(int id);


    void display();
    int save(std::ofstream& fout);

    void inputConsole();
    int inputFile(std::ifstream& fin);

    void edit();
    void justEdit(bool inRepair);

    void checkCorrectInRepairValue();

    int getId();
};