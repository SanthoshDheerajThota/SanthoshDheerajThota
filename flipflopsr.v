module flipflop(q,qb,s,r,clock);
  input s,r,clock;
  inout q,qb;
  wire w1,w2;
  nand g1(w1,clock,s);
  nand g2(w2,clock,r);
  nand g3(q,w1,qb);
  nand g4(qb,w2,q);
endmodule
/*
module myowntestBEnch;
  reg s,r,clock;
  wire q,qb;
  flipflop uut(q,qb,s,r,clock);
  initial
    begin
      clock=1;s=1;r=0;
      #10 s=0;r=1;
      #10 s=1;r=0; 
      #10 s=0;r=0;
      #10 $finish;
    end
  initial
    begin
      $dumpfile("dump.vcd"); $dumpvars;
    end
endmodule
*/
