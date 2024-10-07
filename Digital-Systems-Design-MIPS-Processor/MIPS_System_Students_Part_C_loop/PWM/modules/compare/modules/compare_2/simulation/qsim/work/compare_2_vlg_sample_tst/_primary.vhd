library verilog;
use verilog.vl_types.all;
entity compare_2_vlg_sample_tst is
    port(
        A               : in     vl_logic_vector(1 downto 0);
        B               : in     vl_logic_vector(1 downto 0);
        sampler_tx      : out    vl_logic
    );
end compare_2_vlg_sample_tst;
