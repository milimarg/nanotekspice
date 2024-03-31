/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** EightBitRegister.cpp
*/

#include "../../include/advancedGates/EightBitRegister.hpp"
#include "../../include/advancedGates/EightBitBus.hpp"

nts::EightBitRegister::EightBitRegister()
{
    for (auto &element : _data)
        element = nts::False;
}

nts::EightBitRegister::~EightBitRegister() {}

nts::Tristate nts::EightBitRegister::compute(size_t pin, size_t tick)
{
    nts::Tristate clockState = GET_STATE(_inputs[9]);
    nts::Tristate loadState = GET_STATE(_inputs[10]);
    nts::Tristate enableState = GET_STATE(_inputs[11]);

    if (loadState == nts::True && lastClockState == nts::False &&
        clockState == nts::True) {
        for (size_t i = 0; i < _data.size(); i += 1)
            _data[i] = GET_STATE(_inputs[i + 1]);
    }
    if (lastClockState != clockState)
        lastClockState = clockState;
    if (pin >= firstOutputPin && pin <= 19 && enableState == nts::True) {
        _outputs[pin] = _data[pin - firstOutputPin];
        return _outputs[pin];
    }
    return nts::Undefined;
}

void nts::EightBitRegister::readFrom(nts::EightBitBus &bus, size_t tick)
{
    for (size_t i = 0; i < _data.size(); i += 1)
        _data[i] = bus.compute(i + 1, tick);
}

void nts::EightBitRegister::writeTo(nts::EightBitBus &bus, size_t tick)
{
    for (size_t i = 0; i < _data.size(); i += 1)
        bus.setData(i, this->compute(firstOutputPin + i, tick));
}
