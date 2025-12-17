############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project equalizer
set_top equalizer
add_files equalizer/iir.cpp
add_files equalizer/iir.h
add_files -tb equalizer/iir_test.cpp
open_solution "equalizer"
set_part {xc7z010clg400-1}
create_clock -period 8 -name default
source "./equalizer/equalizer/directives.tcl"
csim_design
csynth_design
cosim_design -rtl vhdl
export_design -rtl vhdl -format ip_catalog -description "equalizer" -vendor "martinho" -version "1.11" -display_name "eq_marte"
