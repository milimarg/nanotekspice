/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-tekspice-noe.tritsch
** File description:
** Ram.hpp
*/

#ifndef B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_RAM_HPP
    #define B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_RAM_HPP
    #include "../base.hpp"
    #include "../elementaryComponents.hpp"
    #include "../advancedGates/OneThousandTwentyFourInputDemultiplexer.hpp"
    #include "../advancedGates/EightBitRegister.hpp"
    #include "../specialComponents/TrueComponent.hpp"
    #include "../specialComponents/FalseComponent.hpp"

namespace nts {
    class RAM : public AComponent {
    public:
        RAM(nts::EightBitBus &bus);
        ~RAM();

        nts::Tristate compute(std::size_t pin, size_t tick) override;
        void storeAt(char value, size_t address);
        void dump(size_t address, size_t tick);

    protected:
    private:
        nts::EightBitBus &_bus;
        nts::OneThousandTwentyFourInputDemultiplexer _loadSelector;
        nts::OneThousandTwentyFourInputDemultiplexer _enableSelector;
        std::array<nts::EightBitRegister, 1024> _registers;
        std::array<size_t, 10> _inputPins = {8, 7, 6, 5, 4, 3, 2, 1, 23, 22};
        std::array<size_t, 8> _outputPins = {9, 10, 11, 13, 14, 15, 16, 17};
        std::unique_ptr<nts::IComponent> _true = std::make_unique<nts::TrueComponent>();
        std::unique_ptr<nts::IComponent> _false = std::make_unique<nts::FalseComponent>();
    };
}

#endif //B_OOP_400_STG_4_1_TEKSPICE_NOE_TRITSCH_RAM_HPP
