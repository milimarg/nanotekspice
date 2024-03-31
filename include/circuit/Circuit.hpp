/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
    #define CIRCUIT_HPP_
    #include "../../include/elementaryComponents.hpp"
    #include "../../include/specialComponents.hpp"
    #include "../../include/gates.hpp"
    #include "../../include/advancedGates.hpp"


class Circuit {
    public:
        class Error : public std::exception {
            public:
                Error(std::string what) : _what(what) {}

                const char *what() const throw() override
                {
                    static std::string errorMessage = "Circuit Error : " + _what;
                    return errorMessage.c_str();
                }

            private:
                std::string _what;
        };
        Circuit();
        ~Circuit();

        void addComponent(std::string &type, std::string &name);
        std::map<std::string, std::unique_ptr<nts::IComponent>> &getComponents();
        void addInput(std::string &type, std::string &name);
        std::map<std::string, std::unique_ptr<nts::IComponent>> &getInput();
        void addOutput(std::string &type, std::string &name);
        std::map<std::string, std::unique_ptr<nts::IComponent>> &getOutput();
        void setLink(std::string &component, size_t pin, std::string &otherComponent, size_t otherPin);
        void checkEmpty();
        nts::EightBitBus &getBus();
        // don't worry bro
        void mov(nts::EightBitRegister &aRegister, nts::EightBitRegister &bRegister, size_t tick);
        void mov(nts::EightBitRegister &aRegister, char value, size_t tick);
        void add(nts::EightBitRegister &aRegister, nts::EightBitRegister &bRegister, size_t tick);
        void sub(nts::EightBitRegister &aRegister, nts::EightBitRegister &bRegister, size_t tick);
protected:
    private:
        std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _inputs;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _outputs;
        std::unique_ptr<nts::IComponent> _true = std::make_unique<nts::TrueComponent>();
        std::unique_ptr<nts::IComponent> _false = std::make_unique<nts::FalseComponent>();
        nts::EightBitBus bus;
        nts::ALU alu;
};

std::ostream &operator<<(std::ostream &os, Circuit &circuit);


#endif /* !CIRCUIT_HPP_ */
