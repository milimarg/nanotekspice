/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** TenInputAndComponent.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_TENINPUTANDCOMPONENT_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_TENINPUTANDCOMPONENT_HPP
    #include "../elementaryComponents/FourInputAndComponent.hpp"

namespace nts {
    class FourInputANDComponent;
    class TenInputAndComponent : public AComponent {
    public:
        TenInputAndComponent();
        ~TenInputAndComponent();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        std::array<nts::FourInputANDComponent, 3> _crazyAnds;
        nts::ANDComponent _andComponent;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_TENINPUTANDCOMPONENT_HPP
