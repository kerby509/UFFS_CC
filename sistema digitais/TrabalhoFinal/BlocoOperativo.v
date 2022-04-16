`include"somador.v"
`include "Multiplexador.v"
`include "Registrador.v"

module BlocoOperativo (
    input lx;
    input h;
    input ls;
    input clk;
    input [16:0] a;
    input [16:0] b;
    input [16:0] c;
    input [1:0] m0;
    input [1:0] m1;
    input [1:0] m2;
    output result;
);

    wire [15:0] out_reg_x ;
    wire [15:0] out_reg_h;
    wire [15:0] out_reg_s ;
    wire [15:0] out_mux_0 ;
    wire [15:0] out_mux_1 ;
    wire [15:0] out_mux_2 ;

    wire [15:0] x_16bits;
    wire [15:0] in_00_mux_0;
s    assign in_00_mux_0 = 0;
    assign x_16bits =x;


     multiplexador mux_0(m0,in_00_mux_0,a , b , c, out mux_0)
     multiplexador mux_1(m1,out_mux_0,out_reg_x,out_reg_s,out_reg_h, out_mux_1)
     multiplexador mux_2(m2,out_mux_0, out_reg_x, out_reg_h,out_mux_2, out_reg_s)
endmodule