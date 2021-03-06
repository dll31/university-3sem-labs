
#include "utility.h"
#include <string>
#include <algorithm>


void parseConnectionAccessErrors(int error)
{
    switch (error)
    {
    
    case available:
    {
        break;
    }

    case have:
    {
        break;
    }

    case exist:
    {
        break;
    }

    case pipeIsUnavailable:
    {
        std::cout << "Pipe is unavailable\n";
        break;
    }

    case pipeIsUnexist:
    {
        std::cout << "Pipe is unexist\n";
        break;
    }

    case csIsUnexist:
    {
        std::cout << "CS is unexist\n";
        break;
    }

    case csWorkshopIsUnavailable:
    {
        std::cout << "This CS dont have free workshop\n";
        break;
    }

    }
}


void repairCin()
{
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}


void parseFileErrorCode(int errCode)
{
    if (errCode == 0)
    {
        std::cout << "Succesfull operation!\n";
    }
    else
    {
        if (errCode == -1)
        {
            std::cout << "Could not open file!\n";
        }
        else if (errCode == -2)
        {
            std::cout << "Broken data in file!\n";
            //TODO: try to write exception in cout
        }
        else
        {
            std::cout << "Unexpected error code: " << errCode << '\n';
        }
    }
}


//https://stackoverflow.com/questions/8888748/how-to-check-if-given-c-string-or-char-contains-only-digits
bool is_digits(const std::string& str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}


bool checkCorrectYorNValue(std::string messageForUser)
{
    while (true)
    {
        char ch;

        std::cout << messageForUser;
        std::cin >> ch;
        repairCin();

        if (std::cin.fail())
            continue;

        ch = char(std::tolower(ch));
        if (ch == 'y')
        {
            return true;
        }

        else if (ch == 'n')
        {
            return false;
        }
    }
}