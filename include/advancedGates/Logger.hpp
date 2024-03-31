/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Logger.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_LOGGER_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_LOGGER_HPP
    #include "../base.hpp"
    #include "../advancedGates.hpp"

namespace nts {
    class Logger : public AComponent {
    public:
        Logger();
        ~Logger();

        nts::Tristate compute(std::size_t pin, size_t tick) override;

    protected:
    private:
        nts::Tristate lastClockState = nts::False;
        bool firstCall = true;
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_LOGGER_HPP
