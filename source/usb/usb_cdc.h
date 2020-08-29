/**
 * @file    usb_cdc.h
 * @brief   USB CDC driver header
 *
 * DAPLink Interface Firmware
 * Copyright (c) 2009-2016, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __USB_CDC_H
#define __USB_CDC_H

/*------------------------------------------------------------------------------
 *      Definitions  based on usbcdc11.pdf (www.usb.org)
 *----------------------------------------------------------------------------*/
/* Communication device class specification version 1.10 */
#define CDC_V1_10                               0x0110

/* Communication interface class code */
/* (usbcdc11.pdf, 4.2, Table 15) */
#define CDC_COMMUNICATION_INTERFACE_CLASS       0x02

/* Communication interface class subclass codes */
/* (usbcdc11.pdf, 4.3, Table 16) */
#define CDC_DIRECT_LINE_CONTROL_MODEL           0x01
#define CDC_ABSTRACT_CONTROL_MODEL              0x02
#define CDC_TELEPHONE_CONTROL_MODEL             0x03
#define CDC_MULTI_CHANNEL_CONTROL_MODEL         0x04
#define CDC_CAPI_CONTROL_MODEL                  0x05
#define CDC_ETHERNET_NETWORKING_CONTROL_MODEL   0x06
#define CDC_ATM_NETWORKING_CONTROL_MODEL        0x07

/* Communication interface class control protocol codes */
/* (usbcdc11.pdf, 4.4, Table 17) */
#define CDC_PROTOCOL_COMMON_AT_COMMANDS         0x01

/* Data interface class code */
/* (usbcdc11.pdf, 4.5, Table 18) */
#define CDC_DATA_INTERFACE_CLASS                0x0A

/* Data interface class protocol codes */
/* (usbcdc11.pdf, 4.7, Table 19) */
#define CDC_PROTOCOL_ISDN_BRI                   0x30
#define CDC_PROTOCOL_HDLC                       0x31
#define CDC_PROTOCOL_TRANSPARENT                0x32
#define CDC_PROTOCOL_Q921_MANAGEMENT            0x50
#define CDC_PROTOCOL_Q921_DATA_LINK             0x51
#define CDC_PROTOCOL_Q921_MULTIPLEXOR           0x52
#define CDC_PROTOCOL_V42                        0x90
#define CDC_PROTOCOL_EURO_ISDN                  0x91
#define CDC_PROTOCOL_V24_RATE_ADAPTATION        0x92
#define CDC_PROTOCOL_CAPI                       0x93
#define CDC_PROTOCOL_HOST_BASED_DRIVER          0xFD
#define CDC_PROTOCOL_DESCRIBED_IN_PUFD          0xFE

/* Type values for bDescriptorType field of functional descriptors */
/* (usbcdc11.pdf, 5.2.3, Table 24) */
#define CDC_CS_INTERFACE                        0x24
#define CDC_CS_ENDPOINT                         0x25

/* Type values for bDescriptorSubtype field of functional descriptors */
/* (usbcdc11.pdf, 5.2.3, Table 25) */
#define CDC_HEADER                              0x00
#define CDC_CALL_MANAGEMENT                     0x01
#define CDC_ABSTRACT_CONTROL_MANAGEMENT         0x02
#define CDC_DIRECT_LINE_MANAGEMENT              0x03
#define CDC_TELEPHONE_RINGER                    0x04
#define CDC_REPORTING_CAPABILITIES              0x05
#define CDC_UNION                               0x06
#define CDC_COUNTRY_SELECTION                   0x07
#define CDC_TELEPHONE_OPERATIONAL_MODES         0x08
#define CDC_USB_TERMINAL                        0x09
#define CDC_NETWORK_CHANNEL                     0x0A
#define CDC_PROTOCOL_UNIT                       0x0B
#define CDC_EXTENSION_UNIT                      0x0C
#define CDC_MULTI_CHANNEL_MANAGEMENT            0x0D
#define CDC_CAPI_CONTROL_MANAGEMENT             0x0E
#define CDC_ETHERNET_NETWORKING                 0x0F
#define CDC_ATM_NETWORKING                      0x10

