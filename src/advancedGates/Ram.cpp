/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Ram.cpp
*/

#include "../../include/advancedGates/Ram.hpp"

nts::RAM::RAM(nts::EightBitBus &bus)
    : _bus(bus)
{
    for (size_t i = 0; i < _registers.size(); i += 1) {
        for (size_t k = 0; k < _outputPins.size(); k += 1) {
            _registers[i].setLink(8 - k, *_false, 1);
            _registers[i].setLink(_outputPins[k], *_false, 1);
        }
    }
}

nts::RAM::~RAM() {}

nts::Tristate nts::RAM::compute(size_t pin, size_t tick)
{
    PinConnection *clock = _inputs[12];
    PinConnection *enable = _inputs[18];
    PinConnection *read = _inputs[20];
    PinConnection *write = _inputs[21];
    PinConnection *temp = nullptr;
    int foundRegisterIndex = -1;

    _loadSelector.setLink(1, write->_component, write->_pin);
    _enableSelector.setLink(1, read->_component, read->_pin);
    if (updateLinks()) {
        for (size_t i = 0; i < _inputPins.size(); i += 1) {
            temp = _inputs[_inputPins[i]];
            _loadSelector.setLink(11 - i, temp->_component, temp->_pin);
            _enableSelector.setLink(11 - i, temp->_component, temp->_pin);
        }
        for (size_t i = 0; i < _registers.size(); i += 1) {
            _registers[i].setLink(9, clock->_component, clock->_pin);
            _registers[i].setLink(10, _loadSelector, 14 + i);
            _registers[i].setLink(11, _enableSelector, 14 + i);
            for (size_t j = 0; j < _outputPins.size(); j += 1) {
                temp = _inputs[_outputPins[j]];
                _registers[i].setLink(j + 1, temp->_component, temp->_pin);
            }
        }
        _loadSelector.setLink(12, *_false, 1);
        _loadSelector.setLink(13, enable->_component, enable->_pin);
        _enableSelector.setLink(12, *_false, 1);
        _enableSelector.setLink(13, enable->_component, enable->_pin);
    }

    for (size_t i = 0; i < _registers.size(); i += 1)
        if (foundRegisterIndex == -1 && _enableSelector.compute(14 + i, tick) == nts::True)
            foundRegisterIndex = (int)i;
    auto it = std::find(_outputPins.begin(), _outputPins.end(), pin);
    if (foundRegisterIndex != -1 && it != _outputPins.end()) {
        _outputs[pin] = _registers[foundRegisterIndex].compute(12 + (it - _outputPins.begin()), tick);
        _registers[foundRegisterIndex].setLink(10, *_false, 1);
        return _outputs[pin];
    }
    return nts::Undefined;
}

void nts::RAM::storeAt(char value, size_t address)
{
    std::bitset<10> bitSet(address);
    std::bitset<8> bitValue(value);

    for (size_t i = 0; i < _inputPins.size(); i += 1) // set address number
        this->setLink(_inputPins[i], bitSet.test(i) ? *_true : *_false, 1);
    for (size_t i = 0; i < _outputPins.size(); i += 1) // set input data
        this->setLink(_outputPins[_outputPins.size() - i - 1], bitValue.test(i) ? *_true : *_false, 1);
}

void nts::RAM::dump(size_t address, size_t tick)
{
    std::bitset<10> bitSet(address);

    this->setLink(12, *_true, 1);
    for (size_t i = 0; i < _inputPins.size(); i += 1)
        this->setLink(_inputPins[i], bitSet.test(i) ? *_true : *_false, 1);
    for (auto &pin : _outputPins)
        std::cout << this->compute(pin, tick);
    this->setLink(12, *_false, 1);
}
