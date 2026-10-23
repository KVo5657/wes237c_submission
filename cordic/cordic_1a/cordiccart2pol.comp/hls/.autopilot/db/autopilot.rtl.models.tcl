set SynModuleInfo {
  {SRCNAME cordiccart2pol_Pipeline_VITIS_LOOP_43_1 MODELNAME cordiccart2pol_Pipeline_VITIS_LOOP_43_1 RTLNAME cordiccart2pol_cordiccart2pol_Pipeline_VITIS_LOOP_43_1
    SUBMODULES {
      {MODELNAME cordiccart2pol_faddfsub_32ns_32ns_32_5_full_dsp_1 RTLNAME cordiccart2pol_faddfsub_32ns_32ns_32_5_full_dsp_1 BINDTYPE op TYPE fadd IMPL fulldsp LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME cordiccart2pol_fmul_32ns_32ns_32_4_max_dsp_1 RTLNAME cordiccart2pol_fmul_32ns_32ns_32_4_max_dsp_1 BINDTYPE op TYPE fmul IMPL maxdsp LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME cordiccart2pol_cordiccart2pol_Pipeline_VITIS_LOOP_43_1_Kvalues_ROM_AUTO_1R RTLNAME cordiccart2pol_cordiccart2pol_Pipeline_VITIS_LOOP_43_1_Kvalues_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME cordiccart2pol_cordiccart2pol_Pipeline_VITIS_LOOP_43_1_angles_ROM_AUTO_1R RTLNAME cordiccart2pol_cordiccart2pol_Pipeline_VITIS_LOOP_43_1_angles_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME cordiccart2pol_flow_control_loop_pipe_sequential_init RTLNAME cordiccart2pol_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME cordiccart2pol_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME cordiccart2pol MODELNAME cordiccart2pol RTLNAME cordiccart2pol IS_TOP 1
    SUBMODULES {
      {MODELNAME cordiccart2pol_fcmp_32ns_32ns_1_2_no_dsp_1 RTLNAME cordiccart2pol_fcmp_32ns_32ns_1_2_no_dsp_1 BINDTYPE op TYPE fcmp IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME cordiccart2pol_control_s_axi RTLNAME cordiccart2pol_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
