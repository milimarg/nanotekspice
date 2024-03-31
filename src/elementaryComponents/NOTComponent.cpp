/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** NOTComponent
*/

#include "../../include/elementaryComponents.hpp"

nts::NOTComponent::NOTComponent()
{
}

nts::NOTComponent::~NOTComponent()
{
}

nts::Tristate nts::NOTComponent::compute(std::size_t pin, size_t tick)
{
    if (tick == lastTickCheck)
        return _outputs[pin];
    lastTickCheck = tick;
    _outputs[pin] = !GET_STATE(_inputs[1]);
    return _outputs[pin];
}
