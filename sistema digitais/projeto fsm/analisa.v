module analisa (
    input rst;
    input w;
    input ck;
    output y1;
    output y0;
    
);
 reg    Q0, Q1;
 wire   D0,D1;

 assign D0= ck ^ Q0;
 assign D1 = ~ck & Q1 + ck & Q0 & ~Q1+ck & ~Q0 & Q1;
 assign Y= Q0 & Q1;

 always @(posedge clk or rst) begin
     if(rst ==1)begin
         
         Q0<=0;
         Q1<=0;
     end
     else begin
         Q0=D0;
         Q0=D1;
     end
     
 end
    
endmodule
//****************************************************************

module testbench;
  
  reg rst0 = 0;
  reg ck0 = 0;
  reg w0 = 0;
  wire y0;

  FSM FSM0(rst0, ck0, w0, y0);
    
endmodule