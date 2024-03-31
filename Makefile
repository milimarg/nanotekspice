##
## EPITECH PROJECT, 2024
## Paradigms Seminar
## File description:
## Makefile
##

SRC	=	main.cpp \
		src/base/AComponent.cpp \
		src/specialComponents/InputComponent.cpp \
		src/specialComponents/OutputComponent.cpp \
		src/specialComponents/TrueComponent.cpp \
		src/specialComponents/FalseComponent.cpp \
		src/specialComponents/ClockComponent.cpp	\
		src/elementaryComponents/ANDComponent.cpp	\
		src/elementaryComponents/NANDComponent.cpp \
		src/elementaryComponents/NOTComponent.cpp	\
		src/elementaryComponents/ORComponent.cpp	\
		src/elementaryComponents/XORComponent.cpp	\
		src/elementaryComponents/NORComponent.cpp \
		src/elementaryComponents/XNORComponent.cpp \
		src/elementaryComponents/FourInputAndComponent.cpp \
		src/elementaryComponents/FourInputOrComponent.cpp \
		src/elementaryComponents/TenInputAndComponent.cpp \
		src/gates/Component4001.cpp \
		src/gates/Component4011.cpp \
		src/gates/Component4030.cpp \
		src/gates/Component4069.cpp \
		src/gates/Component4071.cpp \
		src/gates/Component4081.cpp \
		src/advancedGates/OneBitAdderComponent.cpp \
		src/advancedGates/Component4008.cpp \
		src/advancedGates/EightBitAdderComponent.cpp \
		src/advancedGates/DFlipFlop.cpp \
		src/advancedGates/Component4013.cpp \
		src/advancedGates/Component4017.cpp \
		src/advancedGates/Component4040.cpp \
		src/advancedGates/Component4512.cpp \
		src/advancedGates/Component4514.cpp \
		src/advancedGates/Component4094.cpp \
		src/advancedGates/EightBitRegister.cpp \
		src/advancedGates/EightBitBus.cpp \
		src/advancedGates/Logger.cpp \
		src/advancedGates/Alu.cpp \
		src/advancedGates/SixteenInputDemultiplexer.cpp \
		src/advancedGates/OneThousandTwentyFourInputDemultiplexer.cpp \
		src/advancedGates/Ram.cpp \
		src/circuit/Circuit.cpp	\
		src/logic_instructions/logic_instructions.cpp \
		src/parser/Parser.cpp	\
		src/shell/Shell.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	nanotekspice

CPPFLAGS	=	-Wall -Wextra -std=c++20 -g

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(OBJ) -o $(NAME) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re tests_run
