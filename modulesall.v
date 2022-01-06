module ha(s,c,a,b);
  input a,b;
  output s,c;
  and g1(c,a,b);
  xor g2(s,a,b);
endmodule

module fa(s,cout,a,b,cin);
  input a,b,cin;
  output s,cout;
  wire w1,w2,w3;
  ha ha1(w1,w2,a,b);
  ha ha2(s,w3,w1,cin);
  or g1(cout,w2,w3);
endmodule

module pa(s,cout,a,b,cin);
  input [3:0]a,b;
  output [3:0]s;
  output cout;
  input cin;
  wire [2:0]w;
  fa fa1(s[0],w[0],a[0],b[0],cin);
  fa fa2(s[1],w[1],a[1],b[1],w[0]);
  fa fa3(s[2],w[2],a[2],b[2],w[1]);
  fa fa4(s[3],cout,a[3],b[3],w[2]);
endmodule

module alu(y,a,b,mode);
  input [15:0]a,b;
  output reg [31:0]y;
  input [3:0]mode;
  always @(a or b or mode)
    begin
      case(mode)
        0:y=a+b;
        1:y=a-b;
        2:y=a-1;
        3:y=a*b;
        4:y=a/b;
        5:y=a%b;
        6:y=a&b;
        7:y=a|b;
        8:y=a^b;
        9:y=~(a&b);
        10:y=~(a|b);
        11:y=~(a^b);
        12:y=~a;
        13:y=a<<1;
        14:y=a>>1;
        15:y=a+1;
      endcase
    end
endmodule

module decoder(y,i);
  input [2:0] i;
  output [7:0]y;
  assign y[0]=(~i[2])&(~i[1])&(~i[0]);
  assign y[1]=(~i[2])&(~i[1])&(i[0]);
  assign y[2]=(~i[2])&(i[1])&(~i[0]);
  assign y[3]=(~i[2])&(i[1])&(i[0]);
  assign y[4]=(i[2])&(~i[1])&(~i[0]);
  assign y[5]=(i[2])&(~i[1])&(i[0]);
  assign y[6]=(i[2])&(i[1])&(~i[0]);
  assign y[7]=(i[2])&(i[1])&(i[0]);
endmodule

module encoder(y,i);
  input [7:0]i;
  output [2:0]y;
  assign y[0]=i[1]|i[3]|i[5]|i[7];
  assign y[1]=i[2]|i[3]|i[6]|i[7];
  assign y[2]=i[4]|i[5]|i[6]|i[7];
endmodule

module mux41(y,i,s);
  input [3:0]i;
  input [1:0]s;
  output y;
  assign y=((~s[1])&(~s[0])&i[0])|((~s[1])&(s[0])&i[1])|((s[1])&(~s[0])&i[2])|((s[1])&(s[0])&i[3]);
endmodule

// module func(f,a,b);
//   input a,b;
//   output f;
//   mux41 m1(f,{1,0,1,0},{a,b});
// endmodule

module rslatch(q,qbar,s,r);
  input s,r;
  inout q,qbar;
  nor g1(q,r,qbar);
  nor g2(qbar,q,s);
endmodule

module srflipflop(q,qbar,clock,s,r);
  input s,r,clock;
  inout q,qbar;
  wire w1,w2;
  nand g1(w1,s,clock);
  nand g2(w2,r,clock);
  nand g3(q,qbar,w1);
  nand g4(qbar,q,w2);
endmodule

module tff(q,clock,reset);
  input clock,t,reset;
  output reg q;
  always @(posedge clock or posedge reset )
    begin
      if(reset==1)
        q=0;
      else if(t==0)
        q=q;
      else 
        q=~q;
    end
endmodule

module counter(y,clock,reset);
  output [3:0]y;
  input clock,reset;
  tff t1(y[0],clock,reset);
  tff t2(y[1],y[0],reset);
  tff t3(y[2],y[1],reset);
  tff t4(y[3],y[2],reset);
