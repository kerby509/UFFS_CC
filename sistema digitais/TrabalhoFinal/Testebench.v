// `include "bloco_de_controle.v"
// `include "bloco_operativo.v"

module resolver (
    input  [8:0] x,
    input [16:0] a,
    input [16:0] b,
    input [16:0] c,
    input start,
    input  reset,
    input clk,
    output [16:0] result,
    output done  
);
    wire  [1:0] m0;
    wire  [1:0] m1;
    wire  [1:0] m2;
    wire h;
    wire lx;
    wire lh;
    wire ls;

    

endmodule

module testebench;
    reg [8:0] x = 4;
    reg [16:0] a = 2;
    reg [16:0] b = 1;
    reg [16:0] c = 3;

    wire [16:0] resultado;
    
    reg clk = 0, start = 0, reset = 0;

    wire done;

    resolver rslv(x, a, b, c, start, reset, clk, resultado, done);

    always #1 clk <= ~clk;

    initial begin
        $dumpvars;
	    
	    reset <= 1;

	    #1;

	    reset <= 0;
	    start <= 1;

	#60
	    $finish;
    end
endmodule 