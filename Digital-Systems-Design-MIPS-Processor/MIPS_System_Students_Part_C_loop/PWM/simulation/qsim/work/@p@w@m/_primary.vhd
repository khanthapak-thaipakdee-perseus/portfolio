library verilog;
use verilog.vl_types.all;
entity PWM is
    port(
        clk             : in     vl_logic;
        reset           : in     vl_logic;
        CS_N            : in     vl_logic;
        WR_N            : in     vl_logic;
        Addr            : in     vl_logic_vector(11 downto 0);
        DataIn          : in     vl_logic_vector(7 downto 0);
        LEDR            : out    vl_logic_vector(17 downto 0)
    );
end PWM;
