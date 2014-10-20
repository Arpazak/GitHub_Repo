/*******************************************************************************
********************************************************************************

   COPYRIGHT © 2003 Concept 2

   Contains confidential and proprietary information which may not be copied,
   disclosed or used by others except as expressly authorized in writing
   by Concept 2.

   PM3USB.h       External Interface Definitions for the PM3/USB interface DLL.

   About:         This module contains external interface definitions for the
				  low level DLL functions that allow applications to interface 
				  with PM3s over USB using HID.
				  The functions in this module are intended to be used with
				  the PM3 Device Discovery and Interface DLL, which is the
				  main API DLL for PC-based applications.

   Target:        Win32 Compatible

   Written for:   Concept 2
                  105 Industrial Park Drive
                  Morrisville, VT 05661
                  802-888-5225 (Voice)
                  802-888-6331 (Fax)

   Contacts:      Scott Hamilton 
                  802-888-5226 x3062 (Voice)
                  scotth@concept2.com

   Written by:    Rob Macklin / Andrew Dombek
                  Microprocessor Designs, Inc.
                  65 Longmeadow Drive
                  PO Box 160
                  Shelburne, VT 05482
                  http://www.updesigns.com

   $Revision: 1 $

--------------------------------------------------------------------------------
   $Log: /Concept II/C2PM3/Pc_src/SDK Release/PM3USB.h $
 * 
 * 1     3/10/05 5:23p Adomb
 * Branched a new release directory from the RowPro release, due to the
 * fact that we want an empty CSAFE INI file for public SDK.
 * 
 * 1     6/09/04 9:54a Adomb
 * 
 * 1     10/07/03 4:24p Adomb
 * Release 1.07 - Branched DLL from LogCard Utility.  INI files renamed
 * with "RP" on the front.
 * 
 * 1     10/07/03 7:23a Adomb
 * 
 * 1     6/05/03 9:57a Adomb
 * 
 * 1     xx/xx/03 xx:xxa Adomb
 * Initial check-in
 * 
********************************************************************************
*******************************************************************************/
#ifndef _PM3USB_H
#define _PM3USB_H

#ifdef _MSC_VER
   #ifdef PM3USB_EXPORTS
   #define PM3USB_API  extern "C" __declspec(dllexport)
   #else
   #define PM3USB_API  extern "C" __declspec(dllimport)
   #endif
#else
   #define PM3USB_API
#endif


/* MPD Standard data type definitions */
#ifndef MPD_TYPES
#define MPD_TYPES
typedef unsigned char  UINT8_T;
typedef unsigned short UINT16_T;
typedef unsigned long  UINT32_T;
typedef char           INT8_T;
typedef short          INT16_T;
typedef long           INT32_T;
typedef unsigned char  BOOLEAN_T;
typedef float          FLOAT32_T;
typedef INT16_T        ERRCODE_T;
#endif


/* Definitions for PM3 identifier strings */
//#define TKCMDSET_PM3_MANUFACTURER_NAME       L"Concept II"
#define TKCMDSET_PM3_PRODUCT_NAME            "Concept II PM3"
#define TKCMDSET_PM3_PRODUCT_NAME2           "Concept2 Performance Monitor 3 (PM3)"
#define TKCMDSET_PM3TESTER_PRODUCT_NAME      "Concept 2 PM3 Tester"
//#define TKCMDSET_PM3_PRODUCT_NAME            L"Back-UPS 350 FW: 5.2.D USB FW: c1 "

#define TKCMDSET_PROGRESS_MESSAGE            (WM_USER + 100)
#define TKCMDSET_WRITE_RAM_DATA              1
#define TKCMDSET_READ_RAM_DATA               2
#define TKCMDSET_WRITE_FLASH_DATA            3
#define TKCMDSET_READ_FLASH_DATA             4
#define TKCMDSET_WRITE_EE_DATA               5
#define TKCMDSET_READ_EE_DATA                6

#define DDI_CMD_DATA_OFFSET   1
#define DDI_RSP_DATA_OFFSET   1

/********************************************************************************
   Prototypes for standard DLL functions
********************************************************************************/


/****************************************************************************
   tkcmdsetUSB_get_dll_version()

   Returns the current version number of this software.

   Inputs:     None

   Outputs:    None
   
   Returns:    UINT16_T    ver_info    High byte is major version number
                                       Low byte is minor version number

****************************************************************************/
PM3USB_API UINT16_T tkcmdsetUSB_get_dll_version(void);

/****************************************************************************
   tkcmdsetUSB_get_error_name

   About:      Returns the name of the error associated with the code

   Inputs:     ERRCODE_T   ecode       Code to be looked up
               UINT16_T    namelen     Maximum length of name string

   Outputs:    char *      nameptr     Location to place name string

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3USB_API ERRCODE_T tkcmdsetUSB_get_error_name(ERRCODE_T ecode,char * nameptr,
												UINT16_T namelen);

/****************************************************************************
   tkcmdsetUSB_get_error_text

   About:      Returns the text description of the error associated with the code

   Inputs:     ERRCODE_T   ecode       Code to be looked up
               UINT16_T    namelen     Maximum length of text description string

   Outputs:    char *      nameptr     Location to place text description string

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3USB_API ERRCODE_T tkcmdsetUSB_get_error_text(ERRCODE_T ecode,char * textptr,
												UINT16_T textlen);



/********************************************************************************
   Prototypes for Command Set functions
********************************************************************************/

