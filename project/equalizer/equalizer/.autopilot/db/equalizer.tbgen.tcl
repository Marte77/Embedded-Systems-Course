set C_TypeInfoList {{ 
"equalizer" : [[], { "return": [[], "void"]} , [{"ExternC" : 0}], [ {"y": [[],{ "pointer": "0"}] }, {"x": [[],"0"] }, {"mode": [[], {"scalar": "int"}] }, {"coeffs": [[], {"array": [ {"array": ["0", [6]]}, [5]]}] }],[],""], 
"0": [ "data_t", {"typedef": [[[], {"scalar": "float"}],""]}]
}}
set moduleName equalizer
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set C_modelName {equalizer}
set C_modelType { void 0 }
set C_modelArgList {
	{ y float 32 regular {axi_slave 1}  }
	{ x float 32 regular {axi_slave 0}  }
	{ mode int 32 regular {axi_slave 0}  }
	{ coeffs float 32 regular {axi_slave 0}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "y", "interface" : "axi_slave", "bundle":"eq_io","type":"ap_vld","bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "y","cData": "float","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}], "offset" : {"out":16}, "offset_end" : {"out":23}} , 
 	{ "Name" : "x", "interface" : "axi_slave", "bundle":"eq_io","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "x","cData": "float","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":24}, "offset_end" : {"in":31}} , 
 	{ "Name" : "mode", "interface" : "axi_slave", "bundle":"eq_io","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "mode","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":32}, "offset_end" : {"in":39}} , 
 	{ "Name" : "coeffs", "interface" : "axi_slave", "bundle":"eq_io","type":"ap_memory","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "coeffs","cData": "float","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 4,"step" : 1},{"low" : 0,"up" : 5,"step" : 1}]}]}], "offset" : {"in":128}, "offset_end" : {"in":255}} ]}
# RTL Port declarations: 
set portNum 20
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ s_axi_eq_io_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_eq_io_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_eq_io_AWADDR sc_in sc_lv 8 signal -1 } 
	{ s_axi_eq_io_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_eq_io_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_eq_io_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_eq_io_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_eq_io_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_eq_io_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_eq_io_ARADDR sc_in sc_lv 8 signal -1 } 
	{ s_axi_eq_io_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_eq_io_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_eq_io_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_eq_io_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_eq_io_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_eq_io_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_eq_io_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_eq_io_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "eq_io", "role": "AWADDR" },"address":[{"name":"equalizer","role":"start","value":"0","valid_bit":"0"},{"name":"equalizer","role":"continue","value":"0","valid_bit":"4"},{"name":"equalizer","role":"auto_start","value":"0","valid_bit":"7"},{"name":"x","role":"data","value":"24"},{"name":"mode","role":"data","value":"32"},{"name":"coeffs","role":"data","value":"128"}] },
	{ "name": "s_axi_eq_io_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "eq_io", "role": "AWVALID" } },
	{ "name": "s_axi_eq_io_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "eq_io", "role": "AWREADY" } },
	{ "name": "s_axi_eq_io_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "eq_io", "role": "WVALID" } },
	{ "name": "s_axi_eq_io_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "eq_io", "role": "WREADY" } },
	{ "name": "s_axi_eq_io_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "eq_io", "role": "WDATA" } },
	{ "name": "s_axi_eq_io_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "eq_io", "role": "WSTRB" } },
	{ "name": "s_axi_eq_io_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "eq_io", "role": "ARADDR" },"address":[{"name":"equalizer","role":"start","value":"0","valid_bit":"0"},{"name":"equalizer","role":"done","value":"0","valid_bit":"1"},{"name":"equalizer","role":"idle","value":"0","valid_bit":"2"},{"name":"equalizer","role":"ready","value":"0","valid_bit":"3"},{"name":"equalizer","role":"auto_start","value":"0","valid_bit":"7"},{"name":"y","role":"data","value":"16"}, {"name":"y","role":"valid","value":"20","valid_bit":"0"}] },
	{ "name": "s_axi_eq_io_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "eq_io", "role": "ARVALID" } },
	{ "name": "s_axi_eq_io_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "eq_io", "role": "ARREADY" } },
	{ "name": "s_axi_eq_io_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "eq_io", "role": "RVALID" } },
	{ "name": "s_axi_eq_io_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "eq_io", "role": "RREADY" } },
	{ "name": "s_axi_eq_io_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "eq_io", "role": "RDATA" } },
	{ "name": "s_axi_eq_io_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "eq_io", "role": "RRESP" } },
	{ "name": "s_axi_eq_io_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "eq_io", "role": "BVALID" } },
	{ "name": "s_axi_eq_io_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "eq_io", "role": "BREADY" } },
	{ "name": "s_axi_eq_io_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "eq_io", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "eq_io", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"],
		"CDFG" : "equalizer",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "AlignedPipeline" : "0", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"VariableLatency" : "1",
		"Port" : [
			{"Name" : "y", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "x", "Type" : "None", "Direction" : "I"},
			{"Name" : "mode", "Type" : "None", "Direction" : "I"},
			{"Name" : "coeffs", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "iir_coeff_array", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "iir_x_1", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "iir_x_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "iir_y_1", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "iir_y_2", "Type" : "Memory", "Direction" : "IO"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.iir_coeff_array_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.iir_x_1_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.iir_x_0_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.iir_y_1_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.iir_y_2_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.equalizer_eq_io_s_axi_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.equalizer_faddfsucud_U0", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.equalizer_fmul_32dEe_U1", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.equalizer_fmul_32dEe_U2", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.equalizer_fdiv_32eOg_U3", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.equalizer_fdiv_32eOg_U4", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	equalizer {
		y {Type O LastRead -1 FirstWrite 1}
		x {Type I LastRead 0 FirstWrite -1}
		mode {Type I LastRead 0 FirstWrite -1}
		coeffs {Type I LastRead 2 FirstWrite -1}
		iir_coeff_array {Type IO LastRead -1 FirstWrite -1}
		iir_x_1 {Type IO LastRead -1 FirstWrite -1}
		iir_x_0 {Type IO LastRead -1 FirstWrite -1}
		iir_y_1 {Type IO LastRead -1 FirstWrite -1}
		iir_y_2 {Type IO LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "71", "Max" : "256"}
	, {"Name" : "Interval", "Min" : "72", "Max" : "257"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
