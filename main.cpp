/*
** EPITECH PROJECT, 2024
** Bootstrap_NanoTekSpice
** File description:
** main
*/

#include "include/parser.hpp"
#include "include/specialComponents.hpp"
#include "include/elementaryComponents.hpp"
#include "include/advancedGates.hpp"
#include "include/shell.hpp"

int main(int argc, char **argv) {
    Parser parser;

    try {
       if (!parser.errorHandling(argc, argv))
           return 0;
       parser.parseFile();
       Circuit &circuit = parser.getCircuit();
       Shell shell(circuit);
       shell.start();
       return 0;
    } catch (const std::exception& e) {
       std::cerr << e.what() << std::endl;
       return 84;
    }
    return 0;
}
