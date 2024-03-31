/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** OneBitAdderComponent.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_ONEBITADDERCOMPONENT_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_ONEBITADDERCOMPONENT_HPP
    #include "../base.hpp"
    #include "../elementaryComponents.hpp"

namespace nts {

    class OneBitAdderComponent : public AComponent {
        public:
            OneBitAdderComponent();
            ~OneBitAdderComponent();

            nts::Tristate compute(std::size_t pin, size_t tick) override;

        protected:
        private:
            std::array<nts::XORComponent, 2> _xorComponents;
            std::array<nts::ANDComponent, 2> _andComponents;
            nts::ORComponent _orComponent;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_ONEBITADDERCOMPONENT_HPP
