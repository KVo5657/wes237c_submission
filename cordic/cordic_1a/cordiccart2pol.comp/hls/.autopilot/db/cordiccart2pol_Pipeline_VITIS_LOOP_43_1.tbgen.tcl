set moduleName cordiccart2pol_Pipeline_VITIS_LOOP_43_1
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type loop_auto_rewind
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set DLRegFirstOffset 0
set DLRegItemOffset 0
set svuvm_can_support 1
set cdfgNum 3
set C_modelName {cordiccart2pol_Pipeline_VITIS_LOOP_43_1}
set C_modelType { void 0 }
set ap_memory_interface_dict [dict create]
set C_modelArgList {
	{ y_assign_6 float 32 regular  }
	{ x_assign_2 float 32 regular  }
	{ storemerge5_ph float 32 regular  }
	{ storemerge_out float 32 regular {pointer 1}  }
	{ x_assign_5_out float 32 regular {pointer 1}  }
}
set hasAXIMCache 0
set l_AXIML2Cache [list]
set AXIMCacheInstDict [dict create]
set C_modelArgMapList {[ 
	{ "Name" : "y_assign_6", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "x_assign_2", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "storemerge5_ph", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "storemerge_out", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "x_assign_5_out", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 22
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ y_assign_6 sc_in sc_lv 32 signal 0 } 
	{ x_assign_2 sc_in sc_lv 32 signal 1 } 
	{ storemerge5_ph sc_in sc_lv 32 signal 2 } 
	{ storemerge_out sc_out sc_lv 32 signal 3 } 
	{ storemerge_out_ap_vld sc_out sc_logic 1 outvld 3 } 
	{ x_assign_5_out sc_out sc_lv 32 signal 4 } 
	{ x_assign_5_out_ap_vld sc_out sc_logic 1 outvld 4 } 
	{ grp_fu_123_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_123_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_123_p_dout0 sc_in sc_lv 32 signal -1 } 
	{ grp_fu_123_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_128_p_din0 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_128_p_din1 sc_out sc_lv 32 signal -1 } 
	{ grp_fu_128_p_opcode sc_out sc_lv 5 signal -1 } 
	{ grp_fu_128_p_dout0 sc_in sc_lv 1 signal -1 } 
	{ grp_fu_128_p_ce sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "y_assign_6", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "y_assign_6", "role": "default" }} , 
 	{ "name": "x_assign_2", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "x_assign_2", "role": "default" }} , 
 	{ "name": "storemerge5_ph", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "storemerge5_ph", "role": "default" }} , 
 	{ "name": "storemerge_out", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "storemerge_out", "role": "default" }} , 
 	{ "name": "storemerge_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "storemerge_out", "role": "ap_vld" }} , 
 	{ "name": "x_assign_5_out", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "x_assign_5_out", "role": "default" }} , 
 	{ "name": "x_assign_5_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "x_assign_5_out", "role": "ap_vld" }} , 
 	{ "name": "grp_fu_123_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_123_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_123_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_123_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_123_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_123_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_123_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_123_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_128_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_128_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_128_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "grp_fu_128_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_128_p_opcode", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "grp_fu_128_p_opcode", "role": "default" }} , 
 	{ "name": "grp_fu_128_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_128_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_128_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_128_p_ce", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6"],
		"CDFG" : "cordiccart2pol_Pipeline_VITIS_LOOP_43_1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "203", "EstimateLatencyMax" : "203",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "y_assign_6", "Type" : "None", "Direction" : "I"},
			{"Name" : "x_assign_2", "Type" : "None", "Direction" : "I"},
			{"Name" : "storemerge5_ph", "Type" : "None", "Direction" : "I"},
			{"Name" : "storemerge_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "x_assign_5_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "Kvalues", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "angles", "Type" : "Memory", "Direction" : "I"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_43_1", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "10", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage1", "LastStateIter" : "ap_enable_reg_pp0_iter1", "LastStateBlock" : "ap_block_pp0_stage1_subdone", "QuitState" : "ap_ST_fsm_pp0_stage1", "QuitStateIter" : "ap_enable_reg_pp0_iter1", "QuitStateBlock" : "ap_block_pp0_stage1_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.Kvalues_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.angles_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.faddfsub_32ns_32ns_32_5_full_dsp_1_U1", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.faddfsub_32ns_32ns_32_5_full_dsp_1_U2", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fmul_32ns_32ns_32_4_max_dsp_1_U4", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	cordiccart2pol_Pipeline_VITIS_LOOP_43_1 {
		y_assign_6 {Type I LastRead 0 FirstWrite -1}
		x_assign_2 {Type I LastRead 0 FirstWrite -1}
		storemerge5_ph {Type I LastRead 0 FirstWrite -1}
		storemerge_out {Type O LastRead -1 FirstWrite 11}
		x_assign_5_out {Type O LastRead -1 FirstWrite 11}
		Kvalues {Type I LastRead -1 FirstWrite -1}
		angles {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "203", "Max" : "203"}
	, {"Name" : "Interval", "Min" : "203", "Max" : "203"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	y_assign_6 { ap_none {  { y_assign_6 in_data 0 32 } } }
	x_assign_2 { ap_none {  { x_assign_2 in_data 0 32 } } }
	storemerge5_ph { ap_none {  { storemerge5_ph in_data 0 32 } } }
	storemerge_out { ap_vld {  { storemerge_out out_data 1 32 }  { storemerge_out_ap_vld out_vld 1 1 } } }
	x_assign_5_out { ap_vld {  { x_assign_5_out out_data 1 32 }  { x_assign_5_out_ap_vld out_vld 1 1 } } }
}
