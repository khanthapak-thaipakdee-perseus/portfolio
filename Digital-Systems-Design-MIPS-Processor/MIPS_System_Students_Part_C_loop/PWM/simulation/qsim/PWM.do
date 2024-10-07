onerror {quit -f}
vlib work
vlog -work work PWM.vo
vlog -work work PWM.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.PWM_vlg_vec_tst
vcd file -direction PWM.msim.vcd
vcd add -internal PWM_vlg_vec_tst/*
vcd add -internal PWM_vlg_vec_tst/i1/*
add wave /*
run -all
