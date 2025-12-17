vlib work
vlib riviera

vlib riviera/xil_defaultlib
vlib riviera/xpm
vlib riviera/xlconcat_v2_1_1
vlib riviera/generic_baseblocks_v2_1_0
vlib riviera/axi_infrastructure_v1_1_0
vlib riviera/axi_register_slice_v2_1_13
vlib riviera/fifo_generator_v13_1_4
vlib riviera/axi_data_fifo_v2_1_12
vlib riviera/axi_crossbar_v2_1_14
vlib riviera/xbip_utils_v3_0_7
vlib riviera/axi_utils_v2_0_3
vlib riviera/xbip_pipe_v3_0_3
vlib riviera/xbip_dsp48_wrapper_v3_0_4
vlib riviera/xbip_dsp48_addsub_v3_0_3
vlib riviera/xbip_dsp48_multadd_v3_0_3
vlib riviera/xbip_bram18k_v3_0_3
vlib riviera/mult_gen_v12_0_12
vlib riviera/floating_point_v7_1_4
vlib riviera/axi_protocol_converter_v2_1_13

vmap xil_defaultlib riviera/xil_defaultlib
vmap xpm riviera/xpm
vmap xlconcat_v2_1_1 riviera/xlconcat_v2_1_1
vmap generic_baseblocks_v2_1_0 riviera/generic_baseblocks_v2_1_0
vmap axi_infrastructure_v1_1_0 riviera/axi_infrastructure_v1_1_0
vmap axi_register_slice_v2_1_13 riviera/axi_register_slice_v2_1_13
vmap fifo_generator_v13_1_4 riviera/fifo_generator_v13_1_4
vmap axi_data_fifo_v2_1_12 riviera/axi_data_fifo_v2_1_12
vmap axi_crossbar_v2_1_14 riviera/axi_crossbar_v2_1_14
vmap xbip_utils_v3_0_7 riviera/xbip_utils_v3_0_7
vmap axi_utils_v2_0_3 riviera/axi_utils_v2_0_3
vmap xbip_pipe_v3_0_3 riviera/xbip_pipe_v3_0_3
vmap xbip_dsp48_wrapper_v3_0_4 riviera/xbip_dsp48_wrapper_v3_0_4
vmap xbip_dsp48_addsub_v3_0_3 riviera/xbip_dsp48_addsub_v3_0_3
vmap xbip_dsp48_multadd_v3_0_3 riviera/xbip_dsp48_multadd_v3_0_3
vmap xbip_bram18k_v3_0_3 riviera/xbip_bram18k_v3_0_3
vmap mult_gen_v12_0_12 riviera/mult_gen_v12_0_12
vmap floating_point_v7_1_4 riviera/floating_point_v7_1_4
vmap axi_protocol_converter_v2_1_13 riviera/axi_protocol_converter_v2_1_13

vlog -work xil_defaultlib  -sv2k12 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"C:/Xilinx/Vivado/2017.2/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \

vcom -work xpm -93 \
"C:/Xilinx/Vivado/2017.2/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"../../../bd/system/ip/system_processing_system7_0_0/system_processing_system7_0_0_sim_netlist.v" \
"../../../bd/system/ip/system_axi_gpio_0_0/system_axi_gpio_0_0_sim_netlist.v" \
"../../../bd/system/ip/system_zybo_audio_ctrl_0_0/system_zybo_audio_ctrl_0_0_sim_netlist.v" \
"../../../bd/system/ip/system_rst_ps7_0_50M_0/system_rst_ps7_0_50M_0_sim_netlist.v" \

vlog -work xlconcat_v2_1_1  -v2k5 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/73b7/hdl/xlconcat_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"../../../bd/system/ip/system_xlconcat_0_0/sim/system_xlconcat_0_0.v" \

vlog -work generic_baseblocks_v2_1_0  -v2k5 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/f9c1/hdl/generic_baseblocks_v2_1_vl_rfs.v" \

vlog -work axi_infrastructure_v1_1_0  -v2k5 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_register_slice_v2_1_13  -v2k5 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/55c0/hdl/axi_register_slice_v2_1_vl_rfs.v" \

vlog -work fifo_generator_v13_1_4  -v2k5 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/ebc2/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_1_4 -93 \
"../../../../audio.srcs/sources_1/bd/system/ipshared/ebc2/hdl/fifo_generator_v13_1_rfs.vhd" \

