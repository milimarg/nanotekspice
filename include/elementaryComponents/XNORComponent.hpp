/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** XnorComponent.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_XNORCOMPONENT_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_XNORCOMPONENT_HPP
    #include "../base/AComponent.hpp"
    #include "../../include/elementaryComponents/XORComponent.hpp"
    #include "../../include/elementaryComponents/NOTComponent.hpp"

namespace nts {

    class XNORComponent : public AComponent
    {
    public:
        XNORComponent();
        ~XNORComponent();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        nts::XORComponent xorComponent;
        nts::NOTComponent notComponent;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_XNORCOMPONENT_HPP
