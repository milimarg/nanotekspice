🌟 = custom gate

## Elementary Components

[AND Gate](https://1.bp.blogspot.com/-PsATvkQYnvI/UVGZow5XscI/AAAAAAAAAEQ/NmDa7OG2kHI/s1600/And+gate.jpg): \
inputs: 1 (a), 2 (b) \
output: 3

[OR Gate](https://ecomputernotes.com/images/OR%20Gate.jpg): \
inputs: 1 (a), 2 (b) \
output: 3

[NOT Gate](https://2.bp.blogspot.com/-Hzp36s7hDi4/W0ivHf5Xf6I/AAAAAAAAAJI/LmOubGZjOzwy3Mfa13DPW8G0SiC3Ki5cACEwYBhgL/s1600/NOT%2Bgate.png): \
input: 1 \
output: 2

[XOR Gate](https://3.bp.blogspot.com/-pqaoSPDj4ms/VQAi57krJAI/AAAAAAAAAJ0/5Ud5EPesUJA/s1600/xor.jpg): \
inputs: 1 (a), 2 (b) \
output: 3

[NAND Gate](http://hyperphysics.phy-astr.gsu.edu/hbase/Electronic/ietron/nand.gif): \
inputs: 1 (a), 2 (b) \
output: 3

[NOR Gate](https://projectiot123.com/wp-content/uploads/2019/05/nor-gate-truth-table.jpg): \
inputs: 1 (a), 2 (b) \
output: 3

🌟 [XNOR Gate](https://www.build-electronic-circuits.com/wp-content/uploads/2022/09/Truth-table-XNOR-gate-417x500.png): \
inputs: 1 (a), 2 (b) \
output: 3

🌟 4-input AND Gate: \
inputs: 1 (a), 2 (b), 3 (c), 4 (d) \
output: 5

🌟 10-input AND Gate: \
inputs: 1..10 \
output: 11

🌟 4-input OR Gate: \
inputs: 1 (a), 2 (b), 3 (c), 4 (d) \
output: 5

## Special components

True Component: \
output: 1

False Component: \
output: 1

Input Component: \
output: 1

Output Component: \
output: 1

Clock Component: \
output: 1

## Gates

4x NOR Gates (4001) \
inputs: 1,2, 5,6, 8,9, 12,13 \
outputs: 3, 4, 10, 11

4x NAND Gates (4011) \
inputs: 1,2, 5,6, 8,9, 12,13 \
outputs: 3, 4, 10, 11

4x XOR Gates (4030) \
inputs: 1,2, 5,6, 8,9, 12,13 \
outputs: 3, 4, 10, 11

6x NOT Gates (4069) \
inputs: 1, 3, 5, 9, 11, 13 \
outputs: 2, 4, 6, 8, 10, 12

4x OR Gates (4071) \
inputs: 1,2, 5,6, 8,9, 12,13 \
outputs: 3, 4, 10, 11

4x AND Gates (4081) \
inputs: 1,2, 5,6, 8,9, 12,13 \
outputs: 3, 4, 10, 11

## Advanced Gates

🌟 [1-bit Adder](https://1.bp.blogspot.com/-Vuzw9eMbEJA/WTmdACngHTI/AAAAAAAAivQ/T57q-rWqTekBWQkDtzoiKn1hn0Rz3-wkgCLcB/s1600/full%2Badder%2Blayout.jpg): \
inputs: 1 (a), 2 (b), 3 (carry in) \
outputs: 4 (carry out), 5 (sum)

[4-bit Adder](https://3.bp.blogspot.com/-5Az3ntKTsFc/VCGAZ_Rb94I/AAAAAAAAAXQ/zhtfxj5jOeE/s1600/Block+Diagram.png): \
inputs: 7,5,3,1 (a), 6,4,2,15 (b), 9 (carry in) \
outputs: 10..13 (sum), 14 (carry out)

🌟 [8-bit Adder](https://www.engineersgarage.com/wp-content/uploads/2021/02/full-adder-8bit.png): \
inputs: 1..16 (odd is a, even is b), 17 (carry in) \
outputs: 18..25 (sum), 26 (carry out)

🌟 [D Flip-Flop](https://i1.wp.com/dcaclab.com/blog/wp-content/uploads/2020/05/Document-5_1.jpg): \
inputs: 1 (set), 2 (reset), 3 (clock), 4 (data) \
outputs: 5 (Q), 6 (!Q)

Dual D Flip-Flop: \
inputs: 5 (data1), 6 (set1), 4 (reset1), 3 (clock1), 9 (data2), 8 (set2), 10 (reset2), 11 (clock2) \
outputs: 1 (Q1), 2 (!Q1), 13 (Q2), 12 (!Q2)

[10-bit Johnson Decade](https://www.falstad.com/circuit/e-johnsonctr.html): \
inputs: 13 (enable), 14 (clock), 15 (reset) \
outputs: 3, 2, 4, 7, 10, 1, 5, 6, 9, 11 (data), 12 (carry out)

[12-bit binary counter](https://www.ti.com/lit/ds/symlink/sn74lv4040a-ep.pdf): \
inputs: 10 (clock), 11 (reset) \
outputs: 9, 7, 6, 5, 3, 2, 4, 13, 12, 14, 15, 1 (data)

[8-inputs multiplexer (data selector)](https://i.ytimg.com/vi/yJTCkJ4hNxo/maxresdefault.jpg): \
inputs: 11..13 (selector data), 1..7, 9 (input to choose), 10 (inhibit), 15 (enable)
outputs: 14 (out data)

🌟 [16-inputs demultiplexer](https://www.tutorialspoint.com/digital_circuits/images/1_16_demultiplexer.jpg): \
inputs: 1 (data), 2..5 (inputs), 6 (inhibit), 7 (enable) \
outputs: 8..23 (output data)

🌟 1024-inputs demultiplexer: \
inputs: 1 (data), 2..11 (inputs), 12 (inhibit), 13 (enable) \
outputs: 14..1037 (output data)

[4-bit decoder](https://2.bp.blogspot.com/-Wx-GzP7uPMk/T28meHUkp6I/AAAAAAAABgI/k0-o_OtjPYQ/s1600/Logic+diagram+dekoder+4+bit+to+16+line.png): \
inputs: 2, 3, 21, 22 (input), 1 (strobe), 23 (inhibit) \
outputs: 11, 9, 10, 8..4, 18, 17, 20, 19, 14, 13, 16, 15 (decoded bits)

🌟 8-bit register: \
inputs: 1..8 (data), 9 (clock), 10 (load), 11 (enable) \
outputs: 12..19 (data)

🌟 [ALU](https://www.researchgate.net/profile/Jitesh-Shinde-2/publication/330290146/figure/fig1/AS:713546484695040@1547134147520/Arithmetic-unit-logic-in-an-optimized-1-bit-ALU-using-21-multiplexer.png): \
inputs: 1..16 (odd is a, even is b), 17 (instruction, 0 is add, 1 is sub)
outputs: 18..25 (data output)

🌟 1024 Bytes RAM: \
inputs: 12 (clock), 18 (enable), 20 (read), 21 (write), 8, 7, 6, 5, 4, 3, 2, 1, 23, 22 (selector) \
outputs: 9, 10, 11, 13, 14, 15, 16, 17 (data)
