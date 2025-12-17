create_project prj -part xc7z010clg400-1 -force
set_property target_language vhdl [current_project]
set vivado_ver [version -short]
source "C:/Users/marti/Documents/EmbeddedSystems/project/equalizer/equalizer/syn/vhdl/equalizer_ap_faddfsub_5_full_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips equalizer_ap_faddfsub_5_full_dsp_32]]
}
source "C:/Users/marti/Documents/EmbeddedSystems/project/equalizer/equalizer/syn/vhdl/equalizer_ap_fmul_2_max_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips equalizer_ap_fmul_2_max_dsp_32]]
}
