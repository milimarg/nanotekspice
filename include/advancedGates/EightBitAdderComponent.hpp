/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** EightBitAdderComponent.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_EIGHTBITADDERCOMPONENT_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_EIGHTBITADDERCOMPONENT_HPP
    #include "../base.hpp"
    #include "../advancedGates.hpp"

namespace nts {

    class EightBitAdderComponent : public AComponent {
    public:
        EightBitAdderComponent();
        ~EightBitAdderComponent();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        std::array<nts::OneBitAdderComponent, 8> _fullAdder;
        std::vector<PinConnection *> a;
        std::vector<PinConnection *> b;
        const size_t inputNumber = 17;
        const size_t halfMinusOne = ((inputNumber - 1) / 2) - 1;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_EIGHTBITADDERCOMPONENT_HPP
