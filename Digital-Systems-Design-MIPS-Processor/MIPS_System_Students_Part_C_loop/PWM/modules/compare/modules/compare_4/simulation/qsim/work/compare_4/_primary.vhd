library verilog;
use verilog.vl_types.all;
entity compare_4 is
    port(
        A               : in     vl_logic_vector(3 downto 0);
        B               : in     vl_logic_vector(3 downto 0);
        A_less_B        : out    vl_logic;
        A_equal_B       : out    vl_logic;
        A_greater_B     : out    vl_logic
    );
end compare_4;
