/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_
    #include "../circuit.hpp"

class Parser {
    public:
        class Error : public std::exception {
            public:
                Error(std::string what) : _what(what) {}

                const char *what() const throw() override
                {
                    static std::string errorMessage = "Parser Error : " + _what;
                    return errorMessage.c_str();
                }

            private:
                std::string _what;
        };
        Parser();
        ~Parser();

        bool errorHandling(int argc, char **argv);
        void parseFile();
        Circuit &getCircuit();
        static std::vector<std::string> cleanString(std::string line);

    protected:
    private:
        void handleChipsets(std::string &first, std::string &second);
        void handleLinks(std::string &component, size_t pin, std::string &otherComponent, size_t otherPin);
        void showUsage();

        std::string _filepath;
        Circuit _circuit;
};

#endif /* !PARSER_HPP_ */
