/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Component4512.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_ONE_THOUSAND_TWENTY_FOUR_INPUTMULTIPLEXER_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_ONE_THOUSAND_TWENTY_FOUR_INPUTMULTIPLEXER_HPP
    #include "../base.hpp"
    #include "../elementaryComponents.hpp"
    #include <bitset>

namespace nts {
    class OneThousandTwentyFourInputDemultiplexer : public AComponent {
    public:
        OneThousandTwentyFourInputDemultiplexer();
        ~OneThousandTwentyFourInputDemultiplexer();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        std::array<nts::NOTComponent, 10> _notComponents;
        std::array<nts::TenInputAndComponent, 1024> _andComponents;
        std::array<nts::ANDComponent, 1024> _inhibitAnds;
        nts::NOTComponent _inhibitNot;
        const size_t firstInputPin = 2;
        const size_t lastInputPin = 11;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_ONE_THOUSAND_TWENTY_FOUR_INPUTMULTIPLEXER_HPP
