/*
** EPITECH PROJECT, 2024
** Bootstrap_NanoTekSpice
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
    #define ICOMPONENT_HPP_
    #include <iostream>
    #include <map>
    #include <sstream>
    #include <fstream>
    #include <vector>
    #include <memory>
    #include <array>
    #include <functional>

namespace nts
{
    enum Tristate
    {
        Undefined = (-true),
        True = true,
        False = false
    };

    Tristate operator&&(Tristate lhs, Tristate rhs);
    Tristate operator||(Tristate lhs, Tristate rhs);
    Tristate operator!(Tristate lhs);

    class IComponent
    {
        public :
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin, size_t tick) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual nts::Tristate getStatus() = 0;
            virtual void setStatus(nts::Tristate tristate) = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
