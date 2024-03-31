/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** EightBitBus.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_EIGHTBITBUS_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_EIGHTBITBUS_HPP
    #include "../base.hpp"

namespace nts {
    class EightBitBus : public AComponent {
    public:
        EightBitBus();
        ~EightBitBus();

        nts::Tristate compute(std::size_t pin, size_t tick) override;
        void setData(std::size_t bitOrder, nts::Tristate data);

    protected:
    private:
        std::array<nts::Tristate, 8> _data;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_EIGHTBITBUS_HPP
