#ifndef HID_H_
#define HID_H_

#include <LUFA/Drivers/USB/USB.h>
#include <LUFA/Drivers/Peripheral/Serial.h>

#include "LUFADescriptors.h"

USB_JoystickReport_Input_t ReportData;

void HID_Init(void);
void HID_Task(void);

void EVENT_USB_Device_Connect(void);
void EVENT_USB_Device_Disconnect(void);
void EVENT_USB_Device_ConfigurationChanged(void);
void EVENT_USB_Device_ControlRequest(void);

#endif