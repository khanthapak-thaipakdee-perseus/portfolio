library verilog;
use verilog.vl_types.all;
entity counter is
    port(
        clock           : in     vl_logic;
        reset           : in     vl_logic;
        tick            : out    vl_logic_vector(7 downto 0)
    );
end counter;
