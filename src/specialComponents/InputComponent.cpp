/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** InputComponent.cpp
*/

#include "../../include/specialComponents.hpp"

nts::InputComponent::InputComponent()
{
    _outputs[1] = nts::Undefined;
    _outputs[2] = nts::Undefined;
}

nts::InputComponent::~InputComponent()
{

}

nts::Tristate nts::InputComponent::compute(std::size_t pin, size_t tick)
{
    (void)pin;
    (void)tick;
    _outputs[1] = _outputs[2];
    return _outputs[1];
}

nts::Tristate nts::InputComponent::getStatus()
{
    return _outputs[1];
}

void nts::InputComponent::setStatus(nts::Tristate tristate)
{
    _outputs[2] = tristate;
}