endmodule

module counter2(y,clock,reset);
  input clock,reset;
  output reg [3:0]y;
  always @(posedge clock or posedge reset)
    begin
      if(reset==1)
        y=0;
      else
        y=y+1;
    end
endmodule

module johnsoncounter(y,clock,reset);
  input clock,reset;
  output reg [3:0]y;
  always @(posedge clock or posedge reset)
    begin
      if(reset==1)
        y=0;
      else 
        y={~y[0],y[3],y[2],y[1]};
    end
endmodule

module usr(q,pin,lsin,rsin,mode,clock,reset);
  input rsin,lsin,clock,reset;
  input [1:0]mode;
  input [3:0]pin;
  output reg [3:0]q;
  always @(posedge clock or posedge reset)
    begin
      if(reset==1)
        q=0;
      else 
        begin
          case(mode)
            0:q=q;
            1:q={rsin,q[3],q[2],q[1]};
            2:q={q[2],q[1],q[0],lsin};
            3:q=pin;
          endcase
        end
    end
endmodule

module comparator(l,e,g,a,b);
  input [3:0]a,b;
  output reg l,e,g;
  always @(a or b)
    begin
      if(a==b)
        begin
          l=0;
          e=1;
          g=0;
        end
      else if(a>b)
        begin
          l=0;
          e=0;
          g=1;
        end
      else 
        begin
          l=1;
          e=0;
          g=0;
        end
    end
endmodule


//this is mealy machine

module detetctor(y,clock,in,reset);
  input clock,in,reset;
  output reg y;
  parameter a=0;
  parameter b=1;
  parameter c=2;
  parameter d=3;
  reg [1:0] ps,ns;
  always @(posedge clock or posedge reset)
    begin
      if(reset==1)
        begin
        y=0; ps<=a;
        end
      else
        begin
          ps<=ns;
        end
    end
  always @(ps or in)
    begin
      case(ps)
        a:begin
           ns=in?b:a;
           y=0;
          end
        b:begin
          ns=in?b:c;
          y=0;
          end
        c:begin
          ns=in?d:a;
          y=0;
          end
        d:begin
          ns=in?b:a;
          y=in?0:1;
          end
      endcase
    end
endmodule
  

//this is moore machine
module detector2(y,clock,in,reset);
  input clock,in,reset;
  output reg y;
  parameter a=0;
  parameter b=1;
  parameter c=2;
  parameter d=3;
  parameter e=4;
  reg [2:0] ps,ns;
  always @(posedge clock or posedge reset)
    begin
      if(reset==1)
        begin
        y=0; ps<=a;
        end
      else
        begin
          ps<=ns;
        end
    end
  always @(ps or in)
    begin
      case(ps)
        a:begin
           ns=in?b:a;
          end
        b:begin
          ns=in?b:c;
          end
        c:begin
          ns=in?d:a;
          end
        d:begin
          ns=in?d:e;
          end
        e:begin
          ns=in?b:a;
          end
      endcase
    end
  always @(ps)
    begin
      if(ps==a||ps==b||ps==c||ps==d)
        y=0;
      else if(ps==e)
        y=1;
    end
endmodule

module test;
  reg in,clock,reset;
  wire y;
  detetctor uut(y,clock,in,reset);
  initial
    begin
      in=0;reset=1;clock=0;
      #2 reset=0;
      #1in=1;
      #10 in=0;
      #10 in=1;
      #10 in=0;
      #10 in=0;
      #10 in=1;
      #10 in=0;
      #10 in=1;
      #10 in=0;
      #10 in=1;
      #10 in=0;
      #10 in=1;
      #10 in=1;
      #10 in=0;
      #10 in=1;
      #10 in=0;
      #10 $finish;
    end
  always #5 clock=~clock;
  initial
    begin
      $dumpfile("dump.vcd"); $dumpvars;
    end
endmodule
