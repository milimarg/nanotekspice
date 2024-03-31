/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** TenInputAndComponent.cpp
*/

#include "../../include/elementaryComponents/TenInputAndComponent.hpp"

nts::TenInputAndComponent::TenInputAndComponent() {}

nts::TenInputAndComponent::~TenInputAndComponent() {}

nts::Tristate nts::TenInputAndComponent::compute(size_t pin, size_t tick)
{
    _crazyAnds[0].setLink(1, _inputs[1]->_component, _inputs[1]->_pin);
    _crazyAnds[0].setLink(2, _inputs[2]->_component, _inputs[2]->_pin);
    _crazyAnds[0].setLink(3, _inputs[3]->_component, _inputs[3]->_pin);
    _crazyAnds[0].setLink(4, _inputs[4]->_component, _inputs[4]->_pin);

    _crazyAnds[1].setLink(1, _inputs[5]->_component, _inputs[5]->_pin);
    _crazyAnds[1].setLink(2, _inputs[6]->_component, _inputs[6]->_pin);
    _crazyAnds[1].setLink(3, _inputs[7]->_component, _inputs[7]->_pin);
    _crazyAnds[1].setLink(4, _inputs[8]->_component, _inputs[8]->_pin);

    _crazyAnds[2].setLink(1, _crazyAnds[0], 5);
    _crazyAnds[2].setLink(2, _crazyAnds[1], 5);
    _crazyAnds[2].setLink(3, _inputs[9]->_component, _inputs[9]->_pin);
    _crazyAnds[2].setLink(4, _inputs[10]->_component, _inputs[10]->_pin);

    _andComponent.setLink(1, _crazyAnds[2], 5);
    _andComponent.setLink(2, _inputs[11]->_component, _inputs[11]->_pin);
    if (pin == 11) {
        _outputs[pin] = _andComponent.compute(3, tick);
        return _outputs[pin];
    }
    return nts::Undefined;
}
