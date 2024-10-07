library verilog;
use verilog.vl_types.all;
entity PWM_vlg_sample_tst is
    port(
        Addr            : in     vl_logic_vector(11 downto 0);
        CS_N            : in     vl_logic;
        DataIn          : in     vl_logic_vector(7 downto 0);
        WR_N            : in     vl_logic;
        clk             : in     vl_logic;
        reset           : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end PWM_vlg_sample_tst;
