library verilog;
use verilog.vl_types.all;
entity compare_4_vlg_check_tst is
    port(
        A_equal_B       : in     vl_logic;
        A_greater_B     : in     vl_logic;
        A_less_B        : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end compare_4_vlg_check_tst;
