module multiplexador(
input [1:0] sel,
    input signed [15:0] a,
    input signed [15:0] b,
    input signed [15:0] c,
    output signed [15:0] out
);
assign out = sel == 0 ? a : sel == 1 ? b : sel == 2 ? c : ;
endmodule