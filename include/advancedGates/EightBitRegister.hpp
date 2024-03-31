/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** EightBitRegister.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_EIGHTBITREGISTER_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_EIGHTBITREGISTER_HPP
    #include "../base.hpp"
    #include "../advancedGates/EightBitBus.hpp"

namespace nts {
    class EightBitRegister : public AComponent {
    public:
        EightBitRegister();
        ~EightBitRegister();

        nts::Tristate compute(std::size_t pin, size_t tick) override;
        void readFrom(nts::EightBitBus &bus, size_t tick);
        void writeTo(nts::EightBitBus &bus, size_t tick);

    protected:
    private:
        std::array<nts::Tristate, 8> _data;
        nts::Tristate lastClockState = nts::False;
        size_t firstOutputPin = 12;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_EIGHTBITREGISTER_HPP
