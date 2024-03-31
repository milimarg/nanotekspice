/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Parser
*/

#include "../../include/parser.hpp"

Parser::Parser() : _filepath("")
{
}

Parser::~Parser()
{
}

bool Parser::errorHandling(int argc, char **argv)
{
    if (argc != 2) {
        std::ostringstream oss;
        oss << "Not enough arguments." << std::endl;
        oss << "Use -h to see the usage.";
        throw Error(oss.str());
    }
    _filepath = argv[1];
    if (_filepath == "-h") {
        showUsage();
        return false;
    }
    return true;
}

void Parser::showUsage()
{
    std::cout << "Usage:" << std::endl << "\t./nanotekspice circuit.nts" <<  std::endl << std::endl
    << "\tYou can see examples/or_gate.nts file to see a reference file." << std::endl;
    return;
}


void Parser::handleChipsets(std::string &first, std::string &second)
{
    if (first == "output" || first == "logger")
        _circuit.addOutput(first, second);
    else if (first == "input" || first == "clock")
        _circuit.addInput(first, second);
    else
        _circuit.addComponent(first, second);
}

void Parser::handleLinks(std::string &component, size_t pin, std::string &otherComponent, size_t otherPin)
{
    _circuit.setLink(component, pin, otherComponent, otherPin);
}

std::vector<std::string> Parser::cleanString(std::string line)
{
    std::vector<std::string> parts;
    std::string word;

    size_t pos = line.find('#');
    if (pos != std::string::npos)
        line.erase(pos);
    std::replace(line.begin(), line.end(), '\t', ' ');
    std::replace(line.begin(), line.end(), ':', ' ');
    std::istringstream iss(line);

    while (std::getline(iss, word, ' ')) {
        if (word != "")
            parts.push_back(word);
    }
    return parts;
}

void Parser::parseFile()
{
    std::string line;
    bool chipsets = false;
    std::ifstream inputFile(_filepath);

    if (!inputFile.is_open())
        throw Error("Failed to open file.");
    while (getline(inputFile, line)) {
        std::vector<std::string> parts = cleanString(line);
        if (parts.size() == 0)
            continue;
        if (parts[0] == ".chipsets" && parts.size() == 1) {
            chipsets = true;
            continue;
        } else if (parts[0] == ".links" && parts.size() == 1) {
            chipsets = false;
            continue;
        }
        if (chipsets) {
            if (parts.size() != 2)
                throw Error("Bad components");
            handleChipsets(parts[0], parts[1]);
        } else {
            _circuit.checkEmpty();
            if (parts.size() != 4)
                throw Error("Bad link");
            handleLinks(parts[0], std::stoul(parts[1]), parts[2], std::stoul(parts[3]));
        }
    }
    _circuit.checkEmpty();
    inputFile.close();
}

Circuit &Parser::getCircuit()
{
    return _circuit;
}
