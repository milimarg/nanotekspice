/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** EightBitBus.cpp
*/

#include "../../include/advancedGates/EightBitBus.hpp"

nts::EightBitBus::EightBitBus()
{
    for (auto &bit : _data)
        bit = nts::False;
}

nts::EightBitBus::~EightBitBus() {}

nts::Tristate nts::EightBitBus::compute(size_t pin, size_t tick)
{
    (void)tick;
    if (pin >= 1 && pin <= 8) {
        return _data[pin - 1];
    }
    return nts::Undefined;
}

void nts::EightBitBus::setData(size_t bitOrder, nts::Tristate data)
{
    if (bitOrder > _data.size() - 1)
        return;
    _data[bitOrder] = data;
}
