
module alu (output wire [3:0] R, output wire zero, carry, sign, input wire [3:0] A, B, input wire [1:0] ALUOp, input wire L);
	
	wire Op1_A, Op2_B, cpl, Cin0;	//Op1_A y Op2_B líneas de selección de los MUX, cpl complementar o no el 2º MUX
	wire [3:0] OP1, OP2, out_mux2;	//OP1 mux1 -> operando1, out_mux2 mux2 -> complementador, OP2 compl -> operando2

	mux2_4 mux1 (OP1, 4'b0000, A, Op1_A);
	mux2_4 mux2 (out_mux2, A, B, Op2_B);
	compl1 compl (OP2, out_mux2, cpl);
	sumador sumador1 (R, carry, OP1, OP2, ALUOp, L, Cin0);

	assign Op1_A = L | ~ALUOp[1];	//L + ALUOp[1] negado
	assign Op2_B = L | ~ALUOp[1] | ALUOp[0];
	assign cpl = ~L & (ALUOp[0] | ALUOp[1]);
	assign Cin0 = ALUOp[1] | ALUOp[0];	//complemento a 2

	assign zero = (R == 0) ? 1 : 0;
	assign sign = R[3];

endmodule
// ^=XOR; |=OR; &=AND; ~=NOT