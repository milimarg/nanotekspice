/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** FourInputAndComponent.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_FOURINPUTANDCOMPONENT_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_FOURINPUTANDCOMPONENT_HPP
    #include "../gates/Component4081.hpp"

namespace nts {

    class FourInputANDComponent : public AComponent {
    public:
        FourInputANDComponent();
        ~FourInputANDComponent();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        nts::Component4081 _andComponents;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_FOURINPUTANDCOMPONENT_HPP
