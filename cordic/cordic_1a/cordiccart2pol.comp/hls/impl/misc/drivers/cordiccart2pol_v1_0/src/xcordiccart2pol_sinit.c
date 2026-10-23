// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.2 (64-bit)
// Tool Version Limit: 2024.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xcordiccart2pol.h"

extern XCordiccart2pol_Config XCordiccart2pol_ConfigTable[];

#ifdef SDT
XCordiccart2pol_Config *XCordiccart2pol_LookupConfig(UINTPTR BaseAddress) {
	XCordiccart2pol_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XCordiccart2pol_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XCordiccart2pol_ConfigTable[Index].Control_BaseAddress == BaseAddress) {
			ConfigPtr = &XCordiccart2pol_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XCordiccart2pol_Initialize(XCordiccart2pol *InstancePtr, UINTPTR BaseAddress) {
	XCordiccart2pol_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XCordiccart2pol_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XCordiccart2pol_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XCordiccart2pol_Config *XCordiccart2pol_LookupConfig(u16 DeviceId) {
	XCordiccart2pol_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XCORDICCART2POL_NUM_INSTANCES; Index++) {
		if (XCordiccart2pol_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XCordiccart2pol_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XCordiccart2pol_Initialize(XCordiccart2pol *InstancePtr, u16 DeviceId) {
	XCordiccart2pol_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XCordiccart2pol_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XCordiccart2pol_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

