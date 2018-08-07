
module cal (output wire out, c_out, input wire a, b, l, c_in, input wire [1:0] s);

	wire out_fa, out_cl;		//out_fa salida del fa, out_cl salida de la cl(celda logica)

	fa fa1 (c_out, out_fa, a, b, c_in);
	cl cl1 (out_cl, a, b, s);
	
	assign out = l ? out_cl : out_fa;

endmodule