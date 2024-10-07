library verilog;
use verilog.vl_types.all;
entity PWM_vlg_check_tst is
    port(
        LEDR            : in     vl_logic_vector(17 downto 0);
        sampler_rx      : in     vl_logic
    );
end PWM_vlg_check_tst;
