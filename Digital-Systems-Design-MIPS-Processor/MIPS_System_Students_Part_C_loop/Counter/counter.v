module counter(
	input wire clock,
	input wire reset,  // Active-low reset
	output [7:0] tick
);


  // Assign the clock divisor
	parameter CLOCK_DIVISOR = 256;

  // Internal counter for free running 8 bits counter
	reg [7:0] p_baud_counter,n_baud_counter;   //8 bits
	
	assign tick = p_baud_counter;
	
	always @(posedge clock) 
		begin
			if (~reset) 
				p_baud_counter <= 0;
			else 
				p_baud_counter <= n_baud_counter;
		end
		
	always @( p_baud_counter) 
		begin
			n_baud_counter = p_baud_counter;
			if (p_baud_counter == (CLOCK_DIVISOR - 1)) 
				n_baud_counter = 8'd0;
			else
				n_baud_counter = p_baud_counter + 8'd1;   
		end
endmodule