/* CDC class-specific request codes */
/* (usbcdc11.pdf, 6.2, Table 46) */
/* see Table 45 for info about the specific requests. */
#define CDC_SEND_ENCAPSULATED_COMMAND           0x00
#define CDC_GET_ENCAPSULATED_RESPONSE           0x01
#define CDC_SET_COMM_FEATURE                    0x02
#define CDC_GET_COMM_FEATURE                    0x03
#define CDC_CLEAR_COMM_FEATURE                  0x04
#define CDC_SET_AUX_LINE_STATE                  0x10
#define CDC_SET_HOOK_STATE                      0x11
#define CDC_PULSE_SETUP                         0x12
#define CDC_SEND_PULSE                          0x13
#define CDC_SET_PULSE_TIME                      0x14
#define CDC_RING_AUX_JACK                       0x15
#define CDC_SET_LINE_CODING                     0x20
#define CDC_GET_LINE_CODING                     0x21
#define CDC_SET_CONTROL_LINE_STATE              0x22
#define CDC_SEND_BREAK                          0x23
#define CDC_SET_RINGER_PARMS                    0x30
#define CDC_GET_RINGER_PARMS                    0x31
#define CDC_SET_OPERATION_PARMS                 0x32
#define CDC_GET_OPERATION_PARMS                 0x33
#define CDC_SET_LINE_PARMS                      0x34
#define CDC_GET_LINE_PARMS                      0x35
#define CDC_DIAL_DIGITS                         0x36
#define CDC_SET_UNIT_PARAMETER                  0x37
#define CDC_GET_UNIT_PARAMETER                  0x38
#define CDC_CLEAR_UNIT_PARAMETER                0x39
#define CDC_GET_PROFILE                         0x3A
#define CDC_SET_ETHERNET_MULTICAST_FILTERS      0x40
#define CDC_SET_ETHERNET_PMP_FILTER             0x41
#define CDC_GET_ETHERNET_PMP_FILTER             0x42
#define CDC_SET_ETHERNET_PACKET_FILTER          0x43
#define CDC_GET_ETHERNET_STATISTIC              0x44
#define CDC_SET_ATM_DATA_FORMAT                 0x50
#define CDC_GET_ATM_DEVICE_STATISTICS           0x51
#define CDC_SET_ATM_DEFAULT_VC                  0x52
#define CDC_GET_ATM_VC_STATISTICS               0x53

/* Communication feature selector codes */
/* (usbcdc11.pdf, 6.2.2..6.2.4, Table 47) */
#define CDC_ABSTRACT_STATE                      0x01
#define CDC_COUNTRY_SETTING                     0x02

/* Feature Status returned for ABSTRACT_STATE Selector */
/* (usbcdc11.pdf, 6.2.3, Table 48) */
#define CDC_IDLE_SETTING                        (1 << 0)
#define CDC_DATA_MULTPLEXED_STATE               (1 << 1)


/* Control signal bitmap values for the SetControlLineState request */
/* (usbcdc11.pdf, 6.2.14, Table 51) */
#define CDC_DTE_PRESENT                         (1 << 0)
#define CDC_ACTIVATE_CARRIER                    (1 << 1)

/* CDC class-specific notification codes */
/* (usbcdc11.pdf, 6.3, Table 68) */
/* see Table 67 for Info about class-specific notifications */
#define CDC_NOTIFICATION_NETWORK_CONNECTION     0x00
#define CDC_RESPONSE_AVAILABLE                  0x01
#define CDC_AUX_JACK_HOOK_STATE                 0x08
#define CDC_RING_DETECT                         0x09
#define CDC_NOTIFICATION_SERIAL_STATE           0x20
#define CDC_CALL_STATE_CHANGE                   0x28
#define CDC_LINE_STATE_CHANGE                   0x29
#define CDC_CONNECTION_SPEED_CHANGE             0x2A

/* UART state bitmap values (Serial state notification). */
/* (usbcdc11.pdf, 6.3.5, Table 69) */
#define CDC_SERIAL_STATE_OVERRUN                (1 << 6)  /* receive data overrun error has occurred */
#define CDC_SERIAL_STATE_OVERRUN_Pos            (     6)
#define CDC_SERIAL_STATE_OVERRUN_Msk            (1 << CDC_SERIAL_STATE_OVERRUN_Pos)
#define CDC_SERIAL_STATE_PARITY                 (1 << 5)  /* parity error has occurred */
#define CDC_SERIAL_STATE_PARITY_Pos             (     5)
#define CDC_SERIAL_STATE_PARITY_Msk             (1 << CDC_SERIAL_STATE_PARITY_Pos)
#define CDC_SERIAL_STATE_FRAMING                (1 << 4)  /* framing error has occurred */
#define CDC_SERIAL_STATE_FRAMING_Pos            (     4)
#define CDC_SERIAL_STATE_FRAMING_Msk            (1 << CDC_SERIAL_STATE_FRAMING_Pos)
#define CDC_SERIAL_STATE_RING                   (1 << 3)  /* state of ring signal detection */
#define CDC_SERIAL_STATE_RING_Pos               (     3)
#define CDC_SERIAL_STATE_RING_Msk               (1 << CDC_SERIAL_STATE_RING_Pos)
#define CDC_SERIAL_STATE_BREAK                  (1 << 2)  /* state of break detection */
#define CDC_SERIAL_STATE_BREAK_Pos              (     2)
#define CDC_SERIAL_STATE_BREAK_Msk              (1 << CDC_SERIAL_STATE_BREAK_Pos)
#define CDC_SERIAL_STATE_TX_CARRIER             (1 << 1)  /* state of transmission carrier */
#define CDC_SERIAL_STATE_TX_CARRIER_Pos         (     1)
#define CDC_SERIAL_STATE_TX_CARRIER_Msk         (1 << CDC_SERIAL_STATE_TX_CARRIER_Pos)
#define CDC_SERIAL_STATE_RX_CARRIER             (1 << 0)  /* state of receiver carrier */
#define CDC_SERIAL_STATE_RX_CARRIER_Pos         (     0)
#define CDC_SERIAL_STATE_RX_CARRIER_Msk         (1 << CDC_SERIAL_STATE_RX_CARRIER_Pos)