vlog -work fifo_generator_v13_1_4  -v2k5 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/ebc2/hdl/fifo_generator_v13_1_rfs.v" \

vlog -work axi_data_fifo_v2_1_12  -v2k5 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/95b9/hdl/axi_data_fifo_v2_1_vl_rfs.v" \

vlog -work axi_crossbar_v2_1_14  -v2k5 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/f582/hdl/axi_crossbar_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"../../../bd/system/ip/system_xbar_0/sim/system_xbar_0.v" \
"../../../bd/system/hdl/system.v" \
"../../../bd/system/ip/system_axi_gpio_1_0/system_axi_gpio_1_0_sim_netlist.v" \
"../../../bd/system/ip/system_axi_gpio_1_1/system_axi_gpio_1_1_sim_netlist.v" \
"../../../bd/system/ip/system_axi_gpio_2_0/system_axi_gpio_2_0_sim_netlist.v" \

vcom -work xbip_utils_v3_0_7 -93 \
"../../../../audio.srcs/sources_1/bd/system/ipshared/3d01/hdl/xbip_utils_v3_0_vh_rfs.vhd" \

vcom -work axi_utils_v2_0_3 -93 \
"../../../../audio.srcs/sources_1/bd/system/ipshared/43f5/hdl/axi_utils_v2_0_vh_rfs.vhd" \

vcom -work xbip_pipe_v3_0_3 -93 \
"../../../../audio.srcs/sources_1/bd/system/ipshared/7db8/hdl/xbip_pipe_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_wrapper_v3_0_4 -93 \
"../../../../audio.srcs/sources_1/bd/system/ipshared/1e87/hdl/xbip_dsp48_wrapper_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_addsub_v3_0_3 -93 \
"../../../../audio.srcs/sources_1/bd/system/ipshared/c9c4/hdl/xbip_dsp48_addsub_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_multadd_v3_0_3 -93 \
"../../../../audio.srcs/sources_1/bd/system/ipshared/779d/hdl/xbip_dsp48_multadd_v3_0_vh_rfs.vhd" \

vcom -work xbip_bram18k_v3_0_3 -93 \
"../../../../audio.srcs/sources_1/bd/system/ipshared/403d/hdl/xbip_bram18k_v3_0_vh_rfs.vhd" \

vcom -work mult_gen_v12_0_12 -93 \
"../../../../audio.srcs/sources_1/bd/system/ipshared/f0ab/hdl/mult_gen_v12_0_vh_rfs.vhd" \

vcom -work floating_point_v7_1_4 -93 \
"../../../../audio.srcs/sources_1/bd/system/ipshared/4a02/hdl/floating_point_v7_1_vh_rfs.vhd" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/82e7/hdl/verilog/equalizer.v" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/82e7/hdl/verilog/equalizer_eq_io_s_axi.v" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/82e7/hdl/verilog/equalizer_faddfsucud.v" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/82e7/hdl/verilog/equalizer_fmul_32dEe.v" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/82e7/hdl/verilog/equalizer_iir_coebkb.v" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/82e7/hdl/verilog/equalizer_iir_x_1.v" \

vcom -work xil_defaultlib -93 \
"../../../../audio.srcs/sources_1/bd/system/ipshared/82e7/hdl/ip/equalizer_ap_faddfsub_5_full_dsp_32.vhd" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/82e7/hdl/ip/equalizer_ap_fmul_2_max_dsp_32.vhd" \
"../../../bd/system/ip/system_equalizer_0_0/sim/system_equalizer_0_0.vhd" \
"../../../bd/system/ip/system_equalizer_0_1/sim/system_equalizer_0_1.vhd" \

vlog -work axi_protocol_converter_v2_1_13  -v2k5 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"../../../../audio.srcs/sources_1/bd/system/ipshared/f0ae/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/7e3a/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/2ad9/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/39ca/hdl/verilog" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/6eb1/hdl" "+incdir+../../../../audio.srcs/sources_1/bd/system/ipshared/1d61/hdl" \
"../../../bd/system/ip/system_auto_pc_0/sim/system_auto_pc_0.v" \

vlog -work xil_defaultlib \
"glbl.v"

