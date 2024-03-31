/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** logic_instructions.cpp
*/

#include "../../include/base.hpp"
#include "../../include/circuit.hpp"

void Circuit::mov(nts::EightBitRegister &bRegister, nts::EightBitRegister &aRegister, size_t tick)
{
    aRegister.writeTo(bus, tick);
    bRegister.readFrom(bus, tick);
}

void Circuit::mov(nts::EightBitRegister &aRegister, char value, size_t tick)
{
    std::bitset<8> bitSet(value);

    for (size_t i = 0; i < bitSet.size(); i += 1) {
        bus.setData(7 - i, bitSet.test(i) ? nts::True : nts::False);
    }
    aRegister.readFrom(bus, tick);
}

static void connectRegistersToALU(nts::EightBitRegister &a, nts::EightBitRegister &b, nts::ALU &alu)
{
    int aIdx = 12;
    int bIdx = 12;

    for (int i = 1; i < 17; i++) {
        if (i % 2 == 0) {
            alu.setLink(i, b, bIdx);
            bIdx += 1;
        } else {
            alu.setLink(i, a, aIdx);
            aIdx += 1;
        }
    }
}

void Circuit::add(nts::EightBitRegister &bRegister, nts::EightBitRegister &aRegister, size_t tick)
{
    connectRegistersToALU(aRegister, bRegister, alu);
    alu.setLink(17, *_false, 1);
    alu.writeTo(bus, tick);
    bRegister.readFrom(bus, tick);
}

void Circuit::sub(nts::EightBitRegister &bRegister, nts::EightBitRegister &aRegister, size_t tick)
{
    connectRegistersToALU(aRegister, bRegister, alu);
    alu.setLink(17, *_true, 1);
    alu.writeTo(bus, tick);
    bRegister.readFrom(bus, tick);
}
