/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Shell
*/

#include "../../include/shell.hpp"
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include <csignal>

bool Shell::_loopEnable = false;

Shell::Shell(Circuit &circuit) : _circuit(circuit), _tick(0)
{
}

Shell::~Shell()
{
}

void Shell::simulate(bool tick)
{
    if (tick)
        _tick += 1;
    for (const auto& pair : _circuit.getOutput())
        pair.second->compute(1, _tick);
}

void Shell::display()
{
    std::cout << "tick: " << _tick << std::endl;
    std::cout << _circuit << std::endl;
}

void Shell::signalHandler(int signum)
{
    (void)signum;
    _loopEnable = false;
}

void Shell::loop()
{
    _loopEnable = true;
    signal(SIGINT, signalHandler);

    while (_loopEnable) {
        simulate(true);
        display();
        sleep(1);
    }
    signal(SIGINT, SIG_DFL);
}

void Shell::assign(std::string &input)
{
    std::replace(input.begin(), input.end(), '=', ' ');
    std::vector<std::string> parts = Parser::cleanString(input);
    std::map<std::string, std::unique_ptr<nts::IComponent>> &_inputs = _circuit.getInput();
    auto it = _inputs.find(parts[0]);

    if (it == _inputs.end()) {
        std::cerr << "this input name doesn't exist" << std::endl;
        return;
    }

    nts::Tristate newValue;
    if (parts[1] == "1")
        newValue = nts::True;
    else if (parts[1] == "0")
        newValue = nts::False;
    else if (parts[1] == "U")
        newValue = nts::Undefined;
    else {
        std::cerr << "invalid value for input" << std::endl;
        return;
    }
    it->second->setStatus(newValue);
}

void Shell::handleCommands(std::string &input)
{
    if (input == "simulate")
        return simulate(true);
    if (input == "display")
        return display();
    if (input == "loop")
        return loop();
    size_t firstPos = input.find('=');
    if (firstPos != std::string::npos)
        return assign(input);
    std::cerr << "invalid command" << std::endl;
}

void Shell::start()
{
    std::string input;

    simulate(false);
    while (1) {
        std::cout << "> ";
        if (!std::getline(std::cin, input)) {
            break;
        }
        std::vector<std::string> parts = Parser::cleanString(input);
        if (parts.size() != 1) {
            std::cerr << "too many arguments" << std::endl;
            continue;
        }
        if (input == "exit")
            break;
        handleCommands(parts[0]);
    }
}