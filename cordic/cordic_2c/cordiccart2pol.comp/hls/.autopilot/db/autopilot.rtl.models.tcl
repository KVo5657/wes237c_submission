set SynModuleInfo {
  {SRCNAME cordiccart2pol_Pipeline_VITIS_LOOP_33_1 MODELNAME cordiccart2pol_Pipeline_VITIS_LOOP_33_1 RTLNAME cordiccart2pol_cordiccart2pol_Pipeline_VITIS_LOOP_33_1
    SUBMODULES {
      {MODELNAME cordiccart2pol_mul_30ns_16s_45_2_1 RTLNAME cordiccart2pol_mul_30ns_16s_45_2_1 BINDTYPE op TYPE mul IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME cordiccart2pol_cordiccart2pol_Pipeline_VITIS_LOOP_33_1_Kvalues_ROM_AUTO_1R RTLNAME cordiccart2pol_cordiccart2pol_Pipeline_VITIS_LOOP_33_1_Kvalues_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME cordiccart2pol_cordiccart2pol_Pipeline_VITIS_LOOP_33_1_angles_ROM_AUTO_1R RTLNAME cordiccart2pol_cordiccart2pol_Pipeline_VITIS_LOOP_33_1_angles_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME cordiccart2pol_flow_control_loop_pipe_sequential_init RTLNAME cordiccart2pol_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME cordiccart2pol_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME cordiccart2pol MODELNAME cordiccart2pol RTLNAME cordiccart2pol IS_TOP 1
    SUBMODULES {
      {MODELNAME cordiccart2pol_mul_16s_14ns_29_1_1 RTLNAME cordiccart2pol_mul_16s_14ns_29_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
    }
  }
}
