/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** ClockComponent.cpp
*/

#include "../../include/specialComponents.hpp"

nts::ClockComponent::ClockComponent() : _didSet(false)
{
    _outputs[1] = nts::Undefined;
    _outputs[2] = nts::Undefined;
}

nts::ClockComponent::~ClockComponent() {}

nts::Tristate nts::ClockComponent::compute(std::size_t pin, size_t tick)
{
    (void)pin;
    _outputs[1] = _outputs[2];
    if (tick == lastTickCheck)
        return _outputs[1];
    lastTickCheck = tick;
    if (!_didSet) {
        if (_outputs[1] == nts::True)
            _outputs[1] = nts::False;
        else if (_outputs[1] == nts::False)
            _outputs[1] = nts::True;
        _outputs[2] = _outputs[1];
    }
    _didSet = false;
    return _outputs[1];
}

nts::Tristate nts::ClockComponent::getStatus()
{
    return _outputs[1];
}

void nts::ClockComponent::setStatus(nts::Tristate tristate)
{
    _outputs[2] = tristate;
    _didSet = true;
}