/*------------------------------------------------------------------------------
 *      Structures  based on usbcdc11.pdf (www.usb.org)
 *----------------------------------------------------------------------------*/

/* Header functional descriptor */
/* (usbcdc11.pdf, 5.2.3.1) */
/* This header must precede any list of class-specific descriptors. */
typedef struct _CDC_HEADER_DESCRIPTOR {
    U8  bFunctionLength;                      /* size of this descriptor in bytes */
    U8  bDescriptorType;                      /* CS_INTERFACE descriptor type */
    U8  bDescriptorSubtype;                   /* Header functional descriptor subtype */
    U16 bcdCDC;                               /* USB CDC specification release version */
} __attribute__((__packed__)) CDC_HEADER_DESCRIPTOR;

/* Call management functional descriptor */
/* (usbcdc11.pdf, 5.2.3.2) */
/* Describes the processing of calls for the communication class interface. */
typedef struct _CDC_CALL_MANAGEMENT_DESCRIPTOR {
    U8  bFunctionLength;                      /* size of this descriptor in bytes */
    U8  bDescriptorType;                      /* CS_INTERFACE descriptor type */
    U8  bDescriptorSubtype;                   /* call management functional descriptor subtype */
    U8  bmCapabilities;                       /* capabilities that this configuration supports */
    U8  bDataInterface;                       /* interface number of the data class interface used for call management (optional) */
} __attribute__((__packed__)) CDC_CALL_MANAGEMENT_DESCRIPTOR;

/* Abstract control management functional descriptor */
/* (usbcdc11.pdf, 5.2.3.3) */
/* Describes the command supported by the communication interface class with the Abstract Control Model subclass code. */
typedef struct _CDC_ABSTRACT_CONTROL_MANAGEMENT_DESCRIPTOR {
    U8  bFunctionLength;                      /* size of this descriptor in bytes */
    U8  bDescriptorType;                      /* CS_INTERFACE descriptor type */
    U8  bDescriptorSubtype;                   /* abstract control management functional descriptor subtype */
    U8  bmCapabilities;                       /* capabilities supported by this configuration */
} __attribute__((__packed__)) CDC_ABSTRACT_CONTROL_MANAGEMENT_DESCRIPTOR;

/* Union functional descriptors */
/* (usbcdc11.pdf, 5.2.3.8) */
/* Describes the relationship between a group of interfaces that can be considered to form a functional unit. */
typedef struct _CDC_UNION_DESCRIPTOR {
    U8  bFunctionLength;                      /* size of this descriptor in bytes */
    U8  bDescriptorType;                      /* CS_INTERFACE descriptor type */
    U8  bDescriptorSubtype;                   /* union functional descriptor subtype */
    U8  bMasterInterface;                     /* interface number designated as master */
} __attribute__((__packed__)) CDC_UNION_DESCRIPTOR;

/* Union functional descriptors with one slave interface */
/* (usbcdc11.pdf, 5.2.3.8) */
typedef struct _CDC_UNION_1SLAVE_DESCRIPTOR {
    CDC_UNION_DESCRIPTOR sUnion;              /* Union functional descriptor */
    U8                   bSlaveInterfaces[1]; /* Slave interface 0 */
} __attribute__((__packed__)) CDC_UNION_1SLAVE_DESCRIPTOR;

/* Line coding structure */
/* Format of the data returned when a GetLineCoding request is received */
/* (usbcdc11.pdf, 6.2.13) */
typedef struct _CDC_LINE_CODING {
    U32 dwDTERate;                            /* Data terminal rate in bits per second */
    U8  bCharFormat;                          /* Number of stop bits */
    U8  bParityType;                          /* Parity bit type */
    U8  bDataBits;                            /* Number of data bits */
} __attribute__((__packed__)) CDC_LINE_CODING;

/* Notification header */
/* Data sent on the notification endpoint must follow this header. */
/* see  USB_SETUP_PACKET in file usb.h */
typedef USB_SETUP_PACKET CDC_NOTIFICATION_HEADER;

#endif /* __USB_CDC_H */

