onerror {quit -f}
vlib work
vlog -work work compare_4.vo
vlog -work work compare_4.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.compare_4_vlg_vec_tst
vcd file -direction compare_4.msim.vcd
vcd add -internal compare_4_vlg_vec_tst/*
vcd add -internal compare_4_vlg_vec_tst/i1/*
add wave /*
run -all
