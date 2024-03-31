/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4512.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_SIXTEEN_BIT_MULTIPLEXER_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_SIXTEEN_BIT_MULTIPLEXER_HPP
    #include "../base.hpp"
    #include "../elementaryComponents.hpp"
    #include <bitset>

namespace nts {
    class SixteenInputDemultiplexer : public AComponent {
    public:
        SixteenInputDemultiplexer();
        ~SixteenInputDemultiplexer();

        nts::Tristate compute(std::size_t pin, size_t tick) override;
        void setInsideAndGates(std::bitset<4> &bitSet, size_t i, size_t j);

    protected:
    private:
        std::array<nts::NOTComponent, 4> _notComponents;
        std::array<nts::FourInputANDComponent, 16> _andComponents;
        std::array<nts::ANDComponent, 16> _outputAnds;
        std::array<nts::ANDComponent, 16> _inhibitAnds;
        nts::NOTComponent _inhibitNot;
        const size_t firstInputPin = 2;
        const size_t lastInputPin = 5;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_SIXTEEN_BIT_MULTIPLEXER_HPP
