//
//  LEDR, LEDG : To turn off, write "0"
//				 To turn on,  write "1"
//
//
//  Register  
//  ========================================================

//  FFFF_2030   LEDR_R

//  --------------------------------------------------------
//  LEDR register(32 bit)
//  ZZZZ_ZZZZ_ZZZZ_ZZ|SLEDR17|LEDR16|_
//          |LEDR15|LEDR14|LEDR13|LEDR12|_
//          |LEDR11|LEDR10|LEDR9|LEDR8|_
//          |LEDR7|LEDR6|LEDR5|LEDR4|_
//          |LEDR3|LEDR2|LEDR1|LEDR0| 
//  --------------------------------------------------------

//  ========================================================

module PWM(
	input clk,
	input reset,
	input CS_N,
	input RD_N,
	input WR_N,
	input [11:0] Addr,
	input [7:0] DataIn,
	output wire pwm_out,
	output reg [31:0] DataOut
  ); 

	reg [7:0] pwm_register;
	wire [7:0] tick_signal;
	wire [7:0] tick;
	wire LEDR_R;
	
	
    // Assign the clock divisor
	parameter CLOCK_DIVISOR = 256;

  // Internal counter for free running 8 bits counter
	reg [7:0] p_counter,n_counter;   //8 bits	

	// Instantiate Couter
   counter c(	.clock(clk),
					.reset(reset),  
					.tick(tick_signal));
	
	// Instantiate flip-flop				
	flop f(		.clk(clk), 
					.reset(reset),
               .d(LEDR_R), 
               .q(pwm_out));
					
	// Register Read
  always @(*)
  begin
      if (~CS_N && ~RD_N)
			DataOut <= pwm_register;
  end
					
					
  //write output Register
  always @(posedge clk, posedge reset)
  begin
		if(reset)
			begin                                        
				pwm_register <= 0;
			end
		else if(~CS_N && ~WR_N) 
			begin                                        
	        if       (Addr[11:0] == 12'h200)  pwm_register	<= DataIn;
			end
  end
  
  	//output 
	assign LEDR_R = (pwm_register >= tick_signal);


endmodule

module counter(
	input wire clock,
	input wire reset, 
	output [7:0] tick
);


  // Assign the clock divisor
	parameter CLOCK_DIVISOR = 256;

  // Internal counter for free running 8 bits counter
	reg [7:0] p_counter,n_counter;   //8 bits
	
	assign tick = p_counter;
	
	always @(posedge clock) 
		begin
			if (reset) 
				p_counter <= 0;
			else 
				p_counter <= n_counter;
		end
		
	always @( p_counter) 
		begin
			n_counter = p_counter;
			if (p_counter == (CLOCK_DIVISOR - 1)) 
				n_counter = 8'd0;
			else
				n_counter = p_counter + 8'd1;   
		end
endmodule

module flop 
              (input       clk, reset,
               input       d, 
               output reg 	q);

  always @(posedge clk, posedge reset)
    if (reset) q <= 0;
    else       q <= d;

endmodule

