module bloco_de_controle (
    input start,
    input reset,
    input clk,
    output [1:0] m0,
    output [1:0] m1,
    output [1:0] m2,
    output h, 
    output lx,
    output lh,
    output ls,
    output done
);

    reg [4:0] state;

    always @(posedge clk or reset) begin
        if (reset)
            state <= 0;

        else begin
            if (state == 0 && ~start)
                state <= state;
            else begin
                if(done) 
                     state <= state;
                else if (state == 12) begin
                    state <= 0;
                end else begin
                state <= state + 1;
                end
            end
        end
    end
    assign lx = state == 1 ? 1 : 0 ;
    assign lh = state == 2 ? 1 : state == 4 ? 1 : 0;
    assign ls = state == 6 ? 1 : state == 8 ? 1 : state == 10 ? 1 : 0;
    assign h = state == 1 ? 1 : state == 2 ? 1 : state == 3 ? 1 : state == 4 ? 1 : state == 5 ? 1 : state == 6 ? 1 : 0;
    assign m0 = state == 3 ? 1 : state == 4 ? 1 : state == 5 ? 2 : state == 6 ? 2 : state == 7 ? 2 : state == 8 ? 2 : state == 9 ? 3 : state == 10 ? 3 : state == 11 ? 3 : 0;
    assign m1 = state == 1 ? 1 : state == 2 ? 1 : state == 3 ? 3 : state == 4 ? 3 : state == 7 ? 3 : state == 8 ? 3 : 0;
    assign m2 = state == 3 ? 1 : state == 4 ? 1 : state == 7 ? 2 : state == 8 ? 2 : state == 9 ? 2 : state == 10 ? 2 : state == 11 ? 2 : 0;
    assign done = state == 11 ? 1 : state == 12 ? 1 : 0;

endmodule