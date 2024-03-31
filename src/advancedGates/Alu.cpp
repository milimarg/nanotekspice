/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Alu.cpp
*/

#include "../../include/advancedGates/Alu.hpp"

nts::ALU::ALU() {}

nts::ALU::~ALU() {}

nts::Tristate nts::ALU::compute(size_t pin, size_t tick)
{
    PinConnection *su = _inputs[17];

    for (size_t i = 0; i < _xorComponents.size(); i += 1) {
        _xorComponents[i].setLink(1, _inputs[inputB[i]]->_component, _inputs[inputB[i]]->_pin);
        _xorComponents[i].setLink(2, su->_component, su->_pin);
    }
    for (size_t i = 0; i < _xorComponents.size(); i += 1) {
        _adderComponent.setLink(inputA[i], _inputs[inputA[i]]->_component, _inputs[inputA[i]]->_pin);
        _adderComponent.setLink(inputB[i], _xorComponents[i], 3);
    }
    _adderComponent.setLink(17, su->_component, su->_pin);
    if (pin >= firstOutputPin && pin <= 25) {
        _outputs[pin] = _adderComponent.compute(pin, tick);
        return _outputs[pin];
    }
    return nts::Undefined;
}

void nts::ALU::writeTo(nts::EightBitBus &bus, size_t tick)
{
    for (size_t i = 0; i < _xorComponents.size(); i += 1)
        bus.setData(i, this->compute(firstOutputPin + i, tick));
}
