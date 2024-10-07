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
			if (~reset) 
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