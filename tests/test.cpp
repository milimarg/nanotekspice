/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** test.c
*/

#include "../include/parser.hpp"
#include "../include/specialComponents.hpp"
#include "../include/elementaryComponents.hpp"
#include "../include/advancedGates.hpp"
#include "../include/shell.hpp"
#include <bitset>

static void ram_test(Circuit &circuit)
{
    std::unique_ptr<nts::IComponent> _true = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> _false = std::make_unique<nts::FalseComponent>();
    nts::RAM ram(circuit.getBus());

    ram.setLink(18, *_false, 1); // enable
    ram.setLink(20, *_true, 1); // read
    ram.setLink(21, *_true, 1); // write

    // real program logic
    std::array<size_t, 3> addresses = {442, 330, 102};
    std::array<size_t, 3> values = {10, 8, 4};

    for (size_t i = 0; i < addresses.size(); i += 1) {
        ram.storeAt(values[i], addresses[i]);
        std::cout << "output (ram " << addresses[i] << ") = ";
        ram.dump(addresses[i], i);
        std::cout << std::endl;
    }
}

static void fibonacci(Circuit &circuit)
{
    std::unique_ptr<nts::IComponent> _true = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> _false = std::make_unique<nts::FalseComponent>();
    size_t tick = 1;
    nts::EightBitRegister n1;
    nts::EightBitRegister n2;
    nts::EightBitRegister nth;

    for (size_t i = 1; i < 9; i += 1) {
        n1.setLink(i, *_false, 1);
        n2.setLink(i, *_false, 1);
        nth.setLink(i, *_false, 1);
    }
    for (size_t i = 9; i < 12; i += 1) {
        n1.setLink(i, (i % 2 != 0) ? *_true : *_false, 1);
        n2.setLink(i, (i % 2 != 0) ? *_true : *_false, 1);
        nth.setLink(i, (i % 2 != 0) ? *_true : *_false, 1);
    }

    // real program logic
    circuit.mov(n1, 0, tick);
    circuit.mov(n2, 1, tick);

    for (int i = 0; i < 8; i += 1) {
        for (int i = 12; i < 20; i++)
            std::cout << n1.compute(i, tick);
        std::cout << std::endl;
        circuit.mov(nth, n1, tick);
        circuit.add(nth, n2, tick);
        circuit.mov(n1, n2, tick);
        circuit.mov(n2, nth, tick);
        tick += 1;
    }
}

int main(int argc, char **argv) {
    Parser parser;

    try {
        if (!parser.errorHandling(argc, argv))
            return 0;
        parser.parseFile();
        Circuit &circuit = parser.getCircuit();

        ram_test(circuit);
        //fibonacci(circuit);
        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
