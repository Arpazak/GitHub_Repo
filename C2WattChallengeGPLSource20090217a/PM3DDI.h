/*******************************************************************************
********************************************************************************

   COPYRIGHT © 2003 Concept 2

   Contains confidential and proprietary information which may not be copied,
   disclosed or used by others except as expressly authorized in writing
   by Concept 2.

   PM3DDI.h   External Interface Definitions for the PM3 Device Discovery & 
				  Interface DLL.

   About:     This module contains the DLL external interface definitions
				  that allow PC-based applications to communicate with PM3s. 
				  Functions in this module deal with discovering PM3s over
				  various media interfaces, and transferring commands and
				  data between the application and PM3s.  This DLL integrates
				  with the lower level media interface DLLs, as well as 
				  (optional) protocol interface DLLs.

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
   $Log: /Concept II/C2PM3/Pc_src/SDK Release/PM3DDI.h $
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
 * 1     10/07/03 7:18a Adomb
 * Moved workspace
 * 
 * 3     7/09/03 3:12p Adomb
 * Release 1.03 - Changed registry key from Concept 2 to Concept2
 * 
 * 1     6/05/03 9:54a Adomb
 * Release 1.0 - For Peter L.
 * 
 * 1     xx/xx/03 xx:xxa Adomb
 * Initial check-in
 * 
********************************************************************************
*******************************************************************************/
#ifndef _PM3DDI_H
#define _PM3DDI_H

#ifdef _MSC_VER
   #ifdef PM3DDI_EXPORTS
   #define PM3DDI_API  extern "C" __declspec(dllexport)
   #else
   #define PM3DDI_API  extern "C" __declspec(dllimport)
   #endif
#else
   #define PM3DDI_API
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

/* Maximum number of active PM3 devices */
#define TKPM3DDI_MAX_DEVICES 64

/* Media types */
#define TKPM3DDI_TYPE_UNDEFINED  0
#define TKPM3DDI_TYPE_USB        1
#define TKPM3DDI_TYPE_IP         2
#define TKPM3DDI_TYPE_ASYNC      3


/* Definitions for PM3 identifier strings */
//#define TKCMDSET_PM3_MANUFACTURER_NAME       L"Concept II"
#define TKCMDSET_PM3_PRODUCT_NAME            "Concept II PM3"
#define TKCMDSET_PM3_PRODUCT_NAME2           "Concept2 Performance Monitor 3 (PM3)"
#define TKCMDSET_PM4_PRODUCT_NAME            "Concept2 Performance Monitor 4 (PM4)"
#define TKCMDSET_PM3TESTER_PRODUCT_NAME      "Concept 2 PM3 Tester"

#define TKCMDSET_PROGRESS_MESSAGE            (WM_USER + 100)
#define TKCMDSET_WRITE_RAM_DATA              1
#define TKCMDSET_READ_RAM_DATA               2
#define TKCMDSET_WRITE_FLASH_DATA            3
#define TKCMDSET_READ_FLASH_DATA             4
#define TKCMDSET_WRITE_EE_DATA               5
#define TKCMDSET_READ_EE_DATA                6
#define TKCMDSET_WRITE_LOG_DATA              7
#define TKCMDSET_READ_LOG_DATA               8

/********************************************************************************
   Prototypes for standard DLL functions
********************************************************************************/


/****************************************************************************
   tkcmdsetDDI_get_dll_version()

   Returns the current version number of this software.

   Inputs:     None

   Outputs:    None
   
   Returns:    UINT16_T    ver_info    High byte is major version number
                                       Low byte is minor version number

****************************************************************************/
PM3DDI_API UINT16_T tkcmdsetDDI_get_dll_version(void);

/****************************************************************************
   tkcmdsetDDI_get_error_name

   About:      Returns the name of the error associated with the code

   Inputs:     ERRCODE_T   ecode       Code to be looked up
               UINT16_T    namelen     Maximum length of name string

   Outputs:    char *      nameptr     Location to place name string

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_get_error_name(ERRCODE_T ecode,char * nameptr,
												UINT16_T namelen);

/****************************************************************************
   tkcmdsetDDI_get_error_text

   About:      Returns the text description of the error associated with the code

   Inputs:     ERRCODE_T   ecode       Code to be looked up
               UINT16_T    namelen     Maximum length of text description string

   Outputs:    char *      nameptr     Location to place text description string

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_get_error_text(ERRCODE_T ecode,char * textptr,
												UINT16_T textlen);



/********************************************************************************
   Prototypes for Command Set functions
********************************************************************************/


