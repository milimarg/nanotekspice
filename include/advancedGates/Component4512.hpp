/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4512.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4512_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4512_HPP
    #include "../base.hpp"
    #include "../elementaryComponents.hpp"

namespace nts {

    class Component4512 : public AComponent {
    public:
        Component4512();
        ~Component4512();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        std::array<nts::NOTComponent, 3> _notComponents;
        std::array<nts::FourInputANDComponent, 8> _andComponents;
        std::array<nts::FourInputORComponent, 2> _fourOrComponents;
        nts::ORComponent _orComponent;
        nts::ANDComponent _andComponent;
        nts::NOTComponent inhibitNot;
        const std::array<size_t, 8> inputPins = {1, 2, 3, 4, 5, 6, 7, 9};
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_COMPONENT4512_HPP
