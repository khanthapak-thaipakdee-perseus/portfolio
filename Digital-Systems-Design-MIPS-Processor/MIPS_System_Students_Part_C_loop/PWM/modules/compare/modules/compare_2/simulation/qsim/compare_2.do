onerror {quit -f}
vlib work
vlog -work work compare_2.vo
vlog -work work compare_2.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.compare_2_vlg_vec_tst
vcd file -direction compare_2.msim.vcd
vcd add -internal compare_2_vlg_vec_tst/*
vcd add -internal compare_2_vlg_vec_tst/i1/*
add wave /*
run -all
