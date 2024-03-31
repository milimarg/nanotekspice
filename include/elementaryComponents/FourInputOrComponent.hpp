/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** FourInputOrComponent.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_FOURINPUTORCOMPONENT_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_FOURINPUTORCOMPONENT_HPP
    #include "../gates/Component4071.hpp"

namespace nts {

    class FourInputORComponent : public AComponent {
    public:
        FourInputORComponent();
        ~FourInputORComponent();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        nts::Component4071 _orComponents;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_FOURINPUTORCOMPONENT_HPP