/****************************************************************************
   tkcmdsetUSB_init

   About:      Initializes the Command Set Toolkit functions.
               Opens the error .INI file, and gets port numbers of all USB HID 
               devices that match the product name.

   Inputs:     INT16_T *    product_name Name of USB device to open

   Outputs:    UINT8_T *   num_found   Number of devices that match name
               UINT8_T     port_list[] Port numbers of devices that match

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3USB_API ERRCODE_T tkcmdsetUSB_init(INT8_T * product_name, UINT8_T * num_found, 
                                      UINT8_T port_list[]);

/****************************************************************************
   tkcmdsetUSB_set_feature

   About:      Sends a USB SetFeature Standard Request to the device
               This is independent of the command / response protocol

   Inputs:     UINT16_T     port        Communication port to use
               UINT16_T    feature     Identifier for desired feature to activate

   Outputs:    None

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3USB_API ERRCODE_T tkcmdsetUSB_set_feature(UINT16_T port, UINT16_T feature);

/****************************************************************************
   tkcmdsetUSB_do_command

   About:      Handle the command / response transaction with the USB device

   Inputs:     UINT16_T    port        Identifier for device
               UINT8_T *   tx_ptr      Pointer to data block to be transmitted
               UINT16_T    timeout     Time to wait for response in milliseconds

   Outputs:    UINT8_T *   rx_ptr      Pointer to data block to save received data

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3USB_API ERRCODE_T tkcmdsetUSB_do_command(UINT16_T port, UINT8_T *tx_ptr, 
                                        UINT8_T *rx_ptr, UINT16_T timeout);

/****************************************************************************
   tkcmdsetUSB_do_DDIcommand

   About:      Send and receive a data block from the DDI interface.

   Inputs:     UINT16_T    port        Identifier for device
               UINT8_T *   cmd_ptr     Location of data to send to device

   Outputs:    UINT8_T *   rsp_ptr     Location to store data returned by device

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3USB_API ERRCODE_T tkcmdsetUSB_do_DDIcommand(UINT16_T port, UINT8_T * cmd_ptr, 
                                               UINT8_T * rsp_ptr, UINT16_T timeout);

/****************************************************************************
   tkcmdsetUSB_echo

   About:      Send and receive a data block, no action taken by device

   Inputs:     UINT16_T    port        Identifier for device
               UINT8_T *   cmd_ptr     Location of data to send to device

   Outputs:    UINT8_T *   rsp_ptr     Location to store data returned by device

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3USB_API ERRCODE_T tkcmdsetUSB_echo(UINT16_T port, UINT8_T * cmd_ptr, UINT8_T * rsp_ptr);

/****************************************************************************
   tkcmdsetUSB_status

   About:      Reads status information from the device

   Inputs:     UINT16_T    port        Identifier for device

   Outputs:    UINT32_T *  stat_ptr    Location to store status information

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3USB_API ERRCODE_T tkcmdsetUSB_status(UINT16_T port, UINT32_T *stat_ptr);

/****************************************************************************
   tkcmdsetUSB_special

   About:      Performs special operations based on the command

   Inputs:     UINT16_T    port        Identifier for device
               UINT16_T    cmd         Special command to execute
               UINT32_T    in_data     Value send with command

   Outputs:    UINT32_T *  out_data    Location to store value returned
                                       with response

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3USB_API ERRCODE_T tkcmdsetUSB_special(UINT16_T port, UINT16_T cmd, 
                                      UINT32_T in_data, UINT32_T *out_data);

/****************************************************************************
   tkcmdsetUSB_fw_version

   About:      Reads the firmware version information from the PM3

   Inputs:     UINT16_T    port        Communication port to use

   Outputs:    UINT8_T *   ver_ptr     FW version string stored at this location

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3USB_API ERRCODE_T tkcmdsetUSB_fw_version(UINT16_T port, UINT8_T * ver_ptr);


/****************************************************************************
   tkcmdsetUSB_hw_version

   About:      Reads the hardware version information from the PM3

   Inputs:     UINT16_T     port        Communication port to use

   Outputs:    UINT8_T *   ver_ptr     HW version string stored at this location

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3USB_API ERRCODE_T tkcmdsetUSB_hw_version(UINT16_T port, UINT8_T * ver_ptr);


/****************************************************************************
   tkcmdsetDDI_serial_number

   About:      Reads the serial number information from the PM3

   Inputs:     UINT16_T    port        Communication port to use

   Outputs:    UINT8_T *   ser_ptr     Serial number string stored at this location

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3USB_API ERRCODE_T tkcmdsetUSB_serial_number(UINT16_T port, UINT8_T * ser_ptr);


/****************************************************************************
   tkcmdsetUSB_shutdown

   About:      Shuts down the Command Set Toolkit functions

   Inputs:     UINT16_T    port        Communication port to use

   Outputs:    None

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3USB_API ERRCODE_T tkcmdsetUSB_shutdown(UINT16_T port);


#endif /* _PM3DDI_H */