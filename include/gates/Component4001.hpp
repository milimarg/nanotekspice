/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4001.hpp (4x NOR Gates)
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4001_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4001_HPP
    #include "../base.hpp"
    #include "../elementaryComponents.hpp"

namespace nts {

    class Component4001 : public AComponent {
        public:
            Component4001();
            ~Component4001();

            nts::Tristate compute(std::size_t pin, size_t tick) override;

        protected:
        private:
            std::array<nts::NORComponent, 4> _norComponents;
            const std::array<size_t, 4> firstInputPins = {1, 5, 8, 12};
            const std::array<size_t, 4> output = {3, 4, 10, 11};
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4001_HPP
