/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** PinConnection.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_PINCONNECTION_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_PINCONNECTION_HPP
    #include "IComponent.hpp"

class PinConnection
{
    public:
        PinConnection(nts::IComponent &component, size_t pin) : _component(component), _pin(pin) {}
        nts::IComponent &_component;
        size_t _pin;
};

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_PINCONNECTION_HPP