/****************************************************************************
   tkcmdsetDDI_init

   About:      Initializes the Command Set Toolkit functions.
               Open the error .INI file.

   Inputs:     None

   Outputs:    None

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_init(void);

/****************************************************************************
   tkcmdsetDDI_discover_pm3s

   About:      Discover all PM3 devices connected to the PC via various
               media interfaces.  Create a PM3 device map that correlates
               consecutive unit identifiers to each device port number and 
               media interface location.  Note that the calling function
               provides the starting address of the unit ID.

   Inputs:     INT8_T      *product_name  Name of product to discover
               UINT16_T    starting_address  Address of first unit

   Outputs:    UINT16_T    *num_units  Number of devices found
                

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_discover_pm3s(INT8_T *product_name, 
                                               UINT16_T starting_address,
                                               UINT16_T *num_units);

/****************************************************************************
   tkcmdsetDDI_init_protocol

   About:      Initialize a protocol engine that will be used for device
               communications.  This is typically called by an external
               DLL to setup a specific communications protocol.

   Inputs:     ERRCODE_T   *frame_builder()  Ptr to frame builder function
               ERRCODE_T   *frame_checker()  Ptr to frame checker function
               UINT16_T    timeout           Command/response time out in MS
               UINT16_T    buffer_size       Max frame size
               UINT8_T     retries           Number of command retries

   Outputs:    None
                

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_init_protocol(ERRCODE_T (*) (UINT8_T *, UINT8_T *, UINT16_T *), 
                                               ERRCODE_T (*) (UINT8_T *, UINT8_T *, UINT16_T *),
                                               UINT16_T timeout, 
                                               UINT16_T buffer_size, UINT8_T retries);

/****************************************************************************
   tkcmdsetDDI_do_protocol

   About:      Utilizing the protocol engine that was previously setup
               in tkcmdsetDDI_init_protocol(), build and send a command
               frame, then receive and check a response frame.
               If the frame is valid, return the data.  

   Inputs:     UINT16_T    port              Identifier for device
               UINT16_T    *num_cmd_bytes    Number of data bytes to send
               UINT8_T     *cmd_data         Data bytes to send


   Outputs:    UINT16_T    *num_rsp_bytes    Number of received bytes
               UINT8_T     *response         Response bytes
               
 

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_do_protocol(UINT16_T port, 
                                             UINT16_T *num_cmd_bytes, UINT8_T *cmd_data,
                                             UINT16_T *num_rsp_bytes, UINT8_T *response);

/****************************************************************************
   tkcmdsetDDI_set_feature

   About:      Sends a USB SetFeature Standard Request to the device
               This is independent of the command / response protocol

   Inputs:     UINT16_T     port        Communication port to use
               UINT16_T    feature     Identifier for desired feature to activate

   Outputs:    None

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_set_feature(UINT16_T port, UINT16_T feature);

/****************************************************************************
   tkcmdsetDDI_do_command

   About:      Handle the command / response transaction with the device

   Inputs:     UINT16_T     port       Identifier for device
               UINT8_T *   tx_ptr      Pointer to data block to be transmitted
               UINT16_T    timeout     Time to wait for response in milliseconds

   Outputs:    UINT8_T *   rx_ptr      Pointer to data block to save received data

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_do_command(UINT16_T port, UINT8_T *tx_ptr, 
                                     UINT8_T *rx_ptr, UINT16_T timeout);

/****************************************************************************
   tkcmdsetDDI_echo

   About:      Send and receive a data block, no action taken by device

   Inputs:     UINT16_T     port        Identifier for device
               UINT8_T *   cmd_ptr     Location of data to send to device

   Outputs:    UINT8_T *   rsp_ptr     Location to store data returned by device

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_echo(UINT16_T port, UINT8_T * cmd_ptr, 
									  UINT8_T * rsp_ptr);


/****************************************************************************
   tkcmdsetDDI_fw_version

   About:      Reads the firmware version information from the PM3

   Inputs:     UINT16_T     port        Communication port to use

   Outputs:    UINT8_T *   ver_ptr     FW version string stored at this location

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_fw_version(UINT16_T port, UINT8_T * ver_ptr);


/****************************************************************************
   tkcmdsetDDI_hw_version

   About:      Reads the hardware version information from the PM3

   Inputs:     UINT16_T     port        Communication port to use

   Outputs:    UINT8_T *   ver_ptr     HW version string stored at this location

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_hw_version(UINT16_T port, UINT8_T * ver_ptr);


/****************************************************************************
   tkcmdsetDDI_serial_number

   About:      Reads the serial number information from the PM3

   Inputs:     UINT16_T     port        Communication port to use

   Outputs:    UINT8_T *   ser_ptr     Serial number string stored at this location

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_serial_number(UINT16_T port, UINT8_T * ser_ptr);


/****************************************************************************
   tkcmdsetDDI_status

   About:      Reads status information from the device

   Inputs:     UINT16_T     port        Identifier for device

   Outputs:    UINT32_T *  stat_ptr    Location to store status information

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_status(UINT16_T port, UINT32_T *stat_ptr);

/****************************************************************************
   tkcmdsetDDI_special

   About:      Performs special operations based on the command

   Inputs:     UINT16_T     port        Identifier for device
               UINT16_T    cmd         Special command to execute
               UINT32_T    in_data     Value send with command

   Outputs:    UINT32_T *  out_data    Location to store value returned
                                       with response

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_special(UINT16_T port, UINT16_T cmd, 
										 UINT32_T in_data, UINT32_T *out_data);


/****************************************************************************
   tkcmdsetDDI_shutdown

   About:      Shuts down the Command Set Toolkit functions

   Inputs:     UINT16_T     port        Communication port to use

   Outputs:    None

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3DDI_API ERRCODE_T tkcmdsetDDI_shutdown(UINT16_T port);


#endif /* _PM3DDI_H */