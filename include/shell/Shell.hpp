/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Shell
*/

#ifndef SHELL_HPP_
    #define SHELL_HPP_
    #include "../parser.hpp"

class Shell {
    public:
        Shell(Circuit &circuit);
        ~Shell();
        void start();
        static bool _loopEnable;
    protected:
    private:
        Circuit &_circuit;
        size_t _tick;
        void simulate(bool tick);
        void display();
        static void signalHandler(int signum);
        void loop();
        void assign(std::string &input);
        void handleCommands(std::string &input);
};

#endif /* !SHELL_HPP_ */
