/*
** EPITECH PROJECT, 2024
** Bootstrap_NanoTekSpice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
    #define ACOMPONENT_HPP_
    #define GET_STATE(c) c->_component.compute(c->_pin, tick)
    #include "IComponent.hpp"
    #include "PinConnection.hpp"

class AComponent : public nts::IComponent
{
    public:
        class Error : public std::exception {
            public:
                Error(std::string what) : _what(what) {}

                const char *what() const throw() override
                {
                    static std::string errorMessage = "AComponent Error : " + _what;
                    return errorMessage.c_str();
                }

            private:
                std::string _what;
        };
        AComponent();
        ~AComponent();

        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        nts::Tristate getStatus() override;
        void setStatus(nts::Tristate tristate) override;
        bool updateLinks();

    protected:
        std::map<size_t, PinConnection *> _inputs;
        std::map<size_t, nts::Tristate> _outputs;
        std::vector<PinConnection *> _lastInputs;
        size_t lastTickCheck = -1;
    private:
};

std::ostream &operator<<(std::ostream &s, const nts::Tristate &v);

#endif /* !ACOMPONENT_HPP_ */
