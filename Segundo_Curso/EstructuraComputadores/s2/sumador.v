
module sumador (output wire [3:0] R, output wire cout3, input wire [3:0] OP1, OP2, input wire [1:0] ALUOp, input wire L, Cin0);

	wire cout0, cout1, cout2;		//Conectan el carry de salida de cada cal con el de entrada de la siguiente cal

	cal cal0 (R[0], cout0, OP1[0], OP2[0], L, Cin0, ALUOp);
	cal cal1 (R[1], cout1, OP1[1], OP2[1], L, cout0, ALUOp);
	cal cal2 (R[2], cout2, OP1[2], OP2[2], L, cout1, ALUOp);
	cal cal3 (R[3], cout3, OP1[3], OP2[3], L, cout2, ALUOp);

endmodule
