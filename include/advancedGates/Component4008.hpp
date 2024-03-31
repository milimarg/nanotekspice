/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** FourBitAdderComponent.hpp (4-bit full adder)
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_FOURBITADDERCOMPONENT_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_FOURBITADDERCOMPONENT_HPP
    #include "../base.hpp"
    #include "../advancedGates.hpp"

namespace nts {

    class FourBitAdderComponent : public AComponent {
        public:
            FourBitAdderComponent();
            ~FourBitAdderComponent();

            nts::Tristate compute(std::size_t pin, size_t tick) override;

        protected:
        private:
            std::array<nts::OneBitAdderComponent, 4> _fullAdder;
            std::vector<PinConnection *> a;
            std::vector<PinConnection *> b;
            const size_t inputNumber = 9;
            const size_t halfMinusOne = ((inputNumber - 1) / 2) - 1;
            const std::array<size_t, 4> aPins = {1, 3, 5, 7};
            const std::array<size_t, 4> bPins = {15, 2, 4, 6};
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_FOURBITADDERCOMPONENT_HPP
