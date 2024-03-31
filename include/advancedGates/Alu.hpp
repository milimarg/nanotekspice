/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Alu.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_ALU_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_ALU_HPP
    #include "../base.hpp"
    #include "../advancedGates/EightBitBus.hpp"
    #include "../advancedGates/EightBitAdderComponent.hpp"
    #include "../elementaryComponents/XORComponent.hpp"

namespace nts {

    class ALU : public AComponent {
    public:
        ALU();
        ~ALU();

        nts::Tristate compute(std::size_t pin, size_t tick) override;
        void writeTo(nts::EightBitBus &bus, size_t tick);

    protected:
    private:
        nts::EightBitAdderComponent _adderComponent;
        std::array<nts::XORComponent, 8> _xorComponents;
        size_t firstOutputPin = 18;
        std::array<size_t, 8> inputA = {1, 3, 5, 7, 9, 11, 13, 15};
        std::array<size_t, 8> inputB = {2, 4, 6, 8, 10, 12, 14, 16};
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_ALU_HPP
