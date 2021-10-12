
#include "Compressor_station.h"
#include "utility.h"


void Compressor_station::display()
{
	std::cout << "Compressor station parameters:\n"
        << "id: " << id << '\n'
		<< "name: " << name << '\n'
		<< "workshops: " << countWorkshops << '\n'
		<< "worked workshops: " << countWorkedWorkshops << '\n'
		<< "performance: " << performance << '\n';
}


int Compressor_station::save(std::ofstream& fout)
{
    if (fout.is_open())
    {
        fout << id << '\n'
            << name << '\n'
            << countWorkshops << '\n'
            << countWorkedWorkshops << '\n'
            << performance << '\n';
        return 0;
    }

    return -2;
}


void Compressor_station::inputConsole()
{
    std::cout << "Enter compressor station name: ";
    std::cin.ignore();
    //TODO: try std::ws
    std::getline(std::cin, name);

    while (true)
    {
        std::cout << "Enter workshop count:\n";
        std::cin >> countWorkshops;
        repairCin();

        if (std::cin.fail())
            continue;

        break;
    }

    while (true)
    {
        std::cout << "Enter worked workshop count:\n";
        std::cin >> countWorkedWorkshops;
        repairCin();

        if (std::cin.fail() || !isValueInRange(countWorkedWorkshops, 0, countWorkshops))
            continue;

        break;
    }

    while (true)
    {
        std::cout << "Enter compressor station performance in range(0, 1):\n";
        std::cin >> performance;
        repairCin();

        if (std::cin.fail() || !isValueInRange(performance, 0.0, 1.0))
            continue;
        
        break;
    }

    //FIXME:
    compStationIsEntered = true;
}


int Compressor_station::inputFile(std::ifstream& fin)
{
    if (fin.is_open())
    {
        /*If we have broken data in file, we return error*/
        fin >> id;
        if (fin.fail())
            return -2;

        fin.ignore();
        std::getline(fin, name);
        if (fin.fail())
            return -2;

        fin >> countWorkshops;
        if (fin.fail())
            return -2;

        fin >> countWorkedWorkshops;
        if (fin.fail())
            return -2;

        fin >> performance;
        if (fin.fail())
            return -2;

        return 0;
    }

    return -1;
}


void Compressor_station::changeWorkedWorkshops()
{
    if (!compStationIsEntered)
    {
        std::cout << "Enter compressor station before edit";
        return;
    }
    
    while (true)
    {
        std::cout << "Enter worked workshops count:\n";
        std::cin >> countWorkedWorkshops;
        repairCin();

        if (std::cin.fail() || !isValueInRange(countWorkedWorkshops, 0, countWorkshops))
            continue;

        break;
    }
}


bool Compressor_station::isValueInRange(int value, int from, int to)
{
    if ((value <= to) && (value >= from))
        return true;

    return false;
}

bool Compressor_station::isValueInRange(double value, double from, double to)
{
    if ((value <= to) && (value >= from))
        return true;

    return false;
}