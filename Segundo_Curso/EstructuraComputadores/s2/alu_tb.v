// Testbench para modulo alu
`timescale 1 ns / 10 ps //Directiva que fija la unidad de tiempo de simulación y la precision de la unidad
module alu_tb;
//declaracion de señales
reg [1:0] t_Op;
reg t_L;
reg [3:0] t_A, t_B;
wire [3:0] t_R;
wire t_z, t_c, t_s;

//instancia del modulo a testear
alu mat(t_R, t_z, t_c, t_s, t_A, t_B, t_Op, t_L);

initial
begin
  $dumpfile("alu.vcd");
  $dumpvars;
  $monitor("tiempo=%0d A=%b B=%b L=%b Op=%b R=%b, Z=%b, C=%b, S=%b", $time, t_A, t_B, t_L, t_Op, t_R, t_z, t_c, t_s);
  //vector de test 0, suma 1000 acarreo, negativo
  t_A = 4'b1010;
  t_B = 4'b1110;
  t_Op = 2'b00;
  t_L = 1'b0;
  # 20;
  //vector de test 1 suma 0000 cero, acarreo
  t_A = 4'b1010;
  t_B = 4'b0110;
  t_Op = 2'b00;
  t_L = 1'b0;
  # 20;
  //vector de test 2 resta 0000 cero
  t_A = 4'b1010;
  t_B = 4'b1010;
  t_Op = 2'b01;
  t_L = 1'b0;
  # 20;
  //vector de test 3 com2 de B 0010
  t_A = 4'b1011;
  t_B = 4'b1110;
  t_Op = 2'b11;
  t_L = 1'b0;

  # 20;
  //vector de test 4 com2 de A 0010
  t_A = 4'b1110;
  t_B = 4'b1010;
  t_Op = 2'b10;
  t_L = 1'b0;

  # 20;
  //vector de test 5 and 1000
  t_A = 4'b1010;
  t_B = 4'b1100;
  t_Op = 2'b00;
  t_L = 1'b1;
  # 20;
  //vector de test 6 xor 0110
  t_A = 4'b1010;
  t_B = 4'b1100;
  t_Op = 2'b10;
  t_L = 1'b1;
  # 20;
  //vector de test 7 inv A 0101
  t_A = 4'b1010;
  t_B = 4'b1100;
  t_Op = 2'b11;
  t_L = 1'b1;
  # 20;

  //fin simulacion
  $finish;
end

endmodule